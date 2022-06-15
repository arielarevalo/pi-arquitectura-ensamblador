#include <stdlib.h>
#include "Headers/Circuito.hpp"
#include "Headers/Logger.hpp"

void enrutar(Circuito);

auto main() -> int {
	Logger::setStart();

	Circuito circuito;
	// Interfaz interfaz;

	// interfaz.andale()

	while (true) {
		circuito.ciclo();
		enrutar(circuito);
	}
}

void enrutar(Circuito circuito) {
	switch (circuito.getRuta_O()) {
	case 0:
		return; // llenar con metodos interfaz
	case 1:
		return;
	case 2:
		return;
	case 3:
		return;
	case 4:
		return;
	case 5:
		return;
	case 6:
		return;
	default:
		Logger::error("Se falló al enrutar: Enrutador retornó valor de fase inválido.");
		exit(1);
	}
}