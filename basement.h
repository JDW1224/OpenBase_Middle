#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

int Division() // ���м��� ����ϴ� �Լ�
{
	int i = 0;

	printf("\n");

	// ���� ������� ������ ���ϵ��� ���м� ���
	for (; i < 51; i++)
	{
		printf("=");
	}
	printf("\n\n");
}

int Next() // �ƹ� Ű�� ������ ��� �����ϵ��� �ϴ� �Լ�
{
	char press;

	// �ƹ� Ű�� �Է� �ް� ���� �ܰ�� �Ѿ
	printf("\n����Ͻ÷��� �ƹ� Ű�� �����ּ���.\n");
	press = _getch();

	// ���м��� ����ϴ� �Լ��� ȣ��
	Division();
}

int Finish()// ��ȣ ���α׷��� ������ ���� ����� �Լ�
{
	int i = 0;
	char choice;

	printf("\n���� ��ȣ ���α׷��� �����Ͻðڽ��ϱ�?\n(���� : Y, ��� ���� : N)\n\n");
	printf("------> �Է� : ");
	scanf(" %c", &choice);

	if (choice == 'y' || choice == 'Y') {           // ����ڰ� 'Y'�� �Է����� ��
		printf("\n��ȣ ���α׷��� �����մϴ�. �̿����ּż� �����մϴ�.\n");

		// ��ȣ ���α׷� ����
		exit(0);
	}
	else {
		printf("\n���⿡ ���� Ű�� �Է��ϼ̽��ϴ�. �ٽ� �������ֽʽÿ�.\n\n");

		// ��ȣ ���α׷��� ������ ���� ����� �Լ��� �ٽ� ȣ��
		Finish();
	}
}

char Guide(int select)// ��ȣ ���α׷��� �ȳ��ϴ� �Լ�
{
	printf("��ȣ�������Դϴ�.\n");
	printf("���ϴ� ����� �������ּ���.\n\n");
	printf("1. ��ȣ ����\nx. ����\n\n");
	printf("------> �Է� : ");

	scanf(" %d", &select);        // ����ڷκ��� � ����� �������� �Է� ����

	return select;        // main �Լ��� select�� ���� ��ȯ
}

