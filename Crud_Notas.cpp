#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Datos Alumno
struct alumno {
    int ID;
    string nombre;
    string apellido;
    int edad;
    int matrizNotas[2][2] = {0};
};

//Ejercicio 2
void ordenar(vector<alumno>& alumnos) {
    for (int i = 0; i < alumnos.size() - 1; i++) {
        for (int j = 0; j < alumnos.size() - i - 1; j++) {
            if (alumnos[j].ID > alumnos[j + 1].ID) {
                alumno temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
            }
        }
    }
}

//Ejercicio 3
void mostrarNotas(alumno& estudiante) {
    cout << "Notas:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << i + 1 << "º Cuatrimestre, " << j + 1 << "º Parcial: " << estudiante.matrizNotas[i][j] << "\n";
        }
    }
}

void busquedaID(vector<alumno>& alumnos, int id) {
    bool encontrado = false;

    for (int i = 0; i < alumnos.size(); i++) {
        if (alumnos[i].ID == id) {
            cout << "\nID: " << alumnos[i].ID << "\n";
            cout << "Nombre: " << alumnos[i].nombre << "\n";
            cout << "Apellido: " << alumnos[i].apellido << "\n";
            cout << "Edad: " << alumnos[i].edad << "\n";
            mostrarNotas(alumnos[i]);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "\nEl alumno con ID " << id << " no se ha encontrado\n";
    }
}

//Ejercicio 4
void actualizarInfo(vector<alumno>& alumnos, int id) {
    string nuevoNombre;
    string nuevoApe;
    int nuevaEdad;
    int truFols;

    for (int i = 0; i < alumnos.size(); i++) {
        if (alumnos[i].ID == id) {
            cout << "\nID: " << alumnos[i].ID << "\n";
            cout << "Nombre: " << alumnos[i].nombre << "\n";
            cout << "Apellido: " << alumnos[i].apellido << "\n";
            cout << "Edad: " << alumnos[i].edad << "\n\n";

            do {
                cout << "Desea cambiar la informacion?\n0 = SI\n1 = NO\n";
                cin >> truFols;

                if (truFols == 0) {
                    cout << "\nNombre anterior: " << alumnos[i].nombre;
                    cout << "\nNuevo nombre: ";
                    cin >> nuevoNombre;
                    alumnos[i].nombre = nuevoNombre;

                    cout << "\nApellido anterior: " << alumnos[i].apellido;
                    cout << "\nNuevo apellido: ";
                    cin >> nuevoApe;
                    alumnos[i].apellido = nuevoApe;

                    cout << "\nEdad anterior: " << alumnos[i].edad;
                    cout << "\nNueva edad: ";
                    cin >> nuevaEdad;
                    alumnos[i].edad = nuevaEdad;

                    cout << "\nInformacion actualizada:\n";
                    cout << "ID: " << alumnos[i].ID << "\n";
                    cout << "Nombre: " << alumnos[i].nombre << "\n";
                    cout << "Apellido: " << alumnos[i].apellido << "\n";
                    cout << "Edad: " << alumnos[i].edad << "\n\n";
                    break;
                } else if (truFols == 1) {
                    cout << "No se cambiara la informacion\n";
                    break;
                } else {
                    cout << "Opcion no valida\n";
                }
            } while (truFols == 1 || truFols == 0);
        }
    }
}

//Ejercicio 5
void eliminarEstudiante(vector<alumno>& alumnos, int id) {
    int truFols;
    bool encontrado = false;

    for (int i = 0; i < alumnos.size(); i++) {
        if (alumnos[i].ID == id) {
            cout << "\nID: " << alumnos[i].ID << "\n";
            cout << "Nombre: " << alumnos[i].nombre << "\n";
            cout << "Apellido: " << alumnos[i].apellido << "\n";
            cout << "Edad: " << alumnos[i].edad << "\n";
            mostrarNotas(alumnos[i]);

            cout << "\nDesea eliminar al estudiante?\n0 = SI\n1 = NO\n";
            cin >> truFols;
            
            do {
                if (truFols == 0) {
                    alumnos.erase(alumnos.begin() + i);
                    cout << "Estudiante eliminado\n";
                    
                } else if (truFols == 1) {
                    cout << "No se eliminara al estudiante\n";
                } else {
                    cout << "Opcion no valida";
                }
                
                encontrado = true;
                break;
                
            } while (truFols == 0 || truFols == 1);
        }
    }
    
    if (!encontrado) {
        cout << "\nEl estudiante con ID " << id << " no se ha encontrado\n";
    }
}

//Ejercicio 6
void notasEstudiante(vector<alumno>& alumnos, int id) {
    int nota;
    bool encontrado = false;

    for (int i = 0; i < alumnos.size(); i++) {
        if (alumnos[i].ID == id) {
            cout << "\nID: " << alumnos[i].ID << "\n";
            cout << "Nombre: " << alumnos[i].nombre << "\n";
            cout << "Apellido: " << alumnos[i].apellido << "\n";
            cout << "Edad: " << alumnos[i].edad << "\n";
            
            cout << "\nIngrese las notas de cada cuatrimestre y parcial:\n";

            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    cout << j + 1 << "º cuatrimestre, " << k + 1 << "º parcial: ";
                    cin >> nota;
                    alumnos[i].matrizNotas[j][k] = nota;
                }
            }

            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "\nEl estudiante con ID " << id << " no se ha encontrado\n";
    }
}

void modificarNotas(vector<alumno>& alumnos, int id) {
    int truFols;
    int nota;
    bool encontrado = false;
    
    for (int i = 0; i < alumnos.size(); i++) {
        if (alumnos[i].ID == id) {
            cout << "\n1º Cuatrimestre: ";
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    cout << alumnos[i].matrizNotas[j][k] << " ";
                }
                if (j == 0) {
                    cout << "\n2º Cuatrimestre: ";
                }
            }
            cout << "\n\nDesea modificar las notas del estudiante?\n0 = SI\n1 = NO\n";
            cin >> truFols;

            do {
                if (truFols == 0) {
                    
                    for (int j = 0; j < 2; j++) {
                        for (int k = 0; k < 2; k++) {
                            cout << "\nNota " << j + 1 << "º cuatrimestre, " << k + 1 << "º parcial anterior: " << alumnos[i].matrizNotas[j][k];
                            cout << "\nNueva Nota: ";
                            cin >> nota;
                            alumnos[i].matrizNotas[j][k] = nota;
                        }
                    }
                } else if (truFols == 1) {
                    cout << "No se eliminara al estudiante\n";
                } else {
                    cout << "Opcion no valida";
                }
                
                encontrado = true;
                break;
                
            } while (truFols == 0 || truFols == 1);
        }
    } if (!encontrado) {
        cout << "\nEl estudiante con ID " << id << " no se ha encontrado\n";
    }
}

void mostrarMatriz(vector<alumno>& alumnos, int id) {
    bool encontrado = false;

    for (int i = 0; i < alumnos.size(); i++) {
        if (alumnos[i].ID == id) {
            cout << "\n1º Cuatrimestre: ";
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    cout << alumnos[i].matrizNotas[j][k] << " ";
                }
                if (j == 0) {
                    cout << "\n2º Cuatrimestre: ";
                }
            }

            encontrado = true;
            cout << "\n\n";
            break;
        }
    }
}

int main() {

    // Ejercicio 1
    int numAlumnos = 0;
    vector<alumno> alumnos;
    bool idExiste = false;
    alumno estudiante;

    // Ejercicio 3
    int idEjercicio3;

    // Ejercicio 4
    int idEjercicio4;

    // Ejercicio 5
    int idEjercicio5;

    // Ejercicio 6
    int idEjercicio6;
    int opcionMenuNotas;

    // Menu
    int opcionMenu;

    do {
        cout << "\n=== Menu Principal ===\n\n";
        cout << "1. Agregar Estudiante\n";
        cout << "2. Mostrar Estudiantes\n";
        cout << "3. Buscar Estudiante por ID\n";
        cout << "4. Actualizar Informacion\n";
        cout << "5. Eliminar Estudiante\n";
        cout << "6. Menu Notas\n";
        cout << "7. Salir\n\n";
        cout << "Seleccione una opción: ";
        cin >> opcionMenu;

        switch (opcionMenu) {
            case 1:
                cout << "\n1. Agregar Estudiante\n";

                cout << "ID: ";
                cin >> estudiante.ID;

                for (int i = 0; i < numAlumnos; i++) {
                    if (alumnos[i].ID == estudiante.ID) {
                        idExiste = true;
                        break;
                    }
                }

                if (idExiste) {
                    cout << "Ya se ha ingresado un estudiante con el ID " << estudiante.ID << "\n\n";
                    idExiste = false; // Reiniciar la bandera
                } else {
                    cout << "Nombre: ";
                    cin >> estudiante.nombre;

                    cout << "Apellido: ";
                    cin >> estudiante.apellido;

                    cout << "Edad: ";
                    cin >> estudiante.edad;

                    if (estudiante.ID > 0 && !estudiante.nombre.empty() && !estudiante.apellido.empty()) {
                        alumnos.push_back(estudiante);
                        numAlumnos++;
                        cout << "Estudiante agregado exitosamente\n\n";
                    } else {
                        cout << "No se ha podido agregar al estudiante\n";
                        cout << "Datos incorrectos\n\n";
                    }
                }
                break;

            case 2:
                cout << "\n2. Mostrar Estudiantes";
                ordenar(alumnos);

                if (alumnos.size() > 0) {

                    if (alumnos.size() == 1) {
                        cout << "\nEstudiante:\n";
                        
                        cout << "ID: " << alumnos[0].ID << "\n";
                        cout << "Nombre: " << alumnos[0].nombre << "\n";
                        cout << "Apellido: " << alumnos[0].apellido << "\n";
                        cout << "Edad: " << alumnos[0].edad << "\n";
                        
                    } else {
                        cout << "\nEstudiantes:\n";
                        
                        for (int i = 0; i < alumnos.size(); i++) {
                            cout << "ID: " << alumnos[i].ID << ". " << "Nombre: " << alumnos[i].nombre << ". " << "Apellido: " << alumnos[i].apellido << ". " << "Edad: " << alumnos[i].edad << ".\n";
                        }
                    }
                    
                } else {
                    cout << "No hay ningun estudiante en la base de datos\n";
                    cout << "Por favor, ingrese un estudiante\n\n";
                }
                break;

            case 3:
                cout << "\n3. Buscar Estudiante por ID\n";
                cout << "Ingrese un ID: ";
                cin >> idEjercicio3;

                busquedaID(alumnos, idEjercicio3);
                break;

            case 4:
                cout << "4. Actualizar Informacion\n";
                cout << "Ingrese un ID: ";
                cin >> idEjercicio4;

                actualizarInfo(alumnos, idEjercicio4);
                break;

            case 5:
                cout << "5. Eliminar Estudiante\n";
                cout << "Ingrese un ID: ";
                cin >> idEjercicio5;

                eliminarEstudiante(alumnos, idEjercicio5);
                break;

            case 6:
                cout << "\n\n=== Menu Notas ===\n";
                cout << "1. Ingresar Notas\n";
                cout << "2. Modificar Notas\n";
                cin >> opcionMenuNotas;
                
                switch (opcionMenuNotas) {
                    case 1:
                        cout << "0. Ingresar Notas\n";
                        cout << "Ingrese un ID: ";
                        cin >> idEjercicio6;
        
                        notasEstudiante(alumnos, idEjercicio6);
        
                    mostrarMatriz(alumnos, idEjercicio6);
                    break;
                        
                    case 2: 
                        cout << "1. Modificar Notas\n";
                        cout << "Ingrese un ID: ";
                        cin >> idEjercicio6;
                        
                        modificarNotas(alumnos, idEjercicio6);
                        
                        cout << "\nInformacion actualizada:\n";
        
                        mostrarMatriz(alumnos, idEjercicio6);
                    break;
                }

            case 7:
                cout << "\nSaliendo del programa...\n";
                break;

            default:
                cout << "Opción no válida. Por favor, seleccione una opción del 1 al 7.\n\n";
                break;
        }
    } while (opcionMenu != 7);

    return 0;
}
