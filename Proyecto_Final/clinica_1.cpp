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
        //datos especialidades
    string med_gen, pedi, ortoped, fisio, med_gen_horario, pedi_horario, ortoped_horario, fisio_horario;
        //menus
    int opcion_admin=0, admin_farmacia=0, admin_especialidad=0;
    int admin_esp_editar=0;
    
    med_gen = "Descripcion de medicina general"; pedi = "Descripcion de pediatria"; ortoped = "Descripcion de ortopedia"; fisio = "Descripcion de fisioterapia";
    med_gen_horario = "lunes a sabado - 8:00 a 17:00"; pedi_horario = "lunes a viernes - 9:00 a 17:00";
    ortoped_horario = "lunes a viernes - 9:00 a 15:00"; fisio_horario = "lunes a sabado - 8:00 a 17:00";

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
        system("cls");

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
                system("cls");
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
                do{
                    cout<<"- Editando especialidades -\n\n";
                    cout<<"1. Medicina General\n   "<<med_gen<<"\n   "<<med_gen_horario<<"\n\n";
                    cout<<"2. Fisioterapia\n   "<<fisio<<"\n   "<<fisio_horario<<"\n\n";
                    cout<<"3. Ortopedia\n   "<<ortoped<<"\n   "<<ortoped_horario<<"\n\n";
                    cout<<"4. Pediatria\n   "<<pedi<<"\n   "<<pedi_horario<<"\n\n";
                    cout<<"5. Regresar\n\n";
                    cout<<"Seleccionar especialidad a editar: "; cin>>admin_especialidad;
                    switch(admin_especialidad){
                        case 1 ... 4:
                        {
                            cout<<"Que desea editar?\n   1. Descripcion\n   2. Horario \n\nSeleccionar opcion: "; cin>>admin_esp_editar;
                        }
                        case 5:
                        {
                            break;
                        }
                        default:
                        {
                            cout<<"Opcion no valida. Intente otra vez.\n"; break;
                        }
                    }
                }while(admin_especialidad != 5);
                system("cls");
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
                cout<<"Opcion no valida. Intente otra vez.\n"; break;
            }
        }

    }while(opcion_admin != 6);
      
    return 0;
}