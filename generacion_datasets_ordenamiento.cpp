#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

// Función para generar una lista ascendente
vector<int> generarAscendente(int size) {
    vector<int> vec(size);
    for (int i = 0; i < size; ++i) {
        vec[i] = i;
    }
    return vec;
}

// Función para generar una lista descendente
vector<int> generarDescendente(int size) {
    vector<int> vec(size);
    for (int i = 0; i < size; ++i) {
        vec[i] = size - i - 1;
    }
    return vec;
}

// Función para generar una lista aleatoria
vector<int> generarAleatorio(int size) {
    vector<int> vec(size);
    mt19937 rng(time(0)); // Generador de números aleatorios
    uniform_int_distribution<int> dist(0, size);
    
    for (int i = 0; i < size; ++i) {
        vec[i] = dist(rng);
    }
    return vec;
}

// Función para generar una lista con muchos elementos repetidos
vector<int> generarConDuplicados(int size) {
    vector<int> vec(size);
    mt19937 rng(time(0)); 
    uniform_int_distribution<int> dist(0, 10);
    
    for (int i = 0; i < size; ++i) {
        vec[i] = dist(rng);
    }
    return vec;
}

// Función para generar una lista casi ordenada
vector<int> generarCasiOrdenado(int size) {
    vector<int> vec = generarAscendente(size);
    mt19937 rng(time(0));
    
    // Desordenar algunos elementos aleatorios
    for (int i = 0; i < size / 10; ++i) { // El 10% de los elementos están fuera de lugar
        int idx1 = rng() % size;
        int idx2 = rng() % size;
        swap(vec[idx1], vec[idx2]);
    }
    return vec;
}

// Función para generar una lista donde todos los elementos son iguales
vector<int> generarTodosIguales(int size) {
    vector<int> vec(size, rand()); // Todos los elementos son un número aleatorio
    return vec;
}

// Función para guardar un vector en un archivo
void guardarEnArchivo(const vector<int>& vec, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (const int& num : vec) {
            archivo << num << "\n";
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }
}

int main() {
    vector<int> sizes = {100, 1000, 10000, 100000, 1000000}; // Diferentes tamaños de dataset

    for (int size : sizes) {
        auto ascendente = generarAscendente(size);
        auto descendente = generarDescendente(size);
        auto aleatorio = generarAleatorio(size);
        auto conDuplicados = generarConDuplicados(size);
        auto casiOrdenado = generarCasiOrdenado(size);
        auto todosIguales = generarTodosIguales(size);

        // Guardar en archivos
        guardarEnArchivo(ascendente, "ascendente_" + to_string(size) + ".txt");
        guardarEnArchivo(descendente, "descendente_" + to_string(size) + ".txt");
        guardarEnArchivo(aleatorio, "aleatorio_" + to_string(size) + ".txt");
        guardarEnArchivo(conDuplicados, "duplicados_" + to_string(size) + ".txt");
        guardarEnArchivo(casiOrdenado, "casi_ordenado_" + to_string(size) + ".txt");
        guardarEnArchivo(todosIguales, "todos_iguales_" + to_string(size) + ".txt");
    }

    cout << "Archivos guardados correctamente." << endl;

    return 0;
}
