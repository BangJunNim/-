#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	//변수 선언
	int Bingo[25];  // < 베이스
	int A, B, C;  // 셔플
	int Inputnumber; // 이동
	int Player = 24; // 플레이어 방 위치를 24 라고 설정


	srand(time(NULL));

	for (int i = 0; i < 24; i++)   // 방 25개 팠음.
	{
		Bingo[i] = i+1;
	}

	for (int i = 0; i < 100; i++) // 그중 23번 까지 방 섞음
	{
		A = rand() % 24;
		B = rand() % 24;
		C = Bingo[A];
		Bingo[A] = Bingo[B];
		Bingo[B] = C;
	}

	Bingo[24] = 0; // 방 24번은 0으로 고정으로 시작.  플레이어 는 24번 방에서 시작을 하고 숫자는 0 임.

	while (1)
	{
		system("cls");
		cout << "숫자 0이 움직여;;;" << endl;

		cout << endl;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << Bingo[i * 5 + j] << "\t";    // 빙고 숫자 입력  근데 위에 24번 마지막 방은 0으로 설정해서 우측 하단은  0으로 나옴.

			}
			cout << endl;
		}

		cout << endl;
		cout << " 위 : 8  | , 왼쪽 : 4  |, 아래 :5  | , 오른쪽 : 6  |" << endl;
		cout << "입력 후 엔터";


		cin >> Inputnumber;
	
		switch (Inputnumber)
		{
		case 8:
			if (Player >= 5)
			{
				C = Bingo[Player];
				Bingo[Player] = Bingo[Player - 5];
				Bingo[Player - 5] = C;
				Player -= 5;
			}
			break;
		case 4:
			if (Player % 5 != 0)
			{
				C = Bingo[Player];
				Bingo[Player] = Bingo[Player - 1];
				Bingo[Player - 1] = C;
				Player -= 1;
			}
			break;
		case 5:
			if (Player < 20)
			{
				C = Bingo[Player];
				Bingo[Player] = Bingo[Player + 5];
				Bingo[Player + 5] = C;
				Player += 5;
			}
			break;
		case 6:
			if ((Player + 1) % 5 != 0)
			{
				C = Bingo[Player];
				Bingo[Player] = Bingo[Player + 1];
				Bingo[Player + 1] = C;
				Player += 1;
			}
			break;
		}

	}


	return 0;
}