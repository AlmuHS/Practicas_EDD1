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
