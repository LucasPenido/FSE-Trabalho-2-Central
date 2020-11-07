#ifndef ALARME_H
#define ALARME_H

#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "informacoes_dispositivos.h"
#include "arquivo.h"

void *tocaAlarme();
void *verificaIntruso();

#endif