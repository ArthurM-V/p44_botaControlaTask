#include <Arduino.h>

volatile bool habilitaPisca = false;

void taskBotao(void *pv) {
  pinMode(33, INPUT_PULLUP);
  bool ultima = HIGH;
  while (true) {
    bool leitura = digitalRead(33);
    if (ultima == HIGH && leitura == LOW) {
      habilitaPisca = !habilitaPisca;
    }
    ultima = leitura;
    vTaskDelay(pdMS_TO_TICKS(80));
  }
}

void taskLed(void *pv) {
  pinMode(25, OUTPUT);
  while (true) {
    if (habilitaPisca) digitalWrite(25, !digitalRead(25));
    else digitalWrite(2, LOW);
    vTaskDelay(pdMS_TO_TICKS(800));
  }
}

void setup() {
  xTaskCreatePinnedToCore(taskBotao, "Botao", 2048, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(taskLed, "Led", 2048, NULL, 1, NULL, 1);
}

void loop() { }
