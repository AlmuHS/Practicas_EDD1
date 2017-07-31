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
