#include <stdio.h>

int getRandomNum(int level);
void showQ(int level, int num1, int num2);
void success();
void fail();

int main_passwordgame(void)
{
	// ���� 5��.
	// ���� ���� ������� ( �����Լ� �̿� )
	// ������ ���. Ʋ���� ����

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
			printf("���α׷��� �����մϴ�.");
			exit(0);  // �ڿ� � ������ �ִ� �� ������ �Լ�
		}
		else if (answer == num1 * num2)
		{
			success();
			count++;
		}
		else
			fail();

	}
	printf("����� 4���� ���� �� %d ������ �¾Ҿ��~ \n", count);

	return 0;
}

int getRandomNum(int level)
{
	return rand() % (level * 7) + 1;
}

void showQ(int level, int num1, int num2)
{
	printf("\n\n\n######## %d ���� ��й�ȣ ########\n", level);
	printf("\n\t%d x %d ?\n\n", num1, num2);  // \t (tap)
	printf("  ###################\n");
	printf("\n ��й�ȣ�� �Է��ϼ���. (����: -1) >> ");

}

void success()
{
	printf("\n����!\n");
}
void fail()
{
	printf("\n����!\n");
}