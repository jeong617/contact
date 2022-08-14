#include <stdio.h>
#include <time.h>

int main_conditon(void)
{
	//������ ź�ٰ� ����. �л� �Ǵ� �Ϲ��� ( �Ϲ���: 20�� )
	//if_else��
	int age = 15;
	if (age >= 20)
		printf("�Ϲ��� �Դϴ�\n");
	else
		printf("�л��Դϴ�.\n");
	
	//��(8~13) , ��(14~16), ��(17~19)�� ������?
	//if else else if
	int age1 = 8;
	if (age1 >= 8 && age1 <= 13)
		printf("�ʵ��л��Դϴ�.");
	else if (age1 >= 14 && age1 <= 16)
		printf("���л� �Դϴ�.");
	else if (age1 >= 17 && age1 <= 19)
		printf("����л��Դϴ�.");
	else
		printf("�л��� �ƴѰ�����?");

	// break&continue
	// 1������ 30������ �ִ� �ݿ��� 1������ 5������ ���� ��ǥ�� �մϴ�.

	for (int i = 1; i <= 30; i++)
	{
		if (i >= 6)
		{
			printf("������ �л��� ���� ������\n");
			break;										// break�� for�� Ż��
		}
		printf("%d �� �л��� ���� ��ǥ �غ� �ϼ���.\n", i);
	}
	printf("\n");
	//1������ 30������ �ִ� �ݿ��� 7�� �л� �Ἦ, 7�� ���� 6~10������ ������ǥ�� �ϼ���

	for (int i = 1; i <= 30; i++)
	{
		if (i >= 6 && i <= 10)
		{
			if (i == 7)
			{
				printf("%d�� �л��� �Ἦ�Դϴ�.\n", i);
				continue; //continue�� ������ �� ���� ���� ���� ���ϰ� ���ο� for�� ����
			}
			printf("%d �� �л��� ��ǥ�� �غ��ϼ���.\n", i);
		}
	}

	// && �� ||  ( and�� or )
	
	int a = 10;
	int b = 11;
	int c = 13;
	int d = 13;

	if (a == b && c == d)
	{
		printf("a�� b�� ����, c�� d�� �����ϴ�\n");
	}
	else
	{
		printf("���� ���� �ٸ��ϴ�\n");
	}

	if (a == b || c == d)
	{
		printf("a�� b�� ���ų�, c�� d�� �����ϴ�.\n");
	}
	else
	{
		printf("���� ���� �ٸ��ϴ�\n");
	}

	//����0  ����1 ��2

	srand(time(NULL));
	int i = rand() % 3;
	if (i == 0)
		printf("����\n");
	else if (i == 1)
		printf(" ����\n");
	else if (i == 2)
		printf(" ��\n");


	srand(time(NULL));
	int j = rand() % 3;
	switch (j)
	{
	case 0: printf("����\n"); break; // break�� ���� switch ���� Ż��
	case 1: printf("����\n"); break;
	case 2: printf("��\n"); break;
	default: printf("�����"); break; // break �Ȱɾ��ָ� �ڿ� ���� �� ��µ�
	}

	//����ī�� ������ switch ��������
	int age2 = 25;
	switch (age2)
	{
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13: printf("�ʵ��л��Դϴ�."); break;     //�̷��� �ϸ� case 8~12������ break��� �� �������ٰ� �ʵ��л� ����ϰ� break ��
	case 14:
	case 15:
	case 16: printf("���л��Դϴ�."); break;
	case 17:
	case 18:
	case 19: printf("����л��Դϴ�."); break;
	default: printf("�л��� �ƴѰ�����");
		break;
	}
	

	//������Ʈ

	srand(time(NULL));
	int num = rand() % 100 + 1; // 1���� 100���� �� �ϳ��� ��
	printf("����: %d\n ", num);
	int answer;
	int chance = 5;

	while (chance > 0)
	{
		printf("���� ��ȸ: %d ��\n", chance--);
		printf("���ڸ� ���纸����: ");
		scanf_s("%d", &answer);

		if (answer < num)
			printf("up \n\n");
		else if (answer > num)
			printf("down\n\n");
		else if (answer == num)
		{
			printf("�����Դϴ�~~\n");
			break;
		}
		else
			printf("���������\n");

		if (chance == 9)
		{
			printf("���� ��ȸ ����~\n");
			break;
		}
	}
	return 0;
}