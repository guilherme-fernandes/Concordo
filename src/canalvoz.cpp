#include "canalvoz.h"

CanalVoz::CanalVoz(string nome) : Canal(nome) {}

CanalVoz::~CanalVoz() {}

void CanalVoz::armazenaMensagem(Mensagem mensagem) {
    ultimaMensagem = mensagem;
}

Mensagem CanalVoz::getUltimaMensagem() {
    return ultimaMensagem;
}

int CanalVoz::retornaTipo() {
    return 2;
}

void CanalVoz::listaMensagens() {
    cout << ultimaMensagem.getNomeRemetente() << " <" << ultimaMensagem.getDataHora() << "> : " << ultimaMensagem.getConteudo() << endl;
}
