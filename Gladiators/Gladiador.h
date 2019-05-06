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

    int inPosX;
    int inPosY;
    int outPosX;
    int outPosY;


public:
    int getInPosX() const {
        return inPosX;
    }

    void setInPosX(int inPosX) {
        Gladiador::inPosX = inPosX;
    }

    int getInPosY() const {
        return inPosY;
    }

    void setInPosY(int inPosY) {
        Gladiador::inPosY = inPosY;
    }

    int getOutPosX() const {
        return outPosX;
    }

    void setOutPosX(int outPosX) {
        Gladiador::outPosX = outPosX;
    }

    int getOutPosY() const {
        return outPosY;
    }

    void setOutPosY(int outPosY) {
        Gladiador::outPosY = outPosY;
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
