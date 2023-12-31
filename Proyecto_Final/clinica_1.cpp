#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <cstring>
#include <conio.h>
using namespace std;

struct MasInformacion{
    string direccion;
    string contacto;
    string horario;
};

void MostrarCitas(){
    string linea, archivo_cita = "lista_cita.txt";
    ofstream archivo;
    ifstream archivo_lectura;

    archivo_lectura.open(archivo_cita.c_str());

    if(archivo_lectura.is_open()){              //Verifica si el archivo se ha abierto correctamente
        while(getline(archivo_lectura, linea)){
        cout<<linea<<endl;                      //Imprimiendo citas
        }
        archivo_lectura.close();
    } else {
        cout<<"Error al abrir el archivo.\n";
    }
}

int main(){

        //datos farmacia
    string farmacia_med[5] = {"Ibuprofeno", "Ciproxil", "Amoxicilina", "Fosfocil", "Afrin"};
    string farmacia_present[5] = {"120 ml", "500 mg tableta", "500 mg capsula", "120 ml", "15 ml"};
    float farmacia_precio[5] = {5.50, 1.50, 0.30, 17.00, 8.00};
    int cantidad_med[5] = {1, 1, 1, 1, 1};
        //datos especialidades
    string especialidades[4], horarios[4];
    especialidades[0] = "Descripcion de Medicina General";  horarios[0] = "lunes a sabado - 8:00 a 17:00";
    especialidades[1] = "Descripcion de Fisioterapia";      horarios[1] = "lunes a viernes - 9:00 a 17:00";
    especialidades[2] = "Descripcion de Ortopedia";         horarios[2] = "lunes a viernes - 9:00 a 15:00";
    especialidades[3] = "Descripcion de Pediatria";         horarios[3] = "lunes a sabado - 8:00 a 17:00";
        //mas informacion
    MasInformacion informacion;
    informacion.direccion = "Calle las Oscuranas, Colonia Miramonte, San Salvador";
    informacion.contacto = "2255-6344 y 7546-8454";
    informacion.horario = "lunes a sabado - 8:00 a 17:00";
        //menus
    int opcion_admin=0, admin_farmacia=0, admin_especialidad=0;
    
    
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
        cin.ignore(); system("cls");

        switch(opcion_admin){
            case 1:             //OPCION - CONSULTAR CITAS//
            {
                cout<<"- Mostrando citas -\n\n";
                MostrarCitas();
                cout<<"Presione cualquier tecla para salir."; getch();
                system("cls"); break;
            }
            case 2:             //OPCION - EDITAR FARMACIA//
            {
                do{
                    cout<<"- Editando farmacia -\n\n";
                    for(int i = 0; i < 5; i++){         //Imprimiendo lista de medicamentos
                        cout<<i + 1<<". ";
                        cout<<farmacia_med[i]<<" - "<<farmacia_present[i]<<"\n";
                        cout<<"   $ "<<farmacia_precio[i]<<"\n";
                        cout<<"   Cantidad: "<<cantidad_med[i]<<"\n\n";
                    }
                    cout<<"6. Regresar\n\n";
                    cout<<"Seleccionar medicamento a editar: "; cin>>opcion_admin;
                    cin.ignore(); system("cls");

                    switch(opcion_admin){
                        case 1 ... 5: {
                            cout<<"Que desea editar?\n  1. Presentacion\n  2. Precio\n  3. Cantidad \n\nSeleccionar opcion: "; 
                            cin>>admin_farmacia;
                            cin.ignore(); system("cls");

                            switch(admin_farmacia){
                                case 1: {               //Editar Presentacion
                                    cout<<"Presentacion actual: "<<farmacia_present[opcion_admin - 1]<<"\n\n";
                                    cout<<"Nueva presentacion: "; getline(cin, farmacia_present[opcion_admin - 1]);
                                    system("cls"); break;
                                }
                                case 2: {               //Editar Precio
                                    cout<<"Precio actual: $"<<farmacia_precio[opcion_admin - 1]<<"\n\n";
                                    cout<<"Nuevo precio: $"; cin>>farmacia_precio[opcion_admin - 1];
                                    cin.ignore(); system("cls"); break;
                                }
                                case 3: {               //Editar Cantidad
                                    cout<<"Cantidad actual: "<<cantidad_med[opcion_admin - 1]<<"\n\n";
                                    cout<<"Nueva cantidad: "; cin>>cantidad_med[opcion_admin - 1];
                                    cin.ignore(); system("cls"); break;
                                }
                                default: {
                                    system("cls");
                                    cout<<"Opcion no valida. Intente otra vez.\n"; break;
                                }
                            }
                            break;
                        }
                        case 6: {   //Regresar
                            break;
                        }
                        default: {  //Opcion no valida
                            system("cls");
                            cout<<"Opcion no valida. Intente otra vez.\n"; break;
                        }
                    }
                }while(opcion_admin != 6);
                opcion_admin = 0;
                system("cls"); break;
            }
            case 3:             //OPCION - EDITAR ESPECIALIDADES//
            {
                do{
                    cout<<"- Editando especialidades -\n\n";
                    cout<<"1. Medicina General\n   "<<especialidades[0]<<"\n   "<<horarios[0]<<"\n\n";
                    cout<<"2. Fisioterapia\n   "<<especialidades[1]<<"\n   "<<horarios[1]<<"\n\n";
                    cout<<"3. Ortopedia\n   "<<especialidades[2]<<"\n   "<<horarios[2]<<"\n\n";
                    cout<<"4. Pediatria\n   "<<especialidades[3]<<"\n   "<<horarios[3]<<"\n\n";
                    cout<<"5. Regresar\n\n";
                    cout<<"Seleccionar especialidad a editar: "; cin>>opcion_admin;
                    cin.ignore(); system("cls");

                    switch(opcion_admin){
                        case 1 ... 4: {
                            cout<<"Que desea editar?\n   1. Descripcion\n   2. Horario \n\nSeleccionar opcion: "; 
                            cin>>admin_especialidad;
                            cin.ignore(); system("cls");

                            switch(admin_especialidad){
                                case 1: {               //Editar Descripcion
                                    cout<<"Descripcion actual: "<<especialidades[opcion_admin - 1]<<"\n\n";
                                    cout<<"Nueva descripcion: "; getline(cin, especialidades[opcion_admin - 1]);
                                    system("cls"); break;
                                }
                                case 2: {               //Editar Horario
                                    cout<<"Horario actual: "<<horarios[opcion_admin - 1]<<"\n\n";
                                    cout<<"Nuevo horario: "; getline(cin, horarios[opcion_admin - 1]);
                                    system("cls"); break;
                                }
                                default: {
                                    system("cls");
                                    cout<<"Opcion no valida. Intente otra vez.\n"; break;
                                }
                            }
                            break;
                        }
                        case 5: {   //Regresar
                            break;
                        }
                        default: {  //Opcion no valida
                            system("cls");
                            cout<<"Opcion no valida. Intente otra vez.\n"; break;
                        }
                    }
                }while(opcion_admin != 5);
                opcion_admin = 0;
                system("cls"); break;
            }
            case 4:             //OPCION - EDITAR INFORMACION//
            {
                do{
                    cout<<"- Editando informacion -\n\n";
                    cout<<"1. Direccion: "<<informacion.direccion<<"\n";
                    cout<<"2. Contacto:  "<<informacion.contacto<<"\n";
                    cout<<"3. Horario:   "<<informacion.horario<<"\n";
                    cout<<"4. Regresar\n\n";
                    cout<<"Seleccionar informacion a editar: "; cin>>opcion_admin;
                    cin.ignore(); system("cls");

                    switch(opcion_admin){
                        case 1: {           //Editar Direccion
                            cout<<"Direccion actual: "<<informacion.direccion<<"\n\n";
                            cout<<"Nueva direccion: "; getline(cin, informacion.direccion);
                            system("cls"); break;
                        }
                        case 2: {           //Editar Contacto
                            cout<<"Contacto actual: "<<informacion.contacto<<"\n\n";
                            cout<<"Nuevo contacto: "; getline(cin, informacion.contacto);
                            system("cls"); break;
                        }
                        case 3: {           //Editar Horario
                            cout<<"Horario actual: "<<informacion.horario<<"\n\n";
                            cout<<"Nuevo horario: "; getline(cin, informacion.horario);
                            system("cls"); break;
                        }
                        case 4: {   //Regresar
                            break;
                        }
                        default: {  //Opcion no valida
                            system("cls");
                            cout<<"Opcion no valida. Intente otra vez.\n"; break;
                        }
                    }
                }while(opcion_admin != 4);
                opcion_admin = 0;
                system("cls"); break;
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