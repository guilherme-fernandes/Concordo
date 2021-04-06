#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "executor.h"
#include "sistema.h"

using namespace std;

int main() {
    // inicialização do sistema
    Sistema sistema;
    Executor executor(sistema);

    // o executor recebe o cin e o cout. Ele irá os utilizar para ler as linhas
    // de comando, executar o método correto em "sistema" e exibir as mensagens
    executor.iniciar(cin, cout);

    return 0;
}