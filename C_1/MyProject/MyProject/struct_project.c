#include <stdio.h>

#include <time.h>


// ����� 5����
// �ƹ� Ű�� ������ �������� ����̸� �̵�
// 5���� ��� �����Ͽ� ���簡 ����
// �ߺ��߻� ����!

/*
�����
�̸�, ����, ����, Ű��� ���̵�(����)*/

typedef struct {
	char* name;
	int age;
	char* character;
	int level;
} CAT;

// ������� ������ �����

int collection[5] = { 0,0,0,0,0 };

// ��ü ����� ����Ʈ
CAT cats[5];

void initCats();
void printCat(int selected);

int main_struct_project(void)
{
	srand(time(NULL));

	initCats();
	while (1)
	{
		printf("� ������� ���簡 �ɱ��~?\n �ƹ�Ű�� �Է��ϼ���.");
		getchar();
		
		int selected = rand() % 5;
		printCat(selected); // ���� ����� ���� ���
		collection[selected] = 1;  // �̱� ó��

		int colledAll = checkCollection();

		if (colledAll == 1)
		{
			break;
		}
	}


	return 0;
}

void initCats()
{
	cats[0].name = "������";
	cats[0].age = 5;
	cats[0].character = "�¼�";
	cats[0].level = "1";

	cats[1].name = "�Ϳ��";
	cats[1].age = 3;
	cats[1].character = "�Ϳ���";
	cats[1].level = 2;

	cats[2].name = "�����";
	cats[2].age = 2;
	cats[2].character = "�ò�����";
	cats[2].level = 3;

	cats[3].name = "ġ�����";
	cats[3].age = 7;
	cats[3].character = "���̸���";
	cats[3].level = 4;

	cats[4].name = "��ĥ��";
	cats[4].age = 4;
	cats[4].character = "��ĥ��";
	cats[4].level = 5;
}

void printCat(int selected)
{
	printf("\n\n === ����� �� ������� ���簡 �Ǿ����! === \n\n");
	printf("  �̸�      : %s\n", cats[selected].name);
	printf("  ����      : %d\n", cats[selected].age);
	printf("  ����      : %s\n", cats[selected].character);
	printf("  ����      : ");

	for (int i = 0; i < cats[selected].level; i++)
	{
		printf("%s", "��");
	}
	printf("\n\n");
}

int checkCollection()
{
	// ������ ����� ��� ��� + �� ��Ҵ� �� ���� ��ȯ
	int collectAll = 1;
	
	printf("\n\n == ������ ����� ��� ==\n\n");
	for (int i = 0; i < 5; i++)
	{
		if (collection[i] == 0)
		{
			printf("%10s", "(��ڽ�)");
			collectAll = 0; // �� ������ ���� ����
		}

		
		else
			printf("%10s", cats[i].name);
	}

	printf("\n ======================================= \n\n");

	if (collectAll == 1)
	{
		printf("�����մϴ�~ ��� ����̸� �� ��Ҿ��!\n");
	}

	return collectAll;
}