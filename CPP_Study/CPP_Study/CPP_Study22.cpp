#include <iostream>
using namespace std;

// ������ ���� : ���� ������

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye";
}

void SetMessage(const char** a)
{
	*a = "Bye";
}

void SetMessage2(const char*& a)
{
	a = "Wow";
}

int main()
{
	int a = 0;
	SetNumber(&a);
	//cout << a << endl;

	// .rdata  Hello �ּ� [H][e][l][l][o][\0]
	// .rdata Bye �ּ� [B][y][e][\0]
	// msg[ Hello �ּ� ] << 8����Ʈ
	const char* msg = "Hello";

	// [�Ű�����][RET][��������(msg(Hello �ּ�))][�Ű�����(a(Hello �ּ�))][RET][��������]
	SetMessage(msg);
	//cout << msg << endl; // Hello? Bye?

	// .rdata  Hello �ּ� [H][e][l][l][o][\0]
	// msg[ Hello �ּ� ] << 8����Ʈ
	// pp[ &msg ] << 8����Ʈ
	const char** pp = &msg;

	// [�Ű�����][RET][��������(msg(Hello �ּ�))][�Ű�����(a(&msg msg�� �ּ�))][RET][��������]
	SetMessage(&msg);
	//cout << msg << endl;

	// ���� ������ : ȥ��������?
	// �׳� ���ı���� �����ϸ� 
	// *�� �ϳ��� ��鼭 Ÿ�� ���ٰ� �����ϸ� �ȴ�

	// [�Ű�����][RET][��������(msg(Hello �ּ�))][�Ű�����(a(&msg msg�� �ּ�))][RET][��������]
	SetMessage2(msg);
	cout << msg << endl;

	return 0;
}