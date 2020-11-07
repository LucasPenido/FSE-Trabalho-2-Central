
#include "interface.h"

#define DISPOSITIVO_DESLIGADO 1
#define DISPOSITIVO_LIGADO 2

int alarme = 0;

void iniciaNcurses() {
    initscr();
    use_default_colors();

    start_color();

    init_pair(DISPOSITIVO_DESLIGADO, COLOR_RED, -1);
    init_pair(DISPOSITIVO_LIGADO, COLOR_GREEN, -1);
    curs_set(0);
    noecho();
}

void printaEstadoDispositivo(WINDOW *menu, int numDispositivo, int linha) {
    switch (numDispositivo) {
        case LAMPADA_01:
            if (estadoDispositivos.estadoLampada01 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                mvwprintw(menu, linha, 32, "ON");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                mvwprintw(menu, linha, 32, "OFF");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;

        case LAMPADA_02:
            if (estadoDispositivos.estadoLampada02 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                mvwprintw(menu, linha, 32, "ON");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                mvwprintw(menu, linha, 32, "OFF");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;

        case LAMPADA_03:
            if (estadoDispositivos.estadoLampada03 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                mvwprintw(menu, linha, 32, "ON");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                mvwprintw(menu, linha, 32, "OFF");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;

        case LAMPADA_04:
            if (estadoDispositivos.estadoLampada04 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                mvwprintw(menu, linha, 32, "ON");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                mvwprintw(menu, linha, 32, "OFF");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;

        case AR_CONDICIONADO_01:
            if (estadoDispositivos.estadoArCondicionado01 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                mvwprintw(menu, linha, 32, "ON");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                mvwprintw(menu, linha, 32, "OFF");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;

        case AR_CONDICIONADO_02:
            if (estadoDispositivos.estadoArCondicionado02 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                mvwprintw(menu, linha, 32, "ON");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                mvwprintw(menu, linha, 32, "OFF");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;
        case ALARME:
            if (alarme == 1 && intruso == 0) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "Alarme Ativado");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else if (alarme == 0) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "Alarme Desativado");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            } else if (alarme == 1 && intruso == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "Alarme Disparado!!");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;
        case SENSOR_PRESENCA_01:
            if (estadoSensores.estadoSensorPresenca01 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "ON");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "OFF");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;
        case SENSOR_PRESENCA_02:
            if (estadoSensores.estadoSensorPresenca02 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "ON");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "OFF");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;
        case SENSOR_ABERTURA_01:
            if (estadoSensores.estadoSensorAbertura01 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "ON");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "OFF");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;
        case SENSOR_ABERTURA_02:
            if (estadoSensores.estadoSensorAbertura02 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "ON");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "OFF");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;
        case SENSOR_ABERTURA_03:
            if (estadoSensores.estadoSensorAbertura03 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "ON");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "OFF");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;
        case SENSOR_ABERTURA_04:
            if (estadoSensores.estadoSensorAbertura04 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "ON");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "OFF");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;
        case SENSOR_ABERTURA_05:
            if (estadoSensores.estadoSensorAbertura05 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "ON");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "OFF");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;
        case SENSOR_ABERTURA_06:
            if (estadoSensores.estadoSensorAbertura06 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "ON");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "OFF");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;
        default:
            break;
    }
}

void menuCabecalho(WINDOW *cabecalho, int col) {
    char cab[] = "Sistema de Automação Residencial";

    box(cabecalho, 0, 0);
    mvwprintw(cabecalho, 1, (col - strlen(cab)) / 2, "%s", cab);
    wrefresh(cabecalho);
}

void menuSensores(WINDOW *menuSensores, int col) {
    char cabSensores[] = "Quadro de Sensores";

    werase(menuSensores);
    box(menuSensores, 0, 0);

    mvwprintw(menuSensores, 1, (col - strlen(cabSensores)) / 2, "%s", cabSensores);
    mvwhline(menuSensores, 2, 1, 0, col - 2);

    mvwprintw(menuSensores, 3, 1, "Sensor Presenca Sala: ");
    printaEstadoDispositivo(menuSensores, SENSOR_PRESENCA_01, 3);

    mvwprintw(menuSensores, 4, 1, "Sensor Presenca Cozinha: ");
    printaEstadoDispositivo(menuSensores, SENSOR_PRESENCA_02, 4);

    mvwprintw(menuSensores, 5, 1, "Sensor Porta Cozinha: ");
    printaEstadoDispositivo(menuSensores, SENSOR_ABERTURA_01, 5);

    mvwprintw(menuSensores, 6, 1, "Sensor Janela Cozinha: ");
    printaEstadoDispositivo(menuSensores, SENSOR_ABERTURA_02, 6);

    mvwprintw(menuSensores, 7, 1, "Sensor Porta Sala: ");
    printaEstadoDispositivo(menuSensores, SENSOR_ABERTURA_03, 7);

    mvwprintw(menuSensores, 8, 1, "Sensor Janela Sala: ");
    printaEstadoDispositivo(menuSensores, SENSOR_ABERTURA_04, 8);

    mvwprintw(menuSensores, 9, 1, "Sensor Janela Quarto 01: ");
    printaEstadoDispositivo(menuSensores, SENSOR_ABERTURA_05, 9);

    mvwprintw(menuSensores, 10, 1, "Sensor Janela Quarto 02: ");
    printaEstadoDispositivo(menuSensores, SENSOR_ABERTURA_06, 10);

    mvwhline(menuSensores, 12, 1, 0, col - 2);

    if (alarme == 1) {
        mvwprintw(menuSensores, 13, 1, "7 - Desativar Alarme: ");
    } else {
        mvwprintw(menuSensores, 13, 1, "7 - Ativar Alarme: ");
    }
    printaEstadoDispositivo(menuSensores, ALARME, 13);

    wrefresh(menuSensores);
}

void menuDispositivos(WINDOW *menu, int col) {
    char cabDispositivos[] = "Quadro de Dispositívos";

    werase(menu);
    box(menu, 0, 0);

    mvwprintw(menu, 1, (col - strlen(cabDispositivos)) / 2, "%s", cabDispositivos);
    mvwhline(menu, 2, 1, 0, col - 2);

    mvwprintw(menu, 3, 1, "1 - Lâmpada Cozinha: ");
    printaEstadoDispositivo(menu, LAMPADA_01, 3);

    mvwprintw(menu, 4, 1, "2 - Lâmpada Sala: ");
    printaEstadoDispositivo(menu, LAMPADA_02, 4);

    mvwprintw(menu, 5, 1, "3 - Lâmpada Quarto 01: ");
    printaEstadoDispositivo(menu, LAMPADA_03, 5);

    mvwprintw(menu, 6, 1, "4 - Lâmpada Quarto 02: ");
    printaEstadoDispositivo(menu, LAMPADA_04, 6);

    mvwprintw(menu, 7, 1, "5 - Ar Condicionado Quarto 01: ");
    printaEstadoDispositivo(menu, AR_CONDICIONADO_01, 7);

    mvwprintw(menu, 8, 1, "6 - Ar Condicionado Quarto 02: ");
    printaEstadoDispositivo(menu, AR_CONDICIONADO_02, 8);

    mvwprintw(menu, 12, 1, "Temperatura: %.2f ºC", temperaturaUmidade.temperatura);
    mvwprintw(menu, 13, 1, "Humidade: %.2f %%", temperaturaUmidade.umidade);
    wrefresh(menu);
}

void leTeclado(WINDOW *dispositivos) {
    int op;
    if ((op = wgetch(dispositivos)) != ERR) {
        switch (op) {
            case '0':
                exit(1);
                break;
            case '1':
                estadoDispositivos.estadoLampada01 = acionarDispositivo(!estadoDispositivos.estadoLampada01,
                                                                        LAMPADA_01);
                escreverArquivo("Dispositivo", LAMPADA_01, estadoDispositivos.estadoLampada01);
                break;
            case '2':
                estadoDispositivos.estadoLampada02 = acionarDispositivo(!estadoDispositivos.estadoLampada02,
                                                                        LAMPADA_02);
                escreverArquivo("Dispositivo", LAMPADA_02, estadoDispositivos.estadoLampada02);
                break;
            case '3':
                estadoDispositivos.estadoLampada03 = acionarDispositivo(!estadoDispositivos.estadoLampada03,
                                                                        LAMPADA_03);
                escreverArquivo("Dispositivo", LAMPADA_03, estadoDispositivos.estadoLampada03);
                break;
            case '4':
                estadoDispositivos.estadoLampada04 = acionarDispositivo(!estadoDispositivos.estadoLampada04,
                                                                        LAMPADA_04);
                escreverArquivo("Dispositivo", LAMPADA_04, estadoDispositivos.estadoLampada04);
                break;
            case '5':
                estadoDispositivos.estadoArCondicionado01 = acionarDispositivo(!estadoDispositivos.estadoArCondicionado01,
                                                                               AR_CONDICIONADO_01);
                escreverArquivo("Dispositivo", AR_CONDICIONADO_01, estadoDispositivos.estadoArCondicionado01);
                break;
            case '6':
                estadoDispositivos.estadoArCondicionado02 = acionarDispositivo(!estadoDispositivos.estadoArCondicionado02,
                                                                               AR_CONDICIONADO_02);
                escreverArquivo("Dispositivo", AR_CONDICIONADO_02, estadoDispositivos.estadoArCondicionado02);
                break;
            case '7':
                alarme = !alarme;
                escreverArquivo("Alarme", ALARME, alarme);
                break;
            default:
                break;
        }
    }
}

void *menuInformacoes() {
    int terminalnCol, sensoresnCol, dispositivosnCol;
    WINDOW *dispositivos, *cabecalho, *sensores;

    terminalnCol = getmaxx(stdscr);

    cabecalho = newwin(3, terminalnCol, 0, 0);

    dispositivos = newwin(15, terminalnCol / 2, 4, 0);
    dispositivosnCol = getmaxx(dispositivos);
    nodelay(dispositivos, TRUE);

    sensores = newwin(15, terminalnCol / 2, 4, terminalnCol / 2);
    sensoresnCol = getmaxx(sensores);

    while (1) {
        menuCabecalho(cabecalho, terminalnCol);
        menuDispositivos(dispositivos, dispositivosnCol);
        menuSensores(sensores, sensoresnCol);

        leTeclado(dispositivos);

        usleep(200000);
    }
}