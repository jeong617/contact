# include <stdio.h>

int main_loop(void)
{
	/*printf("hello world\n");
	return 0;*/
	//++ �Ի�
	int a = 10;
	printf("a�� %d\n", a); // a�� 10
	a++; // a = 11
	printf("a�� %d\n", a); // 11
	a++; // a = 12
	printf("a�� %d\n", a); // 12


	int b = 20;
	printf("b�� %d\n", ++b); // ������ ������ ���� ++ ����
	printf("b�� %d\n", b++); // ������ ���� �Ŀ� ++ ����
	printf("b�� %d\n", b);

	//�ݺ���
	//for, while, do while

	//for(����; ����; ����) �����ݷ����� ����
	for (int i = 1; i <= 10; i++)
	{
		printf("hello world %d\n", i);
	}

	//while (����) {}
	int i = 1;
	while (i <= 10)
	{
		printf("hello world %d\n", i++);

	}

	//do { } while (����);
	int p = 1;
	do {
		printf("hello world %d\n", p++);
	} while (p <= 10);


	// 2�� �ݺ���
	for (int i = 1; i <= 3; i++)
	{
		printf("ù ��° �ݺ���: %d\n", i);
		for (int j = 1; j <= 5; j++)
		{
			printf("	�� ��° �ݺ���: %d\n", j);
		}
	}

	//������ ���α׷�

	for (int i = 2; i <= 9; i++)
	{
		printf("%d�� ���\n", i);
		for (int j = 1; j <= 9; j++)
		{
			printf("%d x %d = %d\n", i, j, i * j);
		}
	}

	// ���� �Ƕ�̵� ��� �׾ƺ���

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//���� �ݺ���
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

	//�Ƕ�̵带 �׾ƶ� ������Ʈ

	int floor;
	printf("�� ������ �װڴ���?");
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