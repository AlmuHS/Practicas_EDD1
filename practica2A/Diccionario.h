#include <iostream>
#include "TADLista.h"
#include <string.h>
#include <stdio.h>

typedef char cadena[51];
typedef char cadena2[251];


struct TNodo_Lista
{
    termino t;
    TNodo_Lista *ant;
    TNodo_Lista *sig;
};


struct tpalabra
{
    cadena termino;
    cadena2 definicion;
};

struct treg
{
    bool vacia;
    tpalabra palabra;
};

class diccionario{
    FILE *f;
    lista lis;
    public:
        bool abrirdiccionario(cadena2 ruta);
        void insertarEntrada(lista& lis, termino t);
        void leerentradas();
        void imprimirlista();
        void mostrar(TNodo_Lista *pNodo);
        TNodo_Lista* invertir(TNodo_Lista *pNodo);
        TNodo_Lista *eliminar(TNodo_Lista *pNodo, int pos);
        void mover(TNodo_Lista *pNodo, int p1, int p2);

};
