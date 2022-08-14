#include <stdio.h>
#include <time.h>

// 10마리의 다른 동물 ( 각 카드는 2장씩)
// 사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
// 모든 동물 쌍을 찾으면 게임 종류
// 총 실패 횟수 알려주기


int arrayAnimal[4][5];  // 카드 지도
int checkAnimal[4][5];  // seq 표시 -> 뒤집혔는지 여부 확인
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
		int selecte1 = 0; // 사용자가 선택한 처음 수
		int selecte2 = 0; // 사용자가 선택한 두번째 수

		printAnimals(); // 동물 위치 출력
		printQuestion(); // 문제 출력(카드 지도)
		printf("뒤집을 카드를 두개 고르세요!: ");
		scanf_s("%d %d", &selecte1, &selecte2);

		if (selecte1 == selecte2) // 같은 카드 선택 시
		{
			continue;
		}

		// 좌표에 해당하는 카드를 뒤집어보고 같은 지 안같은 지 확인
		int firstSelcet_x = conv_pos_x(selecte1);
		int firstSelcet_y = conv_pos_y(selecte1);

		int secondSelcet_x = conv_pos_x(selecte2);
		int secondSelcet_y = conv_pos_y(selecte2);

		if ((checkAnimal[firstSelcet_x][firstSelcet_y]==0)
			&& (checkAnimal[secondSelcet_x][secondSelcet_y]==0)
			&&
			(arrayAnimal[firstSelcet_x][firstSelcet_y] == arrayAnimal[secondSelcet_x][secondSelcet_y]))
		{
			printf("\n\n빙고! %s 발견 \n\n", strAnimal[arrayAnimal[firstSelcet_x][firstSelcet_y]]);
			checkAnimal[firstSelcet_x][firstSelcet_y] = 1;
			checkAnimal[secondSelcet_x][secondSelcet_y] = 1;
		}
		else
		{
			printf("땡! 틀렸거나, 이미 뒤집힌 카드입니다~ \n");
			printf("%d: %s\n", selecte1, strAnimal[arrayAnimal[firstSelcet_x][firstSelcet_y]]);
			printf("%d: %s\n", selecte2, strAnimal[arrayAnimal[secondSelcet_x][secondSelcet_y]]);
			printf("\n\n");

			failCount++;

		}
		// 모든 동물을 찾았는 지 여부
		if (foundAllAnimals() == 1)
		{
			printf("축하합니다! 모든 동물을 다 찾았네요~ \n");
			printf("지금까지 총 %d번 실패하셨습니다. \n", failCount);
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
	strAnimal[0] = "원숭이";
	strAnimal[1] = "하마";
	strAnimal[2] = "강아지";
	strAnimal[3] = "고양이";
	strAnimal[4] = "돼지";

	strAnimal[5] = "코끼리";
	strAnimal[6] = "기린";
	strAnimal[7] = "낙타";
	strAnimal[8] = "타조";
	strAnimal[9] = "호랑이";
}

void shuffleAnimal() // map에 동물 랜덤배치
{
	for (int i = 0; i < 10; i++)  // 동물 10마리만큼 pos 배정
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

int getEmptyPosition()  // 비어있는 randPos를 반환
{
	while (1)
	{
		int randPos = rand() % 20; // 0~19사이 숫자 반환
		// 만약 19 -> (3,4)로 변환해야 함

		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1)
		{
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x)  // 몫을 사용
{
	// 19 -> (3, 4)
	return x / 5;
}

int conv_pos_y(int y) // 나머지를 사용
{
	return y % 5; // y를 5로 나눈 나머지 값
}

void printAnimals() // 동물 위치 출력
{

	printf("\n...비밀인데 몰래 보여줍니다 ㅎㅎ ... \n\n");
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
	printf("문제: \n");
	int seq = 0;  // 0이라고 한건 못찾은거, 1이라고 한건 찾은거

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// 카드를 뒤집어서 정답을 맞췄으면 동물 이름 보여주기
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			// 아직 뒤집지 못했으면 뒷면 -> 임시로 위치를 나타내는 숫자로 보여줌
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