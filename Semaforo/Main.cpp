#include <cstdint>

static uint8_t BOTON[4]{ 0,0,0,0 };
static uint8_t CONTR[4]{ 0,0,0,0 };
static uint8_t VAL_I[2]{ 0,0 };
static uint8_t VAL_O[2]{ 0,0 };
static uint8_t COORD[3]{ 0,0,0 };
static uint8_t WRITE{ 0 };
static uint8_t DUPL{ 0 };

static const uint8_t FASES[7]{};
// storage for phases
// phase counter

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

	__asm {
		// CONTR controlador(BOTON)

		// VAL_I codificador(CONTR)

		// VAL_O validador(VAL_I)
	}
}