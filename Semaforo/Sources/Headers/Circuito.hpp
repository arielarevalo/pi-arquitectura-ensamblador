#pragma once

#include <cstdint>
#include <cstddef>
#include "Logger.hpp"

class Circuito
{
public:
	static void inicio();

	static void ciclo();

	static void setPos(uint8_t pos);

	static uint8_t hayPos();

	static uint8_t getRuta_O();

private:
	static const size_t TAM_BOTON{ 4 };
	static const size_t TAM_CONTR{ TAM_BOTON };
	static const size_t TAM_VAL{ 2 };
	static const size_t TAM_COORD{ 3 };
	static const size_t TAM_RUTA{ 7 };

	static void controlar();

	static void codificar();

	static void validar_i();

	static void validar_o();

	static void coordinar();

	static void decodificar();

	static void enrutar();

	static uint8_t getPos();

	static const uint8_t PEAT{ 3 };

	static uint8_t BOTON[TAM_BOTON];
	static uint8_t CONTR[TAM_CONTR];
	static uint8_t VAL_I[TAM_VAL];
	static uint8_t DUPL;

	static uint8_t VAL_O[TAM_VAL];
	static uint8_t WRITE;

	static uint8_t COORD[TAM_COORD];

	static uint8_t RUTA_I[TAM_RUTA];
	static uint8_t RUTA_O;

	static uint8_t FASE;
	static uint8_t POS;
	static uint8_t POS_ESTA;
};

uint8_t Circuito::BOTON[TAM_BOTON]{ 0,0,0,0 };
uint8_t Circuito::CONTR[TAM_CONTR]{ 0,0,0,0 };
uint8_t Circuito::VAL_I[TAM_VAL]{ 0,0 };
uint8_t Circuito::DUPL{ 0 };

uint8_t Circuito::VAL_O[TAM_VAL]{ 0,0 };
uint8_t Circuito::WRITE{ 0 };

uint8_t Circuito::COORD[TAM_COORD]{ 0,0,0 };
uint8_t Circuito::RUTA_I[TAM_RUTA]{ 0,0,0,0,0,0,0 };
uint8_t Circuito::RUTA_O{ 0 };

uint8_t Circuito::FASE{ 0 };
uint8_t Circuito::POS{ 0 };
uint8_t Circuito::POS_ESTA{ 0 };

void Circuito::inicio() {
	__asm {
		XOR ECX, ECX			; Cero al Contador
	}
}

void Circuito::ciclo() {
	Logger::info("Inicia ciclo. Contador de fase en", "Posición de botón", FASE, POS);
	__asm {
		MOVZX EAX, POS_ESTA
		TEST EAX, EAX
		JZ vehicular

		MOVZX EAX, [POS]		; entrada
		MOV BOTON[EAX], 1
		CALL controlar
		CALL codificar
		CALL validar_i

vehicular : CALL coordinar

		CALL decodificar		; salida
		CALL enrutar
	}
}

void Circuito::controlar() {
	Logger::info("Controlando botones. Valor de entrada", BOTON, TAM_BOTON);
	__asm {
		PUSH EDI
		PUSH ESI
		
		LEA EDI, BOTON             // Lee el array de botones
		LEA ESI, CONTR             // Lee el array para el controlador

		XOR ECX, ECX

		conBotones : CMP ECX, 3    //Compara el ECX a comparar
		JG fin                     // Si es mayor que 3 da Fin
		JMP compara                // Si no, lo manda a COMPARA

		compara : MOV AL, [EDI]    // Lee el dato del array de botones
		CMP AL, 1                  // Compara el dato leido contra un 1
		JE asigna                  // Si son iguales llama a ASIGNA 
		JMP avanza                 // Si son distintos llama a AVANZA

		asigna : MOV [ESI], 1      // Asigna como 1 el valor del array de control
		MOV [EDI], 0               // Limpia la posicion del array de botones
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
	Logger::info("Control de botones termina. Valor de salida", CONTR, TAM_CONTR);
}

void Circuito::codificar() {
	Logger::info("Codificando. Valor de entrada", CONTR, TAM_CONTR);
	__asm {
		// VAL_I codificador(CONTR)

		/* peatonal  db 0,0,1,0
			resul db ?,?
			num1 db ?
			num2 db ?*/
		mov al, 0
		mov resul[0], al
		mov resul[1],al
		cmp peatonal[0],1
		je resultado1
		
		mov al, 0
		mov resul[0], al
		mov al,1
		mov resul[1],al
		cmp peatonal[1],1
		je resultado1
		
		mov al, 1
		mov resul[0], al
		mov al,0
		mov resul[1],al
		cmp peatonal[2],1
		je resultado1
		
		mov al, 1
		mov resul[0], al
		mov resul[1],al
		cmp peatonal[3],1
		je resultado1
	}
	Logger::info("Codificación termina. Valor de salida", VAL_I, TAM_VAL);
}

void Circuito::validar_i() {
	Logger::info("Validando entrada. Valor de entrada", VAL_I, TAM_VAL);
	__asm {
		// DUPL entrada(VAL_I)
	}
	Logger::info("Validación de entrada termina. Banderín duplicado", DUPL);
}

void Circuito::validar_o() {
	Logger::info("Escribiendo validador. Valor de entrada", VAL_I, TAM_VAL);
	__asm {
		// VAL_O salida(WRITE)
	}
	Logger::info("Escritura validador termina. Valor de salida", VAL_O, TAM_VAL);
}

void Circuito::coordinar() {
	Logger::info("Coordinando. Banderín duplicado", DUPL);

	uint8_t* W{&WRITE};

	__asm {
		MOV AL, DUPL			; Confirmar si DUPL es cero
		TEST AL, AL
		JZ peaton
		TEST ECX, ECX			; Confirmar si contador es cero
		JZ peaton
		MOV EAX, ECX			; Valor de fase al Acumulador
		INC ECX					; Contador de fase aumenta
		JMP fases
peaton: INC W					; Solicitar valor reciente al validador
		CALL validar_o			
		DEC W
		MOV AL, VAL_O[1]		; Extraer valor de salida del validador
		SHL AL, 1
		ADD AL, VAL_O[0]
		ADD AL, PEAT			;   Valor de fase al Acumulador
fases:  PUSH ECX
		PUSH ESI
		MOV ECX, 3				; Número de bits del valor de salida al Contador
		MOV ESI, OFFSET COORD
		MOV EDX, EAX
digito: XOR EAX, EAX			; Extraer un bit de la fase del Acumulador
		RCR EDX, 1
		ADC EAX, 0
		MOV[ESI], AL			;   Valor de bit de la fase a salida coordinador
		INC ESI
		LOOP digito				; Tres bits en total
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

	Logger::info("Coordinación termina. Valor de salida", COORD, TAM_COORD);
}

void Circuito::decodificar() {
	Logger::info("Decodificando. Valor de entrada", COORD, TAM_COORD);
	__asm {
		// RUTA_I decodificador(COORD)

		/*entrada  db 1,1,1
   		resul db 8 dup ('0'),'$'
   		aux db 0*/
		cmp entrada[0],0
		jg p1
		cmp entrada[1],0
		jg p2
		cmp entrada[2],0
		jg p5
		//jmp resultado
		
		p1 proc
		
		cmp entrada[1],0
		jg p6
		cmp entrada[2],0
		jg p5
		mov SI,4
		//jmp resultado
		ret
		p1 endp
		
		p2 proc
		cmp entrada[2],0
		jg p4
		mov SI,2
		//jmp resultado
		ret
		p2 endp
		
		p3 proc
		cmp entrada[1],0
		jg p2
		cmp entrada[2],0
		jg p3
		mov SI,1
		//jmp resultado
		ret
		p3 endp

		
		p4 proc
		
		mov SI,3
		//jmp resultado
		ret
		p4 endp
		
		p5 proc
		mov SI,5
		//jmp resultado
		ret
		p5 endp
		
		p6 proc
		cmp entrada[2],0
		jg p7
		mov SI,6
		//jmp resultado
		ret
		p6 endp
		
		p7 proc
		mov SI,7
		//jmp resultado
		ret
		p7 endp
	}
	Logger::info("Decodificación termina. Valor de salida", RUTA_I, TAM_RUTA);
}

void Circuito::enrutar() {
	Logger::info("Enrutando. Valor de entrada", RUTA_I, TAM_RUTA);
	__asm {
		// RUTA_O enrutar(RUTA_I)
	}
	Logger::info("Enrutamiento termina. Valor de salida", RUTA_O);
}

void Circuito::setPos(uint8_t pos) {
	Circuito::POS = pos;
	Circuito::POS_ESTA = 1;
}

uint8_t Circuito::getPos() {
	POS_ESTA = 0;
	return POS;
}

uint8_t Circuito::hayPos() {
	return POS_ESTA;
}

uint8_t Circuito::getRuta_O() {
	return RUTA_O;
}
