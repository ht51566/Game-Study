#include <iostream>

using namespace std;

int main()
{
	// �����)
	// �������� � ������ �Է��ϸ�
	// N*N���� ���� ������� ���ھ��!

	/*
	int input;

	cout << "���� �� ���� �Է����ּ���! >> ";
	cin >> input;

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			cout << "*";
		}

		cout << endl;
	}
	*/

	// �����2)
	// ��.. �׳� N*N���� ���� �����ϱ� �ʹ� �ɽ��ϴ�.
	// 1������ �����ؼ� ���������� �ٸ��� �����ϰ� �������ּ���!

	/*
	int input;

	cout << "���� �� ���� �Է����ּ���! >> ";
	cin >> input;

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}

		cout << endl;
	}
	*/

	// �����3)
	// ����� ���� �����Ǳ� �ߴµ�.
	// N������ �����ؼ� �ٸ��� 1���� �پ��� ���·�!

	/*
	int input;

	cout << "���� �� ���� �Է����ּ���! >> ";
	cin >> input;

	for (int i = 0; i < input; i++)
	{
		for (int j = input; j > i; j--)
		{
			cout << "*";
		}

		if (i != (input - 1))
			cout << endl;
	}
	*/

	// ������)
	// 2*1=2
	// 2�ܺ���~9�ܱ��� �������� ������ּ���!

	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << " * " << j << " = " << (i * j) << endl;
		}
	}
}