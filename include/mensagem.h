#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <iostream>

using namespace std;

class Mensagem {
   private:
    string dataHora;
    int enviadaPor;
    string conteudo;

   public:
    Mensagem();
    Mensagem(string dataHora, int enviadaPor, string conteudo);
    ~Mensagem();
};

#endif