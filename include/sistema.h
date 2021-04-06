#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "canal.h"
#include "canaltexto.h"
#include "canalvoz.h"
#include "mensagem.h"
#include "servidor.h"
#include "usuario.h"

using namespace std;

/* Classe Sistema deve concentrar todas as operações do Concordo */
class Sistema {
   private:
    /* Guarda todos os usuários do Concordo */
    vector<Usuario> usuarios;

    /* Guarda todos os servidores do Concordo */
    vector<Servidor> servidores;

    /* se 0: não logado, caso contrário guarda o id do usuário logado */
    int usuarioLogadoId = 0;

    /* Se "": não tem servidor conectado, caso contrário, guarda o nome do servidor conectado */
    string nomeServidorConectado;

    /* Se "": não tem canal conectado, caso contrário, guarda o nome do canal conectado*/
    string nomeCanalConectado;

    /* ID de usuário gerado automaticamente. Quando cria um novo usuário ele recebe ContID++ */
    int contId = 0;

   public:
    /*
    * @brief da exit(0) no sistema, encerrando ele.
    * @return string vazia
    */
    string quit();

    /*
     * @brief Cria um novo usuário e adiciona à lista de usuários do sistema
     * @param email Email do usuário. Caso já exista no sistema, não cria o usuário
     * @param senha Senha do usuário
     * @param nome Nome do Usuário 
     * @return Uma string com o status da operação
     */
    string create_user(const string email, const string senha, const string nome);

    /*
     * @brief Faz login no Concordo
     * @param email Email do usuário a logar
     * @param senha Senha do usuário a logar
     * @return Uma string com o status da operação
     */
    string login(const string email, const string senha);

    /*
     * @brief Desconectar o usuário logado no Concordo
     * @return Uma string com o status da operação
     */
    string disconnect();

    /*
     * @brief Cria um novo Servidor do Concordo
     * @param nome Nome do novo Servidor
     * @return Uma string com o status da operação
     */
    string create_server(const string nome);

    /*
     * @brief Altera a descrição de um servidor. Só faz a alteração se o usuário logado for
     * o dono do servidor
     * @param nome Nome do servidor
     * @param descrição Nova descrição do servidor
     * @return Uma string com o status da operação
     */
    string set_server_desc(const string nome, const string descricao);

    /*
     * @brief Altera o código de convite de um servidor. Só faz a alteração se o usuário logado for
     * o dono do servidor
     * @param nome Nome do servidor
     * @param descrição Novo código de convite do servidor
     * @return Uma string com o status da operação
     */
    string set_server_invite_code(const string nome, const string codigo);

    /*
     * @brief Imprime o nome do servidor, descrição e se é aberto ou fechado
     * (possui ou não código de convite)
     * @return Uma string vazia.
     */
    string list_servers();

    /*
     * @brief Remove um servidor do Sistema
     * @param nome Nome do servidor a ser removido
     * @return Uma string com o status da operação
     */
    string remove_server(const string nome);

    /*
     * @brief Entra (visualiza) um servidor. Caso o usuário ainda não seja membro do servidor,
     * adiciona seu ID à lista de IDs participantes
     * @param nome Nome do servidor 
     * @param codigo Código de convite, se o servidor for aberto, deixar vazio
     * @return Uma string com o status da operação
     */
    string enter_server(const string nome, const string codigo);

    /*
     * @brief Deixa de visualizar um servidor, caso você esteja conectado a um
     * @return Uma string com o status da operação
     */
    string leave_server();

    /* 
     * @brief lista os participantes do servidor conectado
     * @return uma string vazia, caso ele imprima, e uma mensagem de erro caso não
     * esteja conectado a um servidor.
     */
    string list_participants();
    string list_channels();
    string create_channel(const string nome, const string tipo);
    string enter_channel(const string nome);
    string leave_channel();
    string send_message(const string mensagem);
    string list_messages();
};

#endif