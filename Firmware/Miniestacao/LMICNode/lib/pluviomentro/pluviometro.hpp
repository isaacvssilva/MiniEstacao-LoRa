/*
 * =====================================================================================
 *
 *       Filename:  pluviometro.hpp
 *
 *    Description:  -
 *
 *        Version:  1.0
 *        Created:  16/01/2025 13:04:48
 *       Revision:  none
 *       Compiler:  -
 *
 *         Author:  Isaac Vinicius, isaacvinicius2121@alu.ufc.br
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
*/

#ifndef PLUVIOMETRO_HPP
#define PLUVIOMETRO_HPP

#include <Arduino.h>
#include <LMICNode.h>

#define SENSOR_HALL_PIN 6       // gpio sensor hall
#define DEBOUNCE_DELAY 200      // Debounce de 200 ms
#define PRECIPITACAO  0.841811  // Precipitação por tombo: 0.841811 mm
#define TEMPO_MAXIMO_SEM_CHUVA 10000
typedef struct {
  int contador;
  int ultima_contagem;       // Última contagem exibida
  float raio_mm;
  float volume_ml;
  volatile unsigned long last_interrupt_time;
} SensorPluviometro;

extern SensorPluviometro pluviometro;
void inicializa_sensor_pluviometro(SensorPluviometro *sensor);
#endif
/*****************************END OF FILE**************************************/