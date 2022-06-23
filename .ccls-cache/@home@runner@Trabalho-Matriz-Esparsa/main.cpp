#include <iostream>
#include <vector>
#include "elemento.hpp"
#include "row.hpp"

int main(){
  Row row;
  Elemento e;
  e.coluna = 3;
  e.valor = 5;
  row.elementos.push_back(e);
  return 0;
}