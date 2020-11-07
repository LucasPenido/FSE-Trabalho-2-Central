#ifndef SERVIDOR_CENTRAL_H
#define SERVIDOR_CENTRAL_H

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "informacoes_dispositivos.h"

#define SERV_CENTRAL_TCP_PORT 10014
#define CONEXAO_TIPO_DISPOSITIVO 0
#define CONEXAO_TIPO_SENSOR 1

extern int socketServCentralfd;
extern int clienteSocketfd;

typedef struct {
    unsigned int tipoConexao : 1;  // 0 - Dispositivos; 1 - Sensores;
} TipoConexao;

void *realizaConexaoClienteDistribuido();
void criaServidorCentral();

#endif