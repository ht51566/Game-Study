#include <iostream>

using namespace std;

// ������ ���� : ���� ������ �� ����

// ���� ����
// ����) �ʱ�ȭ ����, const �� .rodata .data .bss
int globalValue = 0;

void Test()
{
	cout << "���� ������ ���� : " << endl;
	globalValue++;
}

void IncreaseHp(int hp)
{
	int finalHp = hp + 1;
}

// [[�Ű�����][RET][��������(hp=1)] [�Ű�����(hp=1)][RET][��������(finalHp=2)] [�Ű�����][RET][��������]										]
int main()
{
	int hp = 1;

	cout << "Increase ȣ�� �� : " << hp << endl;
	IncreaseHp(hp);
	cout << "Increase ȣ�� �� : " << hp << endl;

	return 0;
}