/*
 * =====================================================================================
 *
 *       Filename:  pluviometro.cpp
 *
 *    Description:  -
 *
 *        Version:  1.0
 *        Created:  16/01/2025 13:07:35
 *       Revision:  none
 *       Compiler:  -
 *
 *         Author:  Isaac Vinicius, isaacvinicius2121@alu.ufc.br
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
*/

#include "pluviometro.hpp"

SensorPluviometro pluviometro;

void gpio_callback(uint gpio, uint32_t events) {
  unsigned long current_time = to_ms_since_boot(get_absolute_time()); // Tempo atual em ms
  if (gpio == SENSOR_HALL_PIN && (events & GPIO_IRQ_EDGE_RISE)) {
    if (current_time - pluviometro.last_interrupt_time > DEBOUNCE_DELAY) { // Verifica o debounce
      pluviometro.last_interrupt_time = current_time; // Atualiza o tempo da última interrupção
      pluviometro.contador++; // Incrementa o contador
    }
  }
}

void inicializa_sensor_pluviometro(SensorPluviometro *sensor) {
  sensor->contador = 0;
  sensor->ultima_contagem = 0; // Inicializa a última contagem exibida
  sensor->last_interrupt_time = 0;

  _gpio_init(SENSOR_HALL_PIN);
  gpio_set_dir(SENSOR_HALL_PIN, GPIO_IN);
  gpio_pull_up(SENSOR_HALL_PIN);
  gpio_set_irq_enabled_with_callback(SENSOR_HALL_PIN, GPIO_IRQ_EDGE_RISE, true, &gpio_callback);
}
/*****************************END OF FILE**************************************/