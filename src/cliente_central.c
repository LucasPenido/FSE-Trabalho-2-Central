#include "cliente_central.h"

int socketServDistribuidofd;

int enviarMensagemServidorDistribuido(uint8_t *mensagemEnvio, int tamMensagem) {
    if (send(socketServDistribuidofd, mensagemEnvio, tamMensagem, 0) != tamMensagem) {
        printf("Erro ao enviar mensagem\n");
        return 0;
    }

    return 1;
}

int acionarDispositivo(int novoEstado, int numDispositivo) {
    MensagemDispositivo mensagemDispositivo;

    mensagemDispositivo.estado = novoEstado;
    mensagemDispositivo.numDispositivo = numDispositivo;

    uint8_t *pacoteEnvio = calloc(sizeof(mensagemDispositivo), sizeof(uint8_t));
    uint8_t *pacote = (uint8_t *)pacoteEnvio;

    memcpy(pacote, &mensagemDispositivo, sizeof(mensagemDispositivo));
    pacote += sizeof(mensagemDispositivo);

    int n = sizeof(mensagemDispositivo);

    if (enviarMensagemServidorDistribuido(pacoteEnvio, n) == 0) {
        return !novoEstado;
    }

    return novoEstado;
}

void conectarServidorDistribuido() {
    struct sockaddr_in servaddr;

    socketServDistribuidofd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketServDistribuidofd < 0) {
        printf("Erro ao abrir socket\n");
        exit(1);
    }

    bzero((char *)&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(SERV_DISTRIBUIDO_ADDR);
    servaddr.sin_port = htons(SERV_DISTRIBUIDO_TCP_PORT);

    printf("Aguargando Servidor Distribuído estar disponível\n");
    while (1) {
        if (connect(socketServDistribuidofd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == 0) {
            system("clear");
            break;
        }
        usleep(500000);
    }
}