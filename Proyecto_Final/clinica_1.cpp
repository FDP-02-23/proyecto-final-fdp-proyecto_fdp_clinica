#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <conio.h>
using namespace std;

struct DatosCita{
    string nombre;
    int especialidad;
    int edad;
    int telefono;
    int mes;
    int dia;
    float hora;
};

int main(){

    //archivo para citas
    string linea;
    string archivo_cita = "lista_cita.txt";
    ofstream archivo;
    ifstream archivo_lectura;

    //estructura para citas
    DatosCita cita;
    
    int opcion_admin=0, admin_farmacia=0;
    
    // MENU DE ADMINISTRADOR //
    do{
        cout<<"Menu de Administrador\n\n";
        cout<<"1. Consultar citas\n";
        cout<<"2. Editar farmacia\n";
        cout<<"3. Editar especialidades\n";
        cout<<"4. Editar informacion\n";
        cout<<"5. Regresar al menu principal\n";
        cout<<"6. Salir\n\n";
        cout<<"Seleccionar opcion: "; cin>>opcion_admin;

        switch(opcion_admin){
            case 1:             //OPCION - CONSULTAR CITAS//
            {
                cout<<"- Mostrando citas -\n\n";
                archivo_lectura.open(archivo_cita.c_str());

                if(archivo_lectura.is_open()){  //Verifica si el archivo se ha abierto correctamente
                    while(getline(archivo_lectura, linea)){
                    cout<<linea<<endl;
                    }
                    archivo_lectura.close();
                } else {
                    cout<<"Error al abrir el archivo.\n";
                }
                cout<<"Presione cualquier tecla para salir."; getch();
                cout<<"\n";
                break;
            }
            case 2:             //OPCION - EDITAR FARMACIA//
            {
                cout<<"- Editando farmacia -\n";
                //imprimir lista de medicamentos...
                cout<<"Seleccionar medicamento a editar: "; 

                break;
            }
            case 3:             //OPCION - EDITAR ESPECIALIDADES//
            {
                cout<<"- Editando especialidades -\n";
                //imprimir lista de especialidades...
                cout<<"Seleccionar especialidad a editar: ";

                break;
            }
            case 4:             //OPCION - EDITAR INFORMACION//
            {
                cout<<"- Editando informacion -\n";
                //imprimir informacion...
                cout<<"Seleccionar informacion a editar: ";

                break;
            }
            case 5:             //REGRESAR AL MENU PRINCIPAL//
            {
                //codigo para volver al menu principal...

                break;
            }
            case 6:             //SALIR//
            {
                cout<<"Saliendo."; break;
            }
            default:
            {
                cout<<"La opcion ingresada no es valida. Intente otra vez.\n"; break;
            }
        }

    }while((opcion_admin != 5) || (opcion_admin != 6)); //no volver a mostrar el menu si la opcion es 5 o 6
      
    return 0;
}