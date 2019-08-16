#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ�Լ�..
#include <string.h>   // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>    // _getch, putch  .. MS��� C ��ǥ�� �Լ�
#include <time.h>     // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() ��  ���� C �Լ� ���� 
#pragma warning(disable:4477)   // unsigned <--> signed ���� ����

#include "ListQueue.h"

int main(int argc, char** argv)
{
	// Queue ������ �ʱ�ȭ
	Queue q;
	Data data;
	queue_init(&q);   // ť �ʱ�ȭ

	// ������ �ֱ� enqueue
	queue_enq(&q, 1); 
	queue_enq(&q, 2);
	queue_enq(&q, 3);
	queue_enq(&q, 4);
	queue_enq(&q, 5);

	// ������ ������ dequeue
	queue_deq(&q, &data);  printf("%d ", data);     // <--- 1
	queue_deq(&q, &data);  printf("%d ", data);     // <--- 2

	while (!queue_is_empty(&q))
	{
		queue_deq(&q, &data);  printf("%d ", data);
	}

	queue_destroy(&q);  // ť ����


	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()