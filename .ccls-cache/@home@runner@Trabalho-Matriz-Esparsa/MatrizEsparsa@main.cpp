#include "matriz.hpp"
#include "registro.hpp"

using std::cout;
using std::endl;

int main() {

  Matriz *m = read_file();

  if (!m) {
    m = new Matriz(3, 3);
    m->insert(rand() % 10, rand() % 10, rand() % 10);
    m->insert(rand() % 10, rand() % 10, rand() % 10);
    m->insert(rand() % 10, rand() % 10, rand() % 10);

    m->insert(rand() % 10, rand() % 10, rand() % 10);
    m->insert(rand() % 10, rand() % 10, rand() % 10);
    m->insert(rand() % 10, rand() % 10, rand() % 10);

    m->insert(rand() % 10, rand() % 10, rand() % 10);
    m->insert(rand() % 10, rand() % 10, rand() % 10);
    m->insert(rand() % 10, rand() % 10, rand() % 10);
    m->insert(rand() % 10, rand() % 10, rand() % 10);

    bool salvando = save_file(*m);
  } 
  m->print();

  cout << "REMOVENDO CELULA DA MATRIZ" << endl;
  cout << "CELULA = L: 2 C: 2 = " << m->remove(2, 2) << endl;
  cout << "CELULA = L: 1 C: 2 = " << m->remove(1, 2) << endl;
  m->print();

  cout << "BUSCANDO VALOR EM DETERMINADA POSICAO" << endl;
  int valor = m->find(1, 1);
  int valor_2 = m->find(1, 2);

  if (valor != -1) {
    cout << "CELULA = L: 1 C: 1 = " << valor << endl;
  } else {
    cout << "CELULA = L: 1 C: 1 = VAZIO" << endl;
  }

  if (valor_2 != -1) {
    cout << "CELULA = L: 1 C: 2 = " << valor_2 << endl;
  } else {
    cout << "CELULA = L: 1 C: 2 = VAZIO" << endl;
  }

  m->print();

  cout << "VERIFICANDO SE VALOR EXISTE NA MATRIZ" << endl;
  int l, c, v = 3;
  cout << "VALOR = " << v;

  if (m->existe(v, l, c) != -1) {
    cout << " L: " << l << " C: " << c << endl;
  } else {
    cout << " NAO EXISTE" << endl;
  }
  v = 5;
  cout << "VALOR = " << v;
  if (m->existe(v, l, c) != -1) {
    cout << " L: " << l << " C: " << c << endl;
  } else {
    cout << " NAO EXISTE" << endl;
  }
  m->print();

  return 0;
}