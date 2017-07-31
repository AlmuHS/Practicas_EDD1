#include "TADLista.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

lista::lista() {
    n=0;
}

lista::lista(entrada e) {
    n=1;
    elementos[0]=e;
}

void lista::insertar(int i, entrada e) {
    int pos,postabla;
    postabla=i-1;
    if (n < MAX) {
        for (pos=n-1; pos>=postabla; pos--)
            elementos[pos+1]=elementos[pos]; //Desplazamiento
        elementos[postabla]=e;
        n++;
    }
}

void lista::eliminar(int i) {
    int postabla;
    postabla=i-1;
    while (postabla < n-1) {
        elementos[postabla] = elementos[postabla+1]; //Desplazamiento
        postabla++;
    }
    n--;
}

void lista::modificar(int i, entrada e) {
    elementos[i-1]=e;
}

entrada lista::observar(int i) {
    return(elementos[i-1]);
}

bool lista::esvacia() {
    return (n == 0);
}

/*int lista::posicion(int e) {
    int i=0;
    while ( (elementos[i] != e) && (i < n) )
    	i++;
    if (i < n)
    	return(i+1);
    else
        return(-1);
}*/

int lista::longitud () {
    return n;
}

void lista::anadirIzq(entrada e) {
    insertar(1,e);
}

void lista::anadirDch(entrada e) {
    insertar(n+1,e);
}

void lista::eliminarIzq() {
  	eliminar(1);
}

void lista::eliminarDch() {
    n--;
}

entrada lista::observarIzq() {
    return(observar(1));
}

entrada lista::observarDch() {
    return(observar(n));
}

void lista::concatenar(lista l) {
    int lon=l.longitud();
    for (int i=1;i<=lon;i++)
        insertar(n+1,l.observar(i));
}

/*bool lista::pertenece(int e) {
    return (posicion(e) != -1);
}*/
