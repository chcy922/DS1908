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
	// �迭 ���� : �ڷᱸ��
	int arr[5] = { 1, 2, 3, 4, 5 };

	// �迭�� ����� ���� �� ���ϱ� : �˰���
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += arr[i];
	}
	printf("�հ� : %d\n", sum);


	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()