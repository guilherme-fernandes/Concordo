#include "canaltexto.h"

using namespace std;

CanalTexto::CanalTexto(string nome) : Canal(nome){};

CanalTexto::~CanalTexto() {
}

vector<Mensagem> CanalTexto::getMensagens() {
    return mensagens;
}

int CanalTexto::retornaTipo() {
    return 1;
}

void CanalTexto::armazenaMensagem(Mensagem mensagem) {
    mensagens.push_back(mensagem);
}

void CanalTexto::listaMensagens() {
    auto it = mensagens.begin();

    for (; it != mensagens.end(); it++) {
        cout << it->getNomeRemetente() << " <" << it->getDataHora() << "> : " << it->getConteudo() << endl;
    }
}
