#include "button.h"
void init_button(void)
{
	GPIOC->PUPDR = 0x00000055;
}

void elevator_button_check(void) // 몇 번 버튼이 눌렸는지 check 후 Queue에 삽입 , os 1번
{
	static uint8_t led_data;
	static uint8_t led_data2;
	int button_state = 0;
	init_button();
	if (get_button(GPIOC, GPIO_PIN_0, BTN0) == BUTTON_PRESS)
	{
		button_state = 0 + 1;
		led_data = 0x03;
		beep();
	}
	else if (get_button(GPIOC, GPIO_PIN_1, BTN1) == BUTTON_PRESS)
	{
		button_state = 1 + 1;
		led_data = 0x0C;
		beep();
	}
	else if (get_button(GPIOC, GPIO_PIN_2, BTN2) == BUTTON_PRESS)
	{
		button_state = 2 + 1;
		led_data = 0x30;
		beep();
	}
	else if (get_button(GPIOC, GPIO_PIN_3, BTN3) == BUTTON_PRESS)
	{
		button_state = 3 + 1;
		led_data = 0xC0;
		beep();
	}

	if (!queue_full() && button_state != 0) // 만약 큐가 다 차지 않았고 버튼이 눌렸다면
	{
		insert_queue(button_state);
		button_state = 0;
	}

	if (led_data2 != led_data) {
		send_1byte74hc595_led(led_data);
		GPIOC->ODR &= ~LATCH2_74HC595_Pin;   // latch핀을 pull-down
		GPIOC->ODR |= LATCH2_74HC595_Pin;   // latch핀을 pull-up
		led_data2 = led_data;
	}
}