/**
 * @file menu.cpp
 * @brief Muestra el menú principal del programa y gestiona la interacción con el usuario.
 * 
 * Permite al usuario resolver sistemas de ecuaciones lineales utilizando los métodos de:
 * - Eliminación de Gauss
 * - Eliminación de Gauss-Jordan
 * 
 * El usuario puede:
 * - Ingresar el tamaño del sistema
 * - Proporcionar los coeficientes (matriz A) y el vector independiente (b)
 * - Elegir si desea ver los pasos intermedios de la solución
 * - Ver el resultado del sistema resuelto
 * - Salir del programa
 * 
 * La función se ejecuta en un bucle hasta que el usuario selecciona la opción de salir.
 */
#include "Matrix.hpp"
#include "Methods.hpp"
#include <iostream>
#include <iomanip>
#include "menu.hpp"
#include "validations.hpp"
#include <string>

void menuPrincipal(){
    int opcion {0};
    bool continuar {true};

    std::cout<<"¡Bienvenido al resolvedor de sistemas de ecuaciones lineales!\n";
    
    int size{0};
    bool mostrarPasos{true};

    //Este bucle muestra el menú principal tras cada iteración hasta que el usuario indique que desea salir.
    while (continuar)
    {
        std::cout<<"\nPor favor, elija el método por el cual desea resolver su sistema de ecuaciones lineales o selecciona la opción 'Salir' para terminar el programa: \n";
        std::cout << "\n1. Método de Gauss\n";
        std::cout << "2. Método de Gauss-Jordan\n";
        std::cout << "3. Método de Jacobi\n";
        std::cout << "4. Método de Gauss-Seidel\n";
        std::cout << "5. Salir\n";
        opcion = leerEntero("Su elección: ");
        //Si el usuario ingresa un decimal en una entrada para entero, solo se toma la parte entera de esa entrada, es importante avisar de esto al usuario.
        std::cout << "Entrada registrada como " << opcion << " (cualquier parte decimal fue ignorada en caso de haber sido ingresada).\n";

        switch (opcion)
        {
        case 1: {
            std::cout << "Advertencia: Este método es exacto, no se recomienda para sistemas grandes en equipos de bajos recursos debido al costo computacional, se recomienda utilizar el método de Jacobi o Gauss-Seidel en su lugar para sistemas grandes.\n";
            size = leerEntero("\nIngrese el tamaño de la matriz: ");
            std::cout << "Entrada registrada como " << size << " (cualquier parte decimal fue ignorada en caso de haber sido ingresada).\n";
            //Se inicializan los objetos A y b, ambos del tipo matrix
            Matrix A(size, size);
            Matrix b (size, 1);
            std::cout << "\nIngrese la matriz A:\n";
            A.fillMatrix();
            std::cout << "\nIngrese el vector b:\n";
            b.fillMatrix();
            //Se muestra  al usuario el sistema que ingresó para validación
            std::cout<<"\n Usted ha ingresado el siguiente sistema: \n";
            imprimirSistema(A, b);
            //Se usa una entrada booleana para saber si el usuario desea conocer los pasos o únicamente la solución
            mostrarPasos = leerBooleano("\n¿Desea ver los pasos de la solución? (Y:1/N:0)\n");
            std::vector<double> solution = gaussElimination(A, b, mostrarPasos);
            advertenciaSistemaGrande(size);
            std::cout << "Solución:\n";
    
            //Se imprime la solución al sistema.
            for (double val : solution) {
                std::cout << std::setw(10) << val << " ";
            }
            std::cout<<"\n";
            break;
        }
        case 2: {
            std::cout << "Advertencia: Este método es exacto, no se recomienda para sistemas grandes en equipos de bajos recursos debido al costo computacional, se recomienda utilizar el método de Jacobi o Gauss-Seidel en su lugar para sistemas grandes.\n";
            size = leerEntero("\nIngrese el tamaño de la matriz: ");
            std::cout << "Entrada registrada como " << size << " (cualquier parte decimal fue ignorada en caso de haber sido ingresada).\n";
            //Se inicializan los ojetos A y b del tipo Matix
            Matrix A(size, size);
            Matrix b (size, 1);
            std::cout << "\nIngrese la matriz A:\n";
            A.fillMatrix();
            std::cout << "\nIngrese el vector b:\n";
            b.fillMatrix();
            //Se muestra al usuario el sistema que ingresó para validación.
            std::cout<<"\n Usted ha ingresado el siguiente sistema: \n";
            imprimirSistema(A, b);
            //Se usa una entrada booleana para saber si el usuario desea conocer los pasos de la solución
            mostrarPasos = leerBooleano("\n¿Desea ver los pasos de la solución? (Y:1/N:0)\n");
            std::vector<double> solution = gaussJordanElimination(A, b, mostrarPasos);
            advertenciaSistemaGrande(size);
            //Se imprime la solución
            std::cout << "Solución:\n";
    
            for (double val : solution) {
                std::cout << std::setw(10) << val << " ";
            }
            std::cout<<"\n";
            break;
        }
        case 3: {
            std::cout << "Advertencia: Este método es iterativo, se recomienda para sistemas grandes en equipos de bajos recursos.\n";
            size = leerEntero("\nIngrese el tamaño de la matriz: ");
            std::cout << "Entrada registrada como " << size << " (cualquier parte decimal fue ignorada en caso de haber sido ingresada).\n";
            //Se inicializan los objetos A y b del tipo Matrix
            Matrix A(size, size);
            Matrix b (size, 1);
            std::cout << "\nIngrese la matriz A:\n";
            A.fillMatrix();
            std::cout << "\nIngrese el vector b:\n";
            b.fillMatrix();

            //Se muestra al usuario el sistema que ingresó para validación.
            std::cout<<"\n Usted ha ingresado el siguiente sistema: \n";
            imprimirSistema(A, b);
            std::vector<double> solution = jacobiMethod(A, b);
            //Se imprime la solución
            std::cout << "Solución:\n";
    
            for (double val : solution) {
                std::cout << std::setw(10) << val << " ";
            }
            std::cout<<"\n";
            break;
        }
        case 4: {
            std::cout << "Advertencia: Este método es iterativo, se recomienda para sistemas grandes en equipos de bajos recursos.\n";
            size = leerEntero("\nIngrese el tamaño de la matriz: ");
            std::cout << "Entrada registrada como " << size << " (cualquier parte decimal fue ignorada en caso de haber sido ingresada).\n";
            //Se inicializan los objetos A y b del tipo Matrix
            Matrix A(size, size);
            Matrix b (size, 1);
            std::cout << "\nIngrese la matriz A:\n";
            A.fillMatrix();
            std::cout << "\nIngrese el vector b:\n";
            b.fillMatrix();

            //Se muestra al usuario el sistema que ingresó para validación.
            std::cout<<"\n Usted ha ingresado el siguiente sistema: \n";
            imprimirSistema(A, b);
            std::vector<double> solution = gaussSeidelMethod(A, b);
            //Se imprime la solución
            std::cout << "Solución:\n";
    
            for (double val : solution) {
                std::cout << std::setw(10) << val << " ";
            }
            std::cout<<"\n";
            break;
        }
        //Termina el programa si elige la opción 5.
        case 5:
            continuar = false;
            break;
        //Caso default por si el usuario ingresa una entrada no contemplada.
        default:
            std::cout << "Opción inválida.\n";
            break;
        }
    }
    
}