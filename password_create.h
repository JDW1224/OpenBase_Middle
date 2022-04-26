#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS


char *Create()
{
	int N = 0;
	char Id[20], Site[20];
	printf("\n새로운 암호를 생성합니다.\n");
	printf("영문자 대소문자, 숫자, 특수문자를 각각 하나 이상 포함하여 원하는 자릿수만큼 나오도록 합니다.\n");
	printf("(단, 공백은 허용되지 않습니다.)\n\n");
	
	printf("사이트를 입력하세요 : ");
	scanf("%s", &Site);
	printf("\n아이디를 입력하세요 : ");
	scanf("%s", &Id);

	printf("\n몇자리를 원하는지 입력하세요 : ");
	scanf_s(" %d", &N);
	
	char *password = malloc(sizeof(char) * N);

	printf("\n------> 입력 : ");


	char sym[] = {'@','!','#','^','*','&'};

	int i = 0;

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
	
	Check(password);

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

int Check(char *password[])
{
	int i = 0, length = 0, upper = 0, lower = 0, special = 0, num = 0;


	// 암호에 대소문자, 특수문자, 숫자, 공백 있는지 확인
	for (; i < length; i++) {
		if (isupper(password[i]))
			upper++;
		else if (islower(password[i]))
			lower++;
		else if (isdigit(password[i]))
			num++;
		else
			special++;
	}

	// 암호 길이가 10글자 미만, 공백 포함, 암호에 영문자 대소문자, 특수문자, 숫자 중 어느 하나라도 없는 경우
	if (length < 10 || upper < 1 || lower < 1 || special < 1 || num < 1) {

		printf("\n%d", *password);
		printf("\n암호 생성 조건에 일치하지 않습니다.\n");

		// 아무 키나 입력 받고 다음 단계로 넘어가는 함수를 호출
		Next();

		// 처음부터 시작
		main();
	}
}











/*암호 확인하는 코오드
무조건 최소한 가져야하는것은 기호 하나는 무조건 포함
만약에 생성한 비밀번호에 기호가 없다면 다시돌려어*/
