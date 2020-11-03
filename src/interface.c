
#include "interface.h"

#define DISPOSITIVO_DESLIGADO 1
#define DISPOSITIVO_LIGADO 2

int alarme = 0;

WINDOW *startWindow() {
    initscr();
    WINDOW *menu = newwin(12, 40, 0, 0);
    use_default_colors();
    start_color();
    init_pair(DISPOSITIVO_DESLIGADO, COLOR_RED, -1);
    init_pair(DISPOSITIVO_LIGADO, COLOR_GREEN, -1);
    curs_set(0);

    return menu;
}

void printaEstadoDispositivo(WINDOW *menu, int numDispositivo) {
    switch (numDispositivo) {
        case LAMPADA_01:
            if (estadoDispositivos->estadoLampada01 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "ON\n");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "OFF\n");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;

        case LAMPADA_02:
            if (estadoDispositivos->estadoLampada02 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "ON\n");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "OFF\n");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;

        case LAMPADA_03:
            if (estadoDispositivos->estadoLampada03 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "ON\n");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "OFF\n");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;

        case LAMPADA_04:
            if (estadoDispositivos->estadoLampada04 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "ON\n");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "OFF\n");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;

        case AR_CONDICIONADO_01:
            if (estadoDispositivos->estadoArCondicionado01 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "ON\n");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "OFF\n");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;

        case AR_CONDICIONADO_02:
            if (estadoDispositivos->estadoArCondicionado02 == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "ON\n");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "OFF\n");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
            break;
        case ALARME:
            if (alarme == 1) {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
                wprintw(menu, "ON\n");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_LIGADO));
            } else {
                wattron(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
                wprintw(menu, "OFF\n");
                wattroff(menu, COLOR_PAIR(DISPOSITIVO_DESLIGADO));
            }
        default:
            break;
    }
}

void *menuInformacoes() {
    int op = 0, temp;
    WINDOW *menu;

    estadoDispositivos = malloc(sizeof *estadoDispositivos);
    menu = startWindow();
    nodelay(stdscr, TRUE);
    noecho();

    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    while (1) {
        wmove(menu, 0, 0);
        wclear(menu);

        wprintw(menu, "Qual dispositivo deseja ligar/desligar?\n");
        wprintw(menu, "1 - Lâmpada Cozinha: ");
        printaEstadoDispositivo(menu, LAMPADA_01);

        wprintw(menu, "2 - Lâmpada Sala: ");
        printaEstadoDispositivo(menu, LAMPADA_02);

        wprintw(menu, "3 - Lâmpada Quarto 01: ");
        printaEstadoDispositivo(menu, LAMPADA_03);

        wprintw(menu, "4 - Lâmpada Quarto 02: ");
        printaEstadoDispositivo(menu, LAMPADA_04);

        wprintw(menu, "5 - Ar Condicionado Quarto 01: ");
        printaEstadoDispositivo(menu, AR_CONDICIONADO_01);

        wprintw(menu, "6 - Ar Condicionado Quarto 02: ");
        printaEstadoDispositivo(menu, AR_CONDICIONADO_02);

        wprintw(menu, "\n7 - Alarme: ");
        printaEstadoDispositivo(menu, ALARME);

        wprintw(menu, "\nTemperatura: %.2f ºC\n", estadoDispositivos->temperatura);
        wprintw(menu, "Humidade: %.2f %%", estadoDispositivos->humidade);
        wrefresh(menu);

        if ((temp = getch()) != ERR) {
            op = temp;
            switch (op) {
                case '0':
                    endwin();
                    exit(1);
                    break;
                case '1':
                    estadoDispositivos->estadoLampada01 = acionarDispositivo(!estadoDispositivos->estadoLampada01,
                                                                             LAMPADA_01);
                    break;
                case '2':
                    estadoDispositivos->estadoLampada02 = acionarDispositivo(!estadoDispositivos->estadoLampada02,
                                                                             LAMPADA_02);
                    break;
                case '3':
                    estadoDispositivos->estadoLampada03 = acionarDispositivo(!estadoDispositivos->estadoLampada03,
                                                                             LAMPADA_03);
                    break;
                case '4':
                    estadoDispositivos->estadoLampada04 = acionarDispositivo(!estadoDispositivos->estadoLampada04,
                                                                             LAMPADA_04);
                    break;
                case '5':
                    estadoDispositivos->estadoArCondicionado01 = acionarDispositivo(!estadoDispositivos->estadoArCondicionado01,
                                                                                    AR_CONDICIONADO_01);
                    break;
                case '6':
                    estadoDispositivos->estadoArCondicionado02 = acionarDispositivo(!estadoDispositivos->estadoArCondicionado02,
                                                                                    AR_CONDICIONADO_02);
                    break;                                                                
                case '7':
                    alarme = !alarme;
                default:
                    break;
            }
        }
        sleep(1);
    }
}