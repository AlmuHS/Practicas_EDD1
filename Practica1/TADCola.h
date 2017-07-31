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
