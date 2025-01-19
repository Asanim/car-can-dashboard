// The following is example / workshop code from http://www.jczn1688.com/ 
// Obtained from the following URL: http://pan.jczn1688.com/directlink/1/ESP32%20module/1.28inch_ESP32-2424S012.zip
// This is demo code pre loaded on the development board: https://www.aliexpress.com/item/1005005561489118.html

#include "main_task_handler.h"
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
                int i = digitalRead(9);
                delay(20);
                if (i == 0)
                {
                   
                    now_is_auto_play = !now_is_auto_play;
                    Serial.println("now_is_auto_play is changed to " + String(now_is_auto_play));
                 
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
                    delay(1000);
                    continue;
                }
                else
                {
                    delay(2000);
                    if (now_is_auto_play == 0)
                    {
                        continue;
                    }
                    _ui_screen_change(ui_Screen4, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
                    delay(3000);
                    if (now_is_auto_play == 0)
                    {
                        continue;
                    }
                    _ui_screen_change(ui_Screen7, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
                    delay(3000);
                    if (now_is_auto_play == 0)
                    {
                        continue;
                    }
                    _ui_screen_change(ui_Screen11, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
                    delay(3000);
                    if (now_is_auto_play == 0)
                    {
                        continue;
                    }
                    _ui_screen_change(ui_Screen6, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
                    delay(3000);
                    if (now_is_auto_play == 0)
                    {
                        continue;
                    }
                    _ui_screen_change(ui_Screen8, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
                    delay(3000);
                    if (now_is_auto_play == 0)
                    {
                        continue;
                    }
                    _ui_screen_change(ui_Screen9, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
                    delay(3000);
                    if (now_is_auto_play == 0)
                    {
                        continue;
                    }
                    _ui_screen_change(ui_Screen10, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
                    delay(3000);
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

      cfg.spi_host = SPI2_HOST; // 使用するSPIを選択  ESP32-S2,C3 : SPI2_HOST or SPI3_HOST / ESP32 : VSPI_HOST or HSPI_HOST
      // ※ ESP-IDFバージョンアップに伴い、VSPI_HOST , HSPI_HOSTの記述は非推奨になるため、エラーが出る場合は代わりにSPI2_HOST , SPI3_HOSTを使用してください。
      cfg.spi_mode = 0;                  // SPI通信モードを設定 (0 ~ 3)