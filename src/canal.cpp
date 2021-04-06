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