#include "extint.h"
#include "stepmotor.h"
#include "extern.h"

extern uint8_t stepmotor_state;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch (GPIO_Pin)
	{
	case GPIO_PIN_0: // PA0 / 1類
		if (arrive == 1) // 紫雜п撿й 類檜 1類橾 陽 1類縑 紫雜и 唳辦
		{
			flag = 1;
		}
		break;
	case GPIO_PIN_1: // PB1 / 2類
		if (arrive == 2) // 紫雜п撿й 類檜 2類橾 陽 2類縑 紫雜и 唳辦
		{
			flag = 1;
		}
		break;
	case GPIO_PIN_2: // PB2 / 3類
		if (arrive == 3) // 紫雜п撿й 類檜 3類橾 陽 3類縑 紫雜и 唳辦
		{
			flag = 1;
		}
		break;
	case GPIO_PIN_4: // PB4 / 4類
		if (arrive == 4) // 紫雜п撿й 類檜 4類橾 陽 4類縑 紫雜и 唳辦
		{
			flag = 1;
		}
		break;
	}
}
