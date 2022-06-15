# Diseño de Circuito de Semáforos

## Lineamientos de implementación

Los lineamientos podrán cambiar durante el transcurso de las diversas fases del proyecto. Por favor no esperar que el contenido de este documento sea estático, y mantenerse vigilante de algún cambio a su contenido en cada Pull Request.

* Hacer buen uso de los commits y su mensaje. Se trabajará en español hasta donde sea factible/razonable. Por favor documentar **siempre** en voz *pasiva* o *imperativa*, dependiendo del caso.

* Escribir nombres de circuito en minúsculas, en español, con palabras separadas por espacios. Sin tildes. Para los nombres de *branch*, usar guión bajo ("_") para separar las palabras. Siempre sin tildes.

* Intentar respetar la escala de los circuitos existentes, en cuanto a espacio entre componentes (i.e. largo de cables).

* Inicialmente se esperaba poder correr la simulación en tiempo real, con los valores de cada uno de los elementos de entrada y salida del circuito cambiando inmediatamente, de forma responsiva a la interfaz. A pesar de la conveniencia de esto, quedan muchas dudas sobre la seguridad de esta estrategia en cuanto al preservar los valores de los registros durante la ejecución de código x86 dentro de los bloques de ensamblador en línea del compilador dentro de una función lambda. En aras de ahorrar tiempo, se optó por no experimentar con esta alternativa para determinar su viabilidad, sino que se simulará esta concurrencia a través de un ciclo interrumpido en la simulación.


#### Diseño de la intersección

![Diseño de la intersección](./Resources/Images/Interseccion.png)

#### Posición de los semáforos

![Numeración de los semáforos](./Resources/Images/Semaforos.png)

#### Leyenda de Rutas por Fase

Todos los semáforos peatonales presentan una pareja, por lo cual sólo van numerados una vez.

<table>
<tr><td>

| Fase (Vehicular) | Semáforos |
|------------------|-----------|
| 0                | 0,1       |
| 1                | 2,5       |
| 2                | 3,4       |
| Fase (Peatonal)  | Semáforos |
| 3                | 5,6       |
| 4                | 0,7       |
| 5                | 2,8       |
| 6                | 3,9       |

</td><td>

| Semáforo | Número de conexiones |
|----------|----------------------|
| 0        | 2                    |
| 1        | 1                    |
| 2        | 2                    |
| 3        | 2                    |
| 4        | 1                    |
| 5        | 2                    |
| 6        | 1                    |
| 7        | 1                    |
| 8        | 1                    |
| 9        | 1                    |

</td></tr> </table>

#### Controlador (de) Botones

* Entrada: Direcciones de 32 bits al primer elemento del arreglo de entrada y al primer elemento del arreglo de salida.
* El controlador se ve reducido, en esta fase, a un programa que al correr revisa si uno de cuatro bytes en un arreglo en memoria es diferente a cero. De ser así, cambia todos los valores en un arreglo de salida a cero, y luego cambia el valor en el arreglo de salida de misma posición que el valor que es diferente a cero en el arreglo de entrada. Luego, cambia todos los valores del arreglo de entrada a cero.

#### Codificadores

* Entrada: Direcciones de 32 bits al primer elemento del arreglo de entrada/salida y al primer elemento del arreglo de salida/entrada.
* Los codificadores, dependiendo de su dirección, convierten a/desde una dirección de byte única en memoria, que representa un valor único binario, desde/a un arreglo de bytes en memoria de tamaño *k*, para representar los *k* diferentes estados de entrada/salida.

#### Validador

* Entrada: Direcciones de 32 bits al primer elemento del arreglo de entrada, al primer elemento del arreglo de salida y al elemento DUPL.
* La entrada-del-validador consiste en un programa que compara el valor en un arreglo de entrada de dos bytes en memoria con el valor en un arreglo de salida de dos bytes en memoria. Si los valores son iguales, cambia una dirección de byte en memoria *(DUPL)* a uno, si no son iguales, la cambia a cero.

* Entrada: Direcciones de 32 bits al primer elemento del arreglo de entrada, al primer elemento del arreglo de salida y al elemento WRITE.
* La salida-del-validador consiste en un programa que prueba si el valor del banderín de escritura *(WRITE)* es diferente de cero. Si es diferente de cero, escribe los valores del arreglo de entrada al arreglo de salida.

#### Enrutador

* Entrada: Direcciones de 32 bits al primer elemento del arreglo de entrada, direcciones de memoria
de cada función para cambiar de fase la interfaz.
* El enrutador consiste en un programa que prueba si algún elemento del arreglo de entrada es diferente de cero. Al encontrar el primer elemento diferente de cero, llama la función de la interfaz indicada para la fase del mismo número que la posición diferente de cero.

#### Semáforos

* La funcionalidad de los semáforos se ha visto absorbida por la interfaz gráfica.
