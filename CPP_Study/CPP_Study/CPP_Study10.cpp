#include <iostream>

using namespace std;

// ������ ���� : �Լ�(���ν���, �޼ҵ�, ��ƾ)

/*
input���� ������ �ް�, output���� ������ ������ �����ش�

��ȯŸ�� �Լ��̸�(����Ÿ�� �Ű�����)
{
	�Լ� ����

	return ~~~;
}
*/

// Hello World�� �ֿܼ� ����ϴ� �Լ��� ������!
// input : ���� / output : ����
// Ÿ�� : int float double char~~ void

void PrintHelloWorld()
{
	cout << "Hello World" << endl;
}

// ������ �Է�(�Լ�) �޾Ƽ�, �ֿܼ� ����ϴ� �Լ��� ������
// input : int / output : ����
void PrintNumber(int number)
{
	cout << "�Ѱ��ֽ� ���ڴ� " << number << " �Դϴ�" << endl;
}

// 2�� ���ϰ� ������� ��� �Լ��� ������
// input : int / output : int

int MultiplyBy2(int a)
{
	int b = a * 2;
	return b;
}

// �� ���ڸ� ���ؼ� ������� ��� �Լ��� ������
// input : int / output : int

int MultiplyBy(int a, int b)
{
	int c = a * b;
	return c;
}

// F5
// F10
// F11
int main()
{
	int a = 3;
	int b = 5;
	int result = MultiplyBy(b, a);

	PrintNumber(result);
	//PrintHelloWorld();

	return 0;
}