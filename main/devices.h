#ifndef DEVICES_H
#define DEVICES_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "devices/dht11.h"

#define LED GPIO_NUM_2
#define BTN GPIO_NUM_13
#define ADC GPIO_NUM_36
#define DHT GPIO_NUM_32

#define SIZE_12 ADC_WIDTH_BIT_12

#define DHT11 GPIO_NUM_4

void init_devices();

uint8_t get_LED_state();
uint8_t get_BTN_state();

uint16_t get_ADC_value();

void set_LED_state(uint8_t state);

uint16_t get_DHT11_value_tem();
uint16_t get_DHT11_value_hum();

#endif