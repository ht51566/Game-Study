#include <iostream>
using namespace std;

// ������ ���� : ����

struct StatInfo
{
	int hp; // +0
	int attack; // +4
	int defence; // +8
};

// [�Ű�����][RET][��������(info)][�Ű�����(&info)][RET][��������]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// [�Ű�����][RET][��������(info)][�Ű�����(info(100, 8, 5))][RET][��������]
//void CreateMonster(StatInfo info)
//{
//	info.hp = 100;
//	info.attack = 8;
//	info.defence = 5;
//}

// ���� �������� �ʴ´ٸ�, ���� �� �ϴ� ���� ����.

// 1) �� ���� ���
// [�Ű�����][RET][��������(info)][�Ű�����(info)][RET][��������]
//void PrintInfoByCopy(StatInfo info)
//{
//	cout << "------------------------" << endl;
//	cout << "HP: " << info.hp << endl;
//	cout << "ATT: " << info.attack << endl;
//	cout << "DEF: " << info.defence << endl;
//	cout << "------------------------" << endl;
//}

// Ư�� ������ �����ϴ� ���͸� ã�� �Լ�
StatInfo* FindMonster()
{
	// TODO : Heap �������� ������ ã�ƺ�
	// ã�Ҵ�!
	// return monster~;

	return nullptr;
}

StatInfo globalInfo;
// 2) �ּ� ���� ���
// [�Ű�����][RET][��������(info)][�Ű�����(&info)][RET][��������]
void PrintInfoByPtr(const StatInfo* const info)
{
	if (info == nullptr)
		return;

	cout << "------------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "------------------------" << endl;

	// �� �ڿ� ���δٸ�?
	// StatInfo* const info
	// info��� �ٱ��Ͽ� ���빰(�ּ�)�� �ٲ� �� ����
	// info�� �ּҰ��� ���� �ٱ��� -> �� �ּҰ��� �����̴�!

	// �� ������ ���δٸ�?
	// const StatInfo* info
	// info�� ����Ű�� �ִ� �ٱ��Ͽ� ���빰�� �ٲ� �� ����
	// '����' �ٱ����� ���빰�� �ٲ� �� ����

	// info[ �ּҰ� ]    �ּҰ�[ ������ ]
	//info = &globalInfo;
	//info->hp = 10000;
}

// StatInfo ����ü�� 100����Ʈ¥�� ���� ����ü���?
// - (�� ����) StatInfo�� �ѱ�� 1000����Ʈ�� ����Ǵ�
// - (�ּ� ����) StatInfo*�� 8����Ʈ
// - (���� ����) StatInfo&�� 8����Ʈ

// 3) ���� ���� ���
// �� ����ó�� ���ϰ� ����ϰ�!
// �ּ� ����ó�� �ּҰ��� �̿��� ������ �ǵ帮��!
// �ϼ������� ���!

void PrintInfoByRef(const StatInfo& info)
{
	cout << "------------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "------------------------" << endl;

	// ������ �Դ�
	//info.hp = 10000;
}

#define OUT

void ChangeInfo(OUT StatInfo& info)
{
	info.hp = 1000;
}

int main()
{
	// 4����Ʈ ������ �ٱ��ϸ� ����Ұž�.
	// ������ �� �ٱ��� �̸��� number��� �Ұ�.
	// �׷��ϱ� number���� �� �����ų�, number�� �� �ִ´ٰ� �ϸ�
	// �������� �˾Ƶ�� �ش� �ּҿ� 1�� �־��ָ� �ȴ�!
	//int number = 1;

	// * �ּҸ� ��� �ٱ���
	// int �� �ٱ��ϸ� ���󰡸� int ������(�ٱ���)�� ����
	//int* pointer = &number;
	// pointer �ٱ��Ͽ� �ִ� �ּҸ� Ÿ�� �̵��ؼ�, �� �ָ� �ִ� �ٱ��Ͽ� 2�� �ִ´�
	//*pointer = 2;

	// �ο췹��(�����) �������� ���� �۵� ����� int*�� �Ȱ���
	// ������ �����غ��� �����Ͷ� 100% �Ȱ���.
	//int& reference = number;

	// C++ ���������� number��� �ٱ��Ͽ� �� �ٸ� �̸��� �ο��� ��.
	// number��� �ٱ��Ͽ� reference��� �ٸ� �̸��� �����ٰ�~~
	// ������ reference �ٱ��Ͽ��ٰ� �� �����ų� ������,
	// ���� number �ٱ���(�������ٰ�) �� ���� �����ų� ������ ��!
	//reference = 3;

	// �׷��� ������ �� �ٸ� �̸��� ���� ������?
	// �׳� number = 3�̶�� �ص� �Ȱ�����...
	// ���� ���� ����!

	StatInfo info;

	CreateMonster(&info);
	// ������ vs ���� ������ ���
	// ���� : �Ȱ���!
	// ���Ǽ� : ���� ��!

	// 1) ���Ǽ� ����
	// ���Ǽ��� ���ٴ°� �� �������� �ƴϴ�.
	// �����ʹ� �ּҸ� �ѱ�� Ȯ���ϰ� ������ �ѱ�ٴ� ��Ʈ�� �� �� �ִµ�.
	// ������ �ڿ������� �𸣰� ����ĥ ���� ����!
	// ex) ������� ��ģ�ٸ�?
	// const�� ����ؼ� �̷� ������� ��ġ�� �κ� ���� ����

	// ����� �����͵� const�� ��� ����.
	// * �������� �տ� ���̴���, �ڿ� ���̴��Ŀ� ���� �ǹ̰� �޶�����

	// 2) �ʱ�ȭ ����
	// ���� Ÿ���� �ٱ��Ͽ� 2��° �̸� (��Ī?)
	// -> �����ϴ� ����� ������ �ȵ�
	// �ݸ� �����ʹ� �׳� �~ �ּҶ�� �ǹ�
	// -> ����� �������� ���� ���� ����
	// �����Ϳ��� '����'�� �ǹ̷� ?
	// ���� Ÿ���� �̷� nullptr�� ������ ����

	//PrintInfoByCopy(info);

	StatInfo* pointer = nullptr;
	//pointer = &info;
	PrintInfoByPtr(pointer);

	StatInfo& reference = info;
	PrintInfoByRef(info);

	// �׷��� �����?
	// ��� Team By Team... ������ ���� ����
	// ex) ���ۿ��� ���� ���¼ҽ��� ���� ���� ������ ������ ���
	// ex) �𸮾� �������� reference�� �ֿ�

	// Rookiss ��ȣ ��Ÿ��)
	// - ���� ��쵵 ����ؾ� �Ѵٸ� pointer (null üũ �ʼ�)
	// - �ٲ��� �ʰ� �д� �뵵(readonly)�� ����ϸ� const ret&
	// - �� �� �Ϲ������� ret (��������� ȣ���� �� OUT�� ���δ�)
	// -- ��, �ٸ� ����� pointer�� ���������� �̾ ����ٸ�, ��� pointer (���� ������� �ʴ´�)
	ChangeInfo(OUT info);

	// Bonus) �����ͷ� ����ϴ��� ������ �Ѱ��ַ���?
	// pointer[ �ּ�(&info) ]    ret, info[ ������ ]
	PrintInfoByRef(*pointer);
	
	// Bonus) ������ ����ϴ��� �����ͷ� �Ѱ��ַ���?
	// pointer[ �ּ� ]           reference, info[ ������ ]
	PrintInfoByPtr(&reference);

	return 0;
}