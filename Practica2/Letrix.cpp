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

#include <stdio.h>
#include <iostream>
#include "Letrix.h"

using namespace std;

#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
  #include <windows.h>

  inline void espera(unsigned long ms) {
    Sleep(ms);
  }

  void limpiarPantalla() {
    system("cls");
  }

#else//muchas gracias por hacer una practica multisistema
  #include <unistd.h>

  inline void espera(unsigned long ms) {
    usleep(ms*1000);
  }

  void limpiarPantalla() {
    for (int v=0; v<50; v++)
        cout << endl;
  }
#endif

Letrix::Letrix(){
    numletras=0;
    inicio=new NodoBase;

    if(inicio != NULL){

        inicio->sig=NULL;
        inicio->col=NULL;

    }
    NodoBase *aux;
    for(int i=0; i<7; i++){
        aux = new NodoBase;
        aux->col=NULL;
        aux->sig=inicio;
        inicio=aux;
    }

}

void Letrix::dibujar(int vel) {
    velocidad=vel;
    limpiarPantalla();
    for (int v=0; v<12; v++)
        cout << endl;
    for (int f=1; f<=9; f++) {
        cout << "                     ";
        for (int c=1; c<=8; c++)
            cout << "  " << letra(f,c);
        cout << endl;
    }
    cout << "                      ------------------------" << endl << endl << endl;
    espera(500*vel);
}

char Letrix::letra(int f, int c){
    NodoBase *aux=inicio;
    NodoLetra *tmp=NULL;
    char letra;


    for(int i=1; i<c; i++)//busca la columna indicada por parametro
        aux=aux->sig;

    if(aux!=NULL){

        tmp=aux->col;
        int i=9;

        while(tmp !=NULL && i>f){
            tmp=tmp->sig;
            i--;
        }
    }

    if(tmp!=NULL) letra=tmp->letra;
    else letra= ' ';

    return letra;
}

void Letrix::insertar(int col, char let){
    NodoLetra *nuevo=new NodoLetra;
    nuevo->letra=let;
    nuevo->sig=NULL;
    NodoBase *aux=inicio;
    for(int i=1; i<col; i++){//Busca la columna dada
        aux=aux->sig;
    }
    if (aux->col==NULL){
        aux->col=nuevo;
        char let_fila;
        for(int i=1; i<=8; i++){//comprueba repeticiones en la fila 9
            let_fila=letra(9, i);
            if(let_fila==let && i!=col) aux->col=NULL;
        }
        if (aux->col!=NULL) numletras++;
    }
    else{
        int fila=8;
        NodoLetra *tmp2=aux->col;
        while(tmp2->sig != NULL){
            tmp2=tmp2->sig;//busca el primer elemento libre de la columna
            fila--;
        }
        tmp2->sig=nuevo;//inserta el elemento en el primer sitio vacio de la columna

        bool rep_encontrado=false;

        NodoLetra *buscar=aux->col;
        while(!rep_encontrado && buscar!=tmp2->sig){//busca repeticiones en la columna
            if(buscar->letra==let) rep_encontrado=true;
            else buscar=buscar->sig;
        }//fin while

        int i=1;
        while(!rep_encontrado && i<9){//busca repeticiones en la fila
            char let_fila=letra(fila, i);
            if(let_fila==let && i!=col) rep_encontrado=true;
            i++;
        }//fin while

        if(rep_encontrado){
            dibujar(velocidad);
            tmp2->sig=NULL;
        }
        else numletras++;
    }//fin else
}

int Letrix::totalletras(){
    return numletras;
}

int Letrix::colMax(){
    int num_letra=0, maxim=0, num_colum=1, max_colum=0;
    char let;

    /*for(int j=8; j>=1; j--){
        let=letra(j, 9);
        while (i>=1 && let!=' '){
            let=letra(j, i);
            num_letra++;
            i--;
        }//fin while

        if(let==' '){
            if(num_letra > maxim){
                maxim=num_letra;
                max_colum=i;
            }
            //cout<<max_colum<<"\t";
        }//fin if
    }//fin for*/

    NodoBase *columna=inicio;
    NodoLetra *fila;

    for(int i=1; i<=8; i++){
        if (columna!=NULL) fila=columna->col;
        num_letra=0;
        if(fila !=NULL){
            while(fila != NULL){
                num_letra++;
                fila=fila->sig;
            }
        }
        if(num_letra > maxim){
            maxim=num_letra;
            max_colum=num_colum;
        }

        num_colum++;
        columna=columna->sig;
    }
    return max_colum;
}

Letrix::~Letrix(){
    NodoBase *aux=inicio;

    while(aux->sig !=NULL){
        inicio=aux->sig;
        delete aux;
        aux=inicio;
    }
    delete inicio;
}
