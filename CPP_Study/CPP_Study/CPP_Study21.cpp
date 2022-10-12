#include <iostream>
using namespace std;

// ������ ���� : �ζ� ��ȣ ������

// 1) Swap �Լ� �����
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 2) ���� �Լ� ����� (���� ���ڰ� ���� ������ ����)
// { 1, 42, 3, 15, 5, 6 } => { 1, 3, 5, 6, 15, 42 }
void Sort(int numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		// i��° ���� ���� ���� �ĺ���� ����
		int best = i;

		// �ٸ� �ĺ��� �񱳸� ���� ���� ���� �ĺ��� ã�Ƴ�����
		for (int j = i + 1; j < count; j++)
		{
			if (numbers[j] < numbers[best])
				best = j;
		}

		// ���� ���� �ĺ��� ��ü�ϴ� ����
		if (i != best)
			Swap(numbers[i], numbers[best]);
	}
}

// 3) �ζ� ��ȣ ����
void ChooseLotto(int numbers[])
{
	srand(time(0));

	int count = 0;
	while (count != 6)
	{
		int randValue = 1 + (rand() % 45); // 0~44

		// �̹� ã�� ������?
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				// �̹� ã�� ��
				found = true;
				break;
			}
		}

		// �� ã������ �߰�!
		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}
	}

	Sort(numbers, 6);
	// TODO : �������� 1~45 ������ ���� 6���� ����ּ���! (��, �ߺ��� ����� ��)
}

int main()
{
	// 1) Swap �Լ� �����
	int a = 1;
	int b = 2;
	Swap(a, b);
	// a = 2, b = 1

	//cout << a << " " << b << endl;

	// 2) ���� �Լ� ����� (���� ���ڰ� ���� ������ ����)
	int numbers[6] = { 1, 42, 3, 15, 5, 6 };
	Sort(numbers, sizeof(numbers) / sizeof(int));
	// { 1, 3, 5, 6 ,15, 42 }
	
	// 3) �ζ� ��ȣ ������
	ChooseLotto(numbers);

	// ����� �ζ� �� �ϼ�!
	for (int i = 0; i < 6; i++)
		cout << numbers[i] << endl;

	return 0;
}