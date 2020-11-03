#include <errno.h>
#include <netdb.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/un.h>
#include <time.h>
#include <unistd.h>

#include "cliente_central.h"
#include "informacoes_dispositivos.h"
#include "interface.h"
#include "servidor_central.h"

#define MAXLINE 512

void fechaConexoes() {
    close(socketServCentralfd);
    close(socketServDistribuidofd);
    close(clienteSocketfd);
}

void trata_interrupcao() {
    exit(0);
}

int main(int argc, char const *argv[]) {
    pthread_t thread_servidor, thread_interface;

    atexit(fechaConexoes);
    signal(SIGINT, trata_interrupcao);

    criaServidorCentral();
    conectarServidorDistribuido();

    pthread_create(&thread_servidor, NULL, &realizaConexaoClienteDistribuido, NULL);
    pthread_create(&thread_interface, NULL, &menuInformacoes, NULL);

    pthread_join(thread_servidor, NULL);
    // pthread_join(thread_interface, NULL);

    // endwin();

    return 0;
}
