#ifndef INFORMACOES_DISPOSITIVOS_H
#define INFORMACOES_DISPOSITIVOS_H

#define LAMPADA_01 17          // Lâmpada Cozinha
#define LAMPADA_02 18          // Lâmpada Sala
#define LAMPADA_03 27          // Lâmpada Quarto 01
#define LAMPADA_04 22          // Lâmpada Quarto 02
#define AR_CONDICIONADO_01 23  // Ar Condicionado Quarto 01
#define AR_CONDICIONADO_02 24  // Ar Condicionado Quarto 02
#define SENSOR_PRESENSA_01 25  // Sensor Presensa Sala
#define SENSOR_PRESENSA_02 26  // Sensor Presensa Cozinha
#define SENSOR_ABERTURA_01 5   // Sensor Abertura Porta Cozinha
#define SENSOR_ABERTURA_02 6   // Sensor Abertura Janela Cozinha
#define SENSOR_ABERTURA_03 12  // Sensor Abertura Porta Sala
#define SENSOR_ABERTURA_04 16  // Sensor Abertura Janela Sala
#define SENSOR_ABERTURA_05 20  // Sensor Abertura Janela Quarto 01
#define SENSOR_ABERTURA_06 21  // Sensor Abertura Janela Quarto 02
#define ALARME 1               // Alarme (Utilizado apenas no Servidor Central)

typedef struct
{
    unsigned int estadoLampada01 : 1;
    unsigned int estadoLampada02 : 1;
    unsigned int estadoLampada03 : 1;
    unsigned int estadoLampada04 : 1;
    unsigned int estadoArCondicionado01 : 1;
    unsigned int estadoArCondicionado02 : 1;
    float temperatura;
    float humidade;
} EstadoDispositivos;

typedef struct
{
    unsigned int estadoSensorPresenca01 : 1;
    unsigned int estadoSensorPresenca02 : 1;
    unsigned int estadoSensorAbertura01 : 1;
    unsigned int estadoSensorAbertura02 : 1;
    unsigned int estadoSensorAbertura03 : 1;
    unsigned int estadoSensorAbertura04 : 1;
    unsigned int estadoSensorAbertura05 : 1;
    unsigned int estadoSensorAbertura06 : 1;
} __attribute__((packed)) EstadoSensores;

extern EstadoSensores *estadoSensores;
extern EstadoDispositivos *estadoDispositivos;
extern int alarme;

#endif