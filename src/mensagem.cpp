#include "mensagem.h"

Mensagem::Mensagem() {}

Mensagem::Mensagem(string dataHora, int enviadaPor, string conteudo) {
    this->dataHora = dataHora;
    this->enviadaPor = enviadaPor;
    this->conteudo = conteudo;
}

Mensagem::~Mensagem() {}