 /**
 * @file    Examen1.c
 * @brief   Application entry point.
 */

#include "MK64F12.h"
#include "GPIO.h"
#include "bits.h"
#include "RGB.h"
#include "NVIC.h"
#include "PIT.h"

#define SYSTEM_CLOCK (21000000U)
#define DELAY (1.0F)

gpio_pin_control_register_t led_enable = GPIO_MUX1;
gpio_pin_control_register_t sw_enable = GPIO_MUX1 | GPIO_PE | GPIO_PS |
										INTR_FALLING_EDGE;

int main(void) {

	void (*led_turn[5])();

	led_turn[0] = blue_on;
	led_turn[1] = red_on;
	led_turn[2] = yellow_on;
	led_turn[3] = purple_on;
	led_turn[4] = cyan_on;

	GPIO_clock_gating(GPIO_B);
	GPIO_clock_gating(GPIO_E);

	GPIO_pin_control_register(GPIO_B, bit_21, & led_enable);
	GPIO_pin_control_register(GPIO_B, bit_22, & led_enable);
	GPIO_pin_control_register(GPIO_E, bit_26, & led_enable);

	red_off();
	blue_off();
	green_off();

	GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT, bit_21);
	GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT, bit_22);
	GPIO_data_direction_pin(GPIO_E, GPIO_OUTPUT, bit_26);
}
