/**
 * @file Methods.cpp
 * @brief Implementación de diferentes métodos numéricos para resolver sistemas de ecuaciones lineales.
 * 
 * @section features_sec Características principales.
 * -Método de eliminación de Gauss.
 * -Método de Gauss-Jordan.
 * 
 */
#include "Methods.hpp"
#include "Matrix.hpp"
#include <vector>
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "utils.hpp"

/**
 * @brief Imprime el sistema de ecuaciones lineales en forma matricial.
 *
 * Esta función muestra en consola la matriz de coeficientes `A` y el vector de constantes `b` 
 * en forma de sistema ampliado (matriz aumentada), alineando los valores para mayor legibilidad.
 * 
 * Por ejemplo, imprime una salida como esta:
 * @code
 *        2         -1         3 |         9
 *        1          0        -2 |         3
 * @endcode
 *
 * @param A Matriz de coeficientes del sistema de ecuaciones (tipo Matrix).
 * @param b Vector columna con los términos independientes (tipo Matrix).
 */
void imprimirSistema(Matrix& A, Matrix& b) {
    int rows = A.getRows();
    int cols = A.getCols();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(10) << A.at(i, j) << " ";
        }
        std::cout << "| " << std::setw(10) << b.at(i, 0) << std::endl;
    }
    std::cout << std::endl;
}


/**
 * @brief Resuelve un sistema de ecuaciones lineales mediante el método de eliminación de Gauss con pivoteo parcial.
 * 
 * Este método transforma la matriz A en una matriz triangular superior utilizando eliminación hacia adelante,
 * luego resuelve el sistema triangular resultante mediante sustitución regresiva.
 * 
 * @param A Matriz de coeficientes del sistema (modificada durante la ejecución).
 * @param b Vector columna de términos independientes (modificado durante la ejecución).
 * @return std::vector<double> Vector solución del sistema.
 * 
 * @throw std::runtime_error Si el sistema no tiene solución única (pivote cero en la diagonal).
 */
std::vector<double> gaussElimination(Matrix& A, Matrix& b, bool mostrarPasos) {
    forwardElimination(A, b, mostrarPasos);

    // Sustitución regresiva
    int numEcuations = A.getRows();
    std::vector<double> vectorSolucion(numEcuations);
    const double TOLERANCIA = 1e-12;

    for (int row = numEcuations - 1; row >= 0; row--) {
        //Suma de los elementos ya conocidos
        double sum {0.0};
        //Este ciclo se activa si columna es menor al numero de ecuaciones, lo que nos dice que hay valor a la derecha
        for (int col = row + 1; col < numEcuations; col++) {
            //Se suma la multiplicación del coeficiente por el valor que ya conocemos, lo hace para todos los valores ya conocidos
            sum += A.at(row, col) * vectorSolucion[col];
        }
        
        double denom = A.at(row, row);
        
        //Envía un mensaje de error donde ocurre una división por cero durante la sustitución regresiva para evitar bugs o que el programa se rompa.
        if (std::abs(denom) < TOLERANCIA) {
            throw std::runtime_error("División por cero o sistema mal condicionado en sustitución regresiva.");
        }

        //Despeja la variable desconocida pasando la suma como resta y el coeficiente como cosciente para resolver la incógnita y almacena el resultado en el último espacio libre del vector para que se acomoden de forma ordenada
        vectorSolucion[row] = (b.at(row, 0) - sum) / A.at(row, row);
    }
    //Retorna el vector solución
    return vectorSolucion;

}

/**
 * @brief Resuelve un sistema de ecuaciones lineales mediante el método de eliminación de Gauss-Jordan con pivoteo parcial.
 * 
 * Este método transforma la matriz A en una matriz diagonal utilizando eliminación hacia adelante y atrás,
 * lo que nos entrega el vector solución de forma directa.
 * 
 * @param A Matriz de coeficientes del sistema (modificada durante la ejecución).
 * @param b Vector columna de términos independientes (modificado durante la ejecución).
 * @return std::vector<double> Vector solución del sistema.
 * 
 * @throw std::runtime_error Si el sistema no tiene solución única (pivote cero en la diagonal).
 */
std::vector<double> gaussJordanElimination(Matrix& A, Matrix& b, bool mostrarPasos){
    forwardElimination(A, b, mostrarPasos);

    backwardElimination(A, b, mostrarPasos);

    int numEcuations = A.getRows();
    const double TOLERANCIA = 1e-10;

    for (int row = 0; row < numEcuations; row++) {
        for (int col = 0; col < numEcuations; col++) {
            if ((row == col && std::abs(A.at(row, col) - 1.0) > TOLERANCIA) || (row != col && std::abs(A.at(row, col)) > TOLERANCIA)) {
                throw std::runtime_error("La matriz no se redujo completamente a la identidad. El sistema puede estar mal condicionado.");
            }
        }
    }

    //Guardado del vector solución
    std::vector<double> vectorSolucion(numEcuations);
    for (int sol = 0; sol < numEcuations; sol++)
    {
        vectorSolucion[sol] = b.at (sol, 0);
    }
    
    return vectorSolucion;
}
/**
 * @brief Resuelve un sistema de ecuaciones lineales mediante el método iterativo de Jacobi.
 * 
 * Este método es adecuado para sistemas grandes y se basa en la convergencia de las iteraciones.
 * 
 * @param A Matriz de coeficientes del sistema.
 * @param b Vector columna de términos independientes.
 * @return std::vector<double> Vector solución del sistema.
 */
std::vector<double> jacobiMethod(Matrix& A, Matrix& b) {
    int numEcuations = A.getRows();
    //Inicialización de los vectores solución y solución anterior
    //El vector solución se inicializa con ceros y el vector solución anterior también se inicializa con ceros
    std::vector<double> vectorSolucion(numEcuations, 0.0);
    std::vector<double> vectorSolucionAnterior(numEcuations, 0.0);
    //Constantes para el método iterativo
    const double TOLERANCIA = 1e-6;
    const int MAX_ITERACIONES = 500;

    for(size_t iteracion = 0; iteracion < MAX_ITERACIONES; iteracion++) {
        for (int row = 0; row < numEcuations; row++) {
            double sum = sumaSinDiagonal(A, vectorSolucionAnterior, row);
            //Suma de los elementos ya conocidos
            vectorSolucionAnterior[row] = b.at(row, 0) - sum / A.at(row, row);
        }
        double maxError = calcularError(vectorSolucion, vectorSolucionAnterior);
        vectorSolucion = vectorSolucionAnterior; // Actualiza la solución actual con la anterior
        if (maxError < TOLERANCIA) {
            break; // Si el error máximo es menor que la tolerancia, se considera convergido
        }
    }

    return vectorSolucion;
}
/**
 * @brief Resuelve un sistema de ecuaciones lineales mediante el método iterativo de Gauss-Seidel.
 * 
 * Este método es adecuado para sistemas grandes y se basa en la convergencia de las iteraciones.
 * 
 * @param A Matriz de coeficientes del sistema.
 * @param b Vector columna de términos independientes.
 * @return std::vector<double> Vector solución del sistema.
 */
std::vector<double> gaussSeidelMethod(Matrix& A, Matrix& b) {
    int numEcuations = A.getRows();
    //El vector solución se inicializa con ceros
    std::vector<double> vectorSolucion(numEcuations, 0.0);
    //Constantes para el método iterativo
    const double TOLERANCIA = 1e-6; 
    const int MAX_ITERACIONES = 500;
    for (size_t iteracion = 0; iteracion < MAX_ITERACIONES; iteracion++)
    {
        std::vector<double> vectorSolucionAnterior = vectorSolucion; // Guarda la solución anterior
        for (int row = 0; row < numEcuations; row++) {
            double sum = sumaSinDiagonal(A, vectorSolucion, row);
            //Suma de los elementos ya conocidos
            vectorSolucion[row] = (b.at(row, 0) - sum) / A.at(row, row);
        }
        double maxError = calcularError(vectorSolucion, vectorSolucionAnterior);
        if (maxError < TOLERANCIA) {
            break; // Si el error máximo es menor que la tolerancia, se considera convergido
        }
    }
    
    return vectorSolucion;
}