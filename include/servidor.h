#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

#include "canal.h"
#include "canaltexto.h"
#include "canalvoz.h"
#include "usuario.h"

using namespace std;

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
    vector<shared_ptr<Canal>> canais;

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
    vector<shared_ptr<Canal>> getCanais();

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

    /*
     * @brief Adiciona um novo canal ao vector de canais
     * @param canal Um ponteiro do Canal à ser adicionado através de um push_back()
     */
    void adicionaCanal(shared_ptr<Canal> canal);

    /*
     * @brief Remove um Canal da lista de canais
     * @param canal Um ponteiro do Canal a ser removido da lista de canais
     */
    void removeCanal(shared_ptr<Canal> canal);

    /*
     * @brief Método que testa se um canal já existe no servidor. Faz distinção entre
     * canais de texto e voz.
     * @param canal Um ponteiro do Canal que será checado a existência da duplicata
     * @return true se o Canal já existir; false se o canal não existir
     */
    bool canalDuplicado(shared_ptr<Canal> canal);

    /* Lista os canais de um servidor, primeiro os de texto, seguidos pelos de voz */
    void listarCanais();

    /*
     * @brief Procura um canal pelo seu nome.
     * @param nome O nome do canal a ser procurado
     * @return true, se o canal for encontrado e false, caso não seja encontrado
     */
    bool encontraCanal(const string nome);

    /*
     * @brief Adiciona uma nova mensagem a um Canal.
     * @param nome O nome do canal ao qual a mensagem será adicionada
     * @param mensagem A Mensagem que será enviada
     */
    void adicionaMensagem(const string nome, Mensagem mensagem);

    /*
     * @brief busca o Canal e lista suas mensagens.
     * @param nome O nome do Canal o qual terá as mensagens listadas.
     */
    void listaMensagensCanal(const string nome);
};

#endif
