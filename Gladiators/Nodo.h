//
// Created by manuel on 14/05/19.
//

#ifndef GLADIATORS_NODO_H
#define GLADIATORS_NODO_H


/// Clase necesaria para que lla clase lista funcione
class Nodo {

public: Nodo* siguiente;
public: int Dato;


    Nodo (int dato){
        Dato = dato;
        siguiente = NULL;
    }
};


#endif //GLADIATORS_NODO_H
