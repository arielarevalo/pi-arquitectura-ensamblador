#include "Headers/circuito.h"
#include "Headers/logger.h"

const Coordinacion Circuito::coordinaciones[3]{ coordinar_0, coordinar_1, coordinar_2 };

uint8_t Circuito::boton[TAM_BOTON]{ 0,0,0,0 };
uint8_t Circuito::contr[TAM_CONTR]{ 0,0,0,0 };
uint8_t Circuito::val_i[TAM_VAL]{ 0,0 };
uint8_t Circuito::dupl{ 1 };

uint8_t Circuito::val_o[TAM_VAL]{ 0,0 };
uint8_t Circuito::write{ 0 };

uint8_t Circuito::coord[TAM_COORD]{ 0,0,0 };
uint8_t Circuito::ruta_i[TAM_RUTA]{ 0,0,0,0,0,0,0 };
uint8_t Circuito::ruta_o{ 0 };

uint8_t Circuito::fase{ 0 };
uint8_t Circuito::fase_c{ 0 };
uint8_t Circuito::pos_esta{ 0 };

void Circuito::coordinar() {
	coordinaciones[fase_c]();
	++fase_c %= 3;
}

void Circuito::entrada(uint8_t pos) {
	boton[pos] = 1;

	__asm {
		CALL controlar
		CALL codificar
		CALL validar_i
	}
}

void Circuito::salida() {
	__asm {
		CALL decodificar
		CALL enrutar
	}
}

void Circuito::controlar() {
	Logger::info("Controlando botones. Valor de entrada", boton, TAM_BOTON);
	__asm {
		PUSH EDI
		PUSH ESI

		LEA EDI, boton             // Lee el array de botones
		LEA ESI, contr             // Lee el array para el controlador

		XOR ECX, ECX

		conBotones : CMP ECX, 3    // Compara el ECX a comparar
		JG fin                     // Si es mayor que 3 da Fin
		JMP compara                // Si no, lo manda a COMPARA

		compara : MOV AL, [EDI]    // Lee el dato del array de botones
		CMP AL, 1                  // Compara el dato leido contra un 1
		JE asigna                  // Si son iguales llama a ASIGNA 
		JMP avanza                 // Si son distintos llama a AVANZA

		asigna :
		MOV pos_esta, 1
			MOV[ESI], 1				   // Asigna como 1 el valor del array de control
			MOV[EDI], 0                // Limpia la posicion del array de botones
			INC EDI                    // Avanza en el array de botones
			INC ESI                    // Avanza en el array de control
			INC ECX                    // Aumenta el ECX
			JMP conBotones             // Se devuelve al controlador

			avanza : MOV[ESI], 0       // Limpia la posicion en el array de control
			MOV[EDI], 0                // Limpia la posicion en el array de botones
			INC EDI                    // Avanza en el array de botones
			INC ESI                    // Avanza en el array de control
			INC ECX                    // Aumenta el ECX
			JMP conBotones             // Se devuelve al controlador

			fin : MOV ECX, 0           // Limpia el ECX para evitar basura

			POP ESI
			POP EDI
	}
	Logger::info("Control de botones termina. Valor de salida", contr, TAM_CONTR);
}

void Circuito::codificar() {
	Logger::info("Codificando. Valor de entrada", contr, TAM_CONTR);
	__asm {
		MOV AL, 0
		MOV val_i[1], AL
		MOV  val_i[0], AL
		CMP contr[0], 1			// Si esta encendida pos 0 se sabe que corresponde a la 00 en binario y salta
		JE RESULTADO1

		MOV AL, 0
		MOV  val_i[1], AL
		MOV AL, 1
		MOV  val_i[0], AL
		CMP contr[1], 1			// Si esta encendida pos 1 se sabe que corresponde a la 01 en binario y salta
		JE RESULTADO1

		MOV AL, 1
		MOV  val_i[1], AL
		MOV AL, 0
		MOV  val_i[0], AL
		CMP contr[2], 1			// Si esta pos 2 encendida se sabe que corresponde a la 10 en binario y salta
		JE RESULTADO1

		MOV AL, 1
		MOV  val_i[0], AL
		MOV  val_i[1], AL
		CMP contr[3], 1			// Si esta encendida pos 3 se sabe que corresponde a la 11 en binario y salta
		JE RESULTADO1

		RESULTADO1 : MOV AL, 0	// Limpia el registro AL

	}
	Logger::info("Codificación termina. Valor de salida", val_i, TAM_VAL);
}

void Circuito::validar_i() {
	Logger::info("Validando entrada. Valor de entrada", val_i, TAM_VAL);
	__asm {
	com1:

		mov al, val_o[0]
			cmp val_i[0], al
			je com2
			mov dupl, 0
			mov al, dupl
			jmp resultado

			com2 :

		mov al, val_o[1]
			cmp val_i[1], al
			je dup
			mov dupl, 0
			mov al, dupl
			jmp resultado


			dup :

		mov dupl, 1; dupl = 1
			mov al, dupl; al = 1
			jmp resultado


			resultado :
		mov al, 0

	}
	Logger::info("Validación de entrada termina. Banderín duplicado", dupl);
}

void Circuito::validar_o() {
	Logger::info("Leyendo validador. Valor de entrada", val_i, TAM_VAL);
	__asm {
		cmp write, 1
		je wt
		jmp resultado1

		wt :
		mov al, val_i[0]
			mov val_o[0], al
			mov al, val_i[1]
			mov val_o[1], al
			mov dupl, 1
			mov pos_esta, 0
			jmp resultado1

			resultado1 :
	}
	Logger::info("Lectura validador termina. Valor de salida", val_o, TAM_VAL);
}

void Circuito::coordinar_0() {
	Logger::info("Semáforos en rojo.");
	Logger::info("Coordinando. Banderín duplicado", dupl);
	__asm {
		MOV CL, fase
		MOV AL, dupl					// Confirmar si dupl es cero
		TEST AL, AL
		JZ peaton

		INC fase						// Fase incrementa mod 4
		XOR EDX, EDX
		MOVZX EAX, fase
		MOV EBX, 4
		DIV EBX
		MOV fase, DL

		TEST CL, CL						// Confirmar si contador es cero
		JZ peaton

		MOV DL, CL						// Guardar valor de fase
		DEC DL							// Fase de semáforo es uno menos a fase de circuito (0 => Peaton)
		JMP fases

		peaton : INC write				// Solicitar valor reciente al validador
		PUSH ECX
		CALL validar_o
		POP ECX
		DEC write
		MOV AL, val_o[1]				// Extraer valor de salida del validador
		SHL AL, 1
		ADD AL, val_o[0]
		ADD AL, PEAT					//   Valor de fase al Acumulador
		MOV DL, AL

		fases :
		PUSH ESI
			MOV ECX, 3						// Número de bits del valor de salida al Contador
			MOV ESI, OFFSET coord

			digito : XOR AL, AL				// Extraer un bit de la fase del Acumulador
			RCR DL, 1
			ADC AL, 0
			MOV[ESI], AL					//   Valor de bit de la fase a salida coordinador
			INC ESI
			LOOP digito						// Tres bits en total
			POP ESI
	}
	Logger::info("Coordinación inicial termina. Valor de salida", coord, TAM_COORD);
	__asm {
		CALL salida
	}

}

void Circuito::coordinar_1() {
	Logger::info("Esperando en verde.");
	__asm {
		MOV ECX, 5
		delay30_0:
		PUSH ECX

			MOV ECX, 2147483647
			delay30_1 :
			LOOP delay30_1

			POP ECX
			LOOP delay30_0
	}
}

void Circuito::coordinar_2() {
	Logger::info("Esperando en amarillo.\n");
	__asm {
		MOV ECX, 2147483647
		delay4:
		LOOP delay4
	}
}

void Circuito::decodificar() {
	Logger::info("Decodificando. Valor de entrada", coord, TAM_COORD);
	__asm {
		PUSH ESI

		MOV ESI, 0
		CMP coord[0], 0
		JG P1
		CMP coord[1], 0
		JG P2
		CMP coord[2], 0
		JG P5
		JMP RESULTADO			// Si las tres posiciones estan apagadas (000) salta a resultado

		P1 : CMP coord[1], 0
		JG P6
		CMP coord[2], 0
		JG P3
		MOV ESI, 1				// Si posicion cero en el controlador de botones esta encendida y el resto apagadas (100)
		JMP RESULTADO			// Salta a resultado

		P2 : CMP coord[2], 0
		JG P4
		MOV ESI, 2				// Si posicion uno en el controlador de botones esta encendida y el resto apagadas (010)
		JMP RESULTADO			// Salta a resultado

		P3 : MOV ESI, 5			// Si posicion cero y dos en el controlador de botones estan encendidas y el resto apagadas (101)
		JMP RESULTADO			// Salta a resultado

		P4 : MOV ESI, 6			// Si posicion uno y dos en el controlador de botones estan encendidas y el resto apagadas (011)
		JMP RESULTADO			// Salta a resultado

		P5 : MOV ESI, 4			// Si posicion dos en el controlador de botones esta encendida y el resto apagadas (001)
		JMP RESULTADO			// Salta a resultado

		P6 : CMP coord[2], 0
		JG P7
		MOV ESI, 3				// Si posicion cero y uno en el controlador de botones estan encendidsa y el resto apagadas (110)
		JMP RESULTADO			// Salta a resultado

		P7 : MOV ESI, 7			// Si todas las posiciones en el controlador de botones estan encendidas (111), mueve un siete a SI
		JMP RESULTADO			// Salta a resultado

		RESULTADO : MOV DL, 1    // Coloca un uno en la posicion que recibe de SI
		MOV ruta_i[ESI], DL

		POP ESI
	}
	Logger::info("Decodificación termina. Valor de salida", ruta_i, TAM_RUTA);
}

void Circuito::enrutar() {
	Logger::info("Enrutando. Valor de entrada", ruta_i, TAM_RUTA);
	__asm {
		PUSH EDI
		PUSH ESI
		PUSH EBX

		XOR EBX, EBX

		MOV ECX, TAM_RUTA
		LEA ESI, ruta_i
		iterRuta :

		MOV EBX, ECX
			DEC EBX
			CMP[ESI + EBX], 1
			JE	finSi

			LOOP iterRuta
			JMP	finNo

			finSi :
		MOV[ESI + EBX], 0
			MOV ruta_o, BL

			finNo :
		POP EBX
			POP ESI
			POP EDI
	}
	Logger::info("Enrutamiento termina. Valor de salida", ruta_o);
}

uint8_t Circuito::getRuta() {
	return ruta_o;
}
