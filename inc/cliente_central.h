#ifndef CLIENTE_CENTRAL_H
#define CLIENTE_CENTRAL_H

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERV_DISTRIBUIDO_ADDR "192.168.0.52"
#define SERV_DISTRIBUIDO_TCP_PORT 10114

extern int socketServDistribuidofd;

typedef struct
{
    unsigned int estado : 1;  // Ligado / Desligado
    int numDispositivo;
} MensagemDispositivo;

int acionarDispositivo(int novoEstado, int numDispositivo);
int enviarMensagemServidorDistribuido(uint8_t *mensagemEnvio, int tamMensagem);
void conectarServidorDistribuido();

#endif