#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

/*
	LinkedList �� ADT
*/

#define SUCCESS 1
#define FAIL  0

typedef int Data;     // �����ʹ� int

// ��� Ÿ�� ����
typedef struct _node {
	Data data;   // ��� ������
	struct _node *pNext;   // ���� ��� ������
} Node;

// LinkedList Ÿ�� ����
typedef struct _linkedList {
	Node *pHead;   // ���۳�带 ����Ű�� ������
	Node *pTail;   // ������ ��带 ����Ű�� ������

	int numData;   // ������ ���� (����� ����)

	Node *pCurrent;  // iteration ��
} LinkedList;


/* LinkedList �� ���� */
typedef LinkedList List;

void list_init(List *pList);   // ����Ʈ �ʱ�ȭ
void list_destroy(List *pList);// ����Ʈ ����

int list_add(List *pList, Data data);// ������ �߰�
int list_remove(List *pList, int n);// ������ ���� : n��° ������
int list_set(List *pList, int n, Data data);// ������ ����
int list_length(List *pList);// ������ ����

int list_get(List *pList, int n, Data *pData);// ������ ��ȸ : n��° ������

void list_init_iter(List *pList);// iteration : �ʱ�ȭ
Data list_next(List *pList);// iteration : ���� ������ ����
int list_hasNext(List *pList);// iteration : ���� ������ ����


int list_insert(List* pList, int n, Data data);   // ������ ����: n��° ��ġ�� ������ ����







#endif