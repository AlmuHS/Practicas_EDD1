/* Copyright 2013 Almudena García Jurado-Centurión
    This file is part of Practica2

    Practica2 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Practica2 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Practica2.  If not, see <http://www.gnu.org/licenses/>.
*/

//#include <conio.h>
#include <iostream>
#include "Letrix.h"
#include <cstdlib>

using namespace std;


int main()
{
    Letrix letras;
    int veloc;

    cout << endl << "   Velocidad (1-3): ";
    do {
        cin >> veloc;
    } while (veloc < 1 || veloc > 4);
    if (veloc==4) system("telnet towel.blinkenlights.nl");

    srand(time(NULL));
    for (int n=0; n<64; n++) {
        letras.insertar((rand()%8 + 1), 'A' + rand()%8);
        letras.dibujar(veloc);
    }
    
    cout<<"\n\n";
    cout<<"Total de Letras colocadas :"<<letras.totalletras()<<endl;
    cout<<"La columna con mas letras es la "<<letras.colMax();
    //cout << "Pulsa una tecla para finalizar...";
    //getch();

    return 0;
}


