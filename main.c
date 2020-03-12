 /**
 * @file    Examen1.c
 * @brief   Application entry point.
 */

#include "MK64F12.h"
#include "bits.h"

int main(void) {
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
