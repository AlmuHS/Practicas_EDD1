#include "Clinica.h"
#include "TADCola.h"

using namespace std;


int azar(int n)
{
    return (rand()%n + 1);
}

bool pacienteOperado()
{
    return (azar(TIEMPO) == 1);
}

// métodos de la clase Clínica
Clinica::Clinica(char nombreFichero[])
{
    fichero=fopen(nombreFichero, "rb+");

    if (fichero!=NULL) fread(&numPacientes, sizeof(numPacientes), 1, fichero);

    else
    {
        fichero=fopen(nombreFichero, "wb+");
        numPacientes=0;
        fwrite(&numPacientes, sizeof(int), 1, fichero);
    }
}

void Clinica::posicionar(int p)
{
    fseek(fichero, sizeof(int)+(p-1)*sizeof(Paciente), SEEK_SET);
}

void Clinica::consultar(char inicial)
{
    Paciente p;
    char in;
    int num=0;
    posicionar(1);

    for(int pos=0; pos<numPacientes; pos++)
    {
        fread(&p, sizeof(Paciente), 1, fichero);
        in=p.apellidos[0];
        if(in==inicial){
            num++;
            cout<<"\nNombre: "<<p.nombre
                <<"\nApellidos: "<<p.apellidos
                <<"\nEdad: "<<p.edad
                <<"\nID: "<<p.id<<endl;
        }//fin if

    }//fin for
    if(num==0) cout<<"No existen pacientes con dicha inicial\n";
}

void Clinica::insertar(Paciente p)
{
    posicionar(numPacientes+1);
    fwrite(&p, sizeof(p), 1, fichero);
    numPacientes++;
    fseek(fichero, 0, SEEK_SET);//se posiciona al principio del fichero
    fwrite(&numPacientes, sizeof(numPacientes), 1, fichero);
}

void Clinica::modificar(int id)
{
    int pos=1;
    Paciente p;

    posicionar(1);
    bool encontrar=false;
    while(encontrar==false && pos<=numPacientes)//busca el registro del paciente y su posicion
    {
        fread(&p, sizeof(p), 1, fichero);
        if(p.id==id) encontrar=true;
        else pos++;
    }

    if(!encontrar) cout<<"El ID introducido no corresponde a ningun paciente\n";
    else
    {
        cout<<"Introduce los datos del paciente: \n"
            <<"\nNombre: ";
        cin>>p.nombre;
        cout<<"\nApellidos: ";
        cin>>p.apellidos;
        cout<<"\nEdad: ";
        cin>>p.edad;
    }
    posicionar(pos);//se posiciona al inicio del registro a modificar
    fwrite(&p, sizeof(p), 1, fichero);
}

void Clinica::eliminar(int id)
{
    int pos=1;
    Paciente p;
    Paciente aux;

    posicionar(1);
    bool encontrar=false;
    while(encontrar==false && pos<=numPacientes)//busca el registro del paciente y su posicion
    {
        fread(&p, sizeof(p), 1, fichero);
        if(p.id==id) encontrar=true;
        else pos++;
    }

    if(!encontrar) cout<<"El ID introducido no corresponde a ningun paciente\n";
    else
    {
        for(int i=pos; i<numPacientes; i++)
        {
            posicionar(i+1);//se posiciona en la posicion siguiente al elemento encontrado
            fread(&aux, sizeof(aux), 1, fichero);//copia su contenido en un registro auxiliar
            posicionar(i);//se posiciona en la posicion del elemento encontrado
            fwrite(&aux, sizeof(aux), 1, fichero);//escribe el contenido del registro auxiliar en dicha posicion}
        }
    }
    numPacientes--;
    fseek(fichero, 0, SEEK_SET);
    fwrite(&numPacientes, sizeof(numPacientes), 1, fichero);
}

Clinica::~Clinica()
{
    fclose(fichero);
}

void Clinica::simularOperaciones()
{
    cola quirofano[3];
    int num_quirofano=0;
    posicionar(1);
    Paciente p;

    for(int i=1; i<=numPacientes; i++){//asigna los ID de los pacientes a colas elegidas al azar
        fread(&p, sizeof(p), 1, fichero);
        num_quirofano=azar(3)-1;
        quirofano[num_quirofano].encolar(p.id);
    }


    while(quirofano[0].longitud()>=0 || quirofano[1].longitud()>=0 || quirofano[2].longitud()>=0){
        system("clear");
        int longitud=quirofano[0].longitud()+quirofano[1].longitud()+quirofano[2].longitud();
        cout<<"Pacientes en espera: "<<longitud;
        for(int i=0; i<3; i++){
            int longitud=quirofano[i].longitud();
            cout<<"\nQUIROFANO "<<i+1<<": ";
            for(int j=0; j<longitud; j++){//muestra los pacientes
                int primero=quirofano[i].primero();
                cout<<primero<<"\t";
                quirofano[i].desencolar();
                quirofano[i].encolar(primero);
            }//fin for j
        }//fin for i
        cout<<endl;
        num_quirofano=azar(3)-1;//elige un quirofano al azar
        while(quirofano[num_quirofano].esvacia()==true) num_quirofano=azar(3)-1;//si ese quirofano esta vacio pide otro
        bool operado=pacienteOperado();
        if(operado==true) quirofano[num_quirofano].desencolar();
    }//fin while
}

void Clinica::pacientesMayores(char nombreFichero[]){
     FILE *f_mayores=fopen(nombreFichero, "wb+");
     Paciente p;
     int mayor=0;
     int pos=0;
     posicionar(1);
     for(int i=0; i<numPacientes; i++){//busca la mayor edad
           fread(&p, sizeof(p), 1, fichero);
           if(mayor<p.edad) mayor=p.edad;
     }//fin for i

     posicionar(1);
     for(int j=0; j<numPacientes; j++){//busca a pacientes con esa edad
             fread(&p, sizeof(p), 1, fichero);
             if(p.edad==mayor){
                               fseek(f_mayores, pos*sizeof(p.id), SEEK_SET);
                               fwrite(&p.id, sizeof(p.id), 1, f_mayores);
                               pos++;
             }//fin if
     }//fin for j
     //int num;
     //fseek(f_mayores, 0, SEEK_SET);
     //fread(&num, sizeof(num), 1, f_mayores);
     //cout<<num;
     fclose(f_mayores);
}

