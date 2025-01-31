/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  -
 *
 *        Version:  1.0
 *        Created:  30/01/2025 21:20:20
 *       Revision:  none
 *       Compiler:  -
 *
 *         Author:  Isaac Vinicius, isaacvinicius2121@alu.ufc.br
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
*/

#include <LMICNode.h>
#include <Arduino.h>
#include <string.h>
#include <pluviometro.hpp>
#include <dht22.hpp>
uint16_t counterValue = 1;
char data[243] = "";
LMICNode node;
// Buffer para armazenar a mensagem formatada
char message[100] = "";


//  █ █ █▀▀ █▀▀ █▀▄   █▀▀ █▀█ █▀▄ █▀▀   █▀▄ █▀▀ █▀▀ ▀█▀ █▀█
//  █ █ ▀▀█ █▀▀ █▀▄   █   █ █ █ █ █▀▀   █▀▄ █▀▀ █ █  █  █ █
//  ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀   ▀▀▀ ▀▀▀ ▀▀  ▀▀▀   ▀▀  ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀

void prepareUplink(){
    // This function must be defined by the user. Define the date it will be sent.

    // Use globals: LMICNode::fPort, LMICNode::mydata, LMICNode::sizeData
    
    // This is where the main work is performed like
    // reading sensor and GPS data and schedule uplink
    // messages if anything needs to be transmitted.

    // Verifica se há mudanças na contagem do pluviômetro
    if (pluviometro.contador != pluviometro.ultima_contagem) {
        // Atualiza a última contagem exibida
        pluviometro.ultima_contagem = pluviometro.contador;
    }
    dht_reading reading;     // Estrutura para armazenar os dados do DHT22
    read_from_dht(&reading); // Preenche os dados na estrutura passada por referência

    // Formata a mensagem com os valores de umidade e temperatura
    snprintf(message, sizeof(message), "Hum = %.1f%%, Temp = %.1fC, Prec = %.4f mm",
                reading.humidity, reading.temp_celsius, pluviometro.contador * PRECIPITACAO);
    // Reseta o contador do pluviometro
    pluviometro.contador = 0;
    pluviometro.ultima_contagem = 0;
        // imprime a mensagem formatada
    BSF::serial.print(message);

    strcpy((char*)LMICNode::mydata, message);
    strcpy(message, "");
    LMICNode::sizeData = strlen((char*)LMICNode::mydata);
    LMICNode::printSpaces(BSF::serial, MESSAGE_INDENT);
    BSF::serial.print("Mydata: ");
    BSF::serial.println((char*)LMICNode::mydata);
    LMICNode::printSpaces(BSF::serial, MESSAGE_INDENT);
    BSF::serial.print("Sizedata: ");
    BSF::serial.println(LMICNode::sizeData);
    LMICNode::fPort = 10;
    LMICNode::scheduleUplink(LMICNode::fPort, LMICNode::mydata, LMICNode::sizeData);
}

//  █ █ █▀▀ █▀▀ █▀▄   █▀▀ █▀█ █▀▄ █▀▀   █▀▀ █▀█ █▀▄
//  █ █ ▀▀█ █▀▀ █▀▄   █   █ █ █ █ █▀▀   █▀▀ █ █ █ █
//  ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀   ▀▀▀ ▀▀▀ ▀▀  ▀▀▀   ▀▀▀ ▀ ▀ ▀▀ 


void setup() {

    node.initHardware();

    // Setting the data rate is optional. 
    // By default, it is set to DR_SF7.
    node.setDataRate(DR_SF8);
    
    // This function makes the initial configurations of LMIC. 
    // Then, all the configurations you need must be defined beforehand.
    node.initLmic();  

    //  █ █ █▀▀ █▀▀ █▀▄   █▀▀ █▀█ █▀▄ █▀▀   █▀▄ █▀▀ █▀▀ ▀█▀ █▀█
    //  █ █ ▀▀█ █▀▀ █▀▄   █   █ █ █ █ █▀▀   █▀▄ █▀▀ █ █  █  █ █
    //  ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀   ▀▀▀ ▀▀▀ ▀▀  ▀▀▀   ▀▀  ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀

    inicializa_sensor_pluviometro(&pluviometro);
    _gpio_init(DHT_PIN);

    // Place code for initializing sensors etc. here.

    //  █ █ █▀▀ █▀▀ █▀▄   █▀▀ █▀█ █▀▄ █▀▀   █▀▀ █▀█ █▀▄
    //  █ █ ▀▀█ █▀▀ █▀▄   █   █ █ █ █ █▀▀   █▀▀ █ █ █ █
    //  ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀   ▀▀▀ ▀▀▀ ▀▀  ▀▀▀   ▀▀▀ ▀ ▀ ▀▀ 

    node.initTransmission();
}

void loop() {  
    node.loop_node();
}
