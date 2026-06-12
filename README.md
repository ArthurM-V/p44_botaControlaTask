# P44 - Task de botão controla task de LED

## Fase

Fase 3 — RTOS no ESP32

## Objetivo

Explorar task de botão controla task de led para introduzir a organização por tasks no ESP32, observando como prioridades, sincronização, filas e comunicação entre tarefas alteram a resposta global do sistema.

## Componentes sugeridos

- ESP32 DevKit
- protoboard
- LED vermelho
- LED verde
- botão tátil
- potenciômetro 10k
- cabos jumper
- FreeRTOS embarcado no ESP32

## Ajustes obrigatórios para a aula

1. Ajuste o período de uma task ou o tempo de espera com vTaskDelay.
2. Altere a prioridade relativa entre duas tasks e observe quem domina a execução.
3. Altere a lógica do botão entre ativo em nível e alternância por borda.

## O que registrar

- Configuração inicial utilizada (pinos, tempos, limiares e componentes).
- Modificações realizadas no código e/ou no circuito.
- Efeito observado após cada modificação.
- Conclusão do grupo sobre a relação entre ajuste e comportamento.

## Três questionamentos

1. Como o sistema reagiu ao pressionamento rápido ou repetido do botão?

   O sistema alternou o estado da variável `habilitaPisca` a cada detecção de borda de descida do botão, como a task do botão faz a leitura a cada 80 ms, pressionamentos muito rápidos podem não ser percebidos, enquanto pressionamentos repetidos dentro desse intervalo podem ser filtrados pelo atraso da task.

2. Qual alteração teve maior impacto: prioridade, sincronização, fila ou tempo de espera?
   Nesta prática, o tempo de espera definido com `vTaskDelay` teve o maior impacto observável, pois o atraso de 80 ms na task do botão influencia a sensibilidade da leitura, enquanto o atraso de 800 ms na task do LED define a velocidade do pisca. Como as duas tasks usam a mesma prioridade, a alteração de prioridade não foi o fator dominante neste caso.

3. Que cuidado de projeto você adotaria se esta prática fosse levada para um sistema real?
   Em um sistema real, seria importante tratar o debounce do botão de forma mais robusta e proteger o compartilhamento da variável `habilitaPisca`, por exemplo usando mecanismos de sincronização do FreeRTOS.
