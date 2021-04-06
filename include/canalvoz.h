#ifndef CANAL_VOZ_H
#define CANAL_VOZ_H

#include <iostream>

#include "canal.h"
#include "mensagem.h"

using std::string;

class CanalVoz : public Canal {
   private:
    Mensagem ultimaMensagem;

   public:
    CanalVoz(string nome);
    void setUltimaMensagem(Mensagem mensagem);
    Mensagem getUltimaMensagem();
    ~CanalVoz();
    int retornaTipo();
};

#endif
