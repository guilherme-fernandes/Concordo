#include "servidor.h"

Servidor::Servidor(int usuarioDonoId, string nome) {
    this->usuarioDonoId = usuarioDonoId;
    this->nome = nome;
}

Servidor::Servidor() {}

Servidor::~Servidor() {}

int Servidor::getUsuarioDonoId() {
    return usuarioDonoId;
}

string Servidor::getNome() {
    return nome;
}

string Servidor::getDescricao() {
    return descricao;
}

string Servidor::getCodigoConvite() {
    return codigoConvite;
}

vector<int> Servidor::getParticipantesIds() {
    return participantesIDs;
}

void Servidor::setDescricao(string descricao) {
    this->descricao = descricao;
}

void Servidor::setConvite(string codigoConvite) {
    this->codigoConvite = codigoConvite;
}

void Servidor::adicionaParticipante(int id) {
    participantesIDs.push_back(id);
}

void Servidor::setUsuarioDonoID(int id) {
    usuarioDonoId = id;
}

void Servidor::removeIDparticipantes(int id) {
    vector<int>::iterator it;

    for (it = participantesIDs.begin(); it != participantesIDs.end() && *it != id; ++it) {
        participantesIDs.erase(it);
        return;
    }
}

bool Servidor::testaDono(int ids) {
    auto id = participantesIDs.begin();

    for (; id != participantesIDs.end(); ++id) {
        if (*id == ids) {
            return true;
        }
    }

    return false;
}

void Servidor::listaParticipantes() {
}

void Servidor::adicionaCanal(shared_ptr<Canal> canal) {
    canais.push_back(canal);
}

void Servidor::removeCanal(shared_ptr<Canal> canal) {
}

vector<shared_ptr<Canal>> Servidor::getCanais() {
    return canais;
}

bool Servidor::canalDuplicado(shared_ptr<Canal> canal) {
    auto it = canais.begin();

    if (canais.size() == 0) {
        return false;
    }

    for (; it != canais.end(); ++it) {
        shared_ptr<Canal> canalit = *it;

        if (canalit->retornaTipo() == 1 && canal->getNome() == canalit->getNome()) {
            return true;
        }

        else if (canalit->retornaTipo() == 2 && canal->getNome() == canalit->getNome()) {
            return true;
        }

        else if (canalit->retornaTipo() == 0) {
            cout << "ERRO" << endl;
            return false;
        }
    }

    return false;
}

void Servidor::listarCanais() {
    auto it = canais.begin();

    cout << "#canais de texto" << endl;
    for (; it != canais.end(); ++it) {
        shared_ptr<Canal> canalit = *it;

        if (canalit->retornaTipo() == 1) {
            cout << canalit->getNome() << endl;
        }
    }

    it = canais.begin();
    cout << "#canais de voz" << endl;
    for (; it != canais.end(); ++it) {
        shared_ptr<Canal> canalit = *it;

        if (canalit->retornaTipo() == 2) {
            cout << canalit->getNome() << endl;
        }
    }
}

bool Servidor::encontraCanal(const string nome) {
    auto it = canais.begin();

    for (; it != canais.end(); ++it) {
        shared_ptr<Canal> canalit = *it;

        if (canalit->getNome() == nome) {
            return true;
        }
    }
    return false;
}

void Servidor::adicionaMensagem(const string nome, Mensagem mensagem) {
    auto it = canais.begin();

    for (; it != canais.end(); ++it) {
        shared_ptr<Canal> canalit = *it;

        if (canalit->getNome() == nome) {
            canalit->armazenaMensagem(mensagem);
            return;
        }
    }
    cout << "Canal não encontrado" << endl;
}

void Servidor::listaMensagensCanal(const string nome) {
    auto it = canais.begin();

    for (; it != canais.end(); it++) {
        shared_ptr<Canal> canalit = *it;

        if (canalit->getNome() == nome) {
            canalit->listaMensagens();
            return;
        }
    }

    cout << "Canal não encontrado" << endl;
}