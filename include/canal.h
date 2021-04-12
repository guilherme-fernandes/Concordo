
#ifndef CANAL_H
#define CANAL_H
#include <iostream>

#include "mensagem.h"

using std::string;

/* Classe Base dos Canais */
class Canal {
   protected:
    /* Nome do Canal */
    string nome;

   public:
    /* Construtor de Canal */
    Canal(string nome);

    /* Getters & Setters */
    string getNome();
    void setNome(string nome);

    /*
     * @brief retorna o tipo do Canal. Sobrescrita nas classes derivadas
     * @return 0, se for um Canal Geral, 1 se for um Canal de Texto, 2 se 
     * for um Canal de voz.
     */
    virtual int retornaTipo();

    /*
     * @ armazena uma Mensagem em um Canal. É sobrescrita nas classes derivadas,
     * respeitando o comportamento de cada uma.
     * @param mensagem A mensagem a ser armazenada
     */
    virtual void armazenaMensagem(Mensagem mensagem);

    /* Padrão de impressão das Mensagens dos Canais. É sobrescrita nas classes derivadas. */
    virtual void listaMensagens();
};

#endif
