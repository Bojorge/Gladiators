#include "AStar.h"
#include "Oleada.h"
#include "Backtracking.h"

int main()
{
    //Backtracking bt;
    //bt.solveKT();

    Oleada oleada;
    oleada.crearOleada(7);

    cout<<"\n \n";

    oleada.empezarRecorrido(oleada.getOleada());




    return(0);
}
