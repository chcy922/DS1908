#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ�Լ�..
#include <string.h>   // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>    // _getch, putch  .. MS��� C ��ǥ�� �Լ�
#include <time.h>     // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() ��  ���� C �Լ� ���� 
#pragma warning(disable:4477)   // unsigned <--> signed ���� ����

#include "ListBaseStack.h"

int main(int argc, char** argv)
{
	Stack stack;
	Data data;

	stack_init(&stack);   // ���� ������ �ʱ�ȭ

	// ������ push
	stack_push(&stack, 1);
	stack_push(&stack, 2);
	stack_push(&stack, 3);
	stack_push(&stack, 4);
	stack_push(&stack, 5);

	// ������ pop
	stack_pop(&stack, &data);
	printf("pop--> %d\n", data);  // 5
	stack_pop(&stack, &data);
	printf("pop--> %d\n", data);  // 4

	while (!stack_is_empty(&stack))   // 3   2    1 
	{
		stack_pop(&stack, &data);
		printf("pop--> %d\n", data);
	}


	stack_destroy(&stack);  // ��������

	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()