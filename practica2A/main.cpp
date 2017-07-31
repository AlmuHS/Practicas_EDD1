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
#include "Diccionario.h"
#include <string.h>
#include <stdio.h>

using namespace std;

/*Practica hecha en Debian Testing 6, usando codeblocks y gcc
Version para Linux. En Windows añadir system ("pause") */

int main()
{
    diccionario dictio;
    cadena2 ruta;
    bool correcto;
    cout<<"Introduce la ruta del fichero diccionario: ";
    cin>>ruta;
    correcto=dictio.abrirdiccionario(ruta);
    if (correcto==true) cout<<"Diccionario abierto correctamente\n";
    else cout<<"Error al abrir el fichero";
    dictio.leerentradas();
    dictio.imprimirlista();
    return 0;
}
