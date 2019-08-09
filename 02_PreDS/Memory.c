#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ�Լ�..
#include <string.h>   // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>    // _getch, putch  .. MS��� C ��ǥ�� �Լ�
#include <time.h>     // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() ��  ���� C �Լ� ���� 
#pragma warning(disable:4477)   // unsigned <--> signed ���� ����

/*
	malloc, free
	callog, realloc

	memcpy, memset
*/

int main(int argc, char** argv)
{
	{
		// ���� �޸� �Ҵ� (Dynamic memory allocation)
		// (void*)malloc( �Ҵ� ���� �޸� �뷮 byte )

		int* arr = (int*)malloc(100);  // 100byte �޸� �Ҵ�
		arr[0] = 100;
		arr[1] = 200;

		//int n = 200;
		//arr = &n;  // �޸� ���� ����!

		free(arr);    // �Ҵ���� �޸� ����

		// �޸� ���� (memory leak) �Ҵ� ���� �޸𸮰� ���� ���� ����ä 
		// �����Ǿ� ��ġ �Ǵ� ����.
	}

	{
		int len = 1000000;
		int *arr = (int*)malloc(sizeof(int) * len);

		printf("arr[0]: %d\n", arr[0]);

		// �޸𸮸� �Ҵ� ������ �켱 �ʱ�ȭ �����ִ� ���� ����.
		memset(arr, 0, sizeof(int) * len);

		printf("arr[0]: %d\n", arr[0]);

		free(arr);
	}

	{
		int *arr1 = (int*)malloc(sizeof(int) * 3);  // 12 byte
		arr1[0] = 10;  arr1[1] = 20;  arr1[2] = 30;
		//arr1[3] = 40;  // <-- ����!!

		// ������ �޸� �Ҵ� ���� ������ 'Ȯ��/���' �ؼ�
		// ���Ҵ� �ޱ�,  (���� ������ ���� free ������ �ʿ�� ����)
		// re-allocation
		arr1 = (int*)realloc(arr1, sizeof(int) * 5);

		arr1[3] = 40; arr1[4] = 50;

		printf("%d %d %d %d %d\n", arr1[0], arr1[1], arr1[2], arr1[3], arr1[4]);

		free(arr1);
	}

	// malloc, free, realloc ...  <-- ����� '���?' �Լ��Դϴ�.

	printf("------------------------------\n");
	_getch();
	{
		int len = 1000000;
		int *arr;

		for (int i = 0; i < 100; i++) 
		{
			arr = (int*)malloc(sizeof(int) * len);
			_sleep(50);  // 0.05�� ���� delay �߻�
			free(arr);
		}

	}






	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()