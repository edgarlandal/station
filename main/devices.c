#include "devices.h"

void init_devices()
{
    gpio_pad_select_gpio(LED);
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);


    gpio_set_direction(BTN, GPIO_MODE_INPUT); 
    gpio_set_pull_mode(BTN, GPIO_PULLUP_ONLY);
    
    // adc1_config_width(SIZE_12);
    // adc1_config_channel_atten(ADC, ADC_ATTEN_DB_11);

    DHT11_init(DHT11);
}

uint8_t get_LED_state()
{
    return (uint8_t)gpio_get_level(LED);
}

uint8_t get_BTN_state()
{
    return (uint8_t)gpio_get_level(BTN);
}

void set_LED_state(uint8_t state)
{
    gpio_set_level(LED, state);
}

uint16_t get_ADC_value()
{
    return (uint16_t)adc1_get_raw(ADC);
}

uint16_t get_DHT11_value_tem()
{
    return (uint16_t) DHT11_read().temperature;
}

uint16_t get_DHT11_value_hum()
{
    return (uint16_t) DHT11_read().humidity;
}