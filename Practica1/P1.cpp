#include "Clinica.h"
#include <iostream>
#include <cstring>


using namespace std;


int main() {
    // inicialización de números aleatorios
    srand(time(NULL));

    // completar
    cadena nom_fichero="clinica";
    Clinica clinica(nom_fichero);
    char seguir;
    int opcion=0;

    do{
        int num_pacientes=clinica.getNumPacientes();
        system("clear");
        cout<<"\nClinica 'Los milagros'"
            <<"\n---------------------\n"
            <<"\nPacientes: "<<num_pacientes
            <<"\n\n1. Consultar pacientes"
            <<"\n2. Introducir un nuevo paciente"
            <<"\n3. Modificar un paciente"
            <<"\n4. Eliminar un paciente"
            <<"\n5. Simular operaciones"
            <<"\n6. Crear fichero personas mayores"
            <<"\n7. Salir\n"
            <<"\nElige una opcion: ";
        cin>>opcion;

        switch(opcion){

            case 1:
                //consultar pacientes
                char inicial;
                cout<<"Introduzca la inicial a consultar: ";
                cin>>inicial;
                clinica.consultar(inicial);
            break;

            case 2:
                //introducir nuevo paciente
                Paciente nuevo;
                cout<<"Introduzca los datos del nuevo paciente\n";
                cout<<"Nombre del paciente: ";
                cin>>nuevo.nombre;
                cout<<"Apellidos: ";
                cin>>nuevo.apellidos;
                cout<<"Edad: ";
                cin>>nuevo.edad;
                cout<<"ID: ";
                cin>>nuevo.id;
                clinica.insertar(nuevo);
            break;

            case 3:
                int id;
                cout<<"Introduzca el id del paciente: ";
                cin>>id;
                clinica.modificar(id);
                //modificar paciente
            break;

            case 4:
                //eliminar paciente
                cout<<"Introduce el ID del paciente a eliminar: ";
                cin>>id;
                clinica.eliminar(id);
            break;

            case 5:
                //simular operaciones
                clinica.simularOperaciones();
            break;

            case 6:
                 clinica.pacientesMayores("mayores.dat");
            break;

        }

        if(opcion!=7){
            cout<<"\nDesea realizar otra operacion? (s/n): ";
            cin>>seguir;
        }

    }while((seguir=='s'||seguir=='S') && opcion!=7);
    return 0;
}
