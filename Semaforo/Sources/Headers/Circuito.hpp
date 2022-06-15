#pragma once

#include <cstdint>
#include <cstddef>
#include <string>

class Circuito
{
public:
	void ciclo();

	void setPos(int pos);

	bool hayPos();

	uint8_t getRuta_O();

private:
	static const size_t TAM_BOTON{ 4 };
	static const size_t TAM_CONTR{ TAM_BOTON };
	static const size_t TAM_VAL{ 2 };
	static const size_t TAM_COORD{ 3 };
	static const size_t TAM_RUTA{ 7 };

	void entrada();

	void salida();

	void controlar();

	void codificar();

	void validar_i();

	void validar_o();

	void coordinar();

	void decodificar();

	void enrutar();

	int getPos();

	std::string imprimirArreglo(uint8_t arr[], size_t n);

	uint8_t BOTON[TAM_BOTON]{ 0,0,0,0 };
	uint8_t CONTR[TAM_CONTR]{ 0,0,0,0 };
	uint8_t VAL_I[TAM_VAL]{ 0,0 };
	uint8_t DUPL{ 0 };

	uint8_t VAL_O[TAM_VAL]{ 0,0 };
	uint8_t WRITE{ 0 };

	uint8_t COORD[TAM_COORD]{ 0,0,0 };

	uint8_t RUTA_I[TAM_RUTA]{ 0,0,0,0,0,0,0 };
	uint8_t RUTA_O{ 0 };

	int pos{ 0 };
	bool posEsta{ false };
};

void Circuito::ciclo() {
	// Puede ser ASM
	if (hayPos) {
		entrada();
	}
	coordinar();
	salida();
}

void Circuito::entrada() {
	Logger::info("Procesando entrada. Posición de botón: " + std::to_string(pos));
	// Puede ser ASM
	BOTON[getPos()] = 1;
	controlar();
	codificar();
	validar_i();
	Logger::info("Procesado de entrada termina. Valor de salida: " + imprimirArreglo(VAL_I, TAM_VAL));
}

void Circuito::salida() {
	// Puede ser ASM
	decodificar();
	enrutar();
}

void Circuito::controlar() {
	Logger::info("Controlando botones. Valor de entrada: " + imprimirArreglo(BOTON, TAM_BOTON));
	int indice = 0;
	__asm {
		// CONTR controlador(BOTON)
		
		LEA EDI, BOTON             // Lee el array de botones
		LEA ESI, CONTR             // Lee el array para el controlador

		conBotones : CMP indice, 3 //Compara el indice a comparar
		JG FIN                     // Si es mayor que 3 da Fin
		JMP COMPARA                // Si no, lo manda a COMPARA

		COMPARA : MOV AL, [EDI]    // Lee el dato del array de botones
		CMP AL, 1                  // Compara el dato leido contra un 1
		JE ASIGNA                  // Si son iguales llama a ASIGNA 
		JMP AVANZA                 // Si son distintos llama a AVANZA

		ASIGNA : MOV[ESI], 1       // Asigna como 1 el valor del array de control
		MOV[EDI], 0                // Limpia la posicion del array de botones
		INC EDI                    // Avanza en el array de botones
		INC ESI                    // Avanza en el array de control
		INC indice                 // Aumenta el indice
		JMP conBotones             // Se devuelve al controlador

		AVANZA : MOV[ESI], 0       // Limpia la posicion en el array de control
		MOV[EDI], 0                // Limpia la posicion en el array de botones
		INC EDI                    // Avanza en el array de botones
		INC ESI                    // Avanza en el array de control
		INC indice                 // Aumenta el indice
		JMP conBotones             // Se devuelve al controlador

		FIN : MOV indice, 0        // Limpia el indice para evitar basura

		// Fin CONTR controlador(BOTON)
	}
	Logger::info("Control de botones termina. Valor de salida: " + imprimirArreglo(CONTR, TAM_CONTR));
}

void Circuito::codificar() {
	Logger::info("Codificando. Valor de entrada: " + imprimirArreglo(CONTR, TAM_CONTR));
	__asm {
		// VAL_I codificador(CONTR)
	}
	Logger::info("Codificación termina. Valor de salida: " + imprimirArreglo(VAL_I, TAM_VAL));
}

void Circuito::validar_i() {
	Logger::info("Validando entrada. Valor de entrada: " + imprimirArreglo(VAL_I, TAM_VAL));
	__asm {
		// DUPL entrada(VAL_I)
	}
	Logger::info("Validación de entrada termina. Banderín duplicado: " + std::to_string(DUPL));
}

void Circuito::validar_o() {
	Logger::info("Escribiendo validador. Valor de entrada: " + imprimirArreglo(VAL_I, TAM_VAL));
	__asm {
		// VAL_O entrada(WRITE)
	}
	Logger::info("Escritura validador termina. Valor de salida: " + imprimirArreglo(VAL_O, TAM_VAL));
}

void Circuito::coordinar() {
	Logger::info("Coordinando. Contador de fase en: " + std::to_string(0) + " Banderín duplicado: " + std::to_string(DUPL));

	// Listo

	Logger::info("Coordinación termina. Valor de salida: " + imprimirArreglo(COORD, TAM_COORD));
}

void Circuito::decodificar() {
	Logger::info("Decodificando. Valor de entrada: " + imprimirArreglo(COORD, TAM_COORD));
	__asm {
		// RUTA_I decodificador(COORD)
	}
	Logger::info("Decodificación termina. Valor de salida: " + imprimirArreglo(RUTA_I, TAM_RUTA));
}

void Circuito::enrutar() {
	Logger::info("Enrutando. Valor de entrada: " + imprimirArreglo(RUTA_I, TAM_RUTA));
	__asm {
		// RUTA_O enrutar(RUTA_I)
	}
	Logger::info("Enrutamiento termina. Valor de salida: " + std::to_string(RUTA_O));
}

void Circuito::setPos(int pos) {
	this->pos = pos;
	this->posEsta = true;
}

int Circuito::getPos() {
	this->posEsta = false;
	return this->pos;
}

bool Circuito::hayPos() {
	return posEsta;
}

uint8_t Circuito::getRuta_O() {
	return RUTA_O;
}

std::string Circuito::imprimirArreglo(uint8_t arr[], size_t n) {
	std::string salida{ "[ " };
	for (size_t i{ 0 }; i < n; ++i) {
		salida += std::to_string(arr[i]) + " ";
	}
	return salida += " ]";
}
