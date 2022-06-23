#ifndef MATRIZ_H_
#define MATRIZ_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Classes.hpp"

class Matriz{
  public:
    int l;
    int c;
    std::vector<Row> mat;

    Matriz(int _l, int _c);
    Matriz();

    void insert(int _l, int _c, int v);

    // 0 existe a posicao; 1 existe o elemento inteiro; -1 não existe
    int existe(int p, Elemento e);
    int existe(int v, int & _l, int & _c);
    // retorna o valor dada uma posicao e -1 caso n encontre a posicao especificada;
    int find(int l, int c);
    // remove um item dada uma posicao
    bool remove(int l, int c);
    //realiza a busca binaria nas row da matriz até achar a row informada
    int busca_binaria(int row, int esqueda, int direita);

    void print();
};
#endif