#include "sistema.h"

#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/* COMANDOS */
string Sistema::quit() {
    cout << "Saindo..." << endl;
    exit(0);
    return "";
}

string Sistema::create_user(const string email, const string senha, const string nome) {
    if (contId == 0) {  //não precisava, era só iniciar com o for alí do else
        contId++;
        Usuario novo(contId, nome, email, senha);
        usuarios.push_back(novo);
        return "Usuário Criado";
    }

    for (int i = 0; i < (int)usuarios.size(); i++) {
        if (usuarios[i].getEmail() == email) {
            return "Usuário já existe!";
        }

        else {
            contId++;
            Usuario novo(contId, nome, email, senha);
            usuarios.push_back(novo);
            return "Usuário Criado";
        }
    }

    return "Erro!";
}

/*
A1.3 ok
Interessante, vc desloga os usuarios antes de fazer o comando de login. No entanto, como vc não usa o "logado" do usuário
pra alguma coisa nesta classe realmente era desnecessário. Uma coisa que vc poderia fazer era guardar uma referencia do usuário
logado ao invés de guardar apenas o id. Dessa forma, o setLogado faria sentido pois ia refletir no real usuário logad.
*/

string Sistema::login(const string email, const string senha) {
    for (int i = 0; i < (int)usuarios.size(); i++) {
        if (usuarios[i].getLogado() == true)
            usuarios[i].setLogado(false);
    }

    for (int i = 0; i < (int)usuarios.size(); i++) {
        if (usuarios[i].getEmail() == email && usuarios[i].getSenha() == senha && usuarios[i].getLogado() == false) {
            usuarios[i].setLogado(true);
            usuarioLogadoId = i + 1;
            cout << "Logado como ";
            return email;
        }
    }

    return "Senha ou Usuário Inválido";
}

string Sistema::disconnect() {
    for (int i = 0; i < (int)usuarios.size(); i++) {
        if (usuarios[i].getLogado() == true) {
            usuarios[i].setLogado(false);
            usuarioLogadoId = 0;
            cout << "Desconectando usuário ";
            return usuarios[i].getEmail();
        }
    }

    return "Não está conectado";
}

string Sistema::create_server(const string nome) {
    if (usuarioLogadoId == 0) {
        return "Não há usuários logados";
    }

    if ((int)servidores.size() == 0) {  //realmente não tem necessidade deste caso!
        Servidor novo(usuarioLogadoId, nome);
        servidores.push_back(novo);
        servidores[0].adicionaParticipante(usuarioLogadoId);
        return "Servidor criado";
    }

    else {
        for (int j = 0; j < (int)servidores.size(); j++) {
            if (servidores[j].getNome() == nome) {
                return "Servidor com esse nome já existe";
            }
        }

        Servidor novo(usuarioLogadoId, nome);
        servidores.push_back(novo);
        servidores[(int)servidores.size() - 1].adicionaParticipante(usuarioLogadoId);
        return "Servidor criado";
    }

    return "ERRO";
}

string Sistema::set_server_desc(const string nome, const string descricao) {
    if (usuarioLogadoId == 0) {
        return "Não há nenhum usuário logado";
    }

    for (int i = 0; i < (int)servidores.size(); i++) {
        if (servidores[i].getNome() == nome && servidores[i].getUsuarioDonoId() == usuarioLogadoId) {
            servidores[i].setDescricao(descricao);
            cout << "Descrição do servidor " << nome << " modificada";
            return "";
        }

        else if (servidores[i].getNome() == nome) {
            return "Você não pode alterar a descrição de um servidor que não foi criado por você";
        }
    }

    cout << "Servidor " << nome << " não existe";
    return "";
}

/*
A2.4 ok
um bom ponto para adicionar um lambda =)
*/
string Sistema::set_server_invite_code(const string nome, const string codigo) {
    if (usuarioLogadoId == 0) {
        return "Não há nenhum usuário logado";
    }

    for (int i = 0; i < (int)servidores.size(); i++) {
        if (servidores[i].getNome() == nome && servidores[i].getUsuarioDonoId() == usuarioLogadoId) {
            if (codigo == "") {
                servidores[i].setConvite(codigo);
                cout << "Código de convite do servidor " << nome << " removido";
                return "";
            }

            else {
                servidores[i].setConvite(codigo);
                cout << "Código de convite do servidor " << nome << " modificado";
                return "";
            }
        }

        else if (servidores[i].getNome() == nome) {
            return "Você não pode alterar o código de convite, pois não é o usuário que criou o servidor";
        }
    }

    cout << "Servidor " << nome << "não encontrado";
    return "";
}

string Sistema::list_servers() {
    if (usuarioLogadoId != 0) {
        cout << "\nLista de Servidores:\n";
        for (int i = 0; i < (int)servidores.size(); i++) {
            cout << "\nServidor " << servidores[i].getNome() << " : " << endl
                 << "Descrição - " << servidores[i].getDescricao() << endl;

            if (servidores[i].getCodigoConvite() == "") {
                cout << "Servidor Aberto\n";
            }

            else {
                cout << "Servidor Fechado\n";
            }
        }
        return "";
    }

    return "Usuário não está logado";
}

string Sistema::remove_server(const string nome) {
    vector<Servidor>::iterator it;

    if (usuarioLogadoId != 0) {
        for (it = servidores.begin(); it != servidores.end(); ++it) {
            if (it->getNome() == nome && it->getUsuarioDonoId() == usuarioLogadoId) {
                servidores.erase(it);
                cout << "Servidor " << nome << " removido";
                return "";
            }

            else if (it->getNome() == nome) {
                cout << "Você não é o dono do servidor " << nome;
                return "";
            }
        }

        cout << "Servidor " << nome << " não encontrado";
        return "";
    }

    return "Usuário não está logado";
}

string Sistema::enter_server(const string nome, const string codigo) {
    vector<Servidor>::iterator serv;

    if (usuarioLogadoId == 0) {
        return "Não há usuarios logados";
    }

    for (serv = servidores.begin(); serv != servidores.end(); ++serv) {
        if (serv->getNome() == nome && serv->getCodigoConvite() == "") {
            if (serv->testaDono(usuarioLogadoId) == true) {
                return "Entrou no servidor com sucesso";
            }

            else {
                serv->adicionaParticipante(usuarioLogadoId);
                nomeServidorConectado = nome;
                return "Entrou no servidor com sucesso";
            }
        }

        else if (serv->getNome() == nome) {
            if (codigo == "")
                return "Servidor requer código de convite";

            else if (codigo == serv->getCodigoConvite()) {
                if (serv->testaDono(usuarioLogadoId) == true) {
                    return "Usuario é dono do servidor";
                }

                else {
                    serv->adicionaParticipante(usuarioLogadoId);
                    nomeServidorConectado = nome;
                    return "Entrou no servidor com sucesso";
                }
            }

            else {
                return "Código Incorreto";
            }
        }
    }

    return "Nome do servidor incorreto";
}

string Sistema::leave_server() {
    vector<Servidor>::iterator serv;

    if (nomeServidorConectado == "") {
        return "Você não está visualizando nenhum servidor";
    }

    else {
        for (serv = servidores.begin(); serv != servidores.end(); ++serv) {
            if (serv->getNome() == nomeServidorConectado) {
                cout << "Servidor " << nomeServidorConectado << " desconectado";
                nomeServidorConectado = "";
                return "";
            }
        }
    }

    return "ERRO";
}

/*
A2.9
ok, nesse método o melhor era vc delegar alguma coisa para a classe Servidor, uma vez que o sistema acha o servidor em que o usuário logado está,
o melhor era vc chamar um método da classe servidor para listar os participantes, evitando assim acessar sua lista interna de usuários em outro for.
*/
string Sistema::list_participants() {
    cout << "Lista de Participantes: " << endl;

    for (int i = 0; i < (int)servidores.size(); i++) {
        if (nomeServidorConectado != "" && servidores[i].getNome() == nomeServidorConectado) {
            for (int j = 0; j < (int)servidores[i].getParticipantesIds().size(); j++) {
                for (int z = 0; z < (int)usuarios.size(); z++) {
                    if (servidores[i].getParticipantesIds()[j] == usuarios[z].getId()) {
                        cout << usuarios[z].getNome() << endl;
                    }
                }
            }
        }
    }

    return "";
}

string Sistema::list_channels() {
    return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(const string nome, const string tipo) {
    if (usuarioLogadoId == 0)
        return "Não há um usuário logado";

    if (nomeServidorConectado == "")
        return "Não está conectado a um servidor";

    auto serv = servidores.begin();

    for (; serv != servidores.end(); ++serv) {
        if (serv->getNome() == nomeServidorConectado && tipo == "texto") {
            CanalTexto *novo = new CanalTexto(nome);

            if (serv->canalDuplicado(novo)) {
                cout << "Canal de Texto " << nome << " já existe";
                return "";
            }

            else {
                serv->adicionaCanal(novo);
                cout << "Canal de Texto " << nome << " criado com sucesso!";
                return "";
            }
        }

        else if (tipo == "voz") {
            CanalVoz *novo = new CanalVoz(nome);
            if (serv->canalDuplicado(novo)) {
                cout << "Canal de Texto " << nome << " já existe";
                return "";
            }

            else {
                serv->adicionaCanal(novo);
                cout << "Canal de Texto " << nome << " criado com sucesso!";
                return "";
            }
        }
    }

    return "ERRO";
}

string Sistema::enter_channel(const string nome) {
    return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel() {
    return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(const string mensagem) {
    return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages() {
    return "list_messages NÃO IMPLEMENTADO";
}

/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
