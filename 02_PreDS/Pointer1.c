#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ�Լ�..
#include <string.h>   // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>    // _getch, putch  .. MS��� C ��ǥ�� �Լ�
#include <time.h>     // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() ��  ���� C �Լ� ���� 
#pragma warning(disable:4477)   // unsigned <--> signed ���� ����

/*

*/

int main(int argc, char** argv)
{
	for (int i = 0; i < 10; i++) {  // for �� �ȿ��� ����� �������� i
		printf("%d, ", i);
	}
	printf("\n");
	//printf("i = %d", i);  // �� ���� ���Ŀ��� i ��� ����.

	{
		int n = 10;
		{
			int n = 20;  // ��!?
			printf("n = %d\n", n);
		}
		printf("n = %d\n", n);
	}
	//printf("n = %d\n", n);

	{
		int  n = 100;
	}

	// �ּ� 
	{
		int n = 10;
		printf("n = %d\n", n);

		// �ּҿ����� &
		printf("n �� �ּҴ� %p\n", &n);   // ���� n �� �ּ�
	}
	printf("\n");
	// �ּҸ� ��� Ÿ��: ������ 
	{
		int n = 100;
		int *p;      // p �� int Ÿ���� �ƴ϶� int* Ÿ��

		p = &n;   // ������ ���� p ��  'n�� �ּ�' ����
		printf("p = %p, &n = %p ���� \n", p, &n);

	}






	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()