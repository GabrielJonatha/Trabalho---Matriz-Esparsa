#include "classes.hpp"

Elemento::Elemento(){};
Elemento::Elemento(int i, int v) {
  coluna = i;
  valor = v;
};

bool Elemento::operator==(Elemento &e) {
  if (this->coluna == e.coluna && this->valor == e.valor){
    return true;
  }
  return false;
}

Row::Row(){};
Row::Row(int p, Elemento l) {
  posicao = p;
  items.push_back(l);
};

int Row::buscabi(int coluna, int esquerda, int direita){
   if (esquerda > direita) return -1;

    auto meio = (esquerda + direita) / 2;

    if (coluna == items.at(meio).coluna) return meio;

    if (coluna > items.at(meio).coluna)
        return buscabi(coluna, meio + 1, direita);
    else
        return buscabi(coluna, esquerda, meio - 1);
}