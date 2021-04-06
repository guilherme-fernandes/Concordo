#include "canalvoz.h"

CanalVoz::CanalVoz(string nome) : Canal(nome) {}

CanalVoz::~CanalVoz() {}

void CanalVoz::setUltimaMensagem(Mensagem mensagem) {
    ultimaMensagem = mensagem;
}

Mensagem CanalVoz::getUltimaMensagem() {
    return ultimaMensagem;
}

int CanalVoz::retornaTipo() {
    return 2;
}
