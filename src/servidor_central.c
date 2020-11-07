#include "servidor_central.h"

EstadoDispositivos estadoDispositivos;
EstadoSensores estadoSensores;
TemperaturaUmidade temperaturaUmidade;

int socketServCentralfd, clienteSocketfd;

void TrataClienteDistribuido(int sockfd) {
    TipoConexao tipoConexao;
    uint8_t line[512];
    int n;

    while (1) {
        bzero(line, 512);
        n = recv(sockfd, line, 511, 0);
        if (n == 0) {
            return; /* termina a conexão */

        } else if (n < 0) {
            printf("erro em ler do socket\n");
            exit(1);
        } else {
            tipoConexao = *(TipoConexao *)line;
            if (tipoConexao.tipoConexao == CONEXAO_TIPO_DISPOSITIVO) {
                // Trata dispositivos
                estadoDispositivos = *(EstadoDispositivos *)(line + sizeof(&tipoConexao));
                temperaturaUmidade = *(TemperaturaUmidade *)(line + sizeof(&tipoConexao) + sizeof(&estadoDispositivos));
            } else if (tipoConexao.tipoConexao == CONEXAO_TIPO_SENSOR) {
                // Trata sensor
                estadoSensores = *(EstadoSensores *)(line + sizeof(&tipoConexao));
            }
        }
    }
}

void *realizaConexaoClienteDistribuido() {
    unsigned int cliLen;
    struct sockaddr_in clienteAddr;

    while (1) {
        cliLen = sizeof(struct sockaddr_in);
        clienteSocketfd = accept(socketServCentralfd, (struct sockaddr *)&clienteAddr, (socklen_t *)&cliLen);
        if (clienteSocketfd < 0)
            printf("ERROR on accept");

        TrataClienteDistribuido(clienteSocketfd);
        close(clienteSocketfd);
    }
}

void criaServidorCentral() {
    struct sockaddr_in servAddr;

    socketServCentralfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketServCentralfd < 0) {
        printf("Erro ao abrir socket servidor\n");
        exit(1);
    }

    bzero((char *)&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(SERV_CENTRAL_TCP_PORT);

    if (bind(socketServCentralfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) {
        printf("Erro biding\n");
        exit(1);
    }

    if (listen(socketServCentralfd, 10) < 0) {
        printf("Erro ao criar listen\n");
        exit(1);
    }
}