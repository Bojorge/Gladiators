//
// Created by manuel on 15/05/19.
//

#ifndef GLADIATORS_NODE_H
#define GLADIATORS_NODE_H

#include <iostream>

using namespace std;

template <class T>

class Node
{
public:
    Node();
    Node(T);
    ~Node();

    Node *next;
    T data;
    /**
     * @title
     * @autor
     * @brief
     */
    void delete_all();
    /**
     * @title
     * @autor
     * @brief
     */
    void print();
};


#endif //GLADIATORS_NODE_H
