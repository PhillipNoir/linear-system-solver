/**
 * @file Methods.h
 * @brief Declaración del método para resolver sistemas de ecuaciones lineales mediante eliminación de Gauss y Gauss-Jordan.
 * 
 * Este archivo contiene la declaración de la función `gaussElimination`, que implementa el algoritmo
 * de eliminación de Gauss con pivoteo parcial para resolver sistemas de ecuaciones lineales Ax = b y la función 'gaussJordanElimination' 
 * que impplementa el algoritmo de eliminación de Gauss-Jordan.
 * 
 */
#ifndef METHODS_HPP
#define METHODS_HPP

#include "Matrix.hpp"
#include <vector>

/**
 * @brief Resuelve un sistema de ecuaciones lineales mediante el método de eliminación de Gauss con pivoteo parcial.
 * 
 * Esta función transforma la matriz A en una matriz triangular superior y luego resuelve el sistema mediante 
 * sustitución regresiva. Tanto la matriz A como el vector b se modifican en el proceso.
 * 
 * @param A Matriz cuadrada de coeficientes del sistema (modificada durante la ejecución).
 * @param b Vector columna de términos independientes (modificado durante la ejecución).
 * @param mostrarPasos Indica si el usuario desea conocer los pasos de la solución al sistema.
 * @return std::vector<double> Vector solución del sistema.
 * 
 * @throw std::runtime_error Si el sistema no tiene solución única o puede estar mal condicionado.
 */
std::vector<double> gaussElimination(Matrix& A, Matrix& b, bool mostrarPasos);

/**
 * @brief Resuelve un sistema de ecuaciones lineales mediante el método de Gauss-Jordan.
 * 
 * Esta función transforma la matriz A en una matriz triangular superior para después convertirla en una matriz identidad
 * obteniendo directamente el valor de cada una de las variables del sistema
 * 
 * @param A Matriz cuadrada de coeficientes del sistema (modificada durante la ejecución)
 * @param b Vector columna de términos independientes (modificado durante la ejecución)
 * @param mostrarPasos Indica si el usuario desea conocer los pasos de la solución al sistema
 * @return ** std::vector<double> 
 * 
 * @throw std::runtime_error Si el sistema no tiene solución unica o puede estar mal condicionado.
 */
std::vector<double> gaussJordanElimination(Matrix& A, Matrix&b, bool mostrarPasos);

/**
 * @brief Resuelve un sistema de ecuaciones lineales mediante el método de Jacobi.
 * 
 * Esta función implementa el método iterativo de Jacobi para resolver sistemas de ecuaciones lineales.
 * El método es adecuado para sistemas grandes y se basa en la convergencia de las iteraciones.
 * 
 * @param A Matriz cuadrada de coeficientes del sistema.
 * @param b Vector columna de términos independientes.
 * @return std::vector<double> Vector solución del sistema.
 */
std::vector<double> jacobiMethod(Matrix& A, Matrix& b);

/**
 * @brief Resuelve un sistema de ecuaciones lineales mediante el método de Gauss-Seidel.
 * 
 * Esta función implementa el método iterativo de Gauss-Seidel para resolver sistemas de ecuaciones lineales.
 * El método es adecuado para sistemas grandes y se basa en la convergencia de las iteraciones.
 * 
 * @param A Matriz cuadrada de coeficientes del sistema.
 * @param b Vector columna de términos independientes.
 * @return std::vector<double> Vector solución del sistema.
 */
std::vector<double> gaussSeidelMethod(Matrix& A, Matrix& b);

/**
 * @brief Imprime un sistema de ecuaciones lineales en forma matricial.
 * 
 * Esta funcion muestra en consola la matriz de coeficientes 'A' y el vector de constantes 'b'
 * en forma de sistema ampliado (matriz aumentada), alineando los valores para mayor legibilidad.
 * 
 * @param A Matriz cuadrada de coeficientes del sistema
 * @param b Vector columna de términos independientes.
 */
void imprimirSistema(Matrix& A, Matrix& b);

#endif
