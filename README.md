# MiniEstação Meteorológica com LoRa

Este projeto é uma miniestação meteorológica baseada no Raspberry Pi Pico (waveshare RP2040 zero), utilizando um sensor DHT22, um pluviômetro impresso em 3D e um módulo LoRa para transmissão dos dados.

## Características

- **Monitoramento remoto** de temperatura, umidade e chuva.
- **Baixo consumo de energia** com comunicação LoRa.
- **Pluviômetro modelado em 3D** para melhor precisão.

## Componentes Utilizados

- **Waveshare RP2040 zero**
- **DHT22 (Temperatura e Umidade)**
- **Módulo LoRa SX1276**
- **Pluviômetro 3D**
- **Bateria Li-Ion 18650**

### Default Pinout

| Waveshare RP2040 zero | Semtech SX1276 |
| ----------------- | -------------- |
| 3.3V | VCC |
| GND | GND |
| GPIO 1 | NSS / CS |
| GPIO 2 | SCK |
| GPIO 3 | MOSI |
| GPIO 4 | MISO |
| GPIO 8 | RESET |
| GPIO 14 | DIO0 |
| GPIO 15 | DIO1 |

| Waveshare RP2040 zero | DHT22      |
| ----------------- | -------------- |
| 3.3V | VCC |
| GND | GND |
| GPIO 5 | DATA(2) |

| Waveshare RP2040 zero | Sensor Hall A3144 |
| ----------------- | -------------- |
| 3.3V | VCC |
| GND | GND |
| GPIO 6 | D0 |
