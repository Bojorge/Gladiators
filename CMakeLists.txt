cmake_minimum_required(VERSION 3.13)
project(Gladiators)

find_package (PkgConfig REQUIRED)
find_package(Threads)
SET ( FOOBAR_LIBS ${GTK2_LIBRARIES} )

pkg_check_modules (GTK2 REQUIRED gtk+-3.0)

include_directories (${GTK2_INCLUDE_DIRS})
link_directories (${GTK_LIBRARY_DIRS})
add_executable (Gladiators main.cpp
        Lista.h
        Nodo.h
        tablero.h
        AStar.h
        Gladiador.h
        Torre.h)

target_link_libraries (Gladiators ${GTK2_LIBRARIES})
target_link_libraries (Gladiators ${CMAKE_THREAD_LIBS_INIT})
add_definitions (${GTK_CFLAGS_OTHER})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")