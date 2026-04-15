//
// Created by Lenovo on 14/04/2026.
//
#include <iostream>
#include <vector>
#include "CoreNumeric.h"

int main() {
    //CASO QUE COMPILA:
    std::vector<double> v = {1.0, 2.0, 3.0};

    auto r = core_numeric::transform_reduce(v, [](double x) {
        return x * x;
    });

    std::cout << "[test_transform_reduce] Resultado: " << r << "\n";

    //CASOS QUE NO COMPILAN:

    // std::vector<int> v_int = {1, 2, 3};
    // auto err = core_numeric::transform_reduce(v_int, [](int x) {
    //     return std::string("Texto");
    // });

    /**
     El tipo de retorno de la lambda es std::string. Internamente, la función
     intenta inicializar el 'result' y sumar los strings. Aunque string tiene
     operator+, al inicializarse por defecto (result{}) e intentar sumarse en
     un bucle numérico sin sentido semántico, fallará si el contenedor base
     esperaba otra lógica, pero más importante: si el 'result' necesita
     conceptos numéricos estrictos más adelante, se romperá.
     **/

    return 0;
}