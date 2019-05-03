//
// Created by manuel on 03/05/19.
//

#ifndef GLADIATORS_GLADIADOR_H
#define GLADIATORS_GLADIADOR_H
#include <iostream>

using namespace std;


class Gladiador {
private:
    string name;
    int edad;
    int probSupervivencia;
    int generaciones;
    int inteligenciaEmocional;
    int condFisica;
    int fuerzaSuperior;
    int fuerzaInferior;
    int x,y;

public:
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    string getName(){
        return name;
    }
    void setName(string name){
        Gladiador::name = name;

    }
    int getEdad(){
        return edad;
    }
    void setEdad(int edad){
        Gladiador::edad = edad;

    }
    int getprobSupervivencia(){
        return probSupervivencia;
    }
    void setprobSupervivencia(int x){
        Gladiador::probSupervivencia = x;

    }
    int getGeneraciones(){
        return generaciones;
    }
    void setGeneraciones(int x){
        Gladiador::generaciones = x;

    }
    void setX(int posx){
        Gladiador::x = posx;
    };
    void setY(int posy){
        Gladiador::y = posy;
    };
    int getinteligenciaEmocional(){
        return inteligenciaEmocional;
    }
    void setinteligenciaEmocional(int x){
        Gladiador::inteligenciaEmocional = x;

    }
    int getcondFisica(){
        return condFisica;
    }
    void setcondFisica(int x){
        Gladiador::condFisica = x;

    }
    int getfuerzaSuperior(){
        return fuerzaSuperior;
    }
    void setfuerzaSuperior(int x){
        Gladiador::fuerzaSuperior = x;

    }
    int getfuerzaInferior(){
        return fuerzaInferior;
    }
    void setfuerzaInferior(int x){
        Gladiador::fuerzaInferior = x;

    }

};

#endif //GLADIATORS_GLADIADOR_H
