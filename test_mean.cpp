//
// Created by Lenovo on 14/04/2026.
//
#include <iostream>
#include <vector>
#include <string>
#include "CoreNumeric.h"

int main() {
    //CASO QUE COMPILA
    std::vector<double> v_double = {1.5, 2.5, 3.5};
    auto m = core_numeric::mean(v_double);
    std::cout << "[test_mean] Media (double): " << m << "\n";

    //CASOS QUE NO COMPILAN:

    // std::vector<std::string> v_strings = {"Hola", "C++"};
    // auto err = core_numeric::mean(v_strings);

    /**
     * El concept 'Divisible' falla. std::string permite la suma (operator+)
     por lo que pasa 'Addable', pero no tiene definido el operador de
     división entre un size_t (operator/).
     **/

    return 0;
}