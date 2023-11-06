#include <iostream>
using namespace std;

int main(){
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
                cout<<"Mostrando citas recientes:\n";
                //codigo para mostrar citas...

                break;
            }
            case 2:             //OPCION - EDITAR FARMACIA//
            {
                cout<<"Editando farmacia:\n";
                //imprimir lista de medicamentos...
                cout<<"Seleccionar medicamento a editar: "; 

                break;
            }
            case 3:             //OPCION - EDITAR ESPECIALIDADES//
            {
                cout<<"Editando especialidades:\n";
                //imprimir lista de especialidades...
                cout<<"Seleccionar especialidad a editar: ";

                break;
            }
            case 4:             //OPCION - EDITAR INFORMACION//
            {
                cout<<"Editando informacion:\n";
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
                cout<<"El numero ingresado no es valido. Intente otra vez.\n"; break;
            }
        }

    }while((opcion_admin != 5) || (opcion_admin != 6)); //no volver a mostrar el menu si la opcion es 5 o 6
      
    return 0;
}