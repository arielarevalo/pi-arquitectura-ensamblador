#include <cstdint>

static uint8_t BOTON[4]{ 0,0,0,0 };
static uint8_t CONTR[4]{ 0,0,0,0 };
static uint8_t VAL_I[2]{ 0,0 };
static uint8_t VAL_O[2]{ 0,0 };
static uint8_t COORD[3]{ 0,0,0 };
static uint8_t WRITE{ 0 };
static uint8_t DUPL{ 0 };

void coordinar();

void entrada(int pos);

auto main(int argc, char** argv) -> int {
	coordinar();
	return 0;
}

void coordinar() {
	__asm {
		// selección de nueva fase
		// cambiar COORD a nueva fase
	}

	// cambio de luces fase (COORD)

	__asm {
		// espera de 30 segundos
	}

	// cambio de luces fase (COORD)

	__asm {
		// espera de cuatro segundos
	}

	// cambio de luces fase (COORD)

	__asm {
		// bucle jmp inicio
	}
}

void entrada(int pos) {
	BOTON[pos] = 1;
	int indice = 0;

	__asm {
		// CONTR controlador(BOTON)
		LEA EDI, BOTON            // Lee el array de botones
		LEA ESI, CONTR            // Lee el array para el controlador

		conBotones: CMP indice, 3 //Compara el indice a comparar
		            JG FIN        // Si es mayor que 3 da Fin
		            JMP COMPARA   // Si no, lo manda a COMPARA

		COMPARA: MOV AL, [EDI]    // Lee el dato del array de botones
		         CMP AL, 1        // Compara el dato leido contra un 1
		         JE ASIGNA        // Si son iguales llama a ASIGNA 
		         JMP AVANZA       // Si son distintos llama a AVANZA

		ASIGNA: MOV [ESI], 1      // Asigna como 1 el valor del array de control
		        MOV [EDI], 0      // Limpia la posicion del array de botones
			    INC EDI           // Avanza en el array de botones
			    INC ESI           // Avanza en el array de control
			    INC indice        // Aumenta el indice
				JMP conBotones    // Se devuelve al controlador

		AVANZA: MOV[ESI], 0       // Limpia la posicion en el array de control
				MOV[EDI], 0       // Limpia la posicion en el array de botones
				INC EDI           // Avanza en el array de botones
				INC ESI           // Avanza en el array de control
			    INC indice        // Aumenta el indice
				JMP conBotones    // Se devuelve al controlador

		FIN: MOV indice, 0        // Limpia el indice para evitar basura
	
		// VAL_I codificador(CONTR)

		// VAL_O validador(VAL_I)
	}
}