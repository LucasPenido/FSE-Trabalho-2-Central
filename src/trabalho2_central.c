#include <errno.h>
#include <netdb.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/un.h>
#include <time.h>
#include <unistd.h>

#include "arquivo.h"
#include "cliente_central.h"
#include "informacoes_dispositivos.h"
#include "interface.h"
#include "servidor_central.h"
#include "alarme.h"

#define MAXLINE 512

int intruso;

void fechaConexoes() {
    endwin();
    close(socketServCentralfd);
    close(socketServDistribuidofd);
    close(clienteSocketfd);
}

void trata_interrupcao() {
    exit(0);
}

int main() {
    pthread_t thread_servidor, thread_interface, thread_verificaIntruso;

    atexit(fechaConexoes);
    signal(SIGINT, trata_interrupcao);

    criaServidorCentral();
    conectarServidorDistribuido();

    iniciaNcurses();
    criaArquivo();

    pthread_create(&thread_servidor, NULL, &realizaConexaoClienteDistribuido, NULL);
    pthread_create(&thread_interface, NULL, &menuInformacoes, NULL);
    pthread_create(&thread_verificaIntruso, NULL, &verificaIntruso, NULL);

    pthread_join(thread_servidor, NULL);

    endwin();

    return 0;
}
