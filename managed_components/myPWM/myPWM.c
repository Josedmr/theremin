#include "myPWM.h"
#include "driver/ledc.h"

#define PWM_GPIO 18
#define PWM_CHANNEL LEDC_CHANNEL_0
#define PWM_TIMER LEDC_TIMER_0

void pwm_setup(void)
{
    ledc_timer_config_t timer = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_num = PWM_TIMER,
        .duty_resolution = LEDC_TIMER_13_BIT,
        .freq_hz = 4000,
        .clk_cfg = LEDC_AUTO_CLK
    };

    ledc_timer_config(&timer);

    ledc_channel_config_t channel = {
        .gpio_num = PWM_GPIO,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = PWM_CHANNEL,
        .timer_sel = PWM_TIMER,
        .duty = 0,
        .hpoint = 0
    };

    ledc_channel_config(&channel);
}

void pwm_set(int value)
{
    ledc_set_duty(LEDC_LOW_SPEED_MODE, PWM_CHANNEL, value);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, PWM_CHANNEL);
}