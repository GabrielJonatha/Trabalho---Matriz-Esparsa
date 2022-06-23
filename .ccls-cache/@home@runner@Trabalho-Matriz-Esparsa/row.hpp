#IFNDEF ROW_H_
#DEFINE ROW_H_
#include "elemento.hpp"
#include <iostream>
#include <vector>

class Row{
  public:
    int linha;
    std::vector <Elemento> elementos;
};

#ENDIF