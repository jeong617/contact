#include <stdio.h>

int main_myArrayProject(void)
{
	srand(time(NULL));

	printf(" === 아빠는 대머리~ 게임 === \n\n\n");

	int answer;
	int treatment = rand() % 4;

	int cntShowBottle = 0;
	int prevShowBottle = 0;

	for (int i = 1; i <= 3; i++)
	{
		int bottle[4] = { 0,0,0,0 };
		do {
			cntShowBottle = rand() % 2 + 2;
		} while (cntShowBottle == prevShowBottle);
		prevShowBottle = cntShowBottle;

		int isInclude = 0;

		for (int j = 0; j < cntShowBottle; j++)
		{
			int randBottle = rand() % 4;
			if (bottle[randBottle] == 0)
			{
				bottle[randBottle] = 1;
			}
			else
			{
				j--;
			}
			if (randBottle == treatment)
			{
				isInclude = 1;
			}
		}
		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1)
				printf("%d ", k + 1);
		}
		printf(" 번 물약을 바릅니다~\n");

		if (isInclude == 1)
			printf("머리가 났네용! \n");
		else
			printf("머리가 안났네용 ㅠ\n");

		printf(" \n ... 계속 하려며 아무거나 누르세요 ... ");
		getchar();
	}

	printf("발모제는 몇 번 일까요? \n");
	scanf_s("%d", &answer);

	if (answer == treatment + 1)
		printf("정답!\n");
	else
		printf("실패! 발모제는 %d번 이에용\n", treatment + 1);

	return 0;
}