#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ�Լ�..
#include <string.h>   // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>    // _getch, putch  .. MS��� C ��ǥ�� �Լ�
#include <time.h>     // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() ��  ���� C �Լ� ���� 
#pragma warning(disable:4477)   // unsigned <--> signed ���� ����
#include "LinkedList.h"
/*

*/

// ����Ʈ ��� ����� �Լ�
void printList(List *pList)
{
	list_init_iter(pList);   // iteration �ʱ�ȭ
	printf("[");
	while (list_hasNext(pList))
	{
		printf("%d ", list_next(pList));
	}

	printf("]\n");
}


int main(int argc, char** argv)
{
	List myList;
	list_init(&myList);

	// add() ����Ȯ��
	printList(&myList);
	list_add(&myList, 100);  // ������ �߰�
	printList(&myList);
	list_add(&myList, 50);  // ������ �߰�
	printList(&myList);
	list_add(&myList, 100);  // ������ �߰�
	printList(&myList);
	list_add(&myList, 100);  // ������ �߰�
	printList(&myList);
	list_add(&myList, 70);  // ������ �߰�
	printList(&myList);

	// ������ ����
	list_set(&myList, 0, 40);
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 30);
	list_set(&myList, 10, -400);
	printList(&myList);

	// ������ ��ȸ list_get()
	Data data;
	if (list_get(&myList, 4, &data)) printf("data=%d\n", data);
	if (list_get(&myList, 5, &data)) printf("data=%d\n", data);

	// [40 30 100 100 30 ]

	// ������ ����
	list_remove(&myList, 2);    
	printList(&myList);    // [40 30 100 30 ]
	list_remove(&myList, 2);
	printList(&myList);    // [40 30 30 ]
	list_remove(&myList, 0);
	printList(&myList);    // [30 30 ]
	list_remove(&myList, 2);   // x
	list_remove(&myList, 1);    // [30]
	printList(&myList);
	list_remove(&myList, 0);    // []
	printList(&myList);


	// ������ ����
	list_insert(&myList, 0, 100);  
	printList(&myList);               // [100 ]
	list_insert(&myList, 0, 200);
	printList(&myList);                // [200 100 ]
	list_insert(&myList, 1, 400);     
	printList(&myList);                 // [200 400 100 ]
	list_insert(&myList, 3, 500);
	printList(&myList);				// [200 400 100 500]







	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()