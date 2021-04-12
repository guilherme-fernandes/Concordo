
#ifndef CANAL_TEXTO_H
#define CANAL_TEXTO_H

#include <iostream>
#include <vector>

#include "canal.h"
#include "mensagem.h"

using namespace std;

/* Classe derivada de Canal */
class CanalTexto : public Canal {
   private:
    /* Mensagens recebidas no Canal de Texto são armazenadas neste vector */
    vector<Mensagem> mensagens;

   public:
    /* Construtor */
    CanalTexto(string nome);

    /* Destrutor */
    ~CanalTexto();

    /* Getter */
    vector<Mensagem> getMensagens();

    /*
     * @brief Classe virtual de Canal. Retorna o Tipo do Canal
     * @return 1, para Canal de Texto
     */
    int retornaTipo();

    /*
     * @brief Classe virtual de Canal. Armazena uma mensagem no vector com push_back
     * @param Mensagem A mensagem a ser incluída
     */
    void armazenaMensagem(Mensagem mensagem);

    /* Classe Virtual de Canal. Lista as mensagens do vector mensagens */
    void listaMensagens();
};

#endif
