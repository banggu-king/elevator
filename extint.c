#include "extint.h"
#include "stepmotor.h"
#include "extern.h"

extern uint8_t stepmotor_state;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch (GPIO_Pin)
	{
	case GPIO_PIN_0: // PA0 / 1��
		if (arrive == 1) // �����ؾ��� ���� 1���� �� 1���� ������ ���
		{
			flag = 1;
		}
		break;
	case GPIO_PIN_1: // PB1 / 2��
		if (arrive == 2) // �����ؾ��� ���� 2���� �� 2���� ������ ���
		{
			flag = 1;
		}
		break;
	case GPIO_PIN_2: // PB2 / 3��
		if (arrive == 3) // �����ؾ��� ���� 3���� �� 3���� ������ ���
		{
			flag = 1;
		}
		break;
	case GPIO_PIN_4: // PB4 / 4��
		if (arrive == 4) // �����ؾ��� ���� 4���� �� 4���� ������ ���
		{
			flag = 1;
		}
		break;
	}
}
