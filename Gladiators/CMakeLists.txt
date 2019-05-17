cmake_minimum_required(VERSION 3.13)
project(Gladiators)

set(CMAKE_CXX_STANDARD 14)

add_executable(Gladiators main.cpp AStar.h Torre.h Gladiador.h Oleada.h Backtracking.h Grid.h Lista.h Nodo.h list.cpp list.h node.cpp node.h BackTracking.h)