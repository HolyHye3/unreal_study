#include <iostream>
#include <time.h>


int main() {
	srand((unsigned int)time(0));
	rand();
	/*
		�迭: �� �� �������� ���� Ÿ���� ���� �������� ������ �� �ְ� ���ִ� ���
		����Ÿ�� �迭�̸�[����];

		int NumberArray[100];

		���� ���� int�迭 100��¥���� �����ϸ� 400����Ʈ��ŭ�� �޸𸮰� �ϳ��� ������� ������ �ȴ�.

		�迭�� �� ��ҿ� �����ϱ� ���ؼ��� �ε����� �̿��Ѵ�.
		�ε����� 0 ~ ����-1 ���� �����Ѵ�.
	*/

	// �ʱ�ȭ���� �ʰ� ����ϸ� �����Ⱚ�� ���´�.
	// int NumberArray[100] = 0; -> �̷��� �ʱ�ȭ�ϴ°� �ȵȴ�.
	
	// �Ʒ��� ���� �ʱ�ȭ
	// �迭 ��ü��Ҹ� 0���� �ʱ�ȭ
	int NumberArray[100] = {};
	// Ư�� �ε����� �ʱ�ȭ
	// int NumberArray[100] = {1,3,6,7,10}

	// int index = 105;
	// NumberArray[index] = 1020; -> �� �� �� ����

	int index = 10;

	NumberArray[0] = 500;

	NumberArray[1] += 20;

	if (index < 0 || index >= 100) {
		std::cout << "index Error" << std::endl;
	}
	else {
		NumberArray[index] = 1020;
	}

	std::cout << NumberArray[0] << std::endl;
	std::cout << NumberArray[index] << std::endl;

	std::cout << "\n" << std::endl;

	for (int i = 0; i < 100; i++) {
		std::cout << NumberArray[i] << std::endl;
	}

	/*
		�������迭:

		1���� �迭�� 2���� �迭�� �������� ũ��� �Ȱ����� ���� ��Ŀ��� ���̰� ����.
		

		int Number[5][10]
		int Number[5][10][6];
		��� ������ �� ���Ͽ� ��ü ���� �����ش�.

		int Number[50] : 50��
		int Number[5][10]: 50��
		int Number[5][10][6] = 300��
	*/
	int NumberArray1[5][10] = {};
	NumberArray1[0][2] = 300;


	/*
		1���� �迭 Ư�� ��ġ ã�� ��: 
		���ι�ȣ* ���ΰ��� + ���ι�ȣ
	*/
	int NumberArray2[50] = {};
	NumberArray2[2 * 10 + 7] = 1010;

	
	//======== ī�� ���� ========

	system("cls");

	int Card[50] = {};

	// Card�� 0 ~ 49�� �ε����� 1 ~ 50���� ���ʴ�� �������ش�.
	for (int i = 0; i < 50; i++) {
		Card[i] = i + 1;
		// Card[i] = rand() % 50 + 1;
	}


	for (int i = 0; i < 50; i++) {
		
		// ���� swap
		int index1 = rand() % 50;
		int index2 = rand() % 50;

		int temp = Card[index1];
		Card[index1] = Card[index2];
		Card[index2] = temp;
	}

	for (int i = 0; i < 50; i++) {
		std::cout << Card[i] << std::endl;
	}


	//���ڻ̱�
	for (int i = 0; i < 6; i++) {
		// \t: Tab Ű�� 1�� �����Ͱ� ���� ȿ��
		std::cout << Card[i] << "\t";
	}

	return 0;
}