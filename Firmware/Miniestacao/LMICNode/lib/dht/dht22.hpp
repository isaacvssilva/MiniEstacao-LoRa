/*
 * =====================================================================================
 *
 *       Filename:  dht22.hpp
 *
 *    Description:  -
 *
 *        Version:  1.0
 *        Created:  16/01/2025 21:13:28
 *       Revision:  none
 *       Compiler:  -
 *
 *         Author:  Isaac Vinicius, isaacvinicius2121@alu.ufc.br
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
*/

#ifndef DHT22_HPP
#define DHT22_HPP
#include <LMICNode.h>
#include <sys/types.h>

// Definição do pino de leitura do DHT
const uint DHT_PIN = 5;
const uint MAX_TIMINGS = 85;

// Estrutura que armazena os dados de leitura
typedef struct {
    float humidity;
    float temp_celsius;
} dht_reading;

// Função que lê os dados do sensor DHT
void read_from_dht(dht_reading *result);

#endif
/*****************************END OF FILE**************************************/