#ifndef MATRIZ_H_
#define MATRIZ_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "classes.hpp"
using std::vector;

class Matriz{
  public:
    int l;
    int c;
    vector<Row> mat;

    Matriz();
    Matriz(int l2, int c2);

    void insert(int l2, int c2, int v);

    int existe(int p, Elemento e);
    int existe(int v, int & l2, int & c2);
    int find(int l, int c);
    bool remove(int l, int c);
    int buscabi(int row, int esqueda, int direita);

    void print();
};
#endif