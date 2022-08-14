#include <stdio.h>

int getRandomNum(int level);
void showQ(int level, int num1, int num2);
void success();
void fail();

int main_passwordgame(void)
{
	// 문은 5개.
	// 점점 문제 어려워짐 ( 랜덤함수 이용 )
	// 맞히면 통과. 틀리면 실패

	srand(time(NULL));
	int count = 0;
	for (int i = 1; i < 5; i++)
	{
		int num1 = getRandomNum(i);
		int num2 = getRandomNum(i);
		showQ(i, num1, num2);

		int answer = -1;
		scanf_s("%d", &answer);

		if (answer == -1)
		{
			printf("프로그램을 종료합니다.");
			exit(0);  // 뒤에 어떤 문장이 있던 지 끝내는 함수
		}
		else if (answer == num1 * num2)
		{
			success();
			count++;
		}
		else
			fail();

	}
	printf("당신은 4개의 문제 중 %d 문제를 맞았어요~ \n", count);

	return 0;
}

int getRandomNum(int level)
{
	return rand() % (level * 7) + 1;
}

void showQ(int level, int num1, int num2)
{
	printf("\n\n\n######## %d 번쨰 비밀번호 ########\n", level);
	printf("\n\t%d x %d ?\n\n", num1, num2);  // \t (tap)
	printf("  ###################\n");
	printf("\n 비밀번호를 입력하세요. (종료: -1) >> ");

}

void success()
{
	printf("\n성공!\n");
}
void fail()
{
	printf("\n실패!\n");
}