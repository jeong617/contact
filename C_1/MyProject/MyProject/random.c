#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main_random(void)
{
	// srand(time(NULL));  //���� �ʱ�ȭ
	// int num = rand() % 3; // % �ڿ��� ������ ����. 0���� ���� (0~2)

	printf("���� �ʱ�ȭ ����..\n");   //���� �ʱ�ȭ�� ���ϸ� ���� ���� ��� ����
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", rand() % 10);
	}

	printf("\n");
	printf("\n");

	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", rand() % 10);
	}

	return 0;
}