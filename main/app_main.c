/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_log.h"

#include "ds_timer.h"
#include "ds_spiffs.h"
#include "ds_system_data.h"
#include "ds_nvs.h"

#define CHIP_NAME "ESP32"

static const char *TAG = "MAIN APP";

static void test_task_example(void* arg)
{
    for(;;) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        printf("task run \n");
    }
}

void app_main(void)
{
    printf("Hello world!\n");

    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is %s chip with %d CPU core(s), WiFi%s%s, ",
            CHIP_NAME,
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Minimum free heap size: %d bytes\n", esp_get_minimum_free_heap_size());

    ESP_LOGI(TAG, "system init V1.1");

    ds_timer_init();

    init_spiffs();
    ds_spiffs_test();
    ds_spiffs_deinit();

    char *ssid="leo";
    char *psw="123456789";
    set_system_data_wifi_info(ssid,strlen(ssid),psw,strlen(psw));
    ds_nvs_init();
    ds_nvs_save_wifi_info();
    ds_nvs_read_wifi_info();

    xTaskCreate(test_task_example, "test_task_example", 2048, NULL, 10, NULL);

    while(1){
        printf("system run ...\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
