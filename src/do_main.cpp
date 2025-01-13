#include "do_main.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

int now_is_auto_play = 1;

void ui_mian(void)
{
    ui_init();

    if (is_auto_play)
    {
        auto_play();
    }

    xTaskCreatePinnedToCore(
        [](void *pvParameters)
        {
            while (1)
            {
                int i = gpio_get_level(GPIO_NUM_9);
                vTaskDelay(20 / portTICK_PERIOD_MS);
                if (i == 0)
                {
                    now_is_auto_play = !now_is_auto_play;
                    ESP_LOGI("AUTO_PLAY", "now_is_auto_play is changed to %d", now_is_auto_play);
                }
            }
        },
        "lvglpx", 4096, NULL, 1, NULL, 1);
}

void auto_play(void)
{
    xTaskCreatePinnedToCore(
        [](void *pvParameters)
        {
            while (1)
            {
                if (now_is_auto_play == 0)
                {
                    vTaskDelay(1000 / portTICK_PERIOD_MS);
                    continue;
                }
                else
                {
                    vTaskDelay(2000 / portTICK_PERIOD_MS);
                    if (now_is_auto_play == 0)
                    {
                        continue;
                    }
                    _ui_screen_change(ui_Screen4, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
                    vTaskDelay(3000 / portTICK_PERIOD_MS);
                    if (now_is_auto_play == 0)
                    {
                        continue;
                    }
                    _ui_screen_change(ui_Screen7, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
                    vTaskDelay(3000 / portTICK_PERIOD_MS);
                    if (now_is_auto_play == 0)
                    {
                        continue;
                    }
                    _ui_screen_change(ui_Screen11, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
                    vTaskDelay(3000 / portTICK_PERIOD_MS);
                    if (now_is_auto_play == 0)
                    {
                        continue;
                    }
                    _ui_screen_change(ui_Screen6, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
                    vTaskDelay(3000 / portTICK_PERIOD_MS);
                    if (now_is_auto_play == 0)
                    {
                        continue;
                    }
                    _ui_screen_change(ui_Screen8, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
                    vTaskDelay(3000 / portTICK_PERIOD_MS);
                    if (now_is_auto_play == 0)
                    {
                        continue;
                    }
                    _ui_screen_change(ui_Screen9, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
                    vTaskDelay(3000 / portTICK_PERIOD_MS);
                    if (now_is_auto_play == 0)
                    {
                        continue;
                    }
                    _ui_screen_change(ui_Screen10, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
                    vTaskDelay(3000 / portTICK_PERIOD_MS);
                    if (now_is_auto_play == 0)
                    {
                        continue;
                    }
                    _ui_screen_change(ui_Screen5, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
                }
            }
        },
        "lvglautoplay", 8192, NULL, 1, NULL, 1);
}