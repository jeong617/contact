#include <stdio.h>

struct GameInfo {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // ���� ��ü ����
};

typedef struct GameInformation {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame;
} GAME_INFO;

int main_struct(void)
{
	// ���� ���
	// �̸�: ���� ����
	// �߸ų⵵: 2020
	// ����: 50��
	// ���ۻ�: ����ȸ��

	char* name = "��������";
	int year = 2020;
	int price = 50;
	char* company = "����ȸ��";

	// �ٸ� ���� ���
	// �̸�: ũ����Ż ����
	// �߸ų⵵: 2022
	// ����: 100��
	// ���ۻ�: ����ȸ��
	char* name2 = "ũ����Ż ����";
	int year2 = 2022;
	int price2 = 100;
	char* company2 = "����ȸ��";

	// ����ü ���
	struct GameInfo gameInfo1;
	gameInfo1.name = "��������";
	gameInfo1.year = 2020;
	gameInfo1.price = 50;
	gameInfo1.company = "����ȸ��";

	// ����ü ���
	printf("--���� ��� ����--\n");
	printf("  ���Ӹ�     : %s\n", gameInfo1.name);
	printf(" �߸ų⵵    : %d\n", gameInfo1.year);
	printf("  ����       : %d\n", gameInfo1.price);
	printf("  ���ۻ�     : %s\n\n", gameInfo1.company);

	// ����ü �迭ó�� �ʱ�ȭ
	struct GameInfo gameInfo2 = { "ũ����Ż ����", 2022, 100, "����ȸ��" };
	printf("--�� �ٸ� ���� ��� ����--\n");
	printf("  ���Ӹ�     : %s\n", gameInfo2.name);
	printf(" �߸ų⵵    : %d\n", gameInfo2.year);
	printf("  ����       : %d\n", gameInfo2.price);
	printf("  ���ۻ�     : %s\n\n", gameInfo2.company);

	// ����ü �迭
	struct GameInfo gameArray[2] = {
		{"��������", 2020, 50, "����ȸ��"},
		{"ũ����Ż����", 2022, 100, "����ȸ��"}
	};

	// ����ü ������
	struct GameInfo* gamePtr; // �̼Ǹ�
	gamePtr = &gameInfo1;
	printf("--���� ��� ����--\n");
	printf("  ���Ӹ�     : %s\n", gamePtr->name);  // gamePtr-> = (*gamePtr).name ���� �Ȱ���
	printf(" �߸ų⵵    : %d\n", (*gamePtr).year);
	printf("  ����       : %d\n", (*gamePtr).price);
	printf("  ���ۻ�     : %s\n\n", (*gamePtr).company);

	// ���� ��ü ���� �Ұ�
	gameInfo1.friendGame = &gameInfo2;
	printf("--���� ��ü ���� ��� ����--\n");
	printf("  ���Ӹ�     : %s\n", gameInfo1.friendGame->name);  // gamePtr-> = (*gamePtr).name ���� �Ȱ���
	printf(" �߸ų⵵    : %d\n", gameInfo1.friendGame->year);
	printf("  ����       : %d\n", gameInfo1.friendGame->price);
	printf("  ���ۻ�     : %s\n\n", gameInfo1.friendGame->company);

	// typedef
	// �ڷ����� ���� ����
	int i = 1;
	typedef int ����;
	typedef float �Ǽ�;
	���� �������� = 3;  // int i = ; �̶� �Ȱ���
	�Ǽ� �Ǽ����� = 3.23f; // float f = 3.23f
	printf("��������: %d, �Ǽ�����: %.2f\n\n", ��������, �Ǽ�����);

	typedef struct GameInfo ��������;
	�������� game1;
	game1.name = "�ѱ� ����";
	game1.year = 2015;

	GAME_INFO game2;
	game2.year = 2014;
	game2.name = "�������";
	




	return 0;
}