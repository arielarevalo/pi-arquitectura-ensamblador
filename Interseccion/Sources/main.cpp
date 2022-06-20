#include <QApplication>
#include <stdlib.h>

#include "Headers/mainwindow.h"
#include "Headers/circuito.h"
#include "Headers/logger.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	Logger::setStart();

	while (true) {
		if (w.isPressed()) {
			Circuito::entrada(w.getButton());
		}

		Circuito::coordinar();

		int ruta{ Circuito::getRuta() };
		if (ruta < 8) {
			w.cambio(ruta);
		}
		else {
			Logger::error("Se falló al enrutar: Enrutador retornó valor de fase inválido.");
			exit(1);
		}

		a.processEvents();
	}

	return a.exec();
}