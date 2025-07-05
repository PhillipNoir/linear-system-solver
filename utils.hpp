/**
 * @file utils.cpp
 * @brief Modulacización de funciones que se repiten o pueden repetirse
 * 
 * Este archivo contiene la llamada de las funciones forwardElimination y backward elimination, las cuales, son usadas en los métodos
 * de solución de sistemas lineales implementados en este programa.
 */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "Matrix.hpp"

/**
 * @brief Realiza la eliminación hacia adelante (triangulación) del sistema Ax = b.
 *
 * Esta función aplica el método de eliminación de Gauss para convertir la matriz A
 * en una forma triangular superior, modificando también el vector columna b.
 * Detecta sistemas inconsistentes o numéricamente inestables.
 *
 * @param A Matriz de coeficientes (modificada en el proceso).
 * @param b Vector columna de términos independientes (modificado en el proceso).
 * @param mostrarPasos Si es verdadero, imprime cada paso si el sistema es pequeño (≤ 10 ecuaciones).
 *
 * @throws std::runtime_error Si el sistema es numéricamente inestable o inconsistente.
 */
void forwardElimination(Matrix& A, Matrix& b, bool mostrarPasos);

/**
 * @brief Realiza la eliminación hacia atrás y normalización de pivotes en la matriz A.
 *
 * Esta función convierte A en una matriz identidad (forma reducida por filas) mediante
 * eliminación hacia atrás y normalización de pivotes. Es el paso final del método de Gauss-Jordan.
 *
 * @param A Matriz de coeficientes (modificada).
 * @param b Vector columna de términos independientes (modificado).
 * @param mostrarPasos Si es verdadero, imprime los pasos si el sistema es pequeño.
 *
 * @throws std::runtime_error Si se detectan pivotes demasiado pequeños o inconsistencias numéricas.
 */
void backwardElimination(Matrix& A, Matrix& b, bool mostrarPasos);

/**
 * @brief Calcula la suma de los productos de los coeficientes por los valores de la solución, excluyendo el término diagonal.
 *
 * Esta función se utiliza en el método iterativo de Jacobi para calcular la suma de los productos
 * de los coeficientes por los valores de la solución, excluyendo el término diagonal.
 *
 * @param A Matriz de coeficientes del sistema.
 * @param vectorSolucion Vector solución actual.
 * @param i Índice de la fila actual.
 * @return double Suma de los productos excluyendo el término diagonal.
 */
double sumaSinDiagonal(Matrix& A, const std::vector<double>& vectorSolucion, int i);

/**
 * @brief Calcula el error entre dos vectores de solución.
 *
 * Esta función compara el vector de solución actual con el vector de solución anterior
 * para determinar la convergencia del método iterativo.
 *
 * @param vectorSolucion Vector solución actual.
 * @param vectorAnterior Vector solución del paso anterior.
 * @return double Error calculado como la norma L2 de la diferencia entre los dos vectores.
 */
double calcularError(const std::vector<double>& vectorSolucion, const std::vector<double>& vectorAnterior);

bool esDiagonalDominante(Matrix& A);
#endif