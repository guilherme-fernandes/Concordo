#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <chrono>
#include <ctime>
#include <iostream>

#include "usuario.h"

using namespace std;

/* Classe referente às Mensagens do Concordo */
class Mensagem {
   private:
    /* string que recebe o horário que a mensagem foi enviada (Tempo Real) */
    string dataHora;

    /* ID do Usuário remetente da mensagem */
    int enviadaPor;

    /* Ponteiro para o remetente da mensagem */
    Usuario* remetente;

    /* Conteúdo da mensagem */
    string conteudo;

   public:
    /* Construtor Base */
    Mensagem();

    /* Construtor que recebe o ID e o conteúdo */
    Mensagem(int enviadaPor, string conteudo);

    /* Construtor que recebe além do ID e do conteúdo, uma referência para o remetente */
    Mensagem(int enviadaPor, Usuario* remetente, string conteudo);

    /* Destrutor */
    ~Mensagem();

    /* Getters */
    string getDataHora();
    int getEnviadaPor();
    string getConteudo();

    /* Setters */
    void setDataHora(string dataHora);
    void setEnviadaPor(int enviadaPor);
    void setConteudo(string conteudo);

    /*
     * @brief Este método retorna o nome do Usuário a partir do Usuario* remetente.
     * @return O nome do Usuário
     */
    string getNomeRemetente();
};

#endif