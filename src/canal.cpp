#include "canal.h"

Canal::Canal(std::string nome) {
    this->nome = nome;
}

string Canal::getNome() {
    return nome;
}

int Canal::retornaTipo() {
    return 0;
}

void Canal::setNome(string nome) {
    this->nome = nome;
}

void Canal::armazenaMensagem(Mensagem mensagem) {}

void Canal::listaMensagens(){};