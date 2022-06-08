#pragma once

#include <cstdint>

class Controlador {
public:
	Controlador(uint8_t entrada[4], uint8_t salida[4]) : entrada(entrada), salida(salida) {}

	void procesar();
private:
	uint8_t* entrada;
	uint8_t* salida;
};

void Controlador::procesar()
{
	// __asm 
}