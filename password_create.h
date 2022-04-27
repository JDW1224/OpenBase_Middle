#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS


char *Create()
{
	int N = 0;
	char Id[20], Site[20];
	printf("\n���ο� ��ȣ�� �����մϴ�.\n");
	printf("������ ��ҹ���, ����, Ư�����ڸ� ���� �ϳ� �̻� �����Ͽ� ���ϴ� �ڸ�����ŭ �������� �մϴ�.\n");
	printf("(��, ������ ������ �ʽ��ϴ�.)\n\n");
	
	printf("����Ʈ�� �Է��ϼ��� : ");
	scanf("%s", &Site);
	printf("\n���̵� �Է��ϼ��� : ");
	scanf("%s", &Id);

	printf("\n���ڸ��� ���ϴ��� �Է��ϼ��� : ");
	scanf(" %d", &N);
	
	char *password = (char*)malloc(sizeof(char) * (N+1));


	char sym[] = {'@','!','#','^','*','&'};

	int i = 0;
	srand(time(NULL));
	do {
		for (int i = 0; i < N; i++) {
			switch (rand() % 4) {
			case 1:
				password[i] = rand() % 26 + 65;
				break;
			case 2:
				password[i] = rand() % 26 + 97;
				break;
			case 3:
				password[i] = rand() % 10 + 48;
				break;
			case 0:
				password[i] = sym[rand() % 6];
				break;
			}
		}
		printf("%s\n", password);
	} while (Check(password));
	

	printf("\n\nYour Password: ");
	for (int i = 0; i < N; i++) {
		printf("%c", *(password + i));
	}
	printf("\n\n");

	FILE *fp = fopen("Id_Password.txt", "a+");

	fprintf(fp, "site: %s\n", Site);
	fprintf(fp, "Id: %s\n", Id);
	fprintf(fp, "password: %s\n\n", password);
	
	fclose(fp);   

}

int Check(char password[])
{
	int i = 0, upper = 0, lower = 0, special = 0, num = 0;

	// ��ȣ�� ��ҹ���, Ư������, ����, ���� �ִ��� Ȯ��
	for (i=0; i < strlen(password); i++) {
		if (isupper(password[i]))
			upper++;
		else if (islower(password[i]))
			lower++;
		else if (isdigit(password[i]))
			num++;
		else
			special++;
	}

	// ���� ����, ��ȣ�� ������ ��ҹ���, Ư������, ���� �� ��� �ϳ��� ���� ���
	if (upper < 1 || lower < 1 || special < 1 || num < 1) {
		return 1;
	}
	else {
		return 0;
	}
}











/*��ȣ Ȯ���ϴ� �ڿ���
������ �ּ��� �������ϴ°��� ��ȣ �ϳ��� ������ ����
���࿡ ������ ��й�ȣ�� ��ȣ�� ���ٸ� �ٽõ�����*/
