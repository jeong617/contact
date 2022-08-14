#include <stdio.h>
#include <time.h>

// 물고기 6마리
// 어항에 있는데, 장소는 사막
// 사막이 더워서 시간 지날수록 증발
// 물이 증발하기 전에 부지런히 어항에 물을 줘서 물고기를 살리자
// 물고기는 시간이 지날수록 커져서... 나중에 냠냠

int level;
int arrayFish[6];
int* cursor;

void initDate();
void printFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int main_pointer_project(void)
{
	long startTime = 0; // 게임 시작 시간. 보통 long 자료형 사용
	long totalElapsedTime = 0; // 총 경과 시간
	long prevElapsedTime = 0; // 직전 경과 시간. (최근에 물을 준 시간 간격)

	int num;
	initDate();

	cursor = arrayFish;  // cursor[0] ... cursor[1]...

	startTime = clock(); // 현재 시간을 millisecond (1000분의 1초 단위로 반환)
	while (1) // 무한반복
	{
		printFishes();
		printf("몇 번 어항에 물을 주시겠어요? ");
		scanf_s("%d", &num);

		// 입력값 체크
		if (num < 1 || num > 6)
		{
			printf("입력값이 잘못되었습니다.\n");
			continue;
		}

		// 총 경과 시간
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // sec단위로 바꿔줄 수 있음
		printf("총 경과 시간: %ld 초\n", totalElapsedTime);

		// 직전 물 준 시간(마지막으로 물 준 시간) 이후로 흐른 시간
		prevElapsedTime = (totalElapsedTime - prevElapsedTime);
		printf("최근 경과 시간: %ld초 \n", prevElapsedTime);

		// 어항의 물을 감소(증발)
		decreaseWater(prevElapsedTime);

		// 사용자가 입력한 어항에 물을 준다
		// 1 어항에 물이 0이면? 물을 주지 않는다 ... 이미 물고기 죽음 ㅠㅠ
		if (cursor[num - 1] <= 0)
		{
			printf("%d번 물고기는 이미 죽었어요 ㅠㅠ 물을 주지 않습니다...\n", num);
		}
		// 2 어항의 물이 0이 아닌 경우? 물을 준다. 단 100을 넘지 않도록!
		else if (cursor[num - 1] + 1 <= 100)
		{
			// 물을 준다
			printf("%d번 어항에 물을 줍니다. \n\n", num);
			cursor[num - 1] += 1;
		}

		// 레벨업을 할 건지 확인 (레벨업은 20초마다 한번씩 수행)
		if (totalElapsedTime / 20 > level - 1)  // totalE~ 정수형으로 선언되어서 나머지 버림
		{
			level++;   // level = 1 -> level = 2
			printf(" *** 축 레벨업! 기존 %d 레벨에서 %d 레벨로 업그레이드!\n\n", level - 1, level);

			// 최종레벨 5
			if (level == 5)
			{
				printf("\n\n축하합니다. 최고레벨 달성! 게임을 종료합니다.\n\n");
				exit(0); // 모든 프로그램을 종료하는 동작
			}

		}
		// 모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0)
		{
			printf("물고기가 모두 죽었어요 ㅠㅠ \n\n");
			printf("게임을 종료합니다.");
			exit(0);
		}
		else
		{
			printf("물고기가 아직 살아있어요!\n");
		}
		prevElapsedTime = totalElapsedTime; // 10sec -> 15sec (5sec: prev~Time) -> 25sec (10sec가 prevTime이 되어야 함) 이를 위한 코드
	}

	return 0;
}

void initDate()
{
	level = 1;
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; // 어항의 물높이 0-100
	}
}

void printFishes()
{
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번 \n", 1, 2, 3, 4, 5, 6); // %3d -> 3칸에 숫자를 할당
	for (int i = 0; i < 6; i++)
	{
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n\n");
}
void decreaseWater(long elapsedTime)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (level * 3 * elapsedTime);  // 3은 난이도 조절을 위한 변수
		if (arrayFish[i] < 0)
		{
			arrayFish[i] = 0;
		}
	};
}

int checkFishAlive()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
			return 1; // 참. true
	}
	return 0; // 물고기가 다 죽었음. False
}