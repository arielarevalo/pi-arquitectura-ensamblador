#include <cstdint>

static uint8_t BOTON[4]{ 0,0,0,0 };
static uint8_t CONTR[4]{ 0,0,0,0 };
static uint8_t VAL_I[2]{ 0,0 };
static uint8_t VAL_O[2]{ 0,1 };
static uint8_t COORD[3]{ 0,0,0 };
static uint8_t WRITE{ 0 };
static uint8_t DUPL{ 0 };
static uint8_t FASE{ 0 };
static const uint8_t PEAT{ 3 };

void coordinar();

void entrada(int pos);

auto main(int argc, char** argv) -> int {
	coordinar();
	return 0;
}

void coordinar() {
	__asm {
        XOR ECX, ECX        ; Cero al Contador
start:  MOV AL, DUPL        ; Confirmar si DUPL es cero
        TEST AL, AL
        JZ peaton
        TEST ECX, ECX       ; Confirmar si contador es cero
        JZ peaton
        MOV AL, CL          ; Valor de fase al Acumulador
        INC ECX             ; Contador de fase aumenta
        JMP fases
peaton: MOV WRITE, 1        ; Solicitar valor reciente al validador
                            ; [TODO:Llamar validador]
        DEC WRITE
        MOV AL, VAL_O[1]    ; Extraer valor de salida del validador
        SHL AL, 1
        ADD AL, VAL_O[0]
        ADD AL, PEAT        ;   Valor de fase al Acumulador
fases:  PUSH ECX
        PUSH ESI
        MOV ECX, 3          ; Número de bits del valor de salida al Contador
        MOV ESI, OFFSET COORD
        MOV EDX, EAX
digito: XOR EAX, EAX        ; Extraer un bit de la fase del Acumulador
        RCR EDX, 1
        ADC EAX, 0
        MOV[ESI], AL        ;   Valor de bit de la fase a salida coordinador
        INC ESI
        LOOP digito         ; Tres bits en total
        POP ECX
        POP ESI
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
        JMP start
	}
}

void entrada(int pos) {
	BOTON[pos] = 1;

	__asm {
		// CONTR controlador(BOTON)

		// VAL_I codificador(CONTR)

		// VAL_O validador(VAL_I)
	}
}