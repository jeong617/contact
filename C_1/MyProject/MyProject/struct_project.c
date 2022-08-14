#include <stdio.h>

#include <time.h>


// 고양이 5마리
// 아무 키나 눌러서 랜덤으로 고양이를 뽑되
// 5마리 모두 수집하여 집사가 되자
// 중복발생 가능!

/*
고양이
이름, 나이, 성격, 키우기 난이도(레벨)*/

typedef struct {
	char* name;
	int age;
	char* character;
	int level;
} CAT;

// 현재까지 보유한 고양이

int collection[5] = { 0,0,0,0,0 };

// 전체 고양이 리스트
CAT cats[5];

void initCats();
void printCat(int selected);

int main_struct_project(void)
{
	srand(time(NULL));

	initCats();
	while (1)
	{
		printf("어떤 고양이의 집사가 될까요~?\n 아무키나 입력하세요.");
		getchar();
		
		int selected = rand() % 5;
		printCat(selected); // 뽑은 고양이 정보 출력
		collection[selected] = 1;  // 뽑기 처리

		int colledAll = checkCollection();

		if (colledAll == 1)
		{
			break;
		}
	}


	return 0;
}

void initCats()
{
	cats[0].name = "깜냥이";
	cats[0].age = 5;
	cats[0].character = "온순";
	cats[0].level = "1";

	cats[1].name = "귀요미";
	cats[1].age = 3;
	cats[1].character = "귀여움";
	cats[1].level = 2;

	cats[2].name = "까꿍이";
	cats[2].age = 2;
	cats[2].character = "시끄러움";
	cats[2].level = 3;

	cats[3].name = "치즈냥이";
	cats[3].age = 7;
	cats[3].character = "잠이많음";
	cats[3].level = 4;

	cats[4].name = "까칠이";
	cats[4].age = 4;
	cats[4].character = "까칠함";
	cats[4].level = 5;
}

void printCat(int selected)
{
	printf("\n\n === 당신은 이 고양이의 집사가 되었어요! === \n\n");
	printf("  이름      : %s\n", cats[selected].name);
	printf("  나이      : %d\n", cats[selected].age);
	printf("  성격      : %s\n", cats[selected].character);
	printf("  레벨      : ");

	for (int i = 0; i < cats[selected].level; i++)
	{
		printf("%s", "★");
	}
	printf("\n\n");
}

int checkCollection()
{
	// 보유한 고양이 목록 출력 + 다 모았는 지 여부 반환
	int collectAll = 1;
	
	printf("\n\n == 보유한 고양이 목록 ==\n\n");
	for (int i = 0; i < 5; i++)
	{
		if (collection[i] == 0)
		{
			printf("%10s", "(빈박스)");
			collectAll = 0; // 다 모으지 못한 상태
		}

		
		else
			printf("%10s", cats[i].name);
	}

	printf("\n ======================================= \n\n");

	if (collectAll == 1)
	{
		printf("축하합니다~ 모든 고양이를 다 모았어용!\n");
	}

	return collectAll;
}