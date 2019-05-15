//
// Created by manuel on 03/05/19.
//

#ifndef GLADIATORS_OLEADA_H
#define GLADIATORS_OLEADA_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <zconf.h>
#include "Gladiador.h"
#include "Grid.h"

using namespace std;

class Oleada{
private:
    typedef pair<int, int> Pair;
    int random = rand() % 100;
    std::vector<Gladiador> oleada;

public:
    const vector<Gladiador> &getOleada() const {
        return oleada;
    }

///metodo que creaa la oleada de gladiadores que se le meta como parametro
    void crearOleada(int cantGladiadores){

        //while(cantGladiadores >0){
        Gladiador gladiador;
        for(int i=0;i<cantGladiadores;i++){
            gladiador.setName("Saico");//busca en la lista de nombres desordenados
            gladiador.setcondFisica(rand() % 100);
            gladiador.setEdad(rand() % 100);
            gladiador.setGeneraciones(rand() % 100);
            gladiador.setfuerzaInferior(rand() % 100);
            gladiador.setfuerzaSuperior(rand() % 100);
            gladiador.setprobSupervivencia(rand() % 100);
            gladiador.setinteligenciaEmocional(rand() % 100);

            gladiador.setInPosX(i);
            gladiador.setInPosY(i);
            gladiador.setOutPosX(19);
            gladiador.setOutPosY(19);

            oleada.push_back(gladiador);
        }


    }

    void empezarRecorrido(vector<Gladiador> gladiadoresTablero){ //debe recibir dos listas, una de gladiadores y otra de torres

        AStar pathfinding;


        for(int i=0;i<gladiadoresTablero.size();i++){
            cout<<"\n * GLADIADOR "<<i<<endl;
            Pair inicio = make_pair(gladiadoresTablero[i].getInPosY(), gladiadoresTablero[i].getInPosX());
            Pair fin = make_pair(gladiadoresTablero[i].getOutPosY(), gladiadoresTablero[i].getOutPosX());
            pathfinding.analizarCamino(inicio,fin);
            sleep(3);
            cout<<"\n \n";
        }
        cout<<"\n \n";
    }


///metodo que lee el archivo txt de los nombres y mete cada nombre dentro de una lista
    vector<string> crearListaNombres(){
        std::vector<string> listaordenada;
        string linea;
        int contador = 0;
        fstream archivo;
        archivo.open("Nombres.txt",ios::in); //se abre archivo en modo lectura
        if(archivo.fail()){
            cout<<"error al abrir archivo"<<endl;
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


#endif //GLADIATORS_OLEADA_H
