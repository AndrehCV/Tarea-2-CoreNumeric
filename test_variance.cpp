//
// Created by Lenovo on 14/04/2026.
//
#include <iostream>
#include <vector>
#include "CoreNumeric.h"

// Clase de prueba
class Esfera {
public:
    double radio;
    Esfera() : radio(0.0) {}
    Esfera(double r) : radio(r) {}

    Esfera operator+(const Esfera& o) const { return Esfera(radio + o.radio); }
    Esfera operator-(const Esfera& o) const { return Esfera(radio - o.radio); }
    Esfera operator*(const Esfera& o) const { return Esfera(radio * o.radio); }
    Esfera operator/(std::size_t n) const { return Esfera(radio / n); }
};

class Coordenada {
public:
    int x, y;
    Coordenada(int cx, int cy) : x(cx), y(cy) {}
    // Faltan operadores matemáticos
};

int main() {
    //CASO QUE COMPILA:
    std::vector<Esfera> esferas = {Esfera(2.0), Esfera(4.0), Esfera(6.0)};
    auto var_esferas = core_numeric::variance(esferas);
    std::cout << "[test_variance] Varianza de Esferas (Radio): " << var_esferas.radio << "\n";

    //CASOS QUE NO COMPILAN

    // std::vector<Coordenada> coords = {Coordenada(1,2), Coordenada(3,4)};
    // auto err = core_numeric::variance(coords);

    /**
     Falla el concept 'Addable' y 'Divisible'. La clase Coordenada no tiene
     sobrecargado el operator+ ni el operator/, por lo que no cumple
     las restricciones de compilación requeridas por 'variance' y 'mean'.
     **/

    return 0;
}