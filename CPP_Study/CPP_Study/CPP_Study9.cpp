#include <iostream>

using namespace std;

// ����ΰ� �˰ڴµ� �ʹ� ���� ���� ��� ����
// �ϳ��� ��Ʈ�ε�?
const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

// ���ڸ� ���� ���ϸ� ù ���� 0���� ����
// �� ���� ������ ���� �� + 1
enum ENUM_SRP
{
	ENUM_SCISSORS = 1,
	ENUM_ROCK,
	ENUM_PAPER
};

// #�� ������ -> ��ó�� ���ù�
// #include <iostream>�̶�� ������ ã�Ƽ� �ش� ������ �׳� ����!
// 1) ��ó�� 2) ������ 3) ��ũ
#define DEFINE_SCISSORS (1+2)
#define DEFINE_TEST cout << "Hello World" << endl;

int main()
{
	int value = ENUM_ROCK;

	srand(time(0)); // �õ� ����

	int wins = 0;
	int total = 0;

	while (true)
	{
		cout << "����(1) ����(2) ��(3) ����ּ���!" << endl << "> ";

		if (total == 0)
		{
			cout << "���� �·� : ����" << endl;
		}
		else
		{
			// TODO : Ȯ���� �����ش�
			// (1 * 100) / 4 = 25
			int winPercentage = (wins * 100) / total; // �·�?
			cout << "���� �·� : " << winPercentage << endl;
		}

		// 1 2 3
		// ��ǻ��
		int computerValue = 1 + (rand() % 3); // 0~32767

		// �����
		int input;
		cin >> input;

		if (input == ENUM_SCISSORS)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				break;
			case ROCK:
				cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				total++;
				break;
			case PAPER:
				cout << "����(��) vs ��(��ǻ��) �̰���ϴ�!" << endl;
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
				cout << "����(��) vs ����(��ǻ��) �̰���ϴ�!" << endl;
				wins++;
				total++;
				break;
			case ROCK:
				cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				break;
			case PAPER:
				cout << "����(��) vs ��(��ǻ��) �����ϴ�!" << endl;
				total++;
				break;
			}
		}
		else if (input == PAPER)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "��(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				total++;
				break;
			case ROCK:
				cout << "��(��) vs ����(��ǻ��) �̰���ϴ�!" << endl;
				wins++;
				total++;
				break;
			case PAPER:
				cout << "��(��) vs ��(��ǻ��) �����ϴ�!" << endl;
				break;
			}
		}
		else
			break;
	}
}