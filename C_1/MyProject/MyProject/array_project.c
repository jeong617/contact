#include <stdio.h>

int main_ArrayProject(void)
{
	srand(time(NULL));
	printf("\n\n === 아빠는 대머리 게임 === \n\n");
	int answer;  // 사용자 입력값
	int treatment = rand() % 4;  // 발모제 선택 0~3

	int cntShowBottle = 0; // 이번 게임에 보여줄 병 갯수
	int prevCntShowBottle = 0; // 앞 게임에 보여준 병 갯수
	
	// 서로 보여주는 병 갯수를 다르게 하여 정답률 향상 (처음에 2개 -> 다음엔 3개)

	// 3번의 기회

	for (int i = 1; i <= 3; i++)
	{
		printf("for i = %d\n", i);
		int bottle[4] = { 0, 0, 0, 0 };  // 4개의 병
		do {
			cntShowBottle = rand() % 2 + 2; // 보여줄 병 개수 2 or 3
		} while (cntShowBottle == prevCntShowBottle);
		prevCntShowBottle = cntShowBottle;

		int isIncluded = 0; // 보여줄 병 중에 발모제가 포함되어 있는지
		printf(" > %d 번째 시도: ", i);

		// 보여줄 병 종류를 선택

		for (int j = 0; j < cntShowBottle; j++)
		{
			printf("for j = %d\n", j);
			int randBottle = rand() % 4;

			// 아직 선택되지 않은 병이면, 선택 처리
			if (bottle[randBottle] == 0)
			{
				bottle[randBottle] = 1;
				if (randBottle == treatment)
				{
					isIncluded = 1;
				}
			}
			// 이미 선택 된 병이면, 중복이므로 다시 선택
			else
			{
				j--;
			}

		}		
		// 사용자에게 문제 표시

		for (int k = 0; k < 4; k++)
		{
			printf("for k = %d\n", k);
			if (bottle[k] == 1)
				printf(" %d  ", k + 1);
		}
		printf("물약을 머리에 바릅니다.");

		if (isIncluded == 1)
		{
			printf(" >> 성공! 머리 났어용 \n");
		}
		else
		{
			printf("  >> 실패! 머리가 안났어요 ㅠㅠ \n");
		}

		printf("\n ... 계속 하려면 아무거나 누르세요 ... ");
		getchar();   // 사용자가 어떤 키를 누를 때까지 대기하는 함수
	}

	printf("\n\n 발모제는 몇번일까요~? \n");
	scanf_s("%d", &answer);

	if (answer == treatment + 1)
	{
		printf(" \n 정답입니다~ ");
	}
	else
	{
		printf("\n 땡! 정답은 %d번 입니다 ~ ", treatment + 1);
	}
	return 0;
}