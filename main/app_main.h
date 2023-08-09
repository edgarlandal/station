#ifndef APP_MAIN_H
#define APP_MAIN_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#if CONFIG_ESP_WIFI_AUTH_OPEN
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_OPEN
#elif CONFIG_ESP_WIFI_AUTH_WEP
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WEP
#elif CONFIG_ESP_WIFI_AUTH_WPA_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA_PSK
#elif CONFIG_ESP_WIFI_AUTH_WPA2_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA2_PSK
#elif CONFIG_ESP_WIFI_AUTH_WPA_WPA2_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA_WPA2_PSK
#elif CONFIG_ESP_WIFI_AUTH_WPA3_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA3_PSK
#elif CONFIG_ESP_WIFI_AUTH_WPA2_WPA3_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA2_WPA3_PSK
#elif CONFIG_ESP_WIFI_AUTH_WAPI_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WAPI_PSK
#endif

/* WIFI Datas */
#define SSID      "IZZI-D53C"
#define PASS      "TE3LrBLqEgQQ"
#define RETRY  10

#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1

/* MQTT Datas */
typedef struct mqtt
{
    char* topic;
    char* data;
    int topic_len;
    int data_len;
} mqtt_t;
volatile uint32_t millisCount = 0;


/* WIFI Funtions */
void init_wifi();
static esp_err_t wifi_event_handler(void *ctx, system_event_t *event);

/* MQTT Funtions */
void init_mqtt(char * broker); 
static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data);

esp_err_t mqtt_event_handler_cb(esp_mqtt_event_handle_t event);
void send_data_mqtt(const char* topic, char* device ,uint32_t value);
void get_value(esp_mqtt_event_handle_t event);

/* OTHER FUNTIONS */
void delayMs(uint32_t time)
{
  vTaskDelay(time / portTICK_PERIOD_MS);
}

uint64_t milis()
{
  return esp_timer_get_time() / 1000;
}

#endif