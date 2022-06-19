#pragma once

#include <cstdint>
#include <cstddef>
#include "logger.h"

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

	static uint8_t boton[TAM_BOTON];
	static uint8_t contr[TAM_CONTR];
	static uint8_t val_i[TAM_VAL];
	static uint8_t dupl;

	static uint8_t val_o[TAM_VAL];
	static uint8_t write;

	static uint8_t coord[TAM_COORD];

	static uint8_t ruta_i[TAM_RUTA];
	static uint8_t ruta_o;

	static uint8_t fase;
	static uint8_t pos;
	static uint8_t pos_esta;
};