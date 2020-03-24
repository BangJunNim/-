#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	//변수 선언

	int Card[52]; // < 카드 숫자. 
	int money = 1000000; // < - 기본 배팅 
	int turn = 2;  //  카드 두 장 뽑혀서 시작
	int shape[3], number[3]; // < 모양 및 숫자 입력
	int A, B, C; // < 셔플 
	int betting; // <배팅. 


	//배열 1차원 // 카드 52장 초기화. 
	for (int i = 0; i < 52; i++)
	{
		Card[i] = i;
	}

	//셔플
	for (int i = 0; i < 777; i++) // < 맞춰질 때까지 777번 반복
	{
		A = rand() % 52;
		B = rand() % 52;
		C = Card[A];
		Card[A] = Card[B];
		Card[B] = C;
	}

	while (1)  // < 반복시작. 
	{
		system("cls");
		cout << endl;
		cout << "=======================================================================================================" << endl;
		cout << "트		럼		프		카		드		게		임" << endl;
		cout << "=======================================================================================================" << endl;
		cout << endl;
		cout << " 다음 나온 카드 중 새로 뽑는 카드가 포함 되면 이기고 안되면 패배." << endl;
		cout << " 같은 숫자가 나와 있다면  그것 또한 운명." << endl;
		cout << " 이겼을 시 배팅금 * 2 배 / 최소 배팅금 10,000원 ↑ / 소지금 10,000 ↓ Game over  " << endl;
		cout << endl;

		for (int i = 0; i < 3; i++) // <- 카드를  모양과 같이 3번 뽑음. 
		{
			//
			shape[i] = Card[i + turn - 2] / 13;
			number[i] = Card[i + turn - 2] % 13;
			// <ㅡ 위 3번 뽑는거에서 게임은 2장으로 시작해 다음 나올 숫자를 맞춰야하니  하나는 뺌. 0, 1, 2, 에서 마지막 꺼. 
			if (i == 2)  break;

			// 스위치문
			switch (shape[i]) // < 카드 모양!
			{
			case 0:
				cout << "♣";
				break;  // break 입력을 안하면 밑에 까지 같이 출력
			case 1:
				cout << "◆";
				break;
			case 2:
				cout << "♥";
				break;
			case 3:
				cout << "♠";
				break;
			}

			switch (number[i]) // < 카드 다음 1, 11,12,13 문자 표현
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
			default:  //< 나머지
				cout << number[i] + 1 << "\t";
				break;
			}
		}
		cout << endl;
		cout << endl;
		// 겜 안내
		cout << "총 소지금 : " << money << endl;
		cout << endl;
		cout << "돈 태우기 :";
		cin >> betting; //cin <- 입력  

		if (betting < 1 || betting > money) // 배팅을 할 때 소지금 보다 없을 경우
		{
			cout << " 최소 1만원 걸거나, 소지금 보다 많이 걸었거나 뜨는 오류" << endl;
			cout << " 정신 차려" << endl;
			continue;
		}
		// number 0 ~ 1 은 게임 시작 시 나오는 수,  number 2는 사용자가 배팅 할지 말지 고민하는 카드 . 
		// 첫번 째 카드 가 다음 나올 카드 보다 높거나 두번 째 카드 보다 낮을 경우  3번째에 입력 되는 카드가 승.
		if ((number[0] < number[2] && number[2] < number[1]) || (number[1] < number[2] && number[2] < number[0]))
		{
			cout << " 잘 태웠고~ " << endl;
			money += betting * 2;  // money = money + betting*2
		}
		else // 위 if가 아닐 경우 
		{
			cout << " 응 아니야 ~ " << endl;
			money -= betting;
		}

		if (money < 9999) //
		{
			cout << " 흑우왔는가" << endl;
			break;  // < 여기서 스탑. 
		}
		if (money > 5000000)
		{
			cout << "가족끼리 회식하러가쇼~" << endl;
			break;
		}
		system("pause"); //<<  일시정ㅈㅣ !
		turn += 3;

	}


	return 0;

}

