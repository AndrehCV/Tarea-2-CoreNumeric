//
// Created by Lenovo on 14/04/2026.
//
#include <iostream>
#include "CoreNumeric.h"

int main() {
    //CASOS QUE COMPILAN:
    auto s1 = core_numeric::sum_variadic(1, 2, 33, 4);
    auto s2 = core_numeric::mean_variadic(0.1, 2.0, 3.0, 4.0);
    auto s3 = core_numeric::variance_variadic(1.0, 2.0, 3.0, 4.0);
    auto s4 = core_numeric::max_variadic(1, 2.7, 3.0, 4.0);

    std::cout << "[test_variadic] Sum: " << s1 << "\n";
    std::cout << "[test_variadic] Mean: " << s2 << "\n";
    std::cout << "[test_variadic] Variance: " << s3 << "\n";
    std::cout << "[test_variadic] Max: " << s4 << "\n";

    //CASOS QUE NO COMPILAN:

    // auto err = core_numeric::sum_variadic(1, 2, "Hola");

    /**
     Falla por la incompatibilidad de tipos en el Fold Expression.
     No se puede aplicar el operador binario '+' entre un entero
     y un const char* ("Hola"). El compilador detecta el error
     al expandir los parámetros del template variádico.
     **/

    return 0;
}