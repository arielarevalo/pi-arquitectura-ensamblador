#pragma once

#include <cstdint>

class Circuito
{
public:
	void coordinar();

	void entrada();

	void setPos(int pos);

private:
	void validar_i();

	void validar_o();

	void controlar();

	void codificar();

	void decodificar();

	void enrutar();

	int getPos();

	uint8_t BOTON[4]{ 0,0,0,0 };
	uint8_t CONTR[4]{ 0,0,0,0 };
	uint8_t VAL_I[2]{ 0,0 };
	uint8_t VAL_O[2]{ 0,0 };
	uint8_t WRITE{ 0 };
	uint8_t DUPL{ 0 };
	uint8_t COORD[3]{ 0,0,0 };
	uint8_t RUTA_I[7]{ 0,0,0,0,0,0,0 };
	
	int pos{ 0 };
	bool isPosSet{ false };
};

void Circuito::coordinar() {
	// Listo
}

void Circuito::entrada() {
	BOTON[getPos()] = 1;

	// Puede ser ASM
	controlar();
	codificar();
	validar_i();
}


void Circuito::validar_i() {
	__asm {
		// DUPL entrada(VAL_I)
	}
}

void Circuito::validar_o() {
	__asm {
		// VAL_O entrada(WRITE)
	}
}

void Circuito::controlar() {
	__asm {
		// CONTR controlador(BOTON)
	}
}

void Circuito::codificar() {
	__asm {
		// VAL_I codificador(CONTR)
	}
}

void Circuito::decodificar() {
	__asm {
		// RUTA_I decodificador(COORD)
	}
}

void Circuito::enrutar() {
	// Vamos a ver si esto es factible.
	// Si no, lo hacemos en C.
	// Depende de si al compilador le guste
	// o no llamar funciones C desde ASM.
	// [CALL GUI] enrutar(RUTA_I)
}

void Circuito::setPos(int pos) {
	this->pos = pos;
	this->isPosSet = true;
}

int Circuito::getPos() {
	this->isPosSet = false;
	return this->pos;
}
