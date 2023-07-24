#include <iostream>
#include <time.h>
/*

*  1  2  3  4
5  6  7  8  9
10 11 12 13 14
15 16 17 18 19
20 21 22 23 24

0���� ǥ�õ� �κп� 1 ~ 24 ������ ���ڸ� ��� ����Ѵ�.
�÷��̾�� * ǥ�ø� �������� �� �ִ�.
w: ���� �̵� s: �Ʒ��� �̵� a: ���� �̵� d: ������ �̵� q: ����

�̵� Ű�� ������ �ش� ���⿡ �ִ� ���� *�� ��ġ�� �������ְ� ���ڰ� ���� ������ ���ʴ�� 1 ~ 24���� ������ ������ ����

*/

int main() {
	
	srand((unsigned int)time(0));
	rand();

	int gameStage[25] = {};
	int location = 0;

	// game stage �����
	for (int i = 0; i < 25; i++) {
		

		gameStage[i] = i;
	}

	// swap ����
	for (int i = 0; i < 50; i++) {
		int index1 = rand() % 25;
		int index2 = rand() % 25;

		int temp = gameStage[index1];

		gameStage[index1] = gameStage[index2];
		gameStage[index2] = temp;
	}


	// ���
	for (int i = 0; i < 5; i++) {
		for (int j = i * 5; j < i * 5 + 5; j++) {
			if (gameStage[j] == 0) {
				std::cout << "*" << "\t";
				// ���� ��ġ�� ����
				location = j;
			}
			else
				std::cout << gameStage[j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;



	while (true) {

		//w: ���� �̵� s: �Ʒ��� �̵� a: ���� �̵� d: ������ �̵� q: ����
		char player = 0;

		int move[4] = { location-5, location+5, location-1, location+1 };

		std::cout << "w: ���� �̵� s: �Ʒ��� �̵� a: ���� �̵� d: ������ �̵� q: ����";
		std::cout << std::endl;

		std::cin >> player;
	
		// q�Է�
		if (player == 'q')
			break;


		// w�� �Է��ߴٸ� ���� �̵�
		if (player == 'w') {

			int newLocation = location - 5;

			if (newLocation > 24 || newLocation < 0)
				continue;

			// ������ġ �ε��� ���� ���� �ε����� ������ ��ȯ
			gameStage[location] = gameStage[newLocation];
			// ���� ��ġ ����
			location = newLocation;
			// ���� �ε��� ���� ������ġ �ε��� ������
			gameStage[location] = 0;
			
		}

		// s�� Ŭ���ߴٸ� �Ʒ��� �̵�
		if (player == 's') {

			int newLocation = location + 5;

			if (newLocation > 24 || newLocation < 0)
				continue;

			// ������ġ �ε��� ���� �Ʒ��� �ε����� ������ ��ȯ
			gameStage[location] = gameStage[newLocation];
			// ���� ��ġ ����
			location = newLocation;
			// �Ʒ��� �ε��� ���� ������ġ �ε��� ������
			gameStage[location] = 0;
		}

		// a�� �Է��ߴٸ� ���������� �̵�
		if (player == 'a') {

			int newLocation = location - 1;

			if (newLocation > 24 || newLocation < 0 || newLocation % 5 == 4)
				continue;
		

			// ������ġ �ε��� ���� �Ʒ��� �ε����� ������ ��ȯ
			gameStage[location] = gameStage[newLocation];
			// ���� ��ġ ����
			location = newLocation;
			// �Ʒ��� �ε��� ���� ������ġ �ε��� ������
			gameStage[location] = 0;
		}

		// d�� �Է��ߴٸ� �������� �̵�
		if (player == 'd') {

			int newLocation = location + 1;

			if (newLocation > 24 || newLocation < 0 || newLocation % 5 == 0)
				continue;

			// ������ġ �ε��� ���� �Ʒ��� �ε����� ������ ��ȯ
			gameStage[location] = gameStage[newLocation];
			// ���� ��ġ ����
			location = newLocation;
			// �Ʒ��� �ε��� ���� ������ġ �ε��� ������
			gameStage[location] = 0;
		}


		// ���
		system("cls");
		for (int i = 0; i < 5; i++) {
			for (int j = i * 5; j < i * 5 + 5; j++) {
				if (gameStage[j] == 0) {
					std::cout << "*" << "\t";
					// ���� ��ġ�� ����
					location = j;
				}
				else
					std::cout << gameStage[j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;

		int count = 0;
		for (int i = 0; i < 25; i++) {
			if (gameStage[i+1] == i + 1)
				count++;
		}
		if (count == 24) {
			std::cout << "�ϼ�!! ������ �����մϴ�.." << std::endl;
			break;
		}

	}
	

	return 0;
}