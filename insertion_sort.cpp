#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
using namespace std;
using namespace std::chrono;

vector<int> leerDatosDesdeArchivo(const string& nombreArchivo) {
    vector<int> datos;
    ifstream archivo(nombreArchivo);
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            datos.push_back(stoi(linea));
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }
    return datos;
}

void insertionSort(vector<int>& arr) {
    int i, j, key;
    for (i = 1; i < arr.size(); i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

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
    vector<int> data = leerDatosDesdeArchivo(nombreArchivoEntrada);

    auto start = high_resolution_clock::now();
    insertionSort(data);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Insertion Sort duración: " << duration.count() << " microsegundos" << endl;

    escribirDatosAArchivo(data, nombreArchivoSalida);

    return 0;
}
