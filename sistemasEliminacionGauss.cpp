/**
 * @mainpage Sistema de solución de sistemas de n ecuaciones
 * @brief Sistema que resuelve un sistema de ecuaciones dado por el usuario
 * 
 * @section features_sec Características Principales
 * - Llenado manual del sistema, lo que permite una personalización total para el problema que desee el usuario
 * - Uso de arreglos dinámicos para la creación y manipulación de matrices, lo que permite correr el programa en cualquier equipo
 * - Elección del método libre para el usuario
 * - Interfaz de menú intuitiva
 * 
 * @section usage_sec Modo de Uso
 * 1. Ejecutar el programa
 * 2. Llenar la matriz
 * 3. Seleccionar el método de resolución
 * 4. Se retorna la matriz de resultado
 * 
 * @author Sergio Felipe Gonzalez Cruz
 * @date Junio 2025
 * @version 0.0.1
 */

#include <iostream>
#include <iomanip>
#include <memory>

/**
 * @brief Estructura para manejar matrices dinámicas con memoria segura.
 * 
 * Esta clase permite crear, llenar y visualizar matrices de tamaño arbitrario
 * utilizando `std::unique_ptr` para el manejo automático de memoria.
 */
struct Matrix {
    int rows, cols;
    std::unique_ptr<std::unique_ptr<double[]>[]> matriz;


    /**
     * @brief Constructor de la matriz.
     * 
     * @param r Número de filas.
     * @param c Número de columnas.
     */
    Matrix(int r, int c) : rows(r), cols(c){
        matriz = std::make_unique<std::unique_ptr<double[]>[]>(rows);
        for (size_t i = 0; i < rows; i++)
        {
            matriz[i] = std::make_unique<double[]>(cols);
        }
        
    }

    /**
     * @brief Accede al elemento en la posición (fila, columna).
     * 
     * @param fila Índice de la fila.
     * @param col Índice de la columna.
     * @return Referencia al valor en la posición indicada.
     * @throws std::out_of_range Si los índices están fuera de los límites.
     */
    double& at(int fila, int col) {
    if (fila < 0 || fila >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Índices fuera de rango");
    }
    else{
        return matriz[fila][col];
    }
    }

    /**
     * @brief Solicita al usuario ingresar todos los elementos de la matriz.
     * 
     * Pide los datos fila por fila.
     */
    void fillMatrix(){
        std::cout<<"Ingrese los " << rows*cols <<" elementos de la matriz: \n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout<<"Ingrese el elemento (" <<i<<","<<j<<"): \n";
                std::cin>>matriz[i][j];
            }
            
        }
        
    }

    /**
     * @brief Imprime la matriz en formato tabular con alineación.
     * 
     * Usa `std::setw(10)` para alinear columnas visualmente.
     */
    void print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << std::setw(10) << matriz[i][j] << " ";
        }
        std::cout << '\n';
    }
    }
}
