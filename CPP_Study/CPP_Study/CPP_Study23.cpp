#include <iostream>
using namespace std;

// 오늘의 주제 : 다차원 배열

int main()
{
	int a[10] = { 1, 2, 3 };

	// [1] [1] [5] [2] [2] << 1층
	// [4] [2] [3] [4] [1] << 0층

	int first[5] = { 4, 2, 3, 4, 1 };
	int second[5] = { 1, 1, 5, 2, 2 };

	int apartment2D[2][5] = { { 4, 2, 3, 4, 1 }, { 1, 1, 5, 2, 2 } };

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			// apartment1D[index] + (floor * 20) + 4 * room 을 한 주소
			int num = apartment2D[floor][room];
			cout << num << " ";
		}
		cout << endl;
	}

	int apartment1D[10] = { 4, 2, 3, 4, 1, 1, 1, 5, 2, 2 };

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			int index = (floor * 5) + room;
			// apartment1D[index] + (floor * 20) + 4 * room 을 한 주소
			int num = apartment1D[index];
			cout << num << " ";
		}
		cout << endl;
	}

	return 0;
}