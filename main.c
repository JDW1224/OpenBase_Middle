#include "basement.h"
#include "password_create.h"


// 새로운 암호를 생성하는 함수

int main()
{
	char select = 0, *password = { 0, };
	int count = 0;

	while (1)
	{
		// 암호 프로그램을 안내하는 함수를 호출
		select = Guide(select);

		// 사용자가 입력한 값에 따라 해당 기능을 실행
		switch (select) {
		case '1':
			// 새로운 암호를 생성하는 함수를 호출
			password = Create();

			// 암호가 잘 생성되면 count를 1로 만들어줌
			count++;

			break;
		
		case 120:
		case 88:
			// 사용자가 'x'를 입력했을 때 프로그램을 종료할지 물어보는 Finish 함수를 호출
			Finish();

			break;
		default:
			// 사용자가 보기에 없는 키를 입력했을 때
			printf("\n보기에 없는 기능을 선택하셨습니다.\n암호 생성 및 확인 프로그램을 다시 시작합니다.\n");

			// 아무 키나 입력 받고 다음 단계로 넘어가는 함수를 호출
			Next();
		}
	}
	return 0;
}
// 이 코드에서 바꿔야 할 것: 일단 암호 자릿수를 10자리 이상이 아니라 동적할당을 이용하여 자동으로 암호 생성되도록 하자
// 뭐 내가 사용하는 ghkdlxld,wkdwhddn같이 좀 쓰던거에 뒤에 수,부호를 붙여서 추천해주는 비밀번호 생성기
// + 이 비밀번호가 어디 사이트 비밀번호인지 기억하고, 이거에 저장되어있는 사이트가 어디인지 출력해주고, 사이트를 치면 그 사이트에 해당하는 비밀번호 나오도록

//txt 파일 저장,