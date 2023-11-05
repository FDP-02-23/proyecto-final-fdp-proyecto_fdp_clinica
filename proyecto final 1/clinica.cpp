#include <iostream>

using namespace std;
int opcion, usuario, opcion_especialidad;

int main()
{
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
                            cout << "Es el nivel de atencion medica principal, la cual es importante para la deteccion, tratamiento y prevención de las enfermedades cronicas." << endl;
                            cout << "Horario de atencion: lunes a sabado - 8:00 a 17:00" << endl
                                 << endl;
                            break;
                        case 2:
                            cout << "Fisioterapia: ";
                            cout << "Es una especialidad medica que tiene por objeto la valoracion, diagnostico, prevencion y tratamiento de las discapacidades derivadas de enfermedades y accidentes, utilizando para ellos todos los metodos a su alcance (fisicos, medicamentosos, educacionales.)" << endl;
                            cout << "Horario de atencion: lunes a viernes - 9:00 a 17:00" << endl
                                 << endl;
                            break;
                        case 3:
                            cout << "Ortopeda: ";
                            cout << "Se especializan en el cuidado de trastornos de los huesos, musculos, tendones y ligamentos." << endl;
                            cout << "Horario de atencion: lunes a viernes - 9:00 a 15:00" << endl
                                 << endl;
                            break;
                        case 4:
                            cout << "Pediatria: ";
                            cout << "incluye la Patologia Medicoquirurgica y de especialidades que presentan pacientes en las diferentes edades pediatricas desde el nacimiento hasta el termino del crecimiento y desarrollo que, en promedio, se alcanza entre los 18 y 20 años de edad." << endl;
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
                    /* code */
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
