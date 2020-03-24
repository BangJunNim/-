#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	//���� ����

	int Card[52]; // < ī�� ����. 
	int money = 1000000; // < - �⺻ ���� 
	int turn = 2;  //  ī�� �� �� ������ ����
	int shape[3], number[3]; // < ��� �� ���� �Է�
	int A, B, C; // < ���� 
	int betting; // <����. 


	//�迭 1���� // ī�� 52�� �ʱ�ȭ. 
	for (int i = 0; i < 52; i++)
	{
		Card[i] = i;
	}

	//����
	for (int i = 0; i < 777; i++) // < ������ ������ 777�� �ݺ�
	{
		A = rand() % 52;
		B = rand() % 52;
		C = Card[A];
		Card[A] = Card[B];
		Card[B] = C;
	}

	while (1)  // < �ݺ�����. 
	{
		system("cls");
		cout << endl;
		cout << "=======================================================================================================" << endl;
		cout << "Ʈ		��		��		ī		��		��		��" << endl;
		cout << "=======================================================================================================" << endl;
		cout << endl;
		cout << " ���� ���� ī�� �� ���� �̴� ī�尡 ���� �Ǹ� �̱�� �ȵǸ� �й�." << endl;
		cout << " ���� ���ڰ� ���� �ִٸ�  �װ� ���� ���." << endl;
		cout << " �̰��� �� ���ñ� * 2 �� / �ּ� ���ñ� 10,000�� �� / ������ 10,000 �� Game over  " << endl;
		cout << endl;

		for (int i = 0; i < 3; i++) // <- ī�带  ���� ���� 3�� ����. 
		{
			//
			shape[i] = Card[i + turn - 2] / 13;
			number[i] = Card[i + turn - 2] % 13;
			// <�� �� 3�� �̴°ſ��� ������ 2������ ������ ���� ���� ���ڸ� ������ϴ�  �ϳ��� ��. 0, 1, 2, ���� ������ ��. 
			if (i == 2)  break;

			// ����ġ��
			switch (shape[i]) // < ī�� ���!
			{
			case 0:
				cout << "��";
				break;  // break �Է��� ���ϸ� �ؿ� ���� ���� ���
			case 1:
				cout << "��";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			}

			switch (number[i]) // < ī�� ���� 1, 11,12,13 ���� ǥ��
			{
			case 0:
				cout << "A\t";
				break;

			case 10:
				cout << "J\t";
				break;
			case 11:
				cout << "Q\t";
				break;
			case 12:
				cout << "K\t";
				break;
			default:  //< ������
				cout << number[i] + 1 << "\t";
				break;
			}
		}
		cout << endl;
		cout << endl;
		// �� �ȳ�
		cout << "�� ������ : " << money << endl;
		cout << endl;
		cout << "�� �¿�� :";
		cin >> betting; //cin <- �Է�  

		if (betting < 1 || betting > money) // ������ �� �� ������ ���� ���� ���
		{
			cout << " �ּ� 1���� �ɰų�, ������ ���� ���� �ɾ��ų� �ߴ� ����" << endl;
			cout << " ���� ����" << endl;
			continue;
		}
		// number 0 ~ 1 �� ���� ���� �� ������ ��,  number 2�� ����ڰ� ���� ���� ���� ����ϴ� ī�� . 
		// ù�� ° ī�� �� ���� ���� ī�� ���� ���ų� �ι� ° ī�� ���� ���� ���  3��°�� �Է� �Ǵ� ī�尡 ��.
		if ((number[0] < number[2] && number[2] < number[1]) || (number[1] < number[2] && number[2] < number[0]))
		{
			cout << " �� �¿���~ " << endl;
			money += betting * 2;  // money = money + betting*2
		}
		else // �� if�� �ƴ� ��� 
		{
			cout << " �� �ƴϾ� ~ " << endl;
			money -= betting;
		}

		if (money < 9999) //
		{
			cout << " ���Դ°�" << endl;
			break;  // < ���⼭ ��ž. 
		}
		if (money > 5000000)
		{
			cout << "�������� ȸ���Ϸ�����~" << endl;
			break;
		}
		system("pause"); //<<  �Ͻ������� !
		turn += 3;

	}


	return 0;

}

