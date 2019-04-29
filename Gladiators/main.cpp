#include "AStar.h"

int main()
{
    typedef pair<int, int> Pair;
    AStar pathfinding;
    /* Descripcion de la cuadricula
    1--> La celda esta habilitada
    0--> La celda esta bloqueada */
    int grid[FILA][COLUMNA] =
            {
                    { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                    { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
                    { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                    { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
                    { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                    { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                    { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
                    { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                    { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
            };

    // Source is the left-most bottom-most corner
    Pair inicio = make_pair(8, 0);

    // Destination is the left-most top-most corner
    Pair destino = make_pair(0, 0);

    pathfinding.aStarSearch(grid, inicio, destino);

    return(0);
}
