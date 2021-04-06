
#ifndef CANAL_H
#define CANAL_H

#include <iostream>

using std::string;

class Canal {
   protected:
    string nome;

   public:
    Canal(std::string nome);
    string getNome();

    /*
     * @brief retorna o tipo do Canal. Sobrescrita nas classes derivadas
     * @return 0, se for um Canal Geral, 1 se for um Canal de Texto, 2 se 
     * for um Canal de voz.
     */
    virtual int retornaTipo();
};

#endif
