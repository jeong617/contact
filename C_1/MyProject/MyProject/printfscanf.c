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


	// 실수형 변수 예제
	float f = 46.5;
	printf("%f\n", f);

	double d = 4.428;
	printf("%.2lf\n", d);    // 기댓값 4.43

	//상수
	const int YEAR = 1999;    // const는 상수처리. 아래에서 이 값을 누구도 바꿀 수 없다.
	printf("태어난 연도 : %d\n", YEAR);

	//printf
	int add = 3 + 7;  // 10
	printf("3 + 7 = %d\n", add);
	printf("%d + %d = %d\n", 3, 7, 3 + 7);
	
	//scanf: 키보드 입력을 받아서 저장
	int input;
	printf("값을 입력하세요. : ");
	scanf_s("%d", &input);
	printf("입력값: %d\n", input);
	
	int one, two, three;
	printf("3개의 정수를 입력하세요.: ");
	scanf_s("%d %d %d", &one, &two, &three); // %d %d %d 니까 입력 시 100 200 300 이런 식으로 맞춰줘야 함
	printf("첫 번째 정수: %d \n", one); 
	printf("두 번째 정수: %d \n", two);
	printf("세 번째 정수: %d \n", three);

	//문자(한 글자), 문자열(한 글자 이상의 여러 글자)
	//char c = 'A'; // char -> character
	//printf("%c\n", c);
	//
	//char str[256]; // 256개의 공간을 만드는군. 정도로
	//scanf_s("%s\n", str, sizeof(str));
	//printf("%s\n", str);

	//프로젝트
	//조서 작성
	//이름, 나이, 몸무게, 키, 범죄명
	
	char name[256];
	printf("이름이 뭐에요?");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("몇 살이에요?");
	scanf_s("%d", &age);

	float weight;
	printf("몇키로에요?");
	scanf_s("%f", &weight);

	double height;
	printf("키가 몇이에요? ");
	scanf_s("%lf", &height);

	char what[256];
	printf("무슨 범죄를 저질렀나요?");
	scanf_s("%s", what, sizeof(what));

	//조서 내용 출력
	printf("\n\n--- 범죄자 정보 ---\n\n");
	printf(" 이름     : %s\n", name);
	printf(" 나이     : %d\n", age);
	printf(" 몸무게   : %.2f\n", weight);
	printf(" 키       : %.2lf\n", height);
	printf(" 범죄     : %s\n", what);

	return 0;

	// 주석은 슬래시 두개(//), 또는 /*  */ 이렇게 해준다.


}
