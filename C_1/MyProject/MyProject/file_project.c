#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 비밀번호를 입력받아서
// 맞으면 -> 비밀일기를 읽어와서 보여주고 계속 작성하도록 합니다.
// 틀리면 -> 경고메세지를 표시하고 종료

# define MAX 10000

int main(void)
{
	// fgets, gputs 사용
	char line[MAX];  // 파일에서 불러온 내용을 저장할 변수
	char contents[MAX];   // 일기장에 입력할 내용
	char password[20]; // 비밀번호 입력
	char c; // 비밀번호 입력 시 키값 확인용(마스킹)

	printf("'비밀일기'에 오신 것을 환영합니다.\n");
	printf("비밀번호를 입력하세요.\n");

	// getchar() / getch() 의 차이?
	// getchar(): 엔터를 입력받아야 동작을 합니다.
	// getch(): 키 입력 시 바로바로 동작을 합니다.

	int i = 0;
	while (1)
	{
		c = getch();
		if (c == 13)  // 13은 엔터를 나타내는 아스키코드 -> 비밀번호 입력 종료
		{

			password[i] = '\0';  // NULL -> \0
			break;
		}
		else  // 비밀번호 입력 중
		{
			printf("*");
			password[i] = c;
		}
		i++;
	}

	printf("\\n\n === 비밀번호 확인중 ... ===\n\n");
	if (strcmp(password, "skehzheld") == 0)  // 비밀번호 일치
	{
		printf(" === 비밀번호 입력 완료 === \n\n");
		char* fileName = "c:\\exProject_2022\\C_1\\secretdiary.txt";
		FILE* file = fopen(fileName, "a+b");
		// a+b -> 파일이 없으면 생성, 있으면 append를 한다.(뒤에 내용 추가)
		if (file == NULL)
		{
			printf("파일 열기 실패!");
			return 1;
		}

		while (fgets(line, MAX, file) != NULL)
		{
			printf("%s", line);
		}

		printf("\n\n 내용을 계속 작성하세요! 종료하시면 exit를 입력하세요. \n\n");

		while (1)
		{
			scanf("%[^\n]", contents);  // 줄바꿈(\n)이 나오기 전까지 모든 문자열을 다 집어넣어라~
			getchar();  // enter 입력 (\n) Flush 처리 -> buffer에 남아있던 엔터를 없애버리는 동작

			if (strcmp(contents, "exit") == 0)
			{
				printf("비밀일기를 종료합니다. \n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file);  // enter를 위에서 무시처리 했으므로 임의로 추가
		}
		fclose(file);
	}
	// 비밀번호 틀린 경우
	else
	{
		printf("=== 비밀번호가 틀렸어요 === \n\n\n");
		printf("넌 뭐야~~~~~\n");
	}
	return 0;
}