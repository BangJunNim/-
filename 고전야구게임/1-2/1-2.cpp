#include <iostream>
#include <time.h>


/*
			����Ʈ ��Ʈ �ż���
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
	//  cout << com1 << com2 << com3; //�׽�Ʈ��

	cout << " ���� �߱� ���� ����" << endl;
	cout << " ��ǻ�Ͱ� ������ ���� 3������ ���� �÷��̾�� ���� 3�ڸ��� ���߸� �˴ϴ�." << endl;
	cout << " ���� �ڸ��� ��� st , ���� ������ ������ ���ڰ� ������ ba,  ������ out, ��ȸ�� 10�� �� ���ڸ��� 0�� ���� �� ����." << endl;

	while (1)
	{
		cout << " �Է�  :  ";
		
		cin >> player;
		
		if (player / 100 == (player - (player / 100 * 100)) / 10 || player / 100 == player % 10 || (player - (player / 100 * 100)) / 10 == player % 10)
		{
			cout << " ���ӵ� ���� �굵 ���� ���� �Ӹ��� ��û�� ���ϴ°� ����?" << endl;
			continue;
		}
		if (player > 999)
		{
			cout << " ���ӵ� ���� �굵 ���� ���� �Ӹ��� ��û�� ���ϴ°� ����?" << endl;
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
		cout << HP << "���Ҵ�." << endl;

		if (st == 3)
		{
			cout << "�� ��� �� ��Ҵ�? �����̴�." << endl;
			break;
		}
		if (HP == 0)
		{
			cout << "�̰�??.... ���� out �ʴ� �̷��� ��������.." << endl;
			break;
		}

		st = ba = 0;


	}
	return 0;
}