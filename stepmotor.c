#include "stepmotor.h"
#include "button.h"
#include "extern.h"

/*
 * RPM(Revolutions Per Minutes : �д� ȸ����)
 * 1�� -> 60�� = 60,000,000us
 * 1�� : 1000ms --> 1ms : 1000us * 1000ms = 1,000,000us
 * 1���� ȸ��: 4096 step �ʿ�
 * 4096 / 8 ==> 512sequence : 360�� ȸ��
 * 1 sequence (8step) : 0.70312��
 * 0.70312 x 512 sequence : 360�� ȸ��
 *  ---- RPM ���� ----
 *  ��) 1�п� 13ȸ���� �ִ� �ӵ�
 *  13ȸ�� : 60,000,000us(1��) / 4096 / 13 ==> step�� step���� ���� time : 1126us
 *  1126us x 4096(1ȸ�� �ϴµ� �ʿ� ����) = 4,615,384us
 *  								 = 4615ms(4.6��)
 * 60�� / 4.6�� (1ȸ�� �ϴµ� �ҿ� �ð�) : 13ȸ��
 */
uint8_t stepmotor_state = IDLE;
uint8_t current_state = 5;
uint8_t go = 0; // ���������Ͱ� �۵� ������ Ȯ�� ����
uint8_t arrive = 0;
uint8_t flag = 0; // �����ؼ� ���������Ͱ� ���ߴ°� check�ϴ� flag

void stepmotor_main(void);
void set_rpm(int rpm);
void stepmotor_drive(int step);

void set_rpm(int rpm) // rpm : 1 ~13
{
	delay_us(60000000 / 4096 / rpm);
	// �ִ� speed����(13) : delay_us(1126);
}
// stepmotor
void stepmotor_main(void)
{
#if 1 // OS

	if (!queue_empty() && !go) // ť�� ���� ����ְ�, ���������Ͱ� �۵� ���� �ƴ϶��
	{
		arrive = check_queue();
		go = 1;
		if (current_state < arrive) // ���� ���� �����ؾ��ϴ� ������ ���� ���
		{
			display_lcd(FW);
			stepmotor_state = FW;
		}
		else if (current_state > arrive) // ���� ���� �����ؾ��ϴ� ������ ���� ���
		{
			display_lcd(BW);
			stepmotor_state = BW;
		}
		else // ���� ���� �����ؾ��ϴ� ���� ���� ���
		{
			display_lcd(IDLE);
			stepmotor_state = IDLE;
		}
	}

	if (flag)
	{
		stepmotor_state = IDLE;
		display_lcd(IDLE);
		de_queue();
		current_state = arrive;
		arrive = 0;
		go = 0;
		flag = 0;
	}

	switch (stepmotor_state)
	{
	case IDLE:
		break;
	case FW:
		stepmotor_drive(FW);
		set_rpm(13); // 1126us wait
		break;
	case BW:
		stepmotor_drive(BW);
		set_rpm(13); // 1126us wait
		break;
	}
#endif
