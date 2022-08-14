#include <stdio.h>
void swap(int a, int b);
void swap_addr(int *a, int *b);
void changeArray(int* ptr);

int main_pointer(void)
{
	// 포인터
	// 철수 101호
	// 영희 201호
	// 민수 301호

	int 철수 = 1;    // 암호
	int 영희 = 2;
	int 민수 = 3;

	printf("철수네 주소 : %d, password : %d\n", &철수, 철수);
	printf("영희네 주소 : %d, password : %d\n", &영희, 영희);
	printf("민수네 주소 : %d, password : %d\n", &민수, 민수);

	// 미션맨 !

	// 첫 번째 미션: 아파트의 각 집에 방문하여 문에 적힌 암호 확인
	int * 미션맨; // 포인터 변수
	미션맨 = &철수;  // 미션맨은 철수의 주소를 갖는다
	printf("미션맨이 방문하는 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	미션맨 = &영희;
	printf("미션맨이 방문하는 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	미션맨 = &민수;
	printf("미션맨이 방문하는 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	// 두 번째 미션: 각 암호에 3을 곱해라
	미션맨 = &철수;
	*미션맨 = *미션맨 * 3;
	printf("미션맨이 암호를 바꾼 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	미션맨 = &영희;
	*미션맨 = *미션맨 * 3;
	printf("미션맨이 암호를 바꾼 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);
	
	미션맨 = &민수;
	*미션맨 = *미션맨 * 3;
	printf("미션맨이 암호를 바꾼 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	// 스파이
	// 미션맨이 바꾼 암호에서 2를 빼라 (미션맨 모르게!)

	int* 스파이 = 미션맨;
	printf("\n ... 스파이가 미션 수행 중 ... \n\n");
	스파이 = &철수;
	*스파이 = *스파이 - 2;   // 철수 = 철수 - 2 랑 같은 문장
	printf("스파이가 방문하는 곳 주소: %d, 암호: %d\n", 스파이, *스파이);

	스파이 = &영희;
	*스파이 = *스파이 - 2;
	printf("스파이가 방문하는 곳 주소: %d, 암호: %d\n", 스파이, *스파이);

	스파이 = &민수;
	*스파이 = *스파이 - 2;
	printf("스파이가 방문하는 곳 주소: %d, 암호: %d\n", 스파이, *스파이);

	printf("\n...철수 영희 민수는 집에 와서 바뀐 암호를 보고 깜놀!...\n\n");

	printf("철수네 주소 : %d, password : %d\n", &철수, 철수);
	printf("영희네 주소 : %d, password : %d\n", &영희, 영희);
	printf("민수네 주소 : %d, password : %d\n", &민수, 민수);


	// 스파이
	//			=>  누군가의 아파트주소
	// 미션맨

	// 참고... 미션맨이 사는 주소는 &미션맨으로 확인

	printf("미션맨의 주소는 %d\n", &미션맨);
	printf("스파이의 주소는 %d\n", &스파이);

	// 배열

	int arr[3] = { 5, 10, 15 };
	int* ptr = arr;

	for (int i = 0; i < 3; i++)
	{
		printf("배열 arr[%d]의 값: %d\n", i, arr[i]);  // arr[i] = *(arr + i) 둘이 같은 표현!
	}
	for (int i = 0; i < 3; i++)
	{
		printf("배열 ptr[%d]의 값: %d\n", i, ptr[i]);
	}
	ptr[0] = 100;
	ptr[1] = 200;
	ptr[2] = 300;
	for (int i = 0; i < 3; i++)
	{
		printf("배열 arr[%d]의 값: %d\n", i, arr[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		printf("포인터 ptr[%d]의 값: %d\n", i, ptr[i]);
	}
	// 결론: arr = ptr
	// arr == arr 배열의 첫번째 값의 주소와 동일 == &arr[0]

	printf("arr 자체의 값 : %d\n", arr);
	printf("arr[0]의 주소 : %d\n", &arr[0]);

	printf("arr자체의 값이 가지는 주소의 실제값 : %d\n", *arr); // *(arr + 0)
	printf("arr[0]의 실제값 : %d\n", *&arr[0]);

	// *& 은 이 변수의 주소의 값 => 아무것도 없는 것과 같다. (서로 상쇄)

	// swap
	int a = 10;
	int b = 20;
	printf("a 의 주소: %d\n", &a);
	printf("b 의 주소: %d\n", &b);
	
	// a와 b의 값을 바꾼다
	printf("swap 함수 전 => a: %d, b: %d\n", a, b);
	swap(a, b);
	printf("swap 함수 후 => a: %d, b: %d\n", a, b);

	// 결론: swap 함수 내/외부의 a, b는 서로 다른 변수이다.
	 
	// 값에 의한 복사(call by value) -> 값만 복사한다는 의미

	// 주소값을 넘기면? 메모리 공간에 있는 주소값 자체를 넘기면 ... 철수네처럼
	printf("(주소값 전달)swap 함수 전 => a: %d, b: %d\n", a, b);
	swap_addr(&a, &b);
	printf("(주소값 전달)swap 함수 후 => a: %d, b: %d\n", a, b);

	// 배열일 때 arr2 -> 이 자체로 주소
	int arr2[3] = { 10,20,30 };
	changeArray(arr2);
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", arr2[i]);
	}
	changeArray(&arr2[0]);
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", arr2[i]);
	}

	// scanf에서 &num과 같이 &를 사용하는 이유?


	return 0;
}

void swap(int a, int b)
{
	printf("swap 함수 내 a 의 주소: %d\n", &a);
	printf("swap 함수 내 b 의 주소: %d\n", &b);

	int temp = a;
	a = b;
	b = temp;
	printf("swap 함수 내부 => a: %d, b: %d\n", a, b);
}
void swap_addr(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("(주소값 전달)swap 함수 내부 => a: %d, b: %d\n", a, b);
}

void changeArray(int * ptr)
{
	ptr[2] = 50;
}