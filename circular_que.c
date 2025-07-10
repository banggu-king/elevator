#include <stdio.h>
#include <stdlib.h>
#include "circularQueue.h"
#include "extern.h"

#define TRUE 1
#define FALSE 0
#define QUEUE_MAX 10

int front1 = -1;  // read index
int rear1 = -1;   // insert index
int queue[QUEUE_MAX];

int queue_empty(void)
{
	if (front1 == rear1) //front�� rear�� ������ ť�� ����ִ� ����
		return TRUE;
	else return FALSE;
}

int queue_full(void)
{
	int tmp = (rear1 + 1) % QUEUE_MAX; //���� ť���� rear+1�� MAX�� ���� ����������
	if (tmp == front1) //front�� ������ ť�� ������ �ִ� ����
		return TRUE;
	else
		return FALSE;
}
void insert_queue(int value)
{
	if (queue_full())
	{
		printf("Queue is Full.\n");
	}
	else
	{
		rear1 = (rear1 + 1) % QUEUE_MAX;
		queue[rear1] = value;
	}

}
int check_queue(void)
{
	return queue[rear1];
}

void de_queue()
{
	if (queue_empty())
		printf("Queue is Empty.\n");
	else
	{
		front1 = (front1 + 1) % QUEUE_MAX;
	}
}

void queue_init() // �� �� ��� front�� rear�� ������ġ ����Ŵ
{
	front1 = -1;
	rear1 = -1;
}