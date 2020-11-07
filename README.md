# Trabalho 2 - FSE - Controle de Temperatura de Ambiente Controlado / Servidor Central
aluno: Lucas Penido Antunes  
matrícula: 16/0013143

Repositório com a solução do Servidor Central do Trabalho 2.

## Projeto

O Projeto consiste na criação de um sistema distribuído de automação residencial para controle e monitoramento de sensores e dispositivos. Para isso foram utilizados o sensore de temperatura e umidade: Sensor BME280 (I2C).

Para uma maior descrição do projeto visitar este [GitLab](https://gitlab.com/fse_fga/projetos/projeto-2).

### Executando o programa

Execute:  

`make` 

Após a criação do executável:

`make run`

Para limpar o projeto:

`make clean`

Obs: Os dados serão armazenados no arquivo "dados_temperatura.csv" na mesma pasta.

### Utilização

Após a execução do programa e do servidor distribuído, aparecerá uma tela onde será possível realizar o controle dos dispositívos, monitorar sensores, ativar o alarme, além de obter informações sobre a temperatura e umidade

Para acionar qualquer dispositive digite um número de 1 a 6.  
Para ligar/desligar o alarme digite o número 7.  
Para sair do programa digite o número 0.  

### Tela de Controle
![tela](https://i.imgur.com/YV0wP87.png)
