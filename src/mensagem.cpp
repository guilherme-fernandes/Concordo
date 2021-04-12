#include "mensagem.h"

Mensagem::Mensagem() {
    this->dataHora = "<XX/XX/XXXX - 00:00>";
    this->enviadaPor = 0;
    this->conteudo = "";
}

Mensagem::Mensagem(int enviadaPor, string conteudo) {
    auto hoje = chrono::system_clock::now();
    time_t horaDaMensagem = chrono::system_clock::to_time_t(hoje);

    dataHora = ctime(&horaDaMensagem);
    this->enviadaPor = enviadaPor;
    this->conteudo = conteudo;
}

Mensagem::Mensagem(int enviadaPor, Usuario* remetente, string conteudo) {
    auto hoje = chrono::system_clock::now();
    time_t horaDaMensagem = chrono::system_clock::to_time_t(hoje);

    dataHora = ctime(&horaDaMensagem);
    this->enviadaPor = enviadaPor;
    this->remetente = remetente;
    this->conteudo = conteudo;
}

Mensagem::~Mensagem() {}

string Mensagem::getConteudo() {
    return conteudo;
}

string Mensagem::getDataHora() {
    return dataHora;
}

int Mensagem::getEnviadaPor() {
    return enviadaPor;
}

string Mensagem::getNomeRemetente() {
    return remetente->getNome();
}

void Mensagem::setConteudo(string conteudo) {
    this->conteudo = conteudo;
}

void Mensagem::setDataHora(string dataHora) {
    this->dataHora = dataHora;
}

void Mensagem::setEnviadaPor(int enviadaPor) {
    this->enviadaPor = enviadaPor;
}