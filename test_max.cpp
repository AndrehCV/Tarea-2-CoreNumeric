//
// Created by Lenovo on 14/04/2026.
//
#include <iostream>
#include <vector>
#include "CoreNumeric.h"

class Jugador {
public:
    int score;
    Jugador(int s) : score(s) {}
    // Sobrecarga para cumplir el concept Comparable
    bool operator>(const Jugador& o) const {
        return this->score > o.score;
    }
};

class Enemigo {
public:
    int hp;
    Enemigo(int h) : hp(h) {}
    // No tiene operator>
};

int main() {
    //CASO QUE COMPILA:
    std::vector<Jugador> jugadores = {Jugador(100), Jugador(250), Jugador(50)};
    auto max_jugador = core_numeric::max(jugadores);
    std::cout << "[test_max] Max Score Jugador: " << max_jugador.score << "\n";

    //CASOS QUE NO COMPILAN:

    // std::vector<Enemigo> enemigos = {Enemigo(100), Enemigo(200)};
    // auto err = core_numeric::max(enemigos);

    /**
     Falla el concept propio 'Comparable'. La función 'max' exige que
     los objetos iterados puedan compararse usando el operador '>'.
     La clase 'Enemigo' no proporciona dicha sobrecarga.
     **/

    return 0;
}