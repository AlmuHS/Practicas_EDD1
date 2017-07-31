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

#include "TADCola.h"

cola::cola() {
    inicio=0;
    fin=-1;
}

void cola::encolar(int e) {
    if (fin+1 < MAX) {
        fin++;
        elementos[fin]=e;
    }
}

void cola::desencolar() {
    for(int i=inicio;i<fin;i++)
        elementos[i]=elementos[i+1]; //Desplazamiento 
    fin--;
}

int cola::primero() {
    return(elementos[inicio]);
}

bool cola::esvacia () {
    return (fin == -1);
}

int cola::longitud() { 
    return fin+1;
}
