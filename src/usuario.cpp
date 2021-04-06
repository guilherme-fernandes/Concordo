#include "usuario.h"

Usuario::Usuario(int id, string nome, string email, string senha) {
    this->id = id;
    this->nome = nome;
    this->email = email;
    this->senha = senha;
}

Usuario::Usuario() {
    id = 0;
    nome = "";
    email = "";
    senha = "";
}

Usuario::~Usuario() {
}

int Usuario::getId() {
    return id;
}

string Usuario::getNome() {
    return nome;
}

string Usuario::getEmail() {
    return email;
}

string Usuario::getSenha() {
    return senha;
}

void Usuario::setId(int id) {
    this->id = id;
}

void Usuario::setLogado(bool logado) {
    this->logado = logado;
}

void Usuario::setNome(string nome) {
    this->nome = nome;
}

void Usuario::setEmail(string email) {
    this->email = email;
}

void Usuario::setSenha(string senha) {
    this->senha = senha;
}

bool Usuario::getLogado() {
    return logado;
}