#include <iostream>
#include <time.h>


/*
			쉬프트 알트 신세계
*/
using namespace std;

int main()
{
	srand(time(NULL));
	int com1 = 0;
	int com2 = 0;
	int com3 = 0;
	int player;
	int HP = 10;
	int st = 0;
	int ba = 0;

	while (1)
	{
		com1 = rand() % 10;
		com2 = rand() % 10;
		com3 = rand() % 10;
		if (com1 == 0)
		{
			continue;
		}
		if (com1 != com2 && com1 != com3 && com2 != com3)
		{
			break;
		}
	}
	//  cout << com1 << com2 << com3; //테스트용

	cout << " 고전 야구 게임 시작" << endl;
	cout << " 컴퓨터가 임의의 숫자 3가지를 고르고 플레이어는 숫자 3자리를 맞추면 됩니다." << endl;
	cout << " 같은 자리일 경우 st , 같진 않지만 정해진 숫자가 있으면 ba,  없으면 out, 기회는 10번 맨 앞자리는 0이 들어올 수 없다." << endl;

	while (1)
	{
		cout << " 입력  :  ";
		
		cin >> player;
		
		if (player / 100 == (player - (player / 100 * 100)) / 10 || player / 100 == player % 10 || (player - (player / 100 * 100)) / 10 == player % 10)
		{
			cout << " 게임도 못해 룰도 이해 못해 머리도 멍청해 잘하는게 뭐야?" << endl;
			continue;
		}
		if (player > 999)
		{
			cout << " 게임도 못해 룰도 이해 못해 머리도 멍청해 잘하는게 뭐야?" << endl;
			continue;
		}
		for (int i = 0; i < 1; i++)
		{
			if (player / 100 == com1)
			{
				st++;
				break;
			}
			if (com2 == (player / 100))
			{
				ba++;
			}
			if (com3 == (player / 100))
			{
				ba++;
			}
		}
		for (int i = 0; i < 1; i++)
		{
			if ((player - (player / 100 * 100)) / 10 == com2)
			{
				st++;
				break;
			}
			if ((player - (player / 100 * 100)) / 10 == com1)
			{
				ba++;
			}

			if ((player - (player / 100 * 100)) / 10 == com3)
			{
				ba++;
			}
		}
		for (int i = 0; i < 1; i++)
		{
			if (player % 10 == com3)
			{
				st++;
				break;
			}
			if (player % 10 == com1)
			{
				ba++;
			}
			if (player % 10 == com2)
			{
				ba++;
			}

		}
		--HP;
		cout << st << "   st   " << ba << "    ba   " << endl;
		cout << HP << "남았다." << endl;

		if (st == 3)
		{
			cout << "너 어디서 좀 놀았니? 정답이다." << endl;
			break;
		}
		if (HP == 0)
		{
			cout << "이걸??.... 게임 out 너는 이런거 하지마라.." << endl;
			break;
		}

		st = ba = 0;


	}
	return 0;
}