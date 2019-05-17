cmake_minimum_required(VERSION 3.13)
project(Gladiators)

find_package (PkgConfig REQUIRED)
find_package(Threads)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
SET ( FOOBAR_LIBS ${GTK2_LIBRARIES} )

pkg_check_modules (GTK2 REQUIRED gtk+-3.0)

include_directories (${GTK2_INCLUDE_DIRS})
link_directories (${GTK_LIBRARY_DIRS})
add_executable (Gladiators main.cpp
        list.h
        list.cpp
        node.cpp
        node.h
        tablero.h
        AStar.h
        Gladiador.h
        Lista.h
        Torres.h
        Nodo.h
        TCPclient.h
        Json.h)

target_link_libraries (Gladiators ${GTK2_LIBRARIES})
target_link_libraries (Gladiators ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Gladiators Qt5::Widgets Qt5::Sql)
add_definitions (${GTK_CFLAGS_OTHER})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")