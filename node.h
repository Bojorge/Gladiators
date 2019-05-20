#ifndef NODE_H
#define NODE_H


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

    void setnode(T);

    void delete_all();
    /**
     * @title
     * @autor
     * @brief
     */
    void print();
};

#endif
