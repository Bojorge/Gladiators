//
// Created by manuel on 17/05/19.
//

#ifndef GLADIATORS_BACKTRACK_H
#define GLADIATORS_BACKTRACK_H


#include <iostream>
#include <zconf.h>
#include "Lista.h"

using namespace std;

class BackTrack{
    Lista camino;
    Lista backtrack;
    int inicioX=0;
    int inicioY=0;
    int finalX=19;
    int finalY=19;
    int actualX=inicioX;
    int actualY=inicioY;

    // habilitado = 0
    // bloqueado =1



public:
    Lista backTracking(int grid[20][20]){

        camino.anadir_final(actualX);
        camino.anadir_final(actualY);
        backtrack.anadir_final(actualX);
        backtrack.anadir_final(actualY);

        while(actualY != finalY && actualX != finalX) {
            if (grid[actualY + 1][actualX + 1] == 0) {
                actualX += 1;
                actualY += 1;
                camino.anadir_final(actualX);
                camino.anadir_final(actualY);
                backtrack.anadir_final(actualX);
                backtrack.anadir_final(actualY);
                cout << "se mueve en diagonal \n";
                sleep(1);
            } else if (grid[actualY][actualX + 1] == 0) {
                actualX += 1;
                camino.anadir_final(actualX);
                camino.anadir_final(actualY);
                backtrack.anadir_final(actualX);
                backtrack.anadir_final(actualY);
                cout << "se mueve hacia la derecha \n";
                sleep(1);
            } else if (grid[actualY + 1][actualX] == 0) {
                actualY += 1;
                camino.anadir_final(actualX);
                camino.anadir_final(actualY);
                backtrack.anadir_final(actualX);
                backtrack.anadir_final(actualY);
                cout << "se mueve hacia abajo \n";
                sleep(1);
            }
            else{
                actualX=backtrack.obtener_dato(backtrack.tamano()-4);
                actualY=backtrack.obtener_dato(backtrack.tamano()-3);

                camino.anadir_final(actualX);
                camino.anadir_final(actualY);

                grid[backtrack.obtener_dato(backtrack.tamano()-1)][backtrack.obtener_dato(backtrack.tamano()-2)]=1;

                backtrack.borrar_Dato((backtrack.tamano()-1));
                backtrack.borrar_Dato((backtrack.tamano()-1));

                cout << "se devuelve porque el camino esta bloqueado \n";
                sleep(1);

            }


        }
        cout << "\n***  El gladiador llego a su destino  ***\n";
        camino.print_lista();
        return camino;


    }
};

#endif //GLADIATORS_BACKTRACK_H
