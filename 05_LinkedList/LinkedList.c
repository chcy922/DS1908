#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ�Լ�..
#include <string.h>   // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>    // _getch, putch  .. MS��� C ��ǥ�� �Լ�
#include <time.h>     // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() ��  ���� C �Լ� ���� 
#pragma warning(disable:4477)   // unsigned <--> signed ���� ����

#include "LinkedList.h"

// ����Ʈ �ʱ�ȭ
void list_init(List *pList)
{
	// head�� dummy node ���
	pList->pHead = (Node*)malloc(sizeof(Node));
	pList->pHead->pNext = NULL;
	pList->pTail = pList->pHead;   // ���ʿ��� tail�� head ����

	pList->numData = 0;
	pList->pCurrent = NULL; 
	printf("����Ʈ �ʱ�ȭ\n");
}
// ����Ʈ ����
void list_destroy(List *pList)
{
	list_init_iter(pList);
	Node *pPrev = NULL;
	while (list_hasNext(pList))
	{
		pPrev = pList->pCurrent;
		list_next(pList);  // pCurrent �̵�
		free(pPrev);   // ��� �޸� ����
	}

	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;

	printf("����Ʈ �Ҹ�\n");
}

// ������ �߰�
int list_add(List *pList, Data data)
{
	// ���ο� node ����
	Node *pNewNode = (Node*)malloc(sizeof(Node));  // ���ο� Node �޸� �Ҵ� (����)
	memset(pNewNode, 0, sizeof(Node));    // ���ο� Node, 0���� �ʱ�ȭ
	pNewNode->data = data;       // ������ �߰�

	// tail �� ����Ű�� next �� ������ ���� ���ο� node �� ����
	pList->pTail->pNext = pNewNode;

	// tail �̵�
	pList->pTail = pNewNode;

	printf("[%d] ��° ������ %d �߰�\n", pList->numData, data);

	(pList->numData)++;   // ������ ���� ����
	return SUCCESS;
}

// ������ ����
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) return FAIL;

	// head���ͽ����ؼ� n��° ��� ã��,  iteration ���
	list_init_iter(pList);  
	int i = 0;   // ���� ���° ���?
	while (list_hasNext(pList))
	{
		list_next(pList);

		if (i >= n) break;   // n��° ��� ã��!

		i++;
	}
	// �� while ���� ������ pCurrent �� n��° ��带 ����Ű�� �ֽ�

	printf("%d ��° ������ ���� %d  --> %d\n", n, pList->pCurrent->data, data);

	pList->pCurrent->data = data;  // ������ ����

	return SUCCESS;
}

// ������ ��ȸ : n��° ������
int list_get(List *pList, int n, Data *pData)
{
	if (n >= pList->numData) return FAIL;

	// n��° node ã��,  ã��node�� -> pCurrent
	list_init_iter(pList);
	int i = 0;
	while (list_hasNext(pList))
	{
		list_next(pList);
		if (i >= n) break;
		i++;
	}

	// n��° ����� data�� �����.
	*pData = pList->pCurrent->data;

	return SUCCESS;
}

// ������ ���� : n��° ������
int list_remove(List *pList, int n)
{
	if (n >= pList->numData) return FAIL;

	// n��° ��� ã��....
	// ���� ���(previous node)�� �˾ƾ� �Ѵ�.
	list_init_iter(pList);    
	int i = 0;
	Node *pPrev = NULL;   // ���� ��带 ����ų ������
	while (list_hasNext(pList))
	{
		pPrev = pList->pCurrent;   // �̵��ϱ� ���� pCurrent ���� ������� �� ����ؾ� �Ѵ�
		list_next(pList);
		if (i >= n) break;
		i++;
	}

	// �� while ���� ������ 
	// pCurrent (n��° ���), pPrev(n-1��° ���) �� ������.

	// ���� �� �����ϱ�.. ���̸� ...������ �˴ϴ�.


	// ���� ����!  
	pPrev->pNext = pList->pCurrent->pNext;

	// ���� �����Ϸ��� n��° ��尡 tail �̾��ٸ�?
	if (pList->pCurrent == pList->pTail)
		pList->pTail = pPrev; // tail �� ���� ���� �̵�

	// n��° ������ ���� �޸� �Ҵ� ����! ��!
	free(pList->pCurrent);
	
	pList->numData--;  // ����Ʈ size ����
	
	//printf("%d ��° ������ ����\n", n);

	return SUCCESS;
}




// ������ ����
int list_length(List *pList)
{
	return pList->numData;
}


// iteration : �ʱ�ȭ
void list_init_iter(List *pList)
{
	pList->pCurrent = pList->pHead;  // head ���� iteration ����
}

// iteration : ���� ������ ����
Data list_next(List *pList)
{
	pList->pCurrent = pList->pCurrent->pNext;  // �켱 Current �� �������� �̵�
	Data result = pList->pCurrent->data;
	return result;
}

// iteration : ���� ������ ����
int list_hasNext(List *pList)
{
	if (pList->pCurrent->pNext == NULL)  // '���� ���' ���� ���� üũ
		return FAIL;

	return SUCCESS;
}

// ������ ����: n��° ��ġ�� ������ ����
int list_insert(List* pList, int n, Data data)
{
	if (n > pList->numData) return FAIL;   // >= �� �ƴ϶� > �̴�!
	// ex) numData => 4
	// insert ���� �ε��� : 0, 1, 2, 3, 4
	// get, remove, set ���� �ε��� : 0, 1, 2, 3

	// ex) numData => 0
	// insert ���� �ε��� : 0

	// ���ο� node ����
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));
	pNewNode->data = data;

	if (pList->numData == 0) // #1 : ù��° ������ insert �ϴ� ���
	{
		pList->pHead->pNext = pNewNode;
		pList->pTail = pNewNode;
	}
	else if (pList->numData == n)// #2 : �� �� �ڿ� insert �ϴ� ���
	{
		pList->pTail->pNext = pNewNode;
		pList->pTail = pNewNode;
	}
	else // #3 : ������.
	{
		// n��° ��� ã��..
		// ������� (prev node) ���� �˾ƾ� �Ѵ�.
		list_init_iter(pList);
		int i = 0;
		Node *pPrev = NULL; // ���� ��带 ����ų ������
		while (list_hasNext(pList))
		{
			pPrev = pList->pCurrent;  // pCurrent �̵����� pCurrent���� ���� ��� ������ ����ؾ� ��
			list_next(pList);    // pCurrent �� �̵�
			if (i >= n) break;    // n��° ��� ã���� ����
			i++;
		}

		// �� while ���� ������
		// pCurrent(n ��° ���),  pPrev(n -1 ��° ���) �� ������

		// ���Ե��� ����
		pPrev->pNext = pNewNode;   // �������� ���ο� ��带 ����Ű��
		pNewNode->pNext = pList->pCurrent;    // ���ο� ���� current �� ����Ŵ
	}

	(pList->numData)++;    // ��������
	return FAIL;
}
