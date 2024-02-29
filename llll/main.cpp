#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Función para crear un archivo
void crearArchivo(string nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        cout << "Archivo " << nombreArchivo << " creado exitosamente." << endl;
    } else {
        cout << "Error al crear el archivo." << endl;
    }
    archivo.close();
}

// Función para editar un archivo
void editarArchivo(string nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::app); // Abre el archivo en modo de agregar contenido
    if (archivo.is_open()) {
        string contenido;
        cout << "Introduce el contenido a agregar al archivo: ";
        getline(cin, contenido); // Lee una línea de entrada del usuario
        archivo << contenido << endl; // Escribe el contenido en el archivo
        cout << "Contenido agregado al archivo." << endl;
    } else {
        cout << "Error al abrir el archivo para edición." << endl;
    }
    archivo.close();
}

// Función para eliminar un archivo
void eliminarArchivo(string nombreArchivo) {
    if (remove(nombreArchivo.c_str()) == 0) {
        cout << "Archivo " << nombreArchivo << " eliminado exitosamente." << endl;
    } else {
        cout << "Error al eliminar el archivo." << endl;
    }
}

// Función para mostrar información del archivo.
void mostrarInformacionArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        cout << "Contenido del archivo:" << endl;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
    } else {
        cout << "Error al abrir el archivo para lectura." << endl;
    }
    archivo.close();
}

int main() {
    string nombreArchivo = "mi_archivo.txt"; // Cambia el nombre del archivo según tus necesidades

    crearArchivo(nombreArchivo);
    editarArchivo(nombreArchivo);
    mostrarInformacionArchivo(nombreArchivo);
    eliminarArchivo(nombreArchivo);

    return 0;
}