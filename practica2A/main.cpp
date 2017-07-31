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
