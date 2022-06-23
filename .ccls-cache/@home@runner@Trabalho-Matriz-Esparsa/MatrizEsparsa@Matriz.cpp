#include "matriz.hpp"
using std::cout;
using std::distance;
using std::endl;

Matriz::Matriz() {}

Matriz::Matriz(int _l, int _c) {
  this->l = _l;
  this->c = _c;
}

void Matriz::insert(int _l, int _c, int v = 0) {
  Elemento e(_c, v);
  Row l;

  if (_l <= this->l - 1 && _c <= this->c - 1) {
    int _existe = existe(_l, e);
    if (_existe == -1) {
      l.posicao = _l;
      l.items.push_back(e);
      mat.push_back(l);
    } else if (_existe == 0) {
      for (auto it = mat.begin(); it < mat.end(); it++) {
        if (it->posicao == _l) {
          it->items.push_back(e);
          break;
        }
      }
    } else {
      for (auto it = mat.begin(); it < mat.end(); it++) {
        if (it->posicao == _l) {
          for (auto i = it->items.begin(); i < it->items.end(); i++) {
            if (i->coluna == e.coluna) {
              int indice = distance(it->items.begin(), i);
              it->items.at(indice) = e;
              break;
            }
          }
        }
      }
    }
  } else {
    cout << "VALOR PASSA DAS EXTREMIDADES DA MATRIZ" << endl;
  }
}

int Matriz::existe(int p, Elemento e) {
  for (auto it = mat.begin(); it < mat.end(); it++) {
    if (it->posicao == p) {
      for (auto i = it->items.begin(); i < it->items.end(); i++) {
        if (i->coluna == e.coluna)
          return 1;
      }
      return 0;
    }
  }
  return -1;
}

int Matriz::existe(int v, int &_l, int &_c) {
  for (auto it = mat.begin(); it < mat.end(); it++) {

    for (auto i = it->items.begin(); i < it->items.end(); i++) {
      if (i->valor == v) {
        _l = it->posicao;
        _c = i->coluna;
        return 1;
      }
    }
  }
  return -1;
}

int Matriz::find(int l, int c) {
  int t_mat = distance(mat.begin(), mat.end());
  int row = this->busca_binaria(l, 0, t_mat - 1);

  if (row != -1) {
    int t_row =
        distance(mat.at(row).items.begin(), mat.at(row).items.end());
    int coluna = mat.at(row).busca_binaria(c, 0, t_row - 1);

    if (coluna != -1) {
      return mat.at(row).items.at(coluna).valor;
    }
  }
  return -1;
}

bool Matriz::remove(int l, int c) {
  int saida = false;
  int t_mat = distance(mat.begin(), mat.end());
  int row = this->busca_binaria(l, 0, t_mat - 1);

  if (row != -1) {
    int t_row =
        distance(mat.at(row).items.begin(), mat.at(row).items.end());
    int coluna = mat.at(row).busca_binaria(c, 0, t_row - 1);

    if (coluna != -1) {
      mat.at(row).items.erase(mat.at(row).items.begin() + row - 1);

      if (t_row > distance(mat.at(row).items.begin(),
                                  mat.at(row).items.end())) {
        saida = true;
      }
      return saida;
    }
  }

  return saida;
}

int Matriz::busca_binaria(int row, int esquerda, int direita) {
  if (esquerda > direita)
    return -1;

  auto meio = (esquerda + direita) / 2;

  if (row == mat.at(meio).posicao)
    return meio;

  if (row > mat.at(meio).posicao)
    return busca_binaria(row, meio + 1, direita);
  else
    return busca_binaria(row, esquerda, meio - 1);
}

void Matriz::print() {
  cout << "PRINTANDO MATRIZ NA TELA" <<endl;
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      int f = find(i, j);
      if (f != -1) {
        cout << " " << f;
      } else {
        cout << " "
                  << "θ";
      }
    }
    cout << endl;
  }
}