#ifndef CLASSES
#define CLASSES
#include <iostream>
#include <vector>

class Elemento {
public:
  int coluna;
  int valor;

  Elemento();
  Elemento(int c, int v);
  bool operator== (Elemento & e);
};

class Linha {
public:
  int posicao;
  std::vector<Elemento> items;
  Linha();
  Linha(int p, Elemento e);

  //realiza a busca binaria nos items da linha para achar a coluna do item procurado
  int busca_binaria(int coluna, int s1, int s2);
};

#endif