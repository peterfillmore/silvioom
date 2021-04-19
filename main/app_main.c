// Copyright 2016-2017 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "esp_attr.h"

#include "esp32/rom/cache.h"
#include "esp32/rom/ets_sys.h"
#include "esp32/rom/spi_flash.h"
#include "esp32/rom/crc.h"

#include "soc/soc.h"
#include "soc/dport_reg.h"
#include "soc/io_mux_reg.h"
#include "soc/efuse_reg.h"
#include "soc/rtc_cntl_reg.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdlib.h>
#include "esp_err.h"
#include "nvs_flash.h"
#include "esp_partition.h"

#include "driver/uart.h"
#include "driver/gpio.h"
//#include "sdkconfig.h"
#include <string.h>

#undef false
#undef true
#include "i_system.h"

#include "spi_lcd.h"

#include "badge.h"
#include "badge_eink_fb.h"
#include "badge_eink_lut.h"

/**
 * This is an example which echos any data it receives on configured UART back to the sender,
 * with hardware flow control turned off. It does not use UART driver event queue.
 *
 * - Port: configured UART
 * - Receive (Rx) buffer: on
 * - Transmit (Tx) buffer: off
 * - Flow control: off
 * - Event queue: off
 * - Pin assignment: see defines below (See Kconfig)
 */

//#define ECHO_TEST_TXD (CONFIG_EXAMPLE_UART_TXD)
//#define ECHO_TEST_RXD (CONFIG_EXAMPLE_UART_RXD)
//#define ECHO_TEST_RTS (UART_PIN_NO_CHANGE)
//#define ECHO_TEST_CTS (UART_PIN_NO_CHANGE)
#define ECHO_TEST_TXD 33 
#define ECHO_TEST_RXD 32 
#define ECHO_TEST_RTS (UART_PIN_NO_CHANGE)
#define ECHO_TEST_CTS (UART_PIN_NO_CHANGE)


#define ECHO_UART_PORT_NUM      2 
#define ECHO_UART_BAUD_RATE     9600 
#define ECHO_TASK_STACK_SIZE    2048 

#define BUF_SIZE (1024)

#define DISP_SIZE_X 128

/** the number of vertical pixels
 * @note the display is rotated 90 degrees
 */
#define DISP_SIZE_Y 296

/** the number of bytes in a pixel row
 * @note the display is rotated 90 degrees
 */
#define DISP_SIZE_X_B ((DISP_SIZE_X + 7) >> 3)


extern void jsInit();


void doomEngineTask(void *pvParameters)
{
    char const *argv[]={"doom","-cout","ICWEFDA", NULL};
    doom_main(3, argv);
}

static void echo_task(void *arg)
{
    /* Configure parameters of an UART driver,
     * communication pins and install the driver */
    uart_config_t uart_config = {
        .baud_rate = ECHO_UART_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };
    int intr_alloc_flags = 0;

#if CONFIG_UART_ISR_IN_IRAM
    intr_alloc_flags = ESP_INTR_FLAG_IRAM;
#endif

    ESP_ERROR_CHECK(uart_driver_install(ECHO_UART_PORT_NUM, BUF_SIZE * 2, 0, 0, NULL, intr_alloc_flags));
    ESP_ERROR_CHECK(uart_param_config(ECHO_UART_PORT_NUM, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(ECHO_UART_PORT_NUM, ECHO_TEST_TXD, ECHO_TEST_RXD, ECHO_TEST_RTS, ECHO_TEST_CTS));

    // Configure a temporary buffer for the incoming data
    uint8_t *data = (uint8_t *) malloc(BUF_SIZE);
        const int uart_num = UART_NUM_2;
        uint8_t serial_data[128];
        int length = 0;

    while (1) {
        // Read data from the UART
        //int len = uart_read_bytes(ECHO_UART_PORT_NUM, data, BUF_SIZE, 20 / portTICK_RATE_MS);
        // Write data back to the UART
        char* test_str = "This is a test string.\n";
        uart_write_bytes(ECHO_UART_PORT_NUM, test_str, strlen(test_str));
        vTaskDelay(1000 / portTICK_PERIOD_MS);
         
        ESP_ERROR_CHECK(uart_get_buffered_data_len(uart_num, (size_t*)&length));
        length = uart_read_bytes(uart_num, serial_data, length, 100);
        printf("received %s\n", serial_data);         
    }
}

void app_main()
{
	int i;
	const esp_partition_t* part;
	spi_flash_mmap_handle_t hdoomwad;
	esp_err_t err;
    
	part=esp_partition_find_first(66, 6, NULL);
	if (part==0) printf("Couldn't find wad part!\n");

    //badge_init();
    //err = badge_eink_fb_init();
    //assert( err == ESP_OK );
	
    //spi_lcd_init();
	jsInit();
	xTaskCreatePinnedToCore(&doomEngineTask, "doomEngine", 22480, NULL, 5, NULL, 0);
    //xTaskCreate(echo_task, "uart_echo_task", ECHO_TASK_STACK_SIZE, NULL, 10, NULL);
    //uint8_t eink_type = BADGE_EINK_DEFAULT;
     //badge_nvs_get_u8("badge", "eink.dev.type", &eink_type);
    //badge_eink_init(eink_type);
    //badge_init();
    //badge_eink_fb_init();

    //uint32_t *tmpbuf = (uint32_t *) badge_eink_fb;
    //
    //memset(tmpbuf, 0xff, DISP_SIZE_X_B * DISP_SIZE_Y);
/*
    int i;
    for (i = 0; i < 16; i++) {
      int px = dots[i] & 127;
      int py = dots[i] >> 7;
      tmpbuf[(px >> 5) + py*4] &= ~( 0x80000000 >> (px & 31) );
    }
*/
    //struct badge_eink_update eink_upd = {
    //  .lut      = BADGE_EINK_LUT_DEFAULT,
    //  .reg_0x3a = 26,  // 2 dummy lines per gate
    //  .reg_0x3b = 0x08,  // 30us per line
    //  .y_start  = 0,
    //  .y_end    = 295,
    //};
    //badge_eink_update(tmpbuf, &eink_upd);
 
    
}





