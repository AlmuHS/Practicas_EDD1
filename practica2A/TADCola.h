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

#include <string>
#include <iostream>
using namespace std;

typedef string termino;
#define MAX 30

class cola {
    termino  elementos[MAX]; //elementos de la cola
    int  inicio, fin;    //principio y fin de la cola
  public:
    cola(); // constructor de la clase
    void encolar(termino e);
    void desencolar();
    termino primero();
    bool esvacia();
    int longitud();
};
