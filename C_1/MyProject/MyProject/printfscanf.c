# include <stdio.h>
int main_printfscanf(void)
{
	/*int age = 12;
	printf("%d\n", age);
	age = 13;
	printf("%d\n", age); */

	//printf("1\n");
	//printf("2\n");
	//printf("3\n");


	// �Ǽ��� ���� ����
	float f = 46.5;
	printf("%f\n", f);

	double d = 4.428;
	printf("%.2lf\n", d);    // ��� 4.43

	//���
	const int YEAR = 1999;    // const�� ���ó��. �Ʒ����� �� ���� ������ �ٲ� �� ����.
	printf("�¾ ���� : %d\n", YEAR);

	//printf
	int add = 3 + 7;  // 10
	printf("3 + 7 = %d\n", add);
	printf("%d + %d = %d\n", 3, 7, 3 + 7);
	
	//scanf: Ű���� �Է��� �޾Ƽ� ����
	int input;
	printf("���� �Է��ϼ���. : ");
	scanf_s("%d", &input);
	printf("�Է°�: %d\n", input);
	
	int one, two, three;
	printf("3���� ������ �Է��ϼ���.: ");
	scanf_s("%d %d %d", &one, &two, &three); // %d %d %d �ϱ� �Է� �� 100 200 300 �̷� ������ ������� ��
	printf("ù ��° ����: %d \n", one); 
	printf("�� ��° ����: %d \n", two);
	printf("�� ��° ����: %d \n", three);

	//����(�� ����), ���ڿ�(�� ���� �̻��� ���� ����)
	//char c = 'A'; // char -> character
	//printf("%c\n", c);
	//
	//char str[256]; // 256���� ������ ����±�. ������
	//scanf_s("%s\n", str, sizeof(str));
	//printf("%s\n", str);

	//������Ʈ
	//���� �ۼ�
	//�̸�, ����, ������, Ű, ���˸�
	
	char name[256];
	printf("�̸��� ������?");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("�� ���̿���?");
	scanf_s("%d", &age);

	float weight;
	printf("��Ű�ο���?");
	scanf_s("%f", &weight);

	double height;
	printf("Ű�� ���̿���? ");
	scanf_s("%lf", &height);

	char what[256];
	printf("���� ���˸� ����������?");
	scanf_s("%s", what, sizeof(what));

	//���� ���� ���
	printf("\n\n--- ������ ���� ---\n\n");
	printf(" �̸�     : %s\n", name);
	printf(" ����     : %d\n", age);
	printf(" ������   : %.2f\n", weight);
	printf(" Ű       : %.2lf\n", height);
	printf(" ����     : %s\n", what);

	return 0;

	// �ּ��� ������ �ΰ�(//), �Ǵ� /*  */ �̷��� ���ش�.


}
