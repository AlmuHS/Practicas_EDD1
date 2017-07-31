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

#ifndef _COLA
#define _COLA

#include <string>
#include <iostream>
using namespace std;

#define MAX 30

class cola {
    int  elementos[MAX]; //elementos de la cola
    int  inicio, fin;    //principio y fin de la cola
  public:
    cola(); // constructor de la clase
    void encolar(int e);
    void desencolar();
    int primero();
    bool esvacia();
    int longitud();
};

#endif
