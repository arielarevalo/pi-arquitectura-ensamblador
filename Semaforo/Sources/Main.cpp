#include <stdlib.h>
#include "Headers/Circuito.hpp"
#include "Headers/Logger.hpp"

void enrutar(int ruta);

auto main() -> int {
	Logger::setStart();

	while (true) {
		// Interfaz necesita un banderin{false} de que boton fue oprimido
		// if Interfaz.banderin
		// Circuito::entrada(Interfaz.pos)
		// end if
		Circuito::coordinar();
		enrutar(Circuito::getRuta());
		// a.processEvents()
	}
}

void enrutar(int ruta) {
	if (ruta < 8) {
		// Interfaz.cambio(ruta)
	} else {
		Logger::error("Se falló al enrutar: Enrutador retornó valor de fase inválido.");
		exit(1);
	}
}