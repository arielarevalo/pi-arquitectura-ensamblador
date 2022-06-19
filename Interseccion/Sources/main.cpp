#include <QApplication>
#include <stdlib.h>

#include "Headers/mainwindow.h"
#include "Headers/circuito.h"
#include "Headers/logger.h"

void enrutar(Circuito);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	Logger::setStart();

	Circuito circuito;
	circuito.inicio();

	while (true) {
		circuito.ciclo();
		enrutar(circuito);
		a.processEvents();
	}

	return a.exec();
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