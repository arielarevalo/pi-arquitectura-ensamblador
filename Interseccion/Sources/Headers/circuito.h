#pragma once

#include <cstdint>
#include <cstddef>
#include <chrono>
#include <thread>
#include "./logger.h"

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