/**
 * @file validations.cpp
 * @brief Implenmentación de diferentes validaciones para mejorar la robustez y estabilidad del programa.
 * 
 * Este archivo contiene la declaración de 3 funciones quue evitan que el usuario ingrese entradas incorrectas para el tipo de dato 
 * esperado y una para lanzar una advertencia en caso de que el usuario ingrese un sistema cuya magnitud comprometa la estabilidad
 * del sistema si se muestran los pasos.
 */
#include "Matrix.hpp"
#include "Methods.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include "menu.hpp"
#include <limits>

/**
 * @brief Muestra una advertencia si el sistema de ecuaciones es muy grande.
 *
 * Si el número de ecuaciones es mayor o igual a 11, no mostrará pasos
 * para evitar sobrecargar la salida en consola.
 *
 * @param size Número de ecuaciones del sistema.
 */
void advertenciaSistemaGrande(int size){
    bool mostrarPasos = size<11;
    if (mostrarPasos == false)
    {
        std::cout << "Aviso: El sistema tiene muchas ecuaciones. Para evitar sobrecargar la consola, solo se mostrará la solución final.\n";
    }
    
}

/**
 * @brief Solicita y valida la entrada de un número entero desde consola.
 *
 * La función seguirá solicitando al usuario hasta que se ingrese un valor entero válido.
 *
 * @param mensaje Mensaje que se muestra al usuario para solicitar la entrada.
 * @return Un número entero ingresado correctamente.
 */
int leerEntero(const std::string& mensaje) {
    int valor;
    while (true) {
        std::cout << mensaje;
        std::cin >> valor;

        if (std::cin.fail()) {
            std::cin.clear(); // Limpia el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada incorrecta
            std::cout << "Entrada inválida. Por favor ingresa un número entero.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta cualquier resto
            return valor;
        }
    }
}

/**
 * @brief Solicita y valida la entrada de un número decimal (double) desde consola.
 *
 * La función seguirá solicitando al usuario hasta que se ingrese un valor decimal válido.
 *
 * @param mensaje Mensaje que se muestra al usuario para solicitar la entrada.
 * @return Un número decimal ingresado correctamente.
 */
double leerDecimal(const std::string& mensaje) {
    double valor;
    while (true) {
        std::cout << mensaje;
        std::cin >> valor;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Por favor ingresa un número.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }
    }
}

/**
 * @brief Solicita al usuario una entrada booleana (1 o 0) y la valida.
 *
 * Esta función valida que el usuario ingrese 1 (true) o 0 (false). Repite la solicitud hasta obtener una entrada válida.
 *
 * @param mensaje Mensaje que se muestra al usuario para solicitar la entrada.
 * @return true si el usuario ingresa 1, false si ingresa 0.
 */
bool leerBooleano(const std::string& mensaje) {
    int entrada;
    while (true) {
        std::cout << mensaje;
        std::cin >> entrada;

        if (std::cin.fail() || (entrada != 0 && entrada != 1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Ingresa 1 para Sí o 0 para No.\n";
        } else {
            return entrada;
        }
    }
}
