#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include <algorithm>

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

void escribirDatosEnArchivo(const vector<int>& datos, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (const int& num : datos) {
            archivo << num << "\n";
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo para escribir: " << nombreArchivo << endl;
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
    sort(data.begin(), data.end());
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "std::sort execution time: " << duration.count() << " microseconds" << endl;

    escribirDatosEnArchivo(data, nombreArchivoSalida);

    return 0;
}
