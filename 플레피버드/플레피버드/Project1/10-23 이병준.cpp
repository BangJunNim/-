#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	//���� ����
	int Bingo[25];  // < ���̽�
	int A, B, C;  // ����
	int Inputnumber; // �̵�
	int Player = 24; // �÷��̾� �� ��ġ�� 24 ��� ����


	srand(time(NULL));

	for (int i = 0; i < 24; i++)   // �� 25�� ����.
	{
		Bingo[i] = i+1;
	}

	for (int i = 0; i < 100; i++) // ���� 23�� ���� �� ����
	{
		A = rand() % 24;
		B = rand() % 24;
		C = Bingo[A];
		Bingo[A] = Bingo[B];
		Bingo[B] = C;
	}

	Bingo[24] = 0; // �� 24���� 0���� �������� ����.  �÷��̾� �� 24�� �濡�� ������ �ϰ� ���ڴ� 0 ��.

	while (1)
	{
		system("cls");
		cout << "���� 0�� ������;;;" << endl;

		cout << endl;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << Bingo[i * 5 + j] << "\t";    // ���� ���� �Է�  �ٵ� ���� 24�� ������ ���� 0���� �����ؼ� ���� �ϴ���  0���� ����.

			}
			cout << endl;
		}

		cout << endl;
		cout << " �� : 8  | , ���� : 4  |, �Ʒ� :5  | , ������ : 6  |" << endl;
		cout << "�Է� �� ����";


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