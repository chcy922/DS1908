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
	// �迭 ���� �� �ʱ�ȭ
	int arr[5] = {1, 2, 3, 4, 5};   // int Ÿ�� 5���� ��� �迭 arr �� ����

	int i;
	// �迭[n] �� index �� 0 ���� ���� ~ n - 1����
	for (i = 0; i < 5; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	// �迭�̸� arr ..  �迭������� �ϳ�.  ���������� '������' ��!
	printf("arr = %d\n", arr);
	printf("arr = %p\n", arr);

	// sizeof() ������, byte ���� �뷮 ����
	int n = 100;
	printf("sizeof(n) = %d\n", sizeof(n));
	printf("sizeof(double) = %d\n", sizeof(double));
	printf("sizeof(arr[0]) = %d\n", sizeof(arr[0]));
	printf("sizeof(arr) = %d\n", sizeof(arr));   // �迭�� ũ��(size)

	// �迭������ ����
	// �迭�� ���� length
	printf("length = %d\n", sizeof(arr) / sizeof(arr[0]));






	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()