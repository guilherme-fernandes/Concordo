
#ifndef CANAL_TEXTO_H
#define CANAL_TEXTO_H

#include <iostream>
#include <vector>

#include "canal.h"
#include "mensagem.h"

using std::string;
using std::vector;

class CanalTexto : public Canal {
   private:
    vector<Mensagem> mensagens;

   public:
    CanalTexto(string nome);
    ~CanalTexto();
    vector<Mensagem> getMensagens();
    int retornaTipo();
};

#endif
