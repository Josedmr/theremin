#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "myADC.h"
#include "myPWM.h"

void app_main(void)
{

    myADC_setup();
    pwm_setup();

    while (1)
    {
        int waarde = myADC_waarde();
        printf("ADC waarde: %d\n", waarde);

        pwm_set(waarde);

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

