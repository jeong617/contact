#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// ��й�ȣ�� �Է¹޾Ƽ�
// ������ -> ����ϱ⸦ �о�ͼ� �����ְ� ��� �ۼ��ϵ��� �մϴ�.
// Ʋ���� -> ���޼����� ǥ���ϰ� ����

# define MAX 10000

int main(void)
{
	// fgets, gputs ���
	char line[MAX];  // ���Ͽ��� �ҷ��� ������ ������ ����
	char contents[MAX];   // �ϱ��忡 �Է��� ����
	char password[20]; // ��й�ȣ �Է�
	char c; // ��й�ȣ �Է� �� Ű�� Ȯ�ο�(����ŷ)

	printf("'����ϱ�'�� ���� ���� ȯ���մϴ�.\n");
	printf("��й�ȣ�� �Է��ϼ���.\n");

	// getchar() / getch() �� ����?
	// getchar(): ���͸� �Է¹޾ƾ� ������ �մϴ�.
	// getch(): Ű �Է� �� �ٷιٷ� ������ �մϴ�.

	int i = 0;
	while (1)
	{
		c = getch();
		if (c == 13)  // 13�� ���͸� ��Ÿ���� �ƽ�Ű�ڵ� -> ��й�ȣ �Է� ����
		{

			password[i] = '\0';  // NULL -> \0
			break;
		}
		else  // ��й�ȣ �Է� ��
		{
			printf("*");
			password[i] = c;
		}
		i++;
	}

	printf("\\n\n === ��й�ȣ Ȯ���� ... ===\n\n");
	if (strcmp(password, "skehzheld") == 0)  // ��й�ȣ ��ġ
	{
		printf(" === ��й�ȣ �Է� �Ϸ� === \n\n");
		char* fileName = "c:\\exProject_2022\\C_1\\secretdiary.txt";
		FILE* file = fopen(fileName, "a+b");
		// a+b -> ������ ������ ����, ������ append�� �Ѵ�.(�ڿ� ���� �߰�)
		if (file == NULL)
		{
			printf("���� ���� ����!");
			return 1;
		}

		while (fgets(line, MAX, file) != NULL)
		{
			printf("%s", line);
		}

		printf("\n\n ������ ��� �ۼ��ϼ���! �����Ͻø� exit�� �Է��ϼ���. \n\n");

		while (1)
		{
			scanf("%[^\n]", contents);  // �ٹٲ�(\n)�� ������ ������ ��� ���ڿ��� �� ����־��~
			getchar();  // enter �Է� (\n) Flush ó�� -> buffer�� �����ִ� ���͸� ���ֹ����� ����

			if (strcmp(contents, "exit") == 0)
			{
				printf("����ϱ⸦ �����մϴ�. \n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file);  // enter�� ������ ����ó�� �����Ƿ� ���Ƿ� �߰�
		}
		fclose(file);
	}
	// ��й�ȣ Ʋ�� ���
	else
	{
		printf("=== ��й�ȣ�� Ʋ�Ⱦ�� === \n\n\n");
		printf("�� ����~~~~~\n");
	}
	return 0;
}