#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ�Լ�..
#include <string.h>   // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>    // _getch, putch  .. MS��� C ��ǥ�� �Լ�
#include <time.h>     // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() ��  ���� C �Լ� ���� 
#pragma warning(disable:4477)   // unsigned <--> signed ���� ����

/*
	C, C++ ���� �ð� �����ϱ�
	���1: time() ���
	���2: clock() ���
*/

int main(int argc, char** argv)
{
	// time() ���
	//{
	//	// time.h �� time(NULL) ���
	//	time_t start, end;

	//	int sum = 0;
	//	printf("time()���� ����\n");
	//	start = time(NULL);
	//	for (int i = 0; i < 100000; i++) {
	//		for (int j = 0; j < 100000; j++) {
	//			sum += i * j;
	//		}
	//	}
	//	end = time(NULL);
	//	double result = (double)(end - start);
	//	printf("%f s\n", result);   // ����ð� ���
	//}

	// clock() ���
	{
		clock_t start, end;

		int sum = 0;
		printf("clock()���� ����\n");
		start = clock();
		for (int i = 0; i < 100000; i++) {
			for (int j = 0; j < 100000; j++) {
				sum += i * j;
			}
		}
		end = clock();
		long result = (long)(end - start);
		printf("%ld ms\n", result);   // ����ð� ���
	}


	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()