#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
using namespace std;
using namespace std::chrono;

// Función para leer los datos del archivo y almacenarlo en un vector
vector<int> leerDatosDesdeArchivo(const string& nombreArchivo) {
    vector<int> datos;
    ifstream archivo(nombreArchivo);
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            datos.push_back(stoi(linea)); // Convierte cada línea a un entero y lo agrega al vector
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }
    return datos;
}

// Función para realizar la partición del vector
int partition(vector<int>& arr, int bajo, int alto) {
    int pivote = arr[alto]; // Pivot element
    int i = (bajo - 1);

    for (int j = bajo; j <= alto - 1; j++) {
        if (arr[j] < pivote) {
            i++;
            swap(arr[i], arr[j]); // Swap de elementos menores al pivote
        }
    }
    swap(arr[i + 1], arr[alto]); // Posiciona el pivote en su lugar correcto
    return (i + 1);
}

// Función para realizar el ordenamiento quicksort	
void quickSort(vector<int>& arr, int bajo, int alto) {
    if (bajo < alto) {
        int pi = partition(arr, bajo, alto); // Partición del vector
        quickSort(arr, bajo, pi - 1); // Recursion antes de la partición
        quickSort(arr, pi + 1, alto); // Recursion despues de la partición
    }
}

// Función para escribir los datos ordenados en un archivo
void escribirDatosAArchivo(const vector<int>& arr, const string& nombreArchivoSalida) {
    ofstream archivoSalida(nombreArchivoSalida);
    if (archivoSalida.is_open()) {
        for (int num : arr) {
            archivoSalida << num << endl; 
        }
        archivoSalida.close();
    } else {
        cerr << "No se pudo abrir el archivo de salida: " << nombreArchivoSalida << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <nombre_del_archivo_entrada> <nombre_del_archivo_salida>" << endl;
        return 1;
    }

    string nombreArchivoEntrada = argv[1];
    string nombreArchivoSalida = argv[2];
    vector<int> data = leerDatosDesdeArchivo(nombreArchivoEntrada); // Lectura de datos

    auto start = high_resolution_clock::now(); // Comienzo del timer
    quickSort(data, 0, data.size() - 1);
    auto stop = high_resolution_clock::now(); // Detención del timer

    auto duration = duration_cast<microseconds>(stop - start); // Calculo de la duración
    cout << "Quick Sort duración: " << duration.count() << " microseconds" << endl;

    escribirDatosAArchivo(data, nombreArchivoSalida);

    return 0;
}
