#ifndef CLASSES_H_
#define CLASSES_H_
#include <iostream>
#include <vector>

using std::vector;

class Elemento{
public:
  int coluna, valor;
  Elemento();
  Elemento(int c, int v);
  bool operator== (Elemento & e);
};

class Row{
public:
  int posicao;
  vector<Elemento> items;
  Row();
  Row(int p, Elemento e);
  int buscabi(int coluna, int s1, int s2);
};

#endif