#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <conio.h>

using namespace std;

// Declaracion de las variables principales
int opcion, usuario, opcion_especialidad;
string med_gen, pedi, ortoped, fisio;

// Estructura para los datos de la farmacia
struct DatosFarmacia
{
    string nombre_medicamento;
    int cantidad;
    float precio;
};

// declarando arreglos para los medicamentos, con nombre, composicion del medicamento, precio y cantidad en inventario
string farmacia_med[5] = {"Ibuprofeno", "Ciproxil", "Amoxicilina", "Fosfocil", "Afrin"};
string farmacia_present[5] = {"120 ml", "500 mg tableta", "500 mg capsula", "120 ml", "15 ml"};
float farmacia_precio[5] = {5.50, 1.50, 0.30, 17.00, 8.00};
int cantidad_med[5];

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

int main()
{
    // igualando las variables para la descripcion de las especialidades que forman parte de la clinica
    med_gen = "Es el nivel de atencion medica principal, la cual es importante para la deteccion, tratamiento y prevención de las enfermedades cronicas.";
    pedi = "incluye la Patologia Medicoquirurgica y de especialidades que presentan pacientes en las diferentes edades pediatricas desde el nacimiento hasta el termino del crecimiento y desarrollo que, en promedio, se alcanza entre los 18 y 20 años de edad.";
    ortoped = "Se especializan en el cuidado de trastornos de los huesos, musculos, tendones y ligamentos.";
    fisio = "Es una especialidad medica que tiene por objeto la valoracion, diagnostico, prevencion y tratamiento de las discapacidades derivadas de enfermedades y accidentes, utilizando para ellos todos los metodos a su alcance (fisicos, medicamentosos, educacionales.)";

    // archivo para citas
    string linea;
    string archivo_cita = "lista_cita.txt";
    string archivo_farmacia = "Farmacia.txt";
    ofstream archivo;
    ifstream archivo_lectura;

    // estructura para citas
    DatosCita cita;
    do
    {
        cout << "     -----Bienvenido al sistema de la clinica en linea-----      " << endl
             << "Como desea ingresar al sistema de la clinica" << endl
             << endl
             << "1. Usuario" << endl
             << "2. Administrador" << endl
             << "3. Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:

            do
            {
                cout << "Que desea realizar?" << endl
                     << endl
                     << "1. Hacer una cita" << endl
                     << "2. Conocer las especialidades" << endl
                     << "3. Visitar farmacia" << endl
                     << "4. Mas informacion" << endl
                     << "5. Regresar al menu principal" << endl
                     << "6. Salir" << endl;
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
                    } while (cita.dia > 31 || cita.dia < 1);

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
                    break;
                    break;
                case 2:
                    do
                    {
                        cout << "     -----Las especialidades con las que dispone nuestra clinica son-----        " << endl
                             << "1.Medicina General" << endl
                             << "2.Fisioterapia" << endl
                             << "3.Ortopeda" << endl
                             << "4.Pedriatria" << endl
                             << "5.Regresar" << endl;
                        cin >> opcion_especialidad;

                        switch (opcion_especialidad)
                        {
                        case 1:
                            cout << "Medicina General: ";
                            cout << med_gen << endl;
                            cout << "Horario de atencion: lunes a sabado - 8:00 a 17:00" << endl
                                 << endl;
                            break;
                        case 2:
                            cout << "Fisioterapia: ";
                            cout << fisio << endl;
                            cout << "Horario de atencion: lunes a viernes - 9:00 a 17:00" << endl
                                 << endl;
                            break;
                        case 3:
                            cout << "Ortopeda: ";
                            cout << ortoped << endl;
                            cout << "Horario de atencion: lunes a viernes - 9:00 a 15:00" << endl
                                 << endl;
                            break;
                        case 4:
                            cout << "Pediatria: ";
                            cout << pedi << endl;
                            cout << "Horario de atencion: lunes a sabado - 8:00 a 17:00" << endl
                                 << endl;
                            break;
                        case 5:
                            opcion_especialidad = 5;
                            break;

                        default:
                            cout << "La opcion ingresada no es valida";
                            break;
                        }
                    } while (opcion_especialidad != 5);
                case 3:
                    archivo.open(archivo_farmacia.c_str(), fstream::app);
                    for (int i = 0; i < 5; i++)
                    {
                        archivo << "Nombre del medicamento: " << farmacia_med[i] << " " << endl;
                        archivo << farmacia_present[i] << " " << endl;
                        archivo << "$" << farmacia_precio[i] << " " << endl;
                        archivo << "cantidad en stock: " << cantidad_med[i] << endl
                                << endl;
                    }

                    if (archivo.is_open())
                    {
                        while (getline(archivo_lectura, linea))
                        {
                            cout << linea << endl;
                        }
                        archivo.close();
                    }
                    else
                    {
                        cout << "Error al abrir el archivo." << endl;
                    }
                    break;
                case 4:
                    break;
                case 5:
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
            // Daniel, Agregar apartado de administradores.
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
