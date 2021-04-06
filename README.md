# Concordo (Atividade 3 LP1)

@Author Guiherme de Souza Fernandes

## Introdução
Este projeto trata de um sistema chamado *Concordo*, com recursos similares ao *Discord*, porém com funcionalidades mais simples.

## Para compilar

Para compilar, dentro do diretório clonado, utilize:

```console
make
```

## Para executar

Existem duas formas de executar o programa. a primeira é simplesmente digitando no terminal:
```console
./build/apps/program
```
e logo em seguida digitar os comandos.


Ou, pode criar um arquivo de texto com uma lista de comandos (um por linha) e executar o sistema redirecionando esse arquivo como entrada padrão:
```console
./build/apps/program < script_comandos.txt
```

## Comandos

Até o momento, os seguintes comandos podem ser executados:

O comando `create-user`, cria um novo usuário no Concordo, a partir dos dados informados. Não é permitido cadastrar dois usuários com o mesmo e-mail:

```
create-user [e-mail] [senha] [nome do usuário]
```

O comando `login` faz o login de um usuário que já tenha sido cadastrado anteriormente no Concordo:

```
login [e-mail] [senha]
```

O comando `disconnect` desconecta o usuário logado no Concordo (caso haja alguém conectado):

```
disconnect
```

O comando `create-server` cria um novo servidor do Concordo a partir de seu nome. O usuário logado passa a ser o dono desse servidor:


```
create-server [nome do servidor]
```

O comando `set-server-desc` muda a descrição do servidor. Apenas o dono do servidor pode fazer essa alteração:

```
set-server-desc [nome do servidor] [descrição]
```

O comando `set-server-invite-code` modifica o Código de Convite necessário para entrar no servidor. Caso o usuário queira que seu servidor seja aberto, define o código vazio:

```
set-server-invite-code [nome do servidor] [código de convite]
```

O comando `list-servers` exibe os nomes dos servidores do sistema, um por linha:

```
list-servers
```

O comando `remove-server` remove um servidor do Concordo, inserindo seu nome:

```
remove-server [nome do servidor]
```

O comando `enter-server` entra (visualiza) um servidor do Concordo. Se o servidor tiver código de convite, ele deve ser inserido também:

```
enter-server [nome do servidor] [código de convite]
```

O comando `leave-server` encerra (deixa de visualizar) o servidor atualmente conectado:

```
leave-server
```


O comando `list-participants` exibe o nome dos usuários que estão no servidor atualmente conectado:

```
list-participants
```

O comando `quit`  encerra o Concordo:

```
quit
```

**As funcionalidades da Parte 2 do projeto serão adicionadas a seguir.**
