#pragma once

#include <cstdint>
#include <cstddef>
#include <chrono>
#include <thread>
#include "Logger.hpp"

typedef void (*Coordinacion)();

class Circuito
{
public:
	static void coordinar();

	static void entrada(uint8_t pos);

	static void salida();

	static uint8_t getRuta();

private:
	static const size_t TAM_BOTON{ 4 };
	static const size_t TAM_CONTR{ TAM_BOTON };
	static const size_t TAM_VAL{ 2 };
	static const size_t TAM_COORD{ 3 };
	static const size_t TAM_RUTA{ 7 };
	static const uint8_t PEAT{ 3 };
	static const Coordinacion coordinaciones[3];

	static void controlar();

	static void codificar();

	static void validar_i();

	static void coordinar_0();

	static void coordinar_1();

	static void coordinar_2();

	static void validar_o();

	static void decodificar();

	static void enrutar();

	static uint8_t boton[TAM_BOTON];
	static uint8_t contr[TAM_CONTR];
	static uint8_t val_i[TAM_VAL];
	static uint8_t dupl;

	static uint8_t val_o[TAM_VAL];
	static uint8_t write;

	static uint8_t coord[TAM_COORD];

	static uint8_t ruta_i[TAM_RUTA];
	static uint8_t ruta_o;


	static uint8_t fase_c;
	static uint8_t fase;
	static uint8_t pos_esta;
};

const Coordinacion Circuito::coordinaciones[3]{ coordinar_0, coordinar_1, coordinar_2 };

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
		// VAL_I codificador(CONTR)
	}
	Logger::info("Codificación termina. Valor de salida", val_i, TAM_VAL);
}

void Circuito::validar_i() {
	Logger::info("Validando entrada. Valor de entrada", val_i, TAM_VAL);
	__asm {
		// DUPL entrada(VAL_I)
		//entrada  db 1, 0
		//salida  db 1, 1
		//DUPL db ?
		//resul db ?

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
	Logger::info("Escribiendo validador. Valor de entrada", val_i, TAM_VAL);
	__asm {
		// VAL_O salida(WRITE)

	dup1:
		cmp dupl, 1
			je resultado1
			jmp wt


			wt :
		mov al, val_i[0]
			mov val_o[0], al
			mov al, val_i[1]
			mov val_o[1], al
			jmp resultado1


			resultado1 :
		mov al, 0
			jmp resultado2

			resultado2 :
		mov al, 0
			mov pos_esta, 0
	}
	Logger::info("Escritura validador termina. Valor de salida", val_o, TAM_VAL);
}

void Circuito::coordinar_0() {
	Logger::info("Coordinando. Banderín duplicado", dupl);
	__asm {
		MOV AL, dupl					// Confirmar si dupl es cero
		TEST AL, AL
		MOV CL, fase
		JZ peaton
		TEST CL, CL						// Confirmar si contador es cero
		JZ peaton
		MOV AL, CL						// Valor de fase al Acumulador
		INC fase						// Contador de fase aumenta
		JMP fases

		peaton : INC write				// Solicitar valor reciente al validador
		PUSH CX
		CALL validar_o
		POP CX
		DEC write
		MOV AL, val_o[1]				// Extraer valor de salida del validador
		SHL AL, 1
		ADD AL, val_o[0]
		ADD AL, PEAT					//   Valor de fase al Acumulador

		fases : MOV fase, CL

		PUSH ESI
		MOV ECX, 3						// Número de bits del valor de salida al Contador
		MOV ESI, OFFSET coord
		MOV DL, AL

		digito : XOR AL, AL				// Extraer un bit de la fase del Acumulador
		RCR DL, 1
		ADC AL, 0
		MOV[ESI], AL					//   Valor de bit de la fase a salida coordinador
		INC ESI
		LOOP digito						// Tres bits en total
		POP ESI
	}
	Logger::info("Coordinación termina. Valor de salida", coord, TAM_COORD);
}

void Circuito::coordinar_1() {
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
	__asm {
		MOV ECX, 2147483647
		delay4:
		LOOP delay4
	}
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
		PUSH EDI
		PUSH ESI

		MOV ECX, TAM_RUTA
		LEA ESI, ruta_i
		iterRuta :

		MOV EBX, ECX - 1
			CMP ESI[EBX], 1
			JE	finSi

			LOOP iterRuta
			JMP	finNo

			finSi :
		MOV ruta_o, EBX

			finNo :
	}
	Logger::info("Enrutamiento termina. Valor de salida", ruta_o);
}

uint8_t Circuito::getRuta() {
	return ruta_o;
}
