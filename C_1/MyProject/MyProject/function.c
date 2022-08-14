#include <stdio.h>

//선언
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

// 반환형 함수이름(전달값)

int main_function(void)
{


	//function

	int num = 2;
	printf("num은 %d 입니다. \n", num);
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

	// 함수 종류
	// 반환 값이 없는 함수
	function_without_return();
	int re = function_with_return();
	p(re);

	// 파라미터(전달값)가 없는 함수
	function_without_para();

	// 파라미터가 있는 함수
	function_with_para(35, 12, 59);

	// 파라미터도 있고 반환값도 있는 함수
	int ret = apple(5, 2);  // 5개의 사과중 2개를 먹었어용
	printf("사과 5개 중에 2개를 먹으면 %d 개가 남아용\n", ret );

	printf("사과 %d 개 중에 %d 개를 먹으면 %d 개가 남아용\n", 10, 4, apple(10, 4));

	// 계산기 함수
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

//정의
void p(int num)
{
	printf("num = %d \n", num);
}

void function_without_return()
{
	printf("반환값이 없는 함수입니다.\n");
}

int function_with_return()
{
	printf("반환값이 있는 함수입니다.\n");
	return 10;
}

void function_without_para()
{
	printf("전달값이 없는 함수입니다.\n");
}

void function_with_para(int num1, int num2, int num3)
{
	printf("전달값이 있는 함수입니다.\n");
	printf("num1: %d , num2: %d, num3: %d \n", num1, num2, num3);
}

int apple(int total, int ate)
{
	printf("전달값 있고, 반환값 있는 함수\n");
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
