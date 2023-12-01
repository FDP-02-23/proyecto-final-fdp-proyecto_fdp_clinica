#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <cstring>
#include <conio.h>
using namespace std;

// Declaracion de las variables principales
int opcion, usuario, opcion_especialidad;
string med_gen, pedi, ortoped, fisio;
string num_celular = "7546-8554", num_fijo = "2255-6344";

// Estructura para capturar los datos de las citas
struct DatosCita
{
    string nombre;
    int especialidad;
    int edad;
    int telefono;
    int mes;
    int dia;
    float hora;
};

struct MasInformacion
{
    string direccion;
    string contacto;
    string horario;
};

// Funcion para desplegar el menu de las especialidades que posee la clinica
void menu_espec()
{
    cout << "     -----Las especialidades con las que dispone nuestra clinica son-----        " << endl
         << "1.Medicina General" << endl
         << "2.Fisioterapia" << endl
         << "3.Ortopeda" << endl
         << "4.Pedriatria" << endl
         << "5.Regresar" << endl
         <<"Seleccionar opcion: ";
}

void menu_usuario()
{
    cout << "Que desea realizar?" << endl
         << endl
         << "1. Hacer una cita" << endl
         << "2. Conocer las especialidades" << endl
         << "3. Visitar farmacia" << endl
         << "4. Mas informacion" << endl
         << "5. Regresar al menu principal" << endl
         << "6. Salir" << endl
         <<"Seleccionar opcion: ";
}

void inf_clinica()
{
    cout << "Direccion: Calle las Oscuranas, Colonia miramonte, San Salvador." << endl;
    cout << "Numeros de contacto: " << num_celular
         << ", " << num_fijo << endl;
    cout << "Horarios de atencion: lunes a sabado - 8:00 a 17:00" << endl;
}

void MostrarCitas()
{
    string linea, archivo_cita = "lista_cita.txt";
    ofstream archivo;
    ifstream archivo_lectura;

    archivo_lectura.open(archivo_cita.c_str());

    if (archivo_lectura.is_open())
    { // Verifica si el archivo se ha abierto correctamente
        while (getline(archivo_lectura, linea))
        {
            cout << linea << endl; // Imprimiendo citas
        }
        archivo_lectura.close();
    }
    else
    {
        cout << "Error al abrir el archivo.\n";
    }
}

int main()
{
    // Agregando un arreglo para guardar las descripciones de las especialidades que forman parte de la clinica

    string especialidades[4];

    especialidades[0] = "Es el nivel de atencion medica principal, la cual es importante para la deteccion, tratamiento y prevención de las enfermedades cronicas.";
    especialidades[1] = "incluye la Patologia Medicoquirurgica y de especialidades que presentan pacientes en las diferentes edades pediatricas desde el nacimiento hasta el termino del crecimiento y desarrollo que, en promedio, se alcanza entre los 18 y 20 anios de edad.";
    especialidades[2] = "Se especializan en el cuidado de trastornos de los huesos, musculos, tendones y ligamentos.";
    especialidades[3] = "Es una especialidad medica que tiene por objeto la valoracion, diagnostico, prevencion y tratamiento de las discapacidades derivadas de enfermedades y accidentes, utilizando para ellos todos los metodos a su alcance (fisicos, medicamentosos, educacionales.)";

    // archivo para citas
    string linea;
    string archivo_cita = "lista_cita.txt";
    string archivo_farmacia = "Farmacia.txt";
    ofstream archivo;
    ifstream archivo_lectura;

    // estructura para citas
    DatosCita cita;

    // datos farmacia
    string farmacia_med[5] = {"Ibuprofeno", "Ciproxil", "Amoxicilina", "Fosfocil", "Afrin"};
    string farmacia_present[5] = {"120 ml", "500 mg tableta", "500 mg capsula", "120 ml", "15 ml"};
    float farmacia_precio[5] = {5.50, 1.50, 0.30, 17.00, 8.00};
    int cantidad_med[5] = {1, 1, 1, 1, 1};

    // datos especialidades
    string horarios[4];
    horarios[0] = "lunes a sabado - 8:00 a 17:00";
    horarios[1] = "lunes a viernes - 9:00 a 17:00";
    horarios[2] = "lunes a viernes - 9:00 a 15:00";
    horarios[3] = "lunes a sabado - 8:00 a 17:00";
    // mas informacion
    MasInformacion informacion;
    informacion.direccion = "Calle las Oscuranas, Colonia Miramonte, San Salvador";
    informacion.contacto = "2255-6344 y 7546-8454";
    informacion.horario = "lunes a sabado - 8:00 a 17:00";
    // menus
    int opcion_admin = 0, admin_farmacia = 0, admin_especialidad = 0;
    do
    {
        cout << "     -----Bienvenido al sistema de la clinica en linea-----      " << endl
             << "Como desea ingresar al sistema de la clinica" << endl
             << endl
             << "1. Usuario" << endl
             << "2. Administrador" << endl
             << "3. Salir" << endl
             <<"Seleccionar opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:

            do
            {
                menu_usuario();
                cin >> usuario;

                switch (usuario)
                {
                case 1:
                    cout << "- Realizando cita -\n\n";
                    // Nombre
                    cout << "Ingresar nombre del paciente: ";
                    cin.ignore();
                    getline(cin, cita.nombre);
                    // Especialidad
                    // if para verificar que la opcion de la especialidad que elija sea valida.
                    do
                    {
                        cout << "Ingresar especialidad de la cita:\n";
                        cout << "1) Medicina General  2) Fisioterapia  3) Ortopeda  4) Pediatria\nSeleccionar opcion: ";
                        cin >> cita.especialidad;
                        if (cita.especialidad == 1)
                        {
                            break;
                        }
                        else if (cita.especialidad == 2)
                        {
                            break;
                        }
                        else if (cita.especialidad == 3)
                        {
                            break;
                        }
                        else if (cita.especialidad == 4)
                        {
                            break;
                        }
                        else
                        {
                            cout << "La opcion ingresada no es valida\n"
                                 << "\n";
                        }

                    } while (cita.especialidad != 1 || cita.especialidad != 2 || cita.especialidad != 3 || cita.especialidad != 4);

                    // Edad
                    cout << "Ingresar edad del paciente: ";
                    cin >> cita.edad;
                    // Telefono
                    cout << "Ingresar telefono del paciente: ";
                    cin >> cita.telefono;
                    // Mes
                    // Hacer un if para que la opcion ingresada sea entre 1 y 12 (enero - diciembre)
                    do
                    {
                        cout << "Ingresar mes de la cita: ";
                        cin >> cita.mes;
                        if (cita.mes <= 12 && cita.mes >= 1)
                        {
                            break;
                        }
                        else
                        {
                            cout << "La opcion ingresada no es valida\n"
                                 << "\n";
                        }

                    } while (cita.mes > 12 || cita.mes < 1);

                    // Dia
                    do
                    {
                        cout << "Ingresar dia de la cita: ";
                        cin >> cita.dia;
                        // Verificar que el dia ingresado corresponde con los que tiene el mes seleccionado anteriormente
                        // Por ejemplo: si el mes seleccionado fué abril, "cita.dia" debe estar entre 1 y 30, pero si el mes
                        // fué febrero, "cita.dia" debe estar entre 1 y 28

                        if (cita.dia > 31)
                        {
                            cout << "el dia ingresado no es valido";
                        }

                        else if ((cita.mes == 2) && (cita.dia <= 28))
                        {
                            break;
                        }
                        else if ((cita.mes == 4) || (cita.mes == 6) || (cita.mes == 11) && (cita.dia <= 30))
                        {

                            break;
                        }
                        else if ((cita.mes == 1) || (cita.mes == 3) || (cita.mes == 5) || (cita.mes == 7) || (cita.mes == 8) || (cita.mes == 9) || (cita.mes == 12) && (cita.dia <= 31))
                        {

                            break;
                        }
                        else
                        {
                            cout << "el dia ingresado no es valido" << endl;

                        }
                    } while (cita.dia > 31 || cita.dia < 1 || cita.mes == 2 && cita.dia > 29 );

                    // Hora
                    cout << "Ingresar hora de la cita (hh.mm): ";
                    cin >> cita.hora;
                    // Verificar que la fecha y hora esté disponible

                    archivo.open(archivo_cita.c_str(), fstream::app); // Guardando datos en archivo
                    archivo << "Paciente: " << cita.nombre << endl;
                    archivo << "Especialidad: " << cita.especialidad << endl;
                    archivo << "Edad del paciente: " << cita.edad << endl;
                    archivo << "Telefono del paciente: " << cita.telefono << endl;
                    archivo << "Mes: " << cita.mes << endl;
                    archivo << "Dia: " << cita.dia << endl;
                    archivo << "Hora: " << cita.hora << endl
                            << endl;
                    archivo.close();
                    cout << "Cita guardada.\nPresione cualquier tecla para salir.";
                    getch();
                    cout << "\n";
                    opcion = 3;
                    break;
                case 2:
                    do
                    {
                        menu_espec();
                        cin >> opcion_especialidad;

                        switch (opcion_especialidad)
                        {
                        case 1:
                            cout << "Medicina General: ";
                            cout << especialidades[0] << endl;
                            cout << "Horario de atencion: lunes a sabado - 8:00 a 17:00" << endl
                                 << endl;
                            break;
                        case 2:
                            cout << "Fisioterapia: ";
                            cout << especialidades[1] << endl;
                            cout << "Horario de atencion: lunes a viernes - 9:00 a 17:00" << endl
                                 << endl;
                            break;
                        case 3:
                            cout << "Ortopeda: ";
                            cout << especialidades[2] << endl;
                            cout << "Horario de atencion: lunes a viernes - 9:00 a 15:00" << endl
                                 << endl;
                            break;
                        case 4:
                            cout << "Pediatria: ";
                            cout << especialidades[3] << endl;
                            cout << "Horario de atencion: lunes a sabado - 8:00 a 17:00" << endl
                                 << endl;
                            break;
                        case 5:
                            opcion_especialidad = 5;
                            system("cls");
                            break;

                        default:
                            cout << "La opcion ingresada no es valida";
                            break;
                        }
                    } while (opcion_especialidad != 5);
                    break;
                case 3:
                    for (int i = 0; i < 5; i++)
                    {
                        cout << "Nombre del medicamento: " << farmacia_med[i] << " " << endl;
                        cout << farmacia_present[i] << " " << endl;
                        cout << "$" << farmacia_precio[i] << " " << endl;
                        cout << "cantidad en stock: " << cantidad_med[i] << endl
                             << endl;
                    }
                    break;
                case 4:
                    inf_clinica();
                    break;
                case 5:
                    system("cls");
                    usuario = 6;
                    break;
                case 6:
                    opcion = 3;
                    break;

                default:
                    cout << "La opcion ingresada no es valida";
                    break;
                }
            } while (usuario != 6);

            break;
        case 2:

            // MENU DE ADMINISTRADOR //
            do
            {
                cout << "Menu de Administrador\n\n";
                cout << "1. Consultar citas\n";
                cout << "2. Editar farmacia\n";
                cout << "3. Editar especialidades\n";
                cout << "4. Editar informacion\n";
                cout << "5. Regresar al menu principal\n";
                cout << "6. Salir\n\n";
                cout << "Seleccionar opcion: ";
                cin >> opcion_admin;
                cin.ignore();
                system("cls");

                switch (opcion_admin)
                {
                case 1: // OPCION - CONSULTAR CITAS//
                {
                    cout << "- Mostrando citas -\n\n";
                    MostrarCitas();
                    cout << "Presione cualquier tecla para salir.";
                    getch();
                    system("cls");
                    break;
                }
                case 2: // OPCION - EDITAR FARMACIA//
                {
                    do
                    {
                        cout << "- Editando farmacia -\n\n";
                        for (int i = 0; i < 5; i++)
                        { // Imprimiendo lista de medicamentos
                            cout << i + 1 << ". ";
                            cout << farmacia_med[i] << " - " << farmacia_present[i] << "\n";
                            cout << "   $ " << farmacia_precio[i] << "\n";
                            cout << "   Cantidad: " << cantidad_med[i] << "\n\n";
                        }
                        cout << "6. Regresar\n\n";
                        cout << "Seleccionar medicamento a editar: ";
                        cin >> opcion_admin;
                        cin.ignore();
                        system("cls");

                        switch (opcion_admin)
                        {
                        case 1 ... 5:
                        {
                            cout << "Que desea editar?\n  1. Presentacion\n  2. Precio\n  3. Cantidad \n\nSeleccionar opcion: ";
                            cin >> admin_farmacia;
                            cin.ignore();
                            system("cls");

                            switch (admin_farmacia)
                            {
                            case 1:
                            { // Editar Presentacion
                                cout << "Presentacion actual: " << farmacia_present[opcion_admin - 1] << "\n\n";
                                cout << "Nueva presentacion: ";
                                getline(cin, farmacia_present[opcion_admin - 1]);
                                system("cls");
                                break;
                            }
                            case 2:
                            { // Editar Precio
                                cout << "Precio actual: $" << farmacia_precio[opcion_admin - 1] << "\n\n";
                                cout << "Nuevo precio: $";
                                cin >> farmacia_precio[opcion_admin - 1];
                                cin.ignore();
                                system("cls");
                                break;
                            }
                            case 3:
                            { // Editar Cantidad
                                cout << "Cantidad actual: " << cantidad_med[opcion_admin - 1] << "\n\n";
                                cout << "Nueva cantidad: ";
                                cin >> cantidad_med[opcion_admin - 1];
                                cin.ignore();
                                system("cls");
                                break;
                            }
                            default:
                            {
                                system("cls");
                                cout << "Opcion no valida. Intente otra vez.\n";
                                break;
                            }
                            }
                            break;
                        }
                        case 6:
                        { // Regresar
                            break;
                        }
                        default:
                        { // Opcion no valida
                            system("cls");
                            cout << "Opcion no valida. Intente otra vez.\n";
                            break;
                        }
                        }
                    } while (opcion_admin != 6);
                    opcion_admin = 0;
                    system("cls");
                    break;
                }
                case 3: // OPCION - EDITAR ESPECIALIDADES//
                {
                    do
                    {
                        cout << "- Editando especialidades -\n\n";
                        cout << "1. Medicina General\n   " << especialidades[0] << "\n   " << horarios[0] << "\n\n";
                        cout << "2. Fisioterapia\n   " << especialidades[1] << "\n   " << horarios[1] << "\n\n";
                        cout << "3. Ortopedia\n   " << especialidades[2] << "\n   " << horarios[2] << "\n\n";
                        cout << "4. Pediatria\n   " << especialidades[3] << "\n   " << horarios[3] << "\n\n";
                        cout << "5. Regresar\n\n";
                        cout << "Seleccionar especialidad a editar: ";
                        cin >> opcion_admin;
                        cin.ignore();
                        system("cls");

                        switch (opcion_admin)
                        {
                        case 1 ... 4:
                        {
                            cout << "Que desea editar?\n   1. Descripcion\n   2. Horario \n\nSeleccionar opcion: ";
                            cin >> admin_especialidad;
                            cin.ignore();
                            system("cls");

                            switch (admin_especialidad)
                            {
                            case 1:
                            { // Editar Descripcion
                                cout << "Descripcion actual: " << especialidades[opcion_admin - 1] << "\n\n";
                                cout << "Nueva descripcion: ";
                                getline(cin, especialidades[opcion_admin - 1]);
                                system("cls");
                                break;
                            }
                            case 2:
                            { // Editar Horario
                                cout << "Horario actual: " << horarios[opcion_admin - 1] << "\n\n";
                                cout << "Nuevo horario: ";
                                getline(cin, horarios[opcion_admin - 1]);
                                system("cls");
                                break;
                            }
                            default:
                            {
                                system("cls");
                                cout << "Opcion no valida. Intente otra vez.\n";
                                break;
                            }
                            }
                            break;
                        }
                        case 5:
                        { // Regresar
                            break;
                        }
                        default:
                        { // Opcion no valida
                            system("cls");
                            cout << "Opcion no valida. Intente otra vez.\n";
                            break;
                        }
                        }
                    } while (opcion_admin != 5);
                    opcion_admin = 0;
                    system("cls");
                    break;
                }
                case 4: // OPCION - EDITAR INFORMACION//
                {
                    do
                    {
                        cout << "- Editando informacion -\n\n";
                        cout << "1. Direccion: " << informacion.direccion << "\n";
                        cout << "2. Contacto:  " << informacion.contacto << "\n";
                        cout << "3. Horario:   " << informacion.horario << "\n";
                        cout << "4. Regresar\n\n";
                        cout << "Seleccionar informacion a editar: ";
                        cin >> opcion_admin;
                        cin.ignore();
                        system("cls");

                        switch (opcion_admin)
                        {
                        case 1:
                        { // Editar Direccion
                            cout << "Direccion actual: " << informacion.direccion << "\n\n";
                            cout << "Nueva direccion: ";
                            getline(cin, informacion.direccion);
                            system("cls");
                            break;
                        }
                        case 2:
                        { // Editar Contacto
                            cout << "Contacto actual: " << informacion.contacto << "\n\n";
                            cout << "Nuevo contacto: ";
                            getline(cin, informacion.contacto);
                            system("cls");
                            break;
                        }
                        case 3:
                        { // Editar Horario
                            cout << "Horario actual: " << informacion.horario << "\n\n";
                            cout << "Nuevo horario: ";
                            getline(cin, informacion.horario);
                            system("cls");
                            break;
                        }
                        case 4:
                        { // Regresar
                            break;
                        }
                        default:
                        { // Opcion no valida
                            system("cls");
                            cout << "Opcion no valida. Intente otra vez.\n";
                            break;
                        }
                        }
                    } while (opcion_admin != 4);
                    opcion_admin = 0;
                    system("cls");
                    break;
                }
                case 5: // REGRESAR AL MENU PRINCIPAL//
                {
                    opcion_admin = 6;
                    break;
                }
                case 6: // SALIR//
                {
                    opcion = 3;
                    cout << "Saliendo.";
                    break;
                }
                default:
                {
                    cout << "Opcion no valida. Intente otra vez.\n";
                    break;
                }
                }

            } while (opcion_admin != 6);
            break;
        case 3:
            break;

        default:
            cout << "La opcion ingresada no es valida";
            break;
        }

    } while (opcion != 3);

    return 0;
}
