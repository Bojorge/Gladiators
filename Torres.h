//
// Created by gerom on 04/05/19.
//

#ifndef GLADIADOR_TORRES_H
#define GLADIADOR_TORRES_H
#include <iostream>

using namespace std;


class Torres {
public:

    string nombre;
    int danoInferior;
    int danoSuperior;
    int potencia;
    int tipobala;
    int fuerzalanzador;
    int velocidadlanzador;
    int altotorre;
    int dano = (danoInferior+danoSuperior+potencia+tipobala)/4;
    int alcance = (fuerzalanzador+velocidadlanzador+altotorre+tipobala)/4;
    int generaciones;

    int X;
    int Y;

    int getX() const {
        return X;
    }

    void setX(int x) {
        X = x;
    }

    int getY() const {
        return Y;
    }

    void setY(int y) {
        Y = y;
    }


public:
    const string getNombre() const {
        return nombre;
    }

    void setNombre(const string &nombre) {
        Torres::nombre = nombre;
    }

    int getGeneraciones() const {
        return generaciones;
    }

    void setGeneraciones(int generaciones) {
        Torres::generaciones = generaciones;
    }

    int getDanoInferior() const {
        return danoInferior;
    }

    void setDanoInferior(int danoInferior) {
        Torres::danoInferior = danoInferior;
    }

    int getDanoSuperior() const {
        return danoSuperior;
    }

    void setDanoSuperior(int danoSuperior) {
        Torres::danoSuperior = danoSuperior;
    }

    int getPotencia() const {
        return potencia;
    }

    void setPotencia(int potencia) {
        Torres::potencia = potencia;
    }

    int getTipobala() const {
        return tipobala;
    }

    void setTipobala(int tipobala) {
        Torres::tipobala = tipobala;
    }

    int getFuerzalanzador() const {
        return fuerzalanzador;
    }

    void setFuerzalanzador(int fuerzalanzador) {
        Torres::fuerzalanzador = fuerzalanzador;
    }

    int getVelocidadlanzador() const {
        return velocidadlanzador;
    }

    void setVelocidadlanzador(int velocidadlanzador) {
        Torres::velocidadlanzador = velocidadlanzador;
    }

    int getAltotorre() const {
        return altotorre;
    }

    void setAltotorre(int altotorre) {
        Torres::altotorre = altotorre;
    }

    int getDano() const {
        return dano;
    }

    void setDano(int dano) {
        Torres::dano = dano;
    }

    int getAlcance() const {
        return alcance;
    }

    void setAlcance(int alcance) {
        Torres::alcance = alcance;
    }

};


#endif //GLADIADOR_TORRES_H
