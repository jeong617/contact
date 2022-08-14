#include <stdio.h>
#include <time.h>

int main_conditon(void)
{
	//버스를 탄다고 가정. 학생 또는 일반인 ( 일반인: 20세 )
	//if_else문
	int age = 15;
	if (age >= 20)
		printf("일반인 입니다\n");
	else
		printf("학생입니다.\n");
	
	//초(8~13) , 중(14~16), 고(17~19)로 나누면?
	//if else else if
	int age1 = 8;
	if (age1 >= 8 && age1 <= 13)
		printf("초등학생입니다.");
	else if (age1 >= 14 && age1 <= 16)
		printf("중학생 입니다.");
	else if (age1 >= 17 && age1 <= 19)
		printf("고등학생입니다.");
	else
		printf("학생이 아닌가봐용?");

	// break&continue
	// 1번부터 30번까지 있는 반에서 1번에서 5번까지 조별 발표를 합니다.

	for (int i = 1; i <= 30; i++)
	{
		if (i >= 6)
		{
			printf("나머지 학생은 집에 가세요\n");
			break;										// break시 for문 탈출
		}
		printf("%d 번 학생은 조별 발표 준비를 하세요.\n", i);
	}
	printf("\n");
	//1번부터 30번까지 있는 반에서 7번 학생 결석, 7번 제외 6~10번까지 조별발표를 하세용

	for (int i = 1; i <= 30; i++)
	{
		if (i >= 6 && i <= 10)
		{
			if (i == 7)
			{
				printf("%d번 학생은 결석입니다.\n", i);
				continue; //continue를 만나면 이 뒤의 문장 실행 안하고 새로운 for문 실행
			}
			printf("%d 번 학생은 발표를 준비하세요.\n", i);
		}
	}

	// && 랑 ||  ( and와 or )
	
	int a = 10;
	int b = 11;
	int c = 13;
	int d = 13;

	if (a == b && c == d)
	{
		printf("a와 b는 같고, c와 d도 같습니다\n");
	}
	else
	{
		printf("값이 서로 다릅니다\n");
	}

	if (a == b || c == d)
	{
		printf("a와 b가 같거나, c와 d가 같습니다.\n");
	}
	else
	{
		printf("값이 서로 다릅니다\n");
	}

	//가위0  바위1 보2

	srand(time(NULL));
	int i = rand() % 3;
	if (i == 0)
		printf("가위\n");
	else if (i == 1)
		printf(" 바위\n");
	else if (i == 2)
		printf(" 보\n");


	srand(time(NULL));
	int j = rand() % 3;
	switch (j)
	{
	case 0: printf("가위\n"); break; // break를 통해 switch 구문 탈출
	case 1: printf("바위\n"); break;
	case 2: printf("보\n"); break;
	default: printf("몰라용"); break; // break 안걸어주면 뒤에 문장 다 출력됨
	}

	//교통카드 예제를 switch 구문으로
	int age2 = 25;
	switch (age2)
	{
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13: printf("초등학생입니다."); break;     //이렇게 하면 case 8~12에서도 break없어서 쭉 내려오다가 초등학생 출력하고 break 됨
	case 14:
	case 15:
	case 16: printf("중학생입니다."); break;
	case 17:
	case 18:
	case 19: printf("고등학생입니다."); break;
	default: printf("학생이 아닌가봐용");
		break;
	}
	

	//프로젝트

	srand(time(NULL));
	int num = rand() % 100 + 1; // 1부터 100까지 중 하나의 수
	printf("숫자: %d\n ", num);
	int answer;
	int chance = 5;

	while (chance > 0)
	{
		printf("남은 기회: %d 번\n", chance--);
		printf("숫자를 맞춰보세요: ");
		scanf_s("%d", &answer);

		if (answer < num)
			printf("up \n\n");
		else if (answer > num)
			printf("down\n\n");
		else if (answer == num)
		{
			printf("정답입니다~~\n");
			break;
		}
		else
			printf("에러났어용\n");

		if (chance == 9)
		{
			printf("이제 기회 없음~\n");
			break;
		}
	}
	return 0;
}