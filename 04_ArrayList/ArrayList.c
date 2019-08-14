#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ�Լ�..
#include <string.h>   // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>    // _getch, putch  .. MS��� C ��ǥ�� �Լ�
#include <time.h>     // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() ��  ���� C �Լ� ���� 
#pragma warning(disable:4477)   // unsigned <--> signed ���� ����
#include "ArrayList.h"

/* �Ű����� ��ȿ�� ���� ���� */

// ����Ʈ �ʱ�ȭ
void list_init(List *pList)
{
	pList->numData = 0;
	pList->curPosition = -1;
	memset(pList->arr, 0, sizeof(pList->arr));   // �迭 arr �� 0 ���� �ʱ�ȭ
	printf("����Ʈ �ʱ�ȭ\n");
}

// ����Ʈ ����
void list_destroy(List *pList)
{
	pList->numData = 0;
	printf("����Ʈ ����\n");
}

// ������ �߰�
int list_add(List *pList, Data data)
{
	if (pList->numData >= LIST_LEN)
	{
		printf("������ �߰� �Ұ�\n");
		return FAIL;
	}

	pList->arr[pList->numData] = data;

	printf("[%d] ��° ������ %d �߰�\n", pList->numData, data);
	(pList->numData)++;
	return SUCCESS;
}

// ������ ����
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) {
		printf("%d ��° ������ ���� ����\n", n);
		return FAIL;
	}

	printf("%d ��° ������ ���� %d  --> %d\n", n, pList->arr[n], data);
	pList->arr[n] = data;  // n��° �����Ͱ��� data �� ����
	return SUCCESS;
}

// ������ ����
int list_length(List *pList)
{
	return pList->numData;    // ArrayList ���� ���� ������ ����
}

// ������ ��ȸ : n��° ������
int list_get(List *pList, int n, Data *pData)
{
	if (n >= pList->numData) return FAIL;

	*pData = pList->arr[n];   // �����Ͱ�, �����Ͱ� ����Ű�� ���� ����

	return SUCCESS;
}

// ������ ���� : n��° ������
int list_remove(List *pList, int n)
{
	// �迭�̴ϱ�.. �߰��� ���� �ϸ� ���� �����͵��� ��ĭ�� ��ܾ� �Ѵ� (����߻�!!)
	if (n >= pList->numData) {
		printf("%d ��° ������ ���� ����\n", n);
		return FAIL;
	}

	// n��° ���� �����ؼ� numData��° �������� ��ĭ�� ����
	for (int i = n; i < pList->numData; i++)
	{
		pList->arr[i] = pList->arr[i + 1];  // ���� ������ ���� ���� ������ �ֱ� (�����)
	}

	pList->numData--;   // ����Ʈ ���� ����

	//printf("%d ��° ������ ���� ����\n", n);

	return SUCCESS;
}


// iteration : �ʱ�ȭ
void list_init_iter(List *pList)
{
	pList->curPosition = -1;  // �ڷ� ��ĭ ��ܳ��� ����
}

// iteration : ���� ������ ����
Data list_next(List *pList)
{
	pList->curPosition++;    // �ϴ� position ����
	Data result = pList->arr[pList->curPosition];   // position �� ������ �� ����

	return result;
}

// iteration : ���� ������ ����
int list_hasNext(List *pList)
{
	if (pList->curPosition + 1 < pList->numData)
		return SUCCESS;   

	return FAIL;
}


// ������ ����: n��° ��ġ�� ������ ����
int list_insert(List* pList, int n, Data data)
{
	// �̹� �� �������� �Ұ�
	if (pList->numData >= LIST_LEN){
		printf("������ �߰����� �Ұ�\n");
		return FAIL;
	}

	// �߰�, �� ���� ���
	if (n > pList->numData){
		printf("%d ��° ��ġ�� ���� �Ұ�\n", n);
		return FAIL;
	}

	// ������ n��° ���� ��ĭ�� �ڷ� �з����� �Ѵ�.
	// �ǵڿ�������!!! n ���� �͵��� ��ĭ�� �������� ����
	for (int i = pList->numData; i - 1 >= n; i--)
	{
		pList->arr[i] = pList->arr[i - 1];
	}

	pList->arr[n] = data;  // n ���� �� ������ ����
	pList->numData++;   // ������ ���� ����
	
	//printf("%d��° ������ %d ���� ����\n", n, data);

	return SUCCESS;
}