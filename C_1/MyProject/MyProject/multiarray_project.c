#include <stdio.h>
#include <time.h>

// 10������ �ٸ� ���� ( �� ī��� 2�徿)
// ����ڷκ��� 2���� �Է°��� �޾Ƽ� -> ���� ���� ã���� ī�� ������
// ��� ���� ���� ã���� ���� ����
// �� ���� Ƚ�� �˷��ֱ�


int arrayAnimal[4][5];  // ī�� ����
int checkAnimal[4][5];  // seq ǥ�� -> ���������� ���� Ȯ��
char* strAnimal[10];

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();

int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);

int foundAllAnimals();

void printAnimals();
void printQuestion();

int main_multiarray_project(void)
{
	srand(time(NULL));

	initAnimalArray();
	initAnimalName();

	shuffleAnimal();

	int failCount = 0;

	while (1)
	{
		int selecte1 = 0; // ����ڰ� ������ ó�� ��
		int selecte2 = 0; // ����ڰ� ������ �ι�° ��

		printAnimals(); // ���� ��ġ ���
		printQuestion(); // ���� ���(ī�� ����)
		printf("������ ī�带 �ΰ� ������!: ");
		scanf_s("%d %d", &selecte1, &selecte2);

		if (selecte1 == selecte2) // ���� ī�� ���� ��
		{
			continue;
		}

		// ��ǥ�� �ش��ϴ� ī�带 ������� ���� �� �Ȱ��� �� Ȯ��
		int firstSelcet_x = conv_pos_x(selecte1);
		int firstSelcet_y = conv_pos_y(selecte1);

		int secondSelcet_x = conv_pos_x(selecte2);
		int secondSelcet_y = conv_pos_y(selecte2);

		if ((checkAnimal[firstSelcet_x][firstSelcet_y]==0)
			&& (checkAnimal[secondSelcet_x][secondSelcet_y]==0)
			&&
			(arrayAnimal[firstSelcet_x][firstSelcet_y] == arrayAnimal[secondSelcet_x][secondSelcet_y]))
		{
			printf("\n\n����! %s �߰� \n\n", strAnimal[arrayAnimal[firstSelcet_x][firstSelcet_y]]);
			checkAnimal[firstSelcet_x][firstSelcet_y] = 1;
			checkAnimal[secondSelcet_x][secondSelcet_y] = 1;
		}
		else
		{
			printf("��! Ʋ�Ȱų�, �̹� ������ ī���Դϴ�~ \n");
			printf("%d: %s\n", selecte1, strAnimal[arrayAnimal[firstSelcet_x][firstSelcet_y]]);
			printf("%d: %s\n", selecte2, strAnimal[arrayAnimal[secondSelcet_x][secondSelcet_y]]);
			printf("\n\n");

			failCount++;

		}
		// ��� ������ ã�Ҵ� �� ����
		if (foundAllAnimals() == 1)
		{
			printf("�����մϴ�! ��� ������ �� ã�ҳ׿�~ \n");
			printf("���ݱ��� �� %d�� �����ϼ̽��ϴ�. \n", failCount);
			break;
		}
		
	}

	return 0;
}

void initAnimalArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1;
		}
	}
}

void initAnimalName()
{
	strAnimal[0] = "������";
	strAnimal[1] = "�ϸ�";
	strAnimal[2] = "������";
	strAnimal[3] = "�����";
	strAnimal[4] = "����";

	strAnimal[5] = "�ڳ���";
	strAnimal[6] = "�⸰";
	strAnimal[7] = "��Ÿ";
	strAnimal[8] = "Ÿ��";
	strAnimal[9] = "ȣ����";
}

void shuffleAnimal() // map�� ���� ������ġ
{
	for (int i = 0; i < 10; i++)  // ���� 10������ŭ pos ����
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}

int getEmptyPosition()  // ����ִ� randPos�� ��ȯ
{
	while (1)
	{
		int randPos = rand() % 20; // 0~19���� ���� ��ȯ
		// ���� 19 -> (3,4)�� ��ȯ�ؾ� ��

		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1)
		{
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x)  // ���� ���
{
	// 19 -> (3, 4)
	return x / 5;
}

int conv_pos_y(int y) // �������� ���
{
	return y % 5; // y�� 5�� ���� ������ ��
}

void printAnimals() // ���� ��ġ ���
{

	printf("\n...����ε� ���� �����ݴϴ� ���� ... \n\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n ==================================== \n\n");
}

void printQuestion()
{
	printf("����: \n");
	int seq = 0;  // 0�̶�� �Ѱ� ��ã����, 1�̶�� �Ѱ� ã����

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// ī�带 ����� ������ �������� ���� �̸� �����ֱ�
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			// ���� ������ �������� �޸� -> �ӽ÷� ��ġ�� ��Ÿ���� ���ڷ� ������
			else
			{
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

int foundAllAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0)
				return 0;
		}
	}
	return 1;
}