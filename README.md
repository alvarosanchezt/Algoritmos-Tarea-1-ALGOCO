## Autor
- **Nombre Completo:** Álvaro Christian Sánchez Timmermann
- **Correo Electrónico:** alvaro.sanchezt@usm.cl
# Algoritmos-Tarea-1-ALGOCO
Este repositorio contiene implementaciones de varios algoritmos de ordenamiento y de multiplicación de matrices en C++. Los algoritmos leen datos desde archivos de texto, procesan los datos y escriben los resultados en archivos de salida.

## Estructura del Repositorio

- `insertion_sort.cpp`: Implementación del algoritmo de Insertion Sort.
- `merge_sort.cpp`: Implementación del algoritmo de Merge Sort.
- `quick_sort.cpp`: Implementación del algoritmo de Quick Sort.
- `std_sort.cpp`: Implementación del algoritmo de ordenamiento estándar de C++ (`std::sort`).
- `multiplicacion_iterativa_matriz.cpp`: Implementación del algoritmo iterativo cúbico tradicional para la multiplicación de matrices.
- `multiplicacion_iterativa_matriz_optimizada.cpp`: Implementación del algoritmo iterativo cúbico optimizado para la localidad de datos.
- `algoritmo_strassen.cpp`: Implementación del algoritmo de Strassen para la multiplicación de matrices.

## Requisitos Previos
Asegúrate de tener un compilador de C++ instalado en tu sistema. Puedes usar `g++`

Para compilar cualquiera de los archivos `.cpp`, puedes utilizar el siguiente comando:

```bash
g++ nombre_del_archivo.cpp -o nombre_del_programa
```
Por ejemplo, para compilar el archivo insertion_sort.cpp:
```
g++ insertion_sort.cpp -o insertion_sort
```
Esto generará un ejecutable llamado insertion_sort.

Ejecución de los Códigos
1. Insertion Sort
./insertion_sort entrada.txt salida.txt
Descripción: Este comando ejecuta el algoritmo de Insertion Sort, leyendo los datos desde entrada.txt y escribiendo los resultados ordenados en output.txt.
Formato de Entrada: Un número por línea en el archivo entrada.txt.
Formato de Salida: Un número por línea en el archivo output.txt.
2. Merge Sort
./merge_sort entrada.txt salida.txt
Descripción: Ejecuta el algoritmo de Merge Sort, leyendo los datos desde entrada.txt y escribiendo los resultados ordenados en output.txt.
Formato de Entrada: Un número por línea en el archivo entrada.txt.
Formato de Salida: Un número por línea en el archivo output.txt.
3. Quick Sort
./quick_sort entrada.txt salida.txt
Descripción: Ejecuta el algoritmo de Quick Sort, leyendo los datos desde entrada.txt y escribiendo los resultados ordenados en output.txt.
Formato de Entrada: Un número por línea en el archivo entrada.txt.
Formato de Salida: Un número por línea en el archivo output.txt.
4. std::sort
./std_sort entrada.txt salida.txt
Descripción: Ejecuta el algoritmo de ordenamiento estándar de C++, std::sort, leyendo los datos desde entrada.txt y escribiendo los resultados ordenados en output.txt.
Formato de Entrada: Un número por línea en el archivo entrada.txt.
Formato de Salida: Un número por línea en el archivo output.txt.
5. Multiplicación de Matrices (Iterativa Cúbica Tradicional)
./iterative_matrix_multiplication matrizA.txt matrizB.txt
Descripción: Ejecuta el algoritmo iterativo cúbico tradicional para multiplicación de matrices, leyendo las matrices desde matrizA.txt y matrizB.txt y escribiendo la matriz resultante en resultado_normal.txt.
Formato de Entrada: Cada fila de la matriz en una línea, con los elementos separados por espacios.
Formato de Salida: Cada fila de la matriz resultante en una línea, con los elementos separados por espacios.
6. Multiplicación de Matrices (Optimizada para Localidad de Datos)
./optimized_matrix_multiplication matrizA.txt matrizB.txt
Descripción: Ejecuta el algoritmo iterativo cúbico optimizado para localidad de datos, leyendo las matrices desde matrizA.txt y matrizB.txt y escribiendo la matriz resultante en resultado_optimizado.txt.
Formato de Entrada: Cada fila de la matriz en una línea, con los elementos separados por espacios.
Formato de Salida: Cada fila de la matriz resultante en una línea, con los elementos separados por espacios.
7. Multiplicación de Matrices (Strassen)
./strassen_matrix_multiplication matrizA.txt matrizB.txt
Descripción: Ejecuta el algoritmo de Strassen para multiplicación de matrices, leyendo las matrices desde matrizA.txt y matrizB.txt y escribiendo la matriz resultante en resultado_strassen.txt.
Formato de Entrada: Cada fila de la matriz en una línea, con los elementos separados por espacios.
Formato de Salida: Cada fila de la matriz resultante en una línea, con los elementos separados por espacios.

Notas Adicionales:
Asegúrate de que los archivos de entrada estén en el formato correcto, como se describe en cada sección.
Para matrices grandes o listas, la ejecución puede tomar más tiempo.
Los resultados se sobrescribirán en los archivos de salida cada vez que ejecutes un programa.
Si no me equivoco, creo que todos los programas, al ejecutarlos, te dicen cuanto se demoro.
