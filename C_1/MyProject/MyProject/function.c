#include <stdio.h>

//����
void p(int num);

void function_without_return();

int function_with_return();

void function_without_para();

void function_with_para(int num1, int num2, int num3);

int apple(int total, int ate);

int add(int num1, int num2);

int sub(int num1, int num2);

int mul(int num1, int num2);

int div(int num1, int num2);

// ��ȯ�� �Լ��̸�(���ް�)

int main_function(void)
{


	//function

	int num = 2;
	printf("num�� %d �Դϴ�. \n", num);
	p(num);

	// 2 + 3?
	num = num + 3;
	printf("num = %d \n", num);
	p(num);

	// 5 - 1?
	num = num - 1;
	printf("num = %d \n", num);
	p(num);

	// 4 x 3 
	num = num * 3;
	printf("num = %d \n", num);
	p(num);

	// 12 / 6
	num = num / 6;
	printf("num = %d \n", num);
	p(num);

	// �Լ� ����
	// ��ȯ ���� ���� �Լ�
	function_without_return();
	int re = function_with_return();
	p(re);

	// �Ķ����(���ް�)�� ���� �Լ�
	function_without_para();

	// �Ķ���Ͱ� �ִ� �Լ�
	function_with_para(35, 12, 59);

	// �Ķ���͵� �ְ� ��ȯ���� �ִ� �Լ�
	int ret = apple(5, 2);  // 5���� ����� 2���� �Ծ����
	printf("��� 5�� �߿� 2���� ������ %d ���� ���ƿ�\n", ret );

	printf("��� %d �� �߿� %d ���� ������ %d ���� ���ƿ�\n", 10, 4, apple(10, 4));

	// ���� �Լ�
	int numb = 2;
	numb = add(numb, 3);
	p(numb);

	numb = sub(numb, 1);
	p(numb);

	numb = mul(numb, 3);
	p(numb);

	numb = div(numb, 6);
	p(num);


	return 0;
}

//����
void p(int num)
{
	printf("num = %d \n", num);
}

void function_without_return()
{
	printf("��ȯ���� ���� �Լ��Դϴ�.\n");
}

int function_with_return()
{
	printf("��ȯ���� �ִ� �Լ��Դϴ�.\n");
	return 10;
}

void function_without_para()
{
	printf("���ް��� ���� �Լ��Դϴ�.\n");
}

void function_with_para(int num1, int num2, int num3)
{
	printf("���ް��� �ִ� �Լ��Դϴ�.\n");
	printf("num1: %d , num2: %d, num3: %d \n", num1, num2, num3);
}

int apple(int total, int ate)
{
	printf("���ް� �ְ�, ��ȯ�� �ִ� �Լ�\n");
	return total - ate;
}

int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}

int mul(int num1, int num2)
{
	return num1*num2;
}

int div(int num1, int num2)
{
	return num1 / num2;
}
