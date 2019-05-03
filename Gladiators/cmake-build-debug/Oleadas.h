//
// Created by gerom on 25/04/19.
//

#ifndef GLADIADOR_OLEADAS_H
#define GLADIADOR_OLEADAS_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include "Gladiador.h"

using namespace std;

class Oleadas{
    int random = rand() % 100;
    std::vector<Gladiador> oleada;



///metodo que creaa la oleada de gladiadores que se le meta como parametro
    void crearOleada(int cantGladiadores){
        int ind;
        while(cantGladiadores >0){
            Gladiador gladiador;
            gladiador.setName(desordenarListaNombres(crearListaNombres()).at(ind));//busca en la lista de nombres desordenados
            gladiador.setcondFisica(rand() % 100);
            gladiador.setEdad(rand() % 100);
            gladiador.setGeneraciones(rand() % 100);
            gladiador.setfuerzaInferior(rand() % 100);
            gladiador.setfuerzaSuperior(rand() % 100);
            gladiador.setprobSupervivencia(rand() % 100);
            gladiador.setinteligenciaEmocional(rand() % 100);
            oleada.push_back(gladiador);
            ind++;
            cantGladiadores--;

        }

    }

///metodo que lee el archivo txt de los nombres y mete cada nombre dentro de una lista
    vector<string> crearListaNombres(){
        std::vector<string> listaordenada;
        string linea;
        int contador = 0;
        fstream archivo;
        archivo.open("Nombres.txt",ios::in); //se abre archivo en modo lectura
        if(archivo.fail()){
            cout<<"error al abrir archivo">>;
            exit(1);
        }
        while(!archivo.eof()){
            getline(archivo,linea);
            listaordenada.push_back(linea);

        }
        return listaordenada;

    }

///metodo que agarra la lista con los nombres ordenados y los desordena en forma aleatoria
    vector<string> desordenarListaNombres(vector<string> listaordenada){

        std::vector<string> listadesordenada;
        while(!listaordenada.size()>0){
            int random = rand() % 455;
            int value = random;
            listadesordenada.push_back(listaordenada.at(value));
            listaordenada.erase(listaordenada.begin()+value);

        }

        listadesordenada.push_back(listaordenada.at(random));




        return listadesordenada;






    }










};





#endif //GLADIADOR_OLEADAS_H
