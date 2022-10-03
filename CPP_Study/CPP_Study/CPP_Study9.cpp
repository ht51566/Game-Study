#include <iostream>

using namespace std;

int main()
{
	srand(time(0)); // �õ� ����

	const int SCISSORS = 1;
	const int ROCK = 2;
	const int PAPER = 3;

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

		if (input == SCISSORS)
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