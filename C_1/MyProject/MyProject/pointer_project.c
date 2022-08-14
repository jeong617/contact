#include <stdio.h>
#include <time.h>

// ����� 6����
// ���׿� �ִµ�, ��Ҵ� �縷
// �縷�� ������ �ð� �������� ����
// ���� �����ϱ� ���� �������� ���׿� ���� �༭ ����⸦ �츮��
// ������ �ð��� �������� Ŀ����... ���߿� �ȳ�

int level;
int arrayFish[6];
int* cursor;

void initDate();
void printFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int main_pointer_project(void)
{
	long startTime = 0; // ���� ���� �ð�. ���� long �ڷ��� ���
	long totalElapsedTime = 0; // �� ��� �ð�
	long prevElapsedTime = 0; // ���� ��� �ð�. (�ֱٿ� ���� �� �ð� ����)

	int num;
	initDate();

	cursor = arrayFish;  // cursor[0] ... cursor[1]...

	startTime = clock(); // ���� �ð��� millisecond (1000���� 1�� ������ ��ȯ)
	while (1) // ���ѹݺ�
	{
		printFishes();
		printf("�� �� ���׿� ���� �ֽðھ��? ");
		scanf_s("%d", &num);

		// �Է°� üũ
		if (num < 1 || num > 6)
		{
			printf("�Է°��� �߸��Ǿ����ϴ�.\n");
			continue;
		}

		// �� ��� �ð�
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // sec������ �ٲ��� �� ����
		printf("�� ��� �ð�: %ld ��\n", totalElapsedTime);

		// ���� �� �� �ð�(���������� �� �� �ð�) ���ķ� �帥 �ð�
		prevElapsedTime = (totalElapsedTime - prevElapsedTime);
		printf("�ֱ� ��� �ð�: %ld�� \n", prevElapsedTime);

		// ������ ���� ����(����)
		decreaseWater(prevElapsedTime);

		// ����ڰ� �Է��� ���׿� ���� �ش�
		// 1 ���׿� ���� 0�̸�? ���� ���� �ʴ´� ... �̹� ����� ���� �Ф�
		if (cursor[num - 1] <= 0)
		{
			printf("%d�� ������ �̹� �׾���� �Ф� ���� ���� �ʽ��ϴ�...\n", num);
		}
		// 2 ������ ���� 0�� �ƴ� ���? ���� �ش�. �� 100�� ���� �ʵ���!
		else if (cursor[num - 1] + 1 <= 100)
		{
			// ���� �ش�
			printf("%d�� ���׿� ���� �ݴϴ�. \n\n", num);
			cursor[num - 1] += 1;
		}

		// �������� �� ���� Ȯ�� (�������� 20�ʸ��� �ѹ��� ����)
		if (totalElapsedTime / 20 > level - 1)  // totalE~ ���������� ����Ǿ ������ ����
		{
			level++;   // level = 1 -> level = 2
			printf(" *** �� ������! ���� %d �������� %d ������ ���׷��̵�!\n\n", level - 1, level);

			// �������� 5
			if (level == 5)
			{
				printf("\n\n�����մϴ�. �ְ��� �޼�! ������ �����մϴ�.\n\n");
				exit(0); // ��� ���α׷��� �����ϴ� ����
			}

		}
		// ��� ����Ⱑ �׾����� Ȯ��
		if (checkFishAlive() == 0)
		{
			printf("����Ⱑ ��� �׾���� �Ф� \n\n");
			printf("������ �����մϴ�.");
			exit(0);
		}
		else
		{
			printf("����Ⱑ ���� ����־��!\n");
		}
		prevElapsedTime = totalElapsedTime; // 10sec -> 15sec (5sec: prev~Time) -> 25sec (10sec�� prevTime�� �Ǿ�� ��) �̸� ���� �ڵ�
	}

	return 0;
}

void initDate()
{
	level = 1;
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; // ������ ������ 0-100
	}
}

void printFishes()
{
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d�� \n", 1, 2, 3, 4, 5, 6); // %3d -> 3ĭ�� ���ڸ� �Ҵ�
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
		arrayFish[i] -= (level * 3 * elapsedTime);  // 3�� ���̵� ������ ���� ����
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
			return 1; // ��. true
	}
	return 0; // ����Ⱑ �� �׾���. False
}