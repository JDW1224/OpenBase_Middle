#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

int Division() // 구분선을 출력하는 함수
{
	int i = 0;

	printf("\n");

	// 이전 내용과의 구분이 편하도록 구분선 출력
	for (; i < 51; i++)
	{
		printf("=");
	}
	printf("\n\n");
}

int Next() // 아무 키나 눌러서 계속 실행하도록 하는 함수
{
	char press;

	// 아무 키나 입력 받고 다음 단계로 넘어감
	printf("\n계속하시려면 아무 키나 눌러주세요.\n");
	press = _getch();

	// 구분선을 출력하는 함수를 호출
	Division();
}

int Finish()// 암호 프로그램을 종료할 건지 물어보는 함수
{
	int i = 0;
	char choice;

	printf("\n정말 암호 프로그램을 종료하시겠습니까?\n(종료 : Y, 계속 실행 : N)\n\n");
	printf("------> 입력 : ");
	scanf(" %c", &choice);

	if (choice == 'y' || choice == 'Y') {           // 사용자가 'Y'를 입력했을 때
		printf("\n암호 프로그램을 종료합니다. 이용해주셔서 감사합니다.\n");

		// 암호 프로그램 종료
		exit(0);
	}
	else {
		printf("\n보기에 없는 키를 입력하셨습니다. 다시 선택해주십시오.\n\n");

		// 암호 프로그램을 종료할 건지 물어보는 함수를 다시 호출
		Finish();
	}
}

char Guide(int select)// 암호 프로그램을 안내하는 함수
{
	printf("암호생성기입니다.\n");
	printf("원하는 기능을 선택해주세요.\n\n");
	printf("1. 암호 생성\nx. 종료\n\n");
	printf("------> 입력 : ");

	scanf(" %d", &select);        // 사용자로부터 어떤 기능을 실행할지 입력 받음

	return select;        // main 함수의 select로 값을 반환
}

