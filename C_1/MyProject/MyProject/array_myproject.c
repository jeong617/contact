#include <stdio.h>

int main_myArrayProject(void)
{
	srand(time(NULL));

	printf(" === �ƺ��� ��Ӹ�~ ���� === \n\n\n");

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
		printf(" �� ������ �ٸ��ϴ�~\n");

		if (isInclude == 1)
			printf("�Ӹ��� ���׿�! \n");
		else
			printf("�Ӹ��� �ȳ��׿� ��\n");

		printf(" \n ... ��� �Ϸ��� �ƹ��ų� �������� ... ");
		getchar();
	}

	printf("�߸����� �� �� �ϱ��? \n");
	scanf_s("%d", &answer);

	if (answer == treatment + 1)
		printf("����!\n");
	else
		printf("����! �߸����� %d�� �̿���\n", treatment + 1);

	return 0;
}