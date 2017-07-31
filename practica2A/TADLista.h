#include <iostream>
#include "TADCola.h"
using namespace std;
#define MAX 30

struct entrada
{
    char inicial;
    cola colaTerminos;
};



class lista {
	entrada  elementos[MAX]; // elementos de la lista
	int  n;              // nº de elementos que tiene la lista
  public:
    lista();
    lista(entrada e);
    bool esvacia();
    int longitud();
    void anadirIzq(entrada e);
    void anadirDch(entrada e);
    void eliminarIzq();
    void eliminarDch();
    entrada observarIzq();
    entrada observarDch();
    void concatenar(lista l);
    void insertar(int i, entrada e);
    void eliminar(int i);
    void modificar(int i, entrada e);
    entrada observar(int i);
};
