# Diseño de Circuito de Semáforos

## Requisitos de implementación

* Escribir nombres de circuito en minúsculas, en español, con palabras separadas por espacios. Sin tildes. Para los nombres de *branch*, usar guión bajo ("_") para separar las palabras. Siempre sin tildes.

* Intentar respetar la escala de los circuitos existentes, en cuanto a espacio entre componentes (i.e. largo de cables).

* De ser posible, mantener una copia aparte del archivo `circuitos.circ`, ya que se han visto artefactos de merge que parecen estar deformando los circuitos.

#### Controlador (de) Botones

* El controlador debe esperar entrada de pulso, y emitir salida de señal constante. Esto dado que la forma más directa de simular un botón en Logisim es con el periférico incluido en la biblioteca por defecto para `Button`, el cual emite pulso, y la ausencia de alguna forma de programáticamente cambiar el estado de un elemento `Input` dentro de Logisim. Los botones en sí irían fuera del controlador a nivel de `main`.

* El controlador deberá presentar un funcionamiento de *switch*. La funcionalidad del controlador debe ser capaz de garantizar que las entradas del codificador 4x2 solamente reciban 1 de las 4 posibles entradas a la vez.

* Se sugiere fuertmente utilizar/modificar los elementos existentes en la biblioteca del proyecto para lograr convertir el pulso de un `Button` en una corriente constante, la cual a su vez puede ser cortada por la activación de alguna otra corriente. Una solución que nace de los supuestos es una donde cada botón se conecta inicialmente a un `Toggle`, el cual conserva el estado de *activado* para ese botón, y cuyo estado puede ser modificado por un pulso de cualquier otro de los botones.

#### Codificadores

* Los codificadores deben esperar entrada de señal constante, y emitir salida de señal constante.

* Las entradas y salidas del circuito de los codificadores deben ir etiquetadas, indicando cuál entrada/salida representa la 0,1,2,.. etc.

#### Validador

* El validador debe esperar entrada de señal constante, y emitir salida de señal constante.

* El validador debe recibir señal de escritura del coordinador, y emitir señales de salida, así como banderín de duplicado cuando la entrada actual es idéntica a la salida actual.

#### Enrutador

* El enrutador debe esperar entrada de señal constante, y emitir salida de señal constante.

* Las entradas y salidas del circuito del enrutador deben ir etiquetadas, indicando cuál entrada/salida representa la 0,1,2,.. etc.

#### Semáforos

* Los semáforos deben esperar entrada de pulso, e incrementar en uno la fase de su ciclo como resultado.

* Dado lo anterior, los semáforos deben presentar alguna memoria, manteniendo su estado de forma autónoma hasta recibir otro pulso. Esto se puede implementar con elementos básicos de circuitos secuenciales y/o utilizando circuitos existentes en la biblioteca.

* Las salidas del circuito de los semáforos deben ir etiquetadas, indicando cuál sálida representa cada fase de su ciclo (e.g. rojo fijo, verde fijo, amarillo fijo).

* Tránsito: Este semáforo debe presentar un ciclo de rojo fijo -> verde fijo -> amarillo fijo -> rojo fijo.

* Peatonal: Este semáforo debe presentar un ciclo de rojo fijo -> verde fijo -> verde parpadeando -> rojo fijo.

## Apéndices

#### Leyenda de Rutas por Fase

Todos los semáforos peatonales presentan una pareja, por lo cual sólo van numerados una vez.

| Fase (Vehicular) | Semáforos |
|------------------|-----------|
| 0                | 0,1       |
| 1                | 2         |
| 2                | 4,3       |
| 3                | 5         |
| Fase (Peatonal)  | Semáforos |
| 4                | 5,6       |
| 5                | 0,7       |
| 6                | 2,8       |
| 7                | 3,9       |

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

#### Posición de los semáforos

![Numeración de los semáforos](./assets/images/semaforos.png)

#### Diseño de la intersección

![Diseño de la intersección](./assets/images/interseccion.png)
