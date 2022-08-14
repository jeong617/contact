#include <stdio.h>

int main_array(void)
{
	//�迭
	int subway_1 = 30;  // 1ȣ���� 30�� Ÿ�� ����.
	int subway_2 = 40;
	int subway_3 = 50;

	printf("����ö 1ȣ���� %d ���� Ÿ�� ����. \n", subway_1);
	printf("����ö 2ȣ���� %d ���� Ÿ�� ����. \n", subway_2);
	printf("����ö 3ȣ���� %d ���� Ÿ�� ����. \n", subway_3);

	// ���� ���� ������ �Բ�, ���ÿ� ����
	int subway_array[3];   // [] -> �� ���� int�� ������ �����ϴ� �迭�� ���� ���̳�? �� �ڸ��� ���� �� �� ����.
	subway_array[0] = 30;		// index�� 0���� ����
	subway_array[1] = 40;
	subway_array[2] = 50;

	for (int i = 0; i < 3; i++)
	{
		printf("����ö %dȣ���� %d ���� Ÿ���־�\n", i + 1, subway_array[i]);
	}

	//�� ���� ���

	//���� �ʱ�ȭ�� �ݵ�� �ؾ� ��.
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10 };  //����(�ʱ�ȭ)�� ���ϰ� ���� ���̰��� ������ ��.
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
	
	int arra[10] = { 1,2 };   // �����ִ°� ������ ������ ���� ���̰��� �ƴ϶� �ڵ����� 0 ��.
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arra[i]);
	}
	// ���: 1 2 0 0 0 0 0 0 0 0

	int arr_2[] = { 1,2 }; // �迭 ���� arr[2]�� �����ϴ°Ŷ� ����.

	float arr_f[5] = { 1.0f, 2.0f, 3.0f };
	for (int i = 0; i < 5 ; i++)
	{
		printf("%.2f\n", arr_f[i]);
	}

	// ���� vs ���ڿ�
	char c = 'A';
	printf("%c\n", c);

	// ���ڿ� ������ '��'�� �ǹ��ϴ� NULL���� '\0'�� ���� ��.
	char str[6] = "coding"; // [c][o][d][i][n][g]
	printf("%s\n", str); // �ڿ� �̻��� ���ڰ� ���� ����
	char str1[7] = "coding";
	printf("%s\n", str1); // coding�� �� ����

	char str2[] = "coding";
	printf("str2: %s\n", str2);
	printf("str2�� size: %d\n", sizeof(str2));

	printf("str2�� index���� ���\n");

	for (int i = 0; i < sizeof(str2); i++)
	{
		printf("%c\n", str2[i]);
	}

	char kor[] = "�����ڵ�";
	printf("%s\n", kor);
	printf("%d\n", sizeof(kor));  // 9 ���

	// ���� �� ���� 1 byte
	// �ѱ� �� ���� 2 byte �ʿ�
	// �� ��
	// En gl ish
	// char ũ��: 1 byte

	char c_array[7] = { 'c', 'o', 'd', 'i', 'n', 'g' };  // �迭�� ������ NULL�ڸ� �ʿ�
	printf("%s\n", c_array);

	char c_array1[10] = { 'c', 'o', 'd', 'i', 'n', 'g' };
	printf("%s\n", c_array1);         // size�� ū �� ���� ������ �ȵȴ�.

	printf("c_array1�� �ε��� ������ ��� \n");
	for (int i = 0; i < sizeof(c_array1); i++)
	{
		printf("%c\n", c_array1[i]); // ���� �ε����� �������� ���.
	}
	for (int i = 0; i < sizeof(c_array1); i++)
	{
		printf("%d\n", c_array1[i]);  // ASCII �ڵ尪 ���. ( null���ڴ� 0���� �Էµ� ���� Ȯ���� �� ���� )
	}

	// ���ڿ� �Է¹ޱ�: ������ ���� ���� ����
	/*char name[256];
	printf("�̸��� ������?: ");
	scanf_s("%s", name, sizeof(name));
	printf("%s\n", name);*/

	// ����: ASCII �ڵ�? ANSI(�̱�ǥ����ȸ)���� ������ ǥ�� �ڵ� ü��
	// 7 bit, �� 128�� �ڵ� (0-127)
	// a: 97 (���� a�� �ƽ�Ű�ڵ� ������)
	// A: 65 ...

	printf("%c\n", 'a');
	printf("%d\n", 'a');

	printf("%c\n", '\0');
	printf("%d\n", '\0');

	printf("%c\n", '0');
	printf("%d\n", '0');

	// ����2 : 0-127 ������ �ƽ�Ű�ڵ� �������� �ش��ϴ� ���� Ȯ��

	for (int i = 0; i < 128; i++)
	{
		printf("�ƽ�Ű�ڵ� ���� %d : %c\n", i, i);
	}

	return 0;
}