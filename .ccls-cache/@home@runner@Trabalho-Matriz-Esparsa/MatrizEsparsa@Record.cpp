#include "registro.hpp"

Matriz * read_file(){
  int l, c;
  std::ifstream txt_file;

  txt_file.open("matriz.txt");

  if (txt_file.is_open()) {
    txt_file >> l >> c;

    Matriz *m1 = new Matriz(l, c);

    for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
        std::string v;
        txt_file >> v;
        
        if( v != "v"){
          m1->insert(i, j, stoi(v));
        }
      }
    }
    txt_file.close();
    return m1;
  }

  return nullptr;
}

bool save_file(Matriz & m) {
  std::ofstream file;
  file.open("matriz.txt", std::ios::app);
  if (file.is_open()) {
    file << m.l << ' ' << m.c << "\n";

    for (int i = 0; i < m.l; i++) {
      std::string row = "";
      for (int j = 0; j < m.c; j++) {
        int f = m.find(i, j);
        
        if (f != -1){
          file << f;
        } else {
          file << 'v';
        }
        
        if (j < m.c - 1){
          file << ' ';
        }
      }
      file << "\n";
    }
    file.close();
    return true;
  }
  return false;
}
