/* Copyright 2013 Almudena García Jurado-Centurión
    This file is part of Practica2A

    Practica2A is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Practica2A is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Practica2_AMC.  If not, see <http://www.gnu.org/licenses/>.
*/

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
