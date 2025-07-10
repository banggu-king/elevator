void fnd_time()
{
    uint8_t temp;
    read_time_ds1302();
    read_date_ds1302();

    static int i = 0;

    fnd_data[0] = ~(1 << (i + 4));      // �ڸ��� ����

    switch (i)
    {
    case 0:
        fnd_data[1] = fnd_font[ds1302.minutes % 10];
        break;
    case 1:
        fnd_data[1] = fnd_font[ds1302.minutes / 10];
        break;
    case 2:
        fnd_data[1] = fnd_font[ds1302.hours % 10];
        break;
    case 3:
        fnd_data[1] = fnd_font[ds1302.hours / 10];
        break;
    }

    for (int j = 0; j < 2; j++)
    {
        temp = fnd_data[j]; // ���� ������ (1����Ʈ)
        send_1byte74hc595_fnd(temp);
    }
    i++;
    i %= 4;
    GPIOB->ODR &= ~LATCH1_74HC595_Pin;   // latch���� pull-down
    GPIOB->ODR |= LATCH1_74HC595_Pin;   // latch���� pull-up
}