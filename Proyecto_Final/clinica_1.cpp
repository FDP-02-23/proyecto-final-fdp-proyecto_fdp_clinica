#include <iostream>
#include <string>
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

struct MasInformacion{
    string direccion;
    string contacto;
    string horario;
};

int main(){

        //archivo para citas
    string linea;
    string archivo_cita = "lista_cita.txt";
    ofstream archivo; ifstream archivo_lectura;
    DatosCita cita;
        //datos farmacia
    string farmacia_med[5] = {"Ibuprofeno", "Ciproxil", "Amoxicilina", "Fosfocil", "Afrin"};
    string farmacia_present[5] = {"120 ml", "500 mg tableta", "500 mg capsula", "120 ml", "15 ml"};
    float farmacia_precio[5] = {5.50, 1.50, 0.30, 17.00, 8.00};
    int cantidad_med[5] = {1};
        //datos especialidades
    string especialidades[4], horarios[4];
    especialidades[0] = "Descripcion de Medicina General"; horarios[0] = "lunes a sabado - 8:00 a 17:00";
    especialidades[1] = "Descripcion de Pediatria"; horarios[1] = "lunes a viernes - 9:00 a 17:00";
    especialidades[2] = "Descripcion de Ortopedia"; horarios[2] = "lunes a viernes - 9:00 a 15:00";
    especialidades[3] = "Descripcion de Fisioterapia"; horarios[3] = "lunes a sabado - 8:00 a 17:00";
    string med_gen, pedi, ortoped, fisio, med_gen_horario, pedi_horario, ortoped_horario, fisio_horario;
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
                    cout<<"Seleccionar especialidad a editar: "; cin>>opcion_admin;
                    cin.ignore(); system("cls");

                    switch(opcion_admin){
                        case 1 ... 4:
                        {
                            cout<<"Que desea editar?\n   1. Descripcion\n   2. Horario \n\nSeleccionar opcion: "; cin>>admin_especialidad;
                            cin.ignore(); system("cls");

                            if(admin_especialidad == 1){            //Editar Descripcion
                                
                                cout<<"Descripcion actual: ";
                                switch(opcion_admin){
                                    case 1: {    //Medicina General
                                        cout<<med_gen<<"\n\nNueva descripcion: "; getline(cin, med_gen);
                                        system("cls"); break;
                                    }
                                    case 2: {    //Fisioterapia
                                        cout<<fisio<<"\n\nNueva descripcion: "; getline(cin, fisio);
                                        system("cls"); break;
                                    }
                                    case 3: {    //Ortopedia
                                        cout<<ortoped<<"\n\nNueva descripcion: "; getline(cin, ortoped); 
                                        system("cls"); break;
                                    }
                                    case 4: {    //Pediatria
                                        cout<<pedi<<"\n\nNueva descripcion: "; getline(cin, pedi); 
                                        system("cls"); break;
                                    }
                                    default: {
                                        system("cls");
                                        cout<<"Opcion no valida. Intente otra vez.\n"; break;
                                    }
                                }
                            } else if(admin_especialidad == 2){     //Editar Horario
                                
                                cout<<"Horario actual: ";
                                switch(opcion_admin){
                                    case 1: {    //Medicina General
                                        cout<<med_gen_horario<<"\n\nNuevo horario: "; getline(cin, med_gen_horario);
                                        system("cls"); break;
                                    }
                                    case 2: {    //Fisioterapia
                                        cout<<fisio_horario<<"\n\nNuevo horario: "; getline(cin, fisio_horario);
                                        system("cls"); break;
                                    }
                                    case 3: {    //Ortopedia
                                        cout<<ortoped_horario<<"\n\nNuevo horario: "; getline(cin, ortoped_horario); 
                                        system("cls"); break;
                                    }
                                    case 4: {    //Pediatria
                                        cout<<pedi_horario<<"\n\nNuevo horario: "; getline(cin, pedi_horario); 
                                        system("cls"); break;
                                    }
                                    default: {
                                        system("cls");
                                        cout<<"Opcion no valida. Intente otra vez.\n"; break;
                                    }
                                }
                            } else {
                                system("cls");
                                cout<<"Opcion no valida. Intente otra vez.\n"; break;
                            }
                            break;
                        }
                        case 5:
                        {
                            break;
                        }
                        default:
                        {
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
                        case 1: {
                            cout<<"Direccion actual: "<<informacion.direccion<<"\n\n";
                            cout<<"Nueva direccion: "; getline(cin, informacion.direccion);
                            system("cls"); break;
                        }
                        case 2: {
                            cout<<"Contacto actual: "<<informacion.contacto<<"\n\n";
                            cout<<"Nuevo contacto: "; getline(cin, informacion.contacto);
                            system("cls"); break;
                        }
                        case 3: {
                            cout<<"Horario actual: "<<informacion.horario<<"\n\n";
                            cout<<"Nuevo horario: "; getline(cin, informacion.horario);
                            system("cls"); break;
                        }
                        case 4: {
                            break;
                        }
                        default: {
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