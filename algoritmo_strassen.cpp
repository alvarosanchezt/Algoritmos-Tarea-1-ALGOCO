#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>   // Para medir el tiempo

using namespace std;
using namespace std::chrono;

// Función para sumar matrices
vector<vector<int>> sumarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Función para restar matrices
vector<vector<int>> restarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Algoritmo de Strassen
vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));

    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    vector<vector<int>> M1 = strassen(sumarMatrices(A11, A22), sumarMatrices(B11, B22));
    vector<vector<int>> M2 = strassen(sumarMatrices(A21, A22), B11);
    vector<vector<int>> M3 = strassen(A11, restarMatrices(B12, B22));
    vector<vector<int>> M4 = strassen(A22, restarMatrices(B21, B11));
    vector<vector<int>> M5 = strassen(sumarMatrices(A11, A12), B22);
    vector<vector<int>> M6 = strassen(restarMatrices(A21, A11), sumarMatrices(B11, B12));
    vector<vector<int>> M7 = strassen(restarMatrices(A12, A22), sumarMatrices(B21, B22));

    vector<vector<int>> C11 = sumarMatrices(restarMatrices(sumarMatrices(M1, M4), M5), M7);
    vector<vector<int>> C12 = sumarMatrices(M3, M5);
    vector<vector<int>> C21 = sumarMatrices(M2, M4);
    vector<vector<int>> C22 = sumarMatrices(restarMatrices(sumarMatrices(M1, M3), M2), M6);

    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}

// Función para leer una matriz desde un archivo de texto en el formato especificado
vector<vector<int>> leerMatrizDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        exit(1);
    }

    int n;
    archivo >> n;  // Leer el tamaño de la matriz

    vector<vector<int>> matriz(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            archivo >> matriz[i][j];
        }
    }

    archivo.close();
    return matriz;
}

// Función para guardar una matriz en un archivo de texto
void guardarMatrizEnArchivo(const vector<vector<int>>& matriz, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para escribir: " << nombreArchivo << endl;
        exit(1);
    }

    int n = matriz.size();
    archivo << n << endl;  // Escribir el tamaño de la matriz
    for (const auto& fila : matriz) {
        for (int valor : fila) {
            archivo << valor << " ";
        }
        archivo << endl;
    }

    archivo.close();
}

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 4) {
        cerr << "Uso: " << argv[0] << " <archivo_matriz_A> <archivo_matriz_B> [<archivo_salida>]" << endl;
        return 1;
    }

    string archivoA = argv[1];
    string archivoB = argv[2];
    string archivoSalida = (argc == 4) ? argv[3] : "resultado_strassen.txt";

    vector<vector<int>> A = leerMatrizDesdeArchivo(archivoA);
    vector<vector<int>> B = leerMatrizDesdeArchivo(archivoB);

    auto inicio = high_resolution_clock::now();  // Inicia la medición del tiempo

    vector<vector<int>> C = strassen(A, B);

    auto fin = high_resolution_clock::now();   // Detiene la medición del tiempo
    auto duracion = duration<double>(fin - inicio);  // Calcula la duración

    guardarMatrizEnArchivo(C, archivoSalida);  // Escribir el resultado en un archivo
    cout << "Tiempo de ejecución: " << duracion.count() << " segundos" << endl;
    cout << "Multiplicación de matrices completada. Resultado guardado en " << archivoSalida << endl;


    return 0;
}
