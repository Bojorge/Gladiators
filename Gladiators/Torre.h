//
// Created by manuel on 03/05/19.
//

#ifndef GLADIATORS_TORRE_H
#define GLADIATORS_

#include "string"
using namespace std;

class Torre {
    string tipo;
    int ataque;
    int alcance;

    int aumentarAtaque(int actual){
        ataque = actual+7;
    }

    int aumentarAlcance(int actual){
        alcance = actual+2;
    }

};


#endif //GLADIATORS_TORRE_H
