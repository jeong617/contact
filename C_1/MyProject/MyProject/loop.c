# include <stdio.h>

int main_loop(void)
{
	/*printf("hello world\n");
	return 0;*/
	//++ 뿔뿔
	int a = 10;
	printf("a는 %d\n", a); // a는 10
	a++; // a = 11
	printf("a는 %d\n", a); // 11
	a++; // a = 12
	printf("a는 %d\n", a); // 12


	int b = 20;
	printf("b는 %d\n", ++b); // 문장이 끝나기 전에 ++ 수행
	printf("b는 %d\n", b++); // 문장이 끝난 후에 ++ 수행
	printf("b는 %d\n", b);

	//반복문
	//for, while, do while

	//for(선언; 조건; 증감) 세미콜론으로 구분
	for (int i = 1; i <= 10; i++)
	{
		printf("hello world %d\n", i);
	}

	//while (조건) {}
	int i = 1;
	while (i <= 10)
	{
		printf("hello world %d\n", i++);

	}

	//do { } while (조건);
	int p = 1;
	do {
		printf("hello world %d\n", p++);
	} while (p <= 10);


	// 2중 반복문
	for (int i = 1; i <= 3; i++)
	{
		printf("첫 번째 반복문: %d\n", i);
		for (int j = 1; j <= 5; j++)
		{
			printf("	두 번째 반복문: %d\n", j);
		}
	}

	//구구단 프로그램

	for (int i = 2; i <= 9; i++)
	{
		printf("%d단 계산\n", i);
		for (int j = 1; j <= 9; j++)
		{
			printf("%d x %d = %d\n", i, j, i * j);
		}
	}

	// 별로 피라미드 모양 쌓아보기

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//이중 반복문
	for (int i = 0; i < 5; i++)
	{
		for (int j = i ; j < 5 - 1; j++)
		{
			printf(" ");
		}
		for (int k = 0; k <= i; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	//피라미드를 쌓아라 프로젝트

	int floor;
	printf("몇 층으로 쌓겠느냐?");
	scanf_s("%d", &floor);
	for (int i = 0; i < floor; i++)
	{
		for (int j = i ; j < floor - 1; j++)
		{
			printf(" ");
		}
		for (int k = 0; k < i*2 +1 ; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;

}