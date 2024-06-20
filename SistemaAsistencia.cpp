#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

bool validarNombre(const string& nombre) {
    return !nombre.empty();  // Retorna verdadero si el nombre no está vacío
}
void hola(){
}
// En el bucle principal de main():
while (true) {
    cout << "Ingrese el nombre del estudiante ('fin' para salir): ";
    cin >> nombre;
    if (nombre == "fin") {
        break;
    }
    if (!validarNombre(nombre)) {
        cout << RED << "Nombre no válido. Por favor, ingrese un nombre válido." << RESET << endl;
        continue;
    }
    registrarAsistencia(nombre);
}

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
        cout << "Asistencia de " << nombre << " registrada correctamente." << endl;
    } else {
        cout << "Error al abrir el archivo de asistencia." << endl;
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

