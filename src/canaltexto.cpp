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
