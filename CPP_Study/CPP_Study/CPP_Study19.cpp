#include <iostream>
using namespace std;

// ������ ���� : �迭

struct StatInfo
{
	int hp = 0xAAAAAAAA;
	int attack = 0xBBBBBBBB;
	int defence = 0xDDDDDDDD;
};

int main()
{
	// TYPE �̸�[����];

	// �迭�� ũ��� ������� �� (VC �����Ϸ� ����)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	// ���²� �������� [�̸�]�� �ٱ����� �̸��̾���
	int a = 10;
	int b = a;

	// �׷��� �迭�� [�̸�] ���� �ٸ��� �����Ѵ�
	//StatInfo players[10];
	//players = monsters;

	// �׷� �迭�� �̸��� ����?
	// �迭�� �̸��� �� �迭�� ���� �ּ�
	// ��Ȯ���� ���� ��ġ�� ����Ű�� TYPE* ������
	auto WhoAmI = monsters;

	// �ּ�[ (100,10,1) ] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] ...
	// monster_0[ �ּ� ]
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// �������� ����! ��¥ 1�� ���϶�°� �ƴ϶�, StatInfo Ÿ�� �ٱ��� �Ѱ��� �̵��϶�� �ǹ�
	// StatInfo[ ] �ּ�[ (200,20,2) ] StatInfo[ ] StatInfo[ ] StatInfo[ ] ...
	// monster_1[ �ּ� ]
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// �����Ϳ� ������ ��������� ��ȯ �����ϴ�
	// StatInfo[ ] StatInfo[ ] monster_2,�ּ�[ ] StatInfo[ ] StatInfo[ ] ...
	// monster_2[ �ּ� ]
	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// [����] �̰Ŵ� ���� �ٸ� �ǹ̴�
	// StatInfo[ ] StatInfo[ ] �ּ�[ ���빰 ] StatInfo[ ] StatInfo[ ] ...
	// temp[ ���빰 ]
	StatInfo temp;
	temp = *(monsters + 2);
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4;

	// �̸� ���� �� �ڵ�ȭ�Ѵ�!
	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = (i + 1);
	}

	// �ٵ� *(monsters + i) �ʹ� �����ϰ� �������� ��������... �� ���� ���?
	// �ε���!
	// �迭�� 0������ ����. N��° �ε����� �ش��ϴ� �����Ϳ� �����Ϸ��� �迭�̸�[N]
	// *(monsters + i) = monsters[i]

	monsters[0].hp = 100;
	monsters[0].attack = 10;
	monsters[0].defence = 1;

	int hp = monsters[0].hp;

	for (int i = 0; i < 10; i++)
	{
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 10 * (i + 1);
		monsters[i].defence = (i + 1);
	}

	// �迭 �ʱ�ȭ ���� ���
	int numbers[5] = {}; // �� 0���� �о������
	int numbers1[10] = { 1,2,3,4,5 }; // ������ �ֵ��� ������ �����, ������ ������ 0���� �ʱ�ȭ
	int numbers2[] = { 1,2,3,4,11,24,124,14,1 }; // ������ ������ŭ�� ũ�⿡ �ش��ϴ� �迭�� ������ش�
	char helloStr[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	cout << helloStr << endl;

	// �迭 ���?:
	// 1) �����Ѵ�
	int arr[10] = { };

	// 2) �ε����� �����ؼ� ���
	arr[1] = 1;
	cout << arr[1] << endl;

	return 0;
}