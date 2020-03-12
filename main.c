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

uint8_t g_timer_end_flag = FALSE;

void pit_handler(void)
{
	g_timer_end_flag = TRUE;
}

int main(void) {


	void (*led_turn[5])();

	led_turn[0] = blue_on;
	led_turn[1] = red_on;
	led_turn[2] = yellow_on;
	led_turn[3] = purple_on;
	led_turn[4] = cyan_on;

	GPIO_clock_gating(GPIO_A);
	GPIO_clock_gating(GPIO_B);
	GPIO_clock_gating(GPIO_C);
	GPIO_clock_gating(GPIO_E);

	GPIO_pin_control_register(GPIO_B, bit_21, & led_enable);
	GPIO_pin_control_register(GPIO_B, bit_22, & led_enable);
	GPIO_pin_control_register(GPIO_E, bit_26, & led_enable);
	GPIO_pin_control_register(GPIO_A, bit_4, & sw_enable);
	GPIO_pin_control_register(GPIO_C, bit_6, & sw_enable);

	red_off();
	blue_off();
	green_off();

	GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT, bit_21);
	GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT, bit_22);
	GPIO_data_direction_pin(GPIO_E, GPIO_OUTPUT, bit_26);

	GPIO_data_direction_pin(GPIO_A, GPIO_INPUT, bit_4);
	GPIO_data_direction_pin(GPIO_C, GPIO_INPUT, bit_6);

	NVIC_enable_interrupt_and_priotity(PORTA_IRQ,PRIORITY_5);
	NVIC_enable_interrupt_and_priotity(PORTC_IRQ,PRIORITY_5);

	PIT_clock_gating();

	PIT_delay(PIT_0, SYSTEM_CLOCK, DELAY);

	PIT_enable();

	uint8_t init_counter = 0;
	uint8_t led_sw2_counter = 0;

	while(1){
		if(TRUE == GPIO_get_irq_status(GPIO_A)){

		}

	}
}
