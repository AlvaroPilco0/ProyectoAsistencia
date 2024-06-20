#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Colores ANSI para la consola
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Función para obtener la fecha y hora actual
string getCurrentDateTime() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", ltm);
    return string(buffer);
}

// Función para registrar la asistencia
void registrarAsistencia(const string& nombre) {
    ofstream archivo("asistencia.txt", ios::app);
    if (archivo.is_open()) {
        archivo << getCurrentDateTime() << " - " << nombre << endl;
        archivo.close();
        cout << GREEN << "Asistencia de " << nombre << " registrada correctamente." << RESET << endl;
    } else {
        cout << RED << "Error al abrir el archivo de asistencia." << RESET << endl;
    }
}

int main() {
    string nombre;
    cout << "Ingrese el nombre del estudiante ('fin' para salir): ";
    while (cin >> nombre) {
        if (nombre == "fin") {
            break;
        }
        registrarAsistencia(nombre);
        cout << "Ingrese el nombre del siguiente estudiante ('fin' para salir): ";
    }
    return 0;
}

