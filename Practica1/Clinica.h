/* Copyright 2013 Almudena García Jurado-Centurión
    This file is part of P1

    P1 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    P1 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with P1.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
//#include "TADCola.h"

const int TIEMPO = 250;
const int TAM_CADENA = 30;
typedef char cadena[TAM_CADENA];

struct Paciente {
	int id;
	cadena nombre;
	cadena apellidos;
	int edad;
};

class Clinica {
	private:
		FILE *fichero;
		int numPacientes;
		void posicionar(int p);
	public:
		Clinica(char nombreFichero[]);
		~Clinica();
		int getNumPacientes() { return numPacientes; };
		void consultar(char inicial);
		void insertar(Paciente p);
		void modificar(int id);
		void eliminar(int id);
		void simularOperaciones();
        void pacientesMayores(char nombreFichero[]);
};
