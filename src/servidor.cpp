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

void Servidor::adicionaCanal(Canal *canal) {
    canais.push_back(canal);
}

void Servidor::removeCanal(Canal canal) {
}

vector<Canal *> Servidor::getCanais() {
    return canais;
}

bool Servidor::canalDuplicado(Canal *canal) {
    auto it = canais.begin();

    if (canais.size() == 0) {
        return false;
    }

    for (; it != canais.end(); ++it) {
        Canal *canalit = *it;

        if (canalit->retornaTipo() == 1 && canal->getNome() == canalit->getNome()) {
            return true;
        }

        else if (canalit->retornaTipo() == 2 && canal->getNome() == canalit->getNome()) {
            return true;
        }

        else {
            cout << "DEU RUIM" << endl;
            return -1;
        }

        /*
        Canal *canalit = *it;
        cout << "size de canais: " << canais.size() << endl;
        if (dynamic_cast<CanalTexto *>(canalit) != nullptr && canal.getNome() == canalit->getNome()) {
            return true;
        }

        else if (dynamic_cast<CanalVoz *>(canalit) != nullptr && canal.getNome() == canalit->getNome()) {
            return true;
        }
        */
    }

    return false;
}
