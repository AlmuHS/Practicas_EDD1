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
