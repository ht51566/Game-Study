#include <iostream>

using namespace std;

// ������ ���� : �Լ� ������

// �����ε� (�ߺ� ���� : �Լ� �̸��� ����)
// - �Ű����� ������ �ٸ��ų�
// - �Ű����� Ÿ���� �ٸ��ų� (������ �ٸ��� ����)
int Add(int a, int b)
{
	int result = a + b;
	return result;
}

int Add(int a)
{
	float result = a + 1;
	return result;
}

// �⺻ ���ڰ�
void SetPlayerInfo(int hp, int mp, int attack, int guidId = 0, int castleId = 0)
{

}

// ���� �����÷ο�
int Factorial(int n)
{
	if (n <= 1)
		return 1;

	return n * Factorial(n - 1);
}

int main()
{
	/*
	int result = Add(1, 2);
	cout << result << endl;
	
	SetPlayerInfo(100, 40, 10);
	*/

	int result = Factorial(100000000);
	cout << result << endl;

	// 5! = 5 * 4!
	// 4! = 4*3*2*1
	// n! = n * (n-1)!

	// 1! = 1

	return 0;
}