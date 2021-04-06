#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

using namespace std;

/*
ok, boa documentação!
*/
/* Classe referente ao um usuário do sistema Concordo */
class Usuario {
   private:
    /* ID do usuário. Cada usuário tem seu próprio ID */
    int id;

    /* Nome do usuário */
    string nome;

    /* Endereço de email do usuário */
    string email;

    /* Senha do login no concordo */
    string senha;

    /* booleano para dizer se o usuário se encontra logado no concordo */
    bool logado = false;

   public:
    /* Construtor */
    Usuario(int id, string nome, string email, string senha);

    /* Construtor Padrão */
    Usuario();

    /* Destrutor */
    ~Usuario();

    /*
     * @brief Retorna o ID do usuário
     * @return Inteiro correspondente ao ID do usuário 
     */
    int getId();

    /*
     * @brief Retorna o Nome do usuário
     * @return String correspondente ao nome do usuário
     */
    string getNome();

    /*
     * @brief Retorna o Email do usuário
     * @return String correspondente ao email do usuário
     */
    string getEmail();

    /*
     * @brief Retorna a senha do usuário
     * @return String correspondente à senha do usuário
     */
    string getSenha();

    /*
     * @brief Retorna o status do usuário (se está logado ou não)
     * @return True ou false, dependendo do status do usuário
     */
    bool getLogado();

    /*
     * @brief Altera o ID do usuário 
     * @param id ID novo
     */
    void setId(int id);

    /*
     * @brief Altera o status de login do usuário (true ou false)
     * @param logado True ou false, dependendo do estado do usuário no momento
     */
    void setLogado(bool logado);

    /*
     * @brief Altera o nome do usuário
     * @param nome Novo nome
     */
    void setNome(string nome);

    /*
     * @brief Altera o email do usuario
     * @param email Novo email
     */
    void setEmail(string email);

    /*
     * @brief Altera a senha do usuário
     * @param senha Nova senha    
     */
    void setSenha(string senha);
};

#endif
