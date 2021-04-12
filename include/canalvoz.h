#ifndef CANAL_VOZ_H
#define CANAL_VOZ_H

#include <iostream>

#include "canal.h"
#include "mensagem.h"
using std::string;

/* Classe derivada de Canal, que representa um Canal de Voz */
class CanalVoz : public Canal {
   private:
    /* Um Canal de Voz apenas armazena a última mensagem enviada */
    Mensagem ultimaMensagem;

   public:
    /* Construtor */
    CanalVoz(string nome);

    /* Destrutor */
    ~CanalVoz();

    /* retorna ultimaMensagem */
    Mensagem getUltimaMensagem();

    /*
     * @brief Classe virtual de Canal. Retorna o Tipo do Canal
     * @return 2, para Canal de Voz
     */
    int retornaTipo();

    /*
     * @brief Classe virtual de Canal. Armazena a última mensagem enviada na string ultimaMensagem
     * @param Mensagem A mensagem a ser incluída
     */
    void armazenaMensagem(Mensagem mensagem);

    /* Classe Virtual de Canal. Imprime a última mensagem enviada */
    void listaMensagens();
};

#endif
