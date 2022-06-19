#include "Headers/circuito.h"
#include "Headers/logger.h"

uint8_t Circuito::boton[TAM_BOTON]{ 0,0,0,0 };
uint8_t Circuito::contr[TAM_CONTR]{ 0,0,0,0 };
uint8_t Circuito::val_i[TAM_VAL]{ 0,0 };
uint8_t Circuito::dupl{ 0 };

uint8_t Circuito::val_o[TAM_VAL]{ 0,0 };
uint8_t Circuito::write{ 0 };

uint8_t Circuito::coord[TAM_COORD]{ 0,0,0 };
uint8_t Circuito::ruta_i[TAM_RUTA]{ 0,0,0,0,0,0,0 };
uint8_t Circuito::ruta_o{ 0 };

uint8_t Circuito::fase{ 0 };
uint8_t Circuito::pos{ 0 };
uint8_t Circuito::pos_esta{ 0 };

void Circuito::inicio() {
	__asm {
		XOR ECX, ECX				// Cero al Contador
	}
}

void Circuito::ciclo() {
	Logger::info("Inicia ciclo. Contador de fase en", "Posición de botón", fase, pos);
	__asm {
		MOVZX EAX, pos_esta			// Se confirma si es necesario
		TEST EAX, EAX				//   correr lógica de entrada
		JZ vehicular

		MOVZX EAX, [pos]			// Entrada:
		MOV boton[EAX], 1			//   Se asigna entrada de UI a entrada de circuito
		CALL controlar
		CALL codificar
		CALL validar_i

vehicular:
		CALL coordinar

		CALL decodificar			// Salida
		CALL enrutar
	}
}

void Circuito::controlar() {
	Logger::info("Controlando botones. Valor de entrada", boton, TAM_BOTON);
	__asm {
		PUSH EDI
		PUSH ESI

		LEA EDI, boton				// Lee el array de botones
		LEA ESI, contr              // Lee el array para el controlador

		XOR ECX, ECX

conBotones:
		CMP ECX, 3					// Compara el ECX a comparar
		JG fin                      // Si es mayor que 3 da Fin
		JMP compara                 // Si no, lo manda a COMPARA

compara:
		MOV AL, [EDI]				// Lee el dato del array de botones
		CMP AL, 1                   // Compara el dato leido contra un 1
		JE asigna                   // Si son iguales llama a ASIGNA 
		JMP avanza                  // Si son distintos llama a AVANZA

asigna: MOV[ESI], 1					// Asigna como 1 el valor del array de control
		MOV[EDI], 0                 // Limpia la posicion del array de botones
		INC EDI                     // Avanza en el array de botones
		INC ESI                     // Avanza en el array de control
		INC ECX                     // Aumenta el ECX
		JMP conBotones              // Se devuelve al controlador

avanza: MOV[ESI], 0					// Limpia la posicion en el array de control
		MOV[EDI], 0                 // Limpia la posicion en el array de botones
		INC EDI                     // Avanza en el array de botones
		INC ESI                     // Avanza en el array de control
		INC ECX                     // Aumenta el ECX
		JMP conBotones              // Se devuelve al controlador
								    
fin:	MOV ECX, 0					// Limpia el ECX para evitar basura

		POP ESI
		POP EDI
	}
	Logger::info("Control de botones termina. Valor de salida", contr, TAM_CONTR);
}

void Circuito::codificar() {
	Logger::info("Codificando. Valor de entrada", contr, TAM_CONTR);
	__asm {
		// VAL_I codificador(CONTR)
	}
	Logger::info("Codificación termina. Valor de salida", val_i, TAM_VAL);
}

void Circuito::validar_i() {
	Logger::info("Validando entrada. Valor de entrada", val_i, TAM_VAL);
	__asm {
		// DUPL entrada(VAL_I)
	}
	Logger::info("Validación de entrada termina. Banderín duplicado", dupl);
}

void Circuito::validar_o() {
	Logger::info("Escribiendo validador. Valor de entrada", val_i, TAM_VAL);
	__asm {
		// VAL_O salida(WRITE)
	}
	Logger::info("Escritura validador termina. Valor de salida", val_o, TAM_VAL);
}

void Circuito::coordinar() {
	Logger::info("Coordinando. Banderín duplicado", dupl);

	uint8_t* W{ &write };

	__asm {
		MOV AL, dupl; Confirmar si dupl es cero
		TEST AL, AL
		JZ peaton
		TEST ECX, ECX; Confirmar si contador es cero
		JZ peaton
		MOV EAX, ECX; Valor de fase al Acumulador
		INC ECX; Contador de fase aumenta
		JMP fases
		peaton : INC W; Solicitar valor reciente al validador
		CALL validar_o
		DEC W
		MOV AL, val_o[1]; Extraer valor de salida del validador
		SHL AL, 1
		ADD AL, val_o[0]
		ADD AL, PEAT;   Valor de fase al Acumulador
		fases : PUSH ECX
		PUSH ESI
		MOV ECX, 3; Número de bits del valor de salida al Contador
		MOV ESI, OFFSET coord
		MOV EDX, EAX
		digito : XOR EAX, EAX; Extraer un bit de la fase del Acumulador
		RCR EDX, 1
		ADC EAX, 0
		MOV[ESI], AL;   Valor de bit de la fase a salida coordinador
		INC ESI
		LOOP digito; Tres bits en total
		POP ECX
		POP ESI
	}

	// cambio de luces fase (COORD)

	__asm {
		MOV ECX, 1073741823
		delay30:
		LOOP delay30
	}

	// cambio de luces fase (COORD)

	__asm {
		MOV ECX, 134217727
		delay4:
		LOOP delay4
	}

	// cambio de luces fase (COORD)

	Logger::info("Coordinación termina. Valor de salida", coord, TAM_COORD);
}

void Circuito::decodificar() {
	Logger::info("Decodificando. Valor de entrada", coord, TAM_COORD);
	__asm {
		// RUTA_I decodificador(COORD)
	}
	Logger::info("Decodificación termina. Valor de salida", ruta_i, TAM_RUTA);
}

void Circuito::enrutar() {
	Logger::info("Enrutando. Valor de entrada", ruta_i, TAM_RUTA);
	__asm {
		// RUTA_O enrutar(RUTA_I)
	}
	Logger::info("Enrutamiento termina. Valor de salida", ruta_o);
}

void Circuito::setPos(uint8_t pos) {
	Circuito::pos = pos;
	Circuito::pos_esta = 1;
}

uint8_t Circuito::getPos() {
	pos_esta = 0;
	return pos;
}

uint8_t Circuito::hayPos() {
	return pos_esta;
}

uint8_t Circuito::getRuta_O() {
	return ruta_o;
}
