#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;

// Función para leer una matriz desde un archivo de texto
vector<vector<int>> leerMatrizDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    vector<vector<int>> matriz;
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            vector<int> fila;
            int n;
            while (ss >> n) {
                fila.push_back(n);
            }
            matriz.push_back(fila);
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }

    return matriz;
}

// Función para multiplicar matrices de manera tradicional
vector<vector<int>> multiplicarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    // Multiplicación de matrices
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <archivo_matriz_A> <archivo_matriz_B>" << endl;
        return 1;
    }

    string archivoA = argv[1];
    string archivoB = argv[2];

    vector<vector<int>> A = leerMatrizDesdeArchivo(archivoA);
    vector<vector<int>> B = leerMatrizDesdeArchivo(archivoB);

    // Medir el tiempo de ejecución
    auto inicio = chrono::high_resolution_clock::now();

    vector<vector<int>> C = multiplicarMatrices(A, B);

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;

    // Guardar la matriz resultante en un archivo
    ofstream archivo("resultado_normal.txt");
    if (archivo.is_open()) {
        archivo << "Matriz C (Resultado de A x B):\n";
        for (const auto& fila : C) {
            for (int elemento : fila) {
                archivo << elemento << " ";
            }
            archivo << "\n";
        }
        archivo.close();
        cout << "Tiempo de ejecución: " << duracion.count() << " segundos\n";
        cout << "El resultado ha sido guardado en 'resultado_normal.txt'.\n";
    } else {
        cerr << "No se pudo abrir el archivo para escribir.\n";
    }

    return 0;
}
