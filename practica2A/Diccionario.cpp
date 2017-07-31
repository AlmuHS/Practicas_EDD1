#include "Diccionario.h"

bool diccionario::abrirdiccionario(cadena2 ruta){
    bool correcto;
    f=fopen(ruta, "r+b");
    if (f==NULL) correcto=false;
    else correcto=true;
return correcto;
}


void diccionario::insertarEntrada(lista& lis, termino t){
    entrada entry;
    int pos=0;
    int izq=pos-1;
    termino observar;
    termino palanterior;
    char copiapalanterior[30];
    char copia_cola[30];
    char copia[30];
        palanterior=lis.observar(pos).colaTerminos.primero();
        strncpy(copiapalanterior, palanterior.c_str(), 1);
        strncpy(copia, t.c_str(),1);
        if(strcmp(copiapalanterior, copia)==0){
        /*si el termino empieza por la misma letra que el ultimo termino insertado,
        se inserta en la misma cola*/
            entry.colaTerminos.encolar(t);
            lis.insertar(pos, entry);
        }
        else{
            pos++;
            entrada ent;
            ent.colaTerminos.encolar(t);
              lis.insertar(pos, ent);
        } //En caso contrario, se crea una nueva cola y se inserta el termino
}

void diccionario::leerentradas(){
    int pos=1;
    treg palabra;
    termino t;
    while(feof(f)!=0){
        fseek(f, pos*sizeof(palabra), SEEK_END);
        fread(&palabra, sizeof(palabra), 1, f);
        t=palabra.palabra.termino;
        insertarEntrada(lis, t);
        pos++;
    }
}

void diccionario::imprimirlista(){
    termino palabra;
    char inicialpalabra[30];
    int longitud=lis.longitud();
    for(int i=0; i<=longitud; i++){
        palabra=lis.observar(i).colaTerminos.primero();
        strncpy(inicialpalabra, palabra.c_str(), 1);
        cout<<"\n"<<inicialpalabra<<": ";
        while(lis.observar(i).colaTerminos.esvacia()==false){
            cout<<palabra<<"\t";
            lis.observar(i).colaTerminos.desencolar();
            palabra=lis.observar(i).colaTerminos.primero();
        }
    }
}

//void diccionario

