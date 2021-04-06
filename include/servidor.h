#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <iostream>
#include <vector>

#include "canal.h"
#include "canaltexto.h"
#include "canalvoz.h"
#include "usuario.h"

using namespace std;

/*
ok, boa documentação!
*/
/* Classe referente ao Servidor do Concordo */
class Servidor {
   private:
    /* Id do usuário dono do Servidor */
    int usuarioDonoId;

    /* Nome do servidor*/
    string nome;

    /* Descrição do servidor */
    string descricao;

    /* Código de convite do servidor. Se o servidor for aberto, o código é vazio */
    string codigoConvite;

    /* Vector de canais do Servidor */
    vector<Canal *> canais;

    /* Vector que armazena usuários do Servidor */
    vector<int> participantesIDs;

   public:
    /* Construtor */
    Servidor(int UsuarioDonoId, string nome);

    /* Construtor padrão */
    Servidor();

    /* Destrutor */
    ~Servidor();

    /* Getters */
    int getUsuarioDonoId();
    string getNome();
    string getDescricao();
    string getCodigoConvite();
    vector<int> getParticipantesIds();
    vector<Canal *> getCanais();

    /* Setters */
    void setDescricao(string descricao);
    void setConvite(string codigoConvite);
    void setUsuarioDonoID(int id);

    /*
     * @brief Adiciona o ID de um novo participante à lista de IDs do servidor, através de um push_back
     * no vector participantesIDs
     * @param id O id a ser adicionado
     */
    void adicionaParticipante(int id);

    /*
     * @brief Remove o id da lista de participantes do Servidor
     * @param id O id a ser removido. Caso não esteja na lista de IDs, não faz nada.
     */
    void removeIDparticipantes(int id);

    /*
     * @brief Testa se o usuário é dono do servidor
     * @param id  ID do usuário que será testado
     * @return true, caso o usuário seja o dono do servidor, false caso ele
     * não seja o dono
     */
    bool testaDono(int id);

    /* Lista os participantes de um servidor */
    void listaParticipantes();

    void adicionaCanal(Canal *canal);

    void removeCanal(Canal canal);

    bool canalDuplicado(Canal *canal);
};

#endif
