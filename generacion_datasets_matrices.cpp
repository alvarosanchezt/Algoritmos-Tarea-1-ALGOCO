#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para generar y guardar una matriz de tamaño N x N
void generarMatriz(int N, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        archivo << N << "\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                archivo << rand() % 100 << " "; // Genera un número aleatorio entre 0 y 99
            }
            archivo << "\n";
        }
        archivo.close();
        cout << "Matriz " << N << "x" << N << " guardada en " << nombreArchivo << endl;
    } else {
        cerr << "No se pudo abrir el archivo para escribir." << endl;
    }
}

// Generar datasets con diferentes tamaños de matrices
void generarConjuntosDeDatos() {
    srand(time(nullptr)); // Inicializa la semilla aleatoria
    vector<int> sizes = {32, 64, 128, 256, 512, 1024, 2048}; // Tamaños de matrices

    for (int size : sizes) {
        string nombreArchivoA = "matriz_A_" + to_string(size) + ".txt";
        string nombreArchivoB = "matriz_B_" + to_string(size) + ".txt";
        generarMatriz(size, nombreArchivoA);
        generarMatriz(size, nombreArchivoB);
    }
}

int main() {
    generarConjuntosDeDatos();
    return 0;
}
