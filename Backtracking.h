//
// Created by gerom on 14/05/19.
//

#ifndef GLADIATORS_BACKTRACKING_H
#define GLADIATORS_BACKTRACKING_H
#include <vector>
#include "list.h"
#include "list.cpp"



using namespace std;

class Backtracking{

private:

    List <int> listaAnteriores;
    List <int> listaBloqueados;

    int x = 0;
    int y = 0;

public:
    List<int> backtracking(List<int> listaTorres) {
        listaBloqueados.concat(listaTorres);
        while (y <= 10) {

            if (!listaBloqueados.searchPos(x, y)) {
                x++;
                y++;
                listaAnteriores.add_end(x);
                listaAnteriores.add_end(y);

            } else if (!listaBloqueados.searchPos(x + 1, y)) {
                x++;
                listaAnteriores.add_end(x + 1);
                listaAnteriores.add_end(y);

            } else if (!listaBloqueados.searchPos(x, y + 1)) {
                y++;
                listaAnteriores.add_end(x);
                listaAnteriores.add_end(y + 1);

            } else {
                listaBloqueados.add_end(x);
                listaBloqueados.add_end(y);


                y = listaAnteriores.search(listaAnteriores.size() - 1);
                x = listaAnteriores.search(listaAnteriores.size() - 2);

            }

        }
        return listaAnteriores;
    }








};
#endif //GLADIATORS_BACKTRACKING_H
