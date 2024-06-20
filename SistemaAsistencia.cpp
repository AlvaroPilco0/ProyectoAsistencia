#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

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

