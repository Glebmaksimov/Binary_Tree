
#ifndef MAIN_CPP_DECLARATIONS_H
#define MAIN_CPP_DECLARATIONS_H
#include <iomanip>
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define COUNT 10
template<typename T>
struct Node{
    T node_key;
    Node* left_child;
    Node* right_child;

    Node(T _node_key,Node* _left_child,Node* _right_child):node_key(_node_key),left_child(_left_child),right_child(_right_child){};
};

template<typename T>
Node<T>* create_node(T node_key);
template<typename T>
Node<T>* search(Node<T> *root,T need_key);
template<typename T>
void insert_node(Node<T> *&root, T node_key);
template<typename T>
void delete_node(Node<T> *&root, int node_key);
template<typename T>
void print(struct Node<T> *root, int space);
template<typename T>
void print_tree(struct Node<T> *root);

#include "Implementations.hpp"
#endif //MAIN_CPP_DECLARATIONS_H
