#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ�Լ�..
#include <string.h>   // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>    // _getch, putch  .. MS��� C ��ǥ�� �Լ�
#include <time.h>     // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() ��  ���� C �Լ� ���� 
#pragma warning(disable:4477)   // unsigned <--> signed ���� ����

/*
	����ü
*/

int main(int argc, char** argv)
{
	{
		struct Student   // Student ��� ����ü ����
		{
			int age;        // ������� 2�� 
			char gender;
		};

		// Student ����ü Ÿ�� ���� ����
		struct Student stu1;
		// ����ü ��� ��� : ��� ���ٿ����� (member access operator)  . ���
		stu1.age = 15;
		stu1.gender = 'F';

		// ����ü �� ���� ������
		struct Student *pStu;
		pStu = &stu1;

		printf("age : %d, gender : %c \n", stu1.age, stu1.gender);
		printf("age : %d, gender : %c \n", (*pStu).age, (*pStu).gender);
		printf("age : %d, gender : %c \n", pStu->age, pStu->gender);
		   // ����ü �����ʹ� -> �� ����ؼ� ��� ��� ����!
	}

	{
		typedef unsigned int UINT;  // typdef �� ����ؼ� ���ο� Ÿ���̸� ����
		UINT a, b, c;

		// typdef ����ü���� ���̸�;
		typedef struct _Student
		{
			int age;
			char gender;
		} Student;

		Student stu1;   // typdef ���� ���ǵ� Ÿ���̸����� ���ϰ� ���



	}



	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()