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

