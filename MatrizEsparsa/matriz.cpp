#include "matriz.hpp"
using std::cout;
using std::distance;
using std::endl;

Matriz::Matriz() {}

Matriz::Matriz(int l2, int c2){
  this->l = l2;
  this->c = c2;
}

void Matriz::insert(int l2, int c2, int v = 0){
  Elemento e(c2, v);
  Row l;

  if (l2 <= this->l - 1 && c2 <= this->c - 1){
    int existe2 = existe(l2, e);
    if (existe2 == -1) {
      l.posicao = l2;
      l.items.push_back(e);
      mat.push_back(l);
    } else if (existe2 == 0) {
      for (auto it = mat.begin(); it < mat.end(); it++){
        if (it->posicao == l2) {
          it->items.push_back(e);
          break;
        }
      }
    } else {
      for (auto it = mat.begin(); it < mat.end(); it++){
        if (it->posicao == l2){
          for (auto i = it->items.begin(); i < it->items.end(); i++){
            if (i->coluna == e.coluna){
              int indice = distance(it->items.begin(), i);
              it->items.at(indice) = e;
              break;
            }
          }
        }
      }
    }
  }else{
    cout << "VALOR PASSA DAS EXTREMIDADES DA MATRIZ" << endl;
  }
}

int Matriz::existe(int p, Elemento e){
  for (auto it = mat.begin(); it < mat.end(); it++){
    if (it->posicao == p) {
      for (auto i = it->items.begin(); i < it->items.end(); i++){
        if (i->coluna == e.coluna)
          return 1;
      }
      return 0;
    }
  }
  return -1;
}

int Matriz::existe(int v, int &l2, int &c2){
  for (auto it = mat.begin(); it < mat.end(); it++){

    for (auto i = it->items.begin(); i < it->items.end(); i++){
      if (i->valor == v){
        l2 = it->posicao;
        c2 = i->coluna;
        return 1;
      }
    }
  }
  return -1;
}

int Matriz::find(int l, int c){
  int mat2 = distance(mat.begin(), mat.end());
  int row = this->buscabi(l, 0, mat2 - 1);

  if (row != -1){
    int row2 =
        distance(mat.at(row).items.begin(), mat.at(row).items.end());
    int coluna = mat.at(row).buscabi(c, 0, row2 - 1);

    if (coluna != -1) {
      return mat.at(row).items.at(coluna).valor;
    }
  }
  return -1;
}

bool Matriz::remove(int l, int c){
  int saida = false;
  int mat2 = distance(mat.begin(), mat.end());
  int row = this->buscabi(l, 0, mat2 - 1);

  if (row != -1){
    int row2 =
        distance(mat.at(row).items.begin(), mat.at(row).items.end());
    int coluna = mat.at(row).buscabi(c, 0, row2 - 1);

    if (coluna != -1){
      mat.at(row).items.erase(mat.at(row).items.begin() + row - 1);

      if (row2 > distance(mat.at(row).items.begin(),mat.at(row).items.end())){
        saida = true;
      }
      return saida;
    }
  }

  return saida;
}

int Matriz::buscabi(int row, int esquerda, int direita){
  if (esquerda > direita)
    return -1;

  auto meio = (esquerda + direita) / 2;

  if (row == mat.at(meio).posicao)
    return meio;

  if (row > mat.at(meio).posicao)
    return buscabi(row, meio + 1, direita);
  else
    return buscabi(row, esquerda, meio - 1);
}

void Matriz::print(){
  cout << "PRINTANDO MATRIZ NA TELA" <<endl;
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++){
      int f = find(i, j);
      if (f != -1) {
        cout << " " << f;
      }else{
        cout << " "
                  << "θ";
      }
    }
    cout << endl;
  }
}