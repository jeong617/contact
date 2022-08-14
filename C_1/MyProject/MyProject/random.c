#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main_random(void)
{
	// srand(time(NULL));  //난수 초기화
	// int num = rand() % 3; // % 뒤에는 범위를 지정. 0부터 시작 (0~2)

	printf("난수 초기화 이전..\n");   //난수 초기화를 안하면 같은 수가 계속 나옴
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