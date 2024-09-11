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

void merge(vector<int>& left, vector<int>& right, vector<int>& bars) {
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR) {
        if (left[j] < right[k]) {
            bars[i] = left[j];
            j++;
        } else {
            bars[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL) {
        bars[i] = left[j];
        j++; i++;
    }
    while (k < nR) {
        bars[i] = right[k];
        k++; i++;
    }
}

void mergeSort(vector<int>& bar) {
    if (bar.size() <= 1) return;

    int mid = bar.size() / 2;
    vector<int> left(bar.begin(), bar.begin() + mid);
    vector<int> right(bar.begin() + mid, bar.end());

    mergeSort(left);
    mergeSort(right);
    merge(left, right, bar);
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
    mergeSort(data);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Merge Sort duración: " << duration.count() << " microsegundos" << endl;

    escribirDatosAArchivo(data, nombreArchivoSalida);

    return 0;
}
