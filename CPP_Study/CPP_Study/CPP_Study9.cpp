#include <iostream>

using namespace std;

// 상수인건 알겠는데 너무 따로 따로 노는 느낌
// 하나의 셋트인데?
const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

// 숫자를 지정 안하면 첫 값은 0부터 시작
// 그 다음 값들은 이전 값 + 1
enum ENUM_SRP
{
	ENUM_SCISSORS = 1,
	ENUM_ROCK,
	ENUM_PAPER
};

// #이 붙은거 -> 전처리 지시문
// #include <iostream>이라는 파일을 찾아서 해당 내용을 그냥 복붙!
// 1) 전처리 2) 컴파일 3) 링크
#define DEFINE_SCISSORS (1+2)
#define DEFINE_TEST cout << "Hello World" << endl;

int main()
{
	int value = ENUM_ROCK;

	srand(time(0)); // 시드 설정

	int wins = 0;
	int total = 0;

	while (true)
	{
		cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl << "> ";

		if (total == 0)
		{
			cout << "현재 승률 : 없음" << endl;
		}
		else
		{
			// TODO : 확률을 구해준다
			// (1 * 100) / 4 = 25
			int winPercentage = (wins * 100) / total; // 승률?
			cout << "현재 승률 : " << winPercentage << endl;
		}

		// 1 2 3
		// 컴퓨터
		int computerValue = 1 + (rand() % 3); // 0~32767

		// 사용자
		int input;
		cin >> input;

		if (input == ENUM_SCISSORS)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "가위(님) vs 가위(컴퓨터) 비겼습니다!" << endl;
				break;
			case ROCK:
				cout << "가위(님) vs 바위(컴퓨터) 졌습니다!" << endl;
				total++;
				break;
			case PAPER:
				cout << "가위(님) vs 보(컴퓨터) 이겼습니다!" << endl;
				wins++;
				total++;
				break;
			}
		}
		else if (input == ROCK)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "바위(님) vs 가위(컴퓨터) 이겼습니다!" << endl;
				wins++;
				total++;
				break;
			case ROCK:
				cout << "바위(님) vs 바위(컴퓨터) 비겼습니다!" << endl;
				break;
			case PAPER:
				cout << "바위(님) vs 보(컴퓨터) 졌습니다!" << endl;
				total++;
				break;
			}
		}
		else if (input == PAPER)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "보(님) vs 가위(컴퓨터) 졌습니다!" << endl;
				total++;
				break;
			case ROCK:
				cout << "보(님) vs 바위(컴퓨터) 이겼습니다!" << endl;
				wins++;
				total++;
				break;
			case PAPER:
				cout << "보(님) vs 보(컴퓨터) 비겼습니다!" << endl;
				break;
			}
		}
		else
			break;
	}
}