#include <stdio.h>

int main_array(void)
{
	//배열
	int subway_1 = 30;  // 1호차에 30명 타고 있음.
	int subway_2 = 40;
	int subway_3 = 50;

	printf("지하철 1호차에 %d 명이 타고 있음. \n", subway_1);
	printf("지하철 2호차에 %d 명이 타고 있음. \n", subway_2);
	printf("지하철 3호차에 %d 명이 타고 있음. \n", subway_3);

	// 여러 개의 변수를 함께, 동시에 생성
	int subway_array[3];   // [] -> 몇 개의 int형 정수를 보관하는 배열을 만들 것이냐? 이 자리엔 변수 들어갈 수 없음.
	subway_array[0] = 30;		// index는 0부터 시작
	subway_array[1] = 40;
	subway_array[2] = 50;

	for (int i = 0; i < 3; i++)
	{
		printf("지하철 %d호차에 %d 명이 타고있엉\n", i + 1, subway_array[i]);
	}

	//값 설정 방법

	//값은 초기화를 반드시 해야 함.
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10 };  //선언(초기화)을 안하고 들어가면 더미값이 나오게 됨.
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
	
	int arra[10] = { 1,2 };   // 정해주는거 있으면 나머지 값이 더미값이 아니라 자동으로 0 들어감.
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arra[i]);
	}
	// 기댓값: 1 2 0 0 0 0 0 0 0 0

	int arr_2[] = { 1,2 }; // 배열 값은 arr[2]로 선언하는거랑 동일.

	float arr_f[5] = { 1.0f, 2.0f, 3.0f };
	for (int i = 0; i < 5 ; i++)
	{
		printf("%.2f\n", arr_f[i]);
	}

	// 문자 vs 문자열
	char c = 'A';
	printf("%c\n", c);

	// 문자열 끝에는 '끝'을 의미하는 NULL문자 '\0'가 들어가야 함.
	char str[6] = "coding"; // [c][o][d][i][n][g]
	printf("%s\n", str); // 뒤에 이상한 글자가 들어가서 나옴
	char str1[7] = "coding";
	printf("%s\n", str1); // coding이 잘 나옴

	char str2[] = "coding";
	printf("str2: %s\n", str2);
	printf("str2의 size: %d\n", sizeof(str2));

	printf("str2를 index별로 출력\n");

	for (int i = 0; i < sizeof(str2); i++)
	{
		printf("%c\n", str2[i]);
	}

	char kor[] = "나도코딩";
	printf("%s\n", kor);
	printf("%d\n", sizeof(kor));  // 9 출력

	// 영어 한 글자 1 byte
	// 한글 한 글자 2 byte 필요
	// 한 글
	// En gl ish
	// char 크기: 1 byte

	char c_array[7] = { 'c', 'o', 'd', 'i', 'n', 'g' };  // 배열도 무조건 NULL자리 필요
	printf("%s\n", c_array);

	char c_array1[10] = { 'c', 'o', 'd', 'i', 'n', 'g' };
	printf("%s\n", c_array1);         // size가 큰 건 별로 문제가 안된다.

	printf("c_array1를 인덱스 순서로 출력 \n");
	for (int i = 0; i < sizeof(c_array1); i++)
	{
		printf("%c\n", c_array1[i]); // 남는 인덱스는 공백으로 출력.
	}
	for (int i = 0; i < sizeof(c_array1); i++)
	{
		printf("%d\n", c_array1[i]);  // ASCII 코드값 출력. ( null문자는 0으로 입력된 것을 확인할 수 있음 )
	}

	// 문자열 입력받기: 경찰서 조서 쓰기 예제
	/*char name[256];
	printf("이름이 뭐에요?: ");
	scanf_s("%s", name, sizeof(name));
	printf("%s\n", name);*/

	// 참고: ASCII 코드? ANSI(미국표준협회)에서 제시한 표준 코드 체계
	// 7 bit, 총 128개 코드 (0-127)
	// a: 97 (문자 a의 아스키코드 정수값)
	// A: 65 ...

	printf("%c\n", 'a');
	printf("%d\n", 'a');

	printf("%c\n", '\0');
	printf("%d\n", '\0');

	printf("%c\n", '0');
	printf("%d\n", '0');

	// 참고2 : 0-127 사이의 아스키코드 정수값에 해당하는 문자 확인

	for (int i = 0; i < 128; i++)
	{
		printf("아스키코드 정수 %d : %c\n", i, i);
	}

	return 0;
}