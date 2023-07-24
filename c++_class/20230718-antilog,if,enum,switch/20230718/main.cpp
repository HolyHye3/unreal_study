#include <iostream>
#include <time.h>

/*
�÷��̾�� ����, ����, �� �� �� �ϳ��� �����Ѵ�.
AI�� ����, ����, �� ���� �ϳ��� �����ϰ� ���´�.
�÷��̾�� AI�� ���� �̰������ �Ǵ��Ѵ�.
*/

/*
����ü: ����� �̸��� �ο��ϴ� ����̴�.
����ü�� �̿��Ͽ� �̸��� �ο��� ����� �����Ǵ� ���������� ���� ����� �� �ִ�.

����
enum ����ü��{
	�̸� �ο�.
}; <- �����ݷ� �ٿ������;;;

�̸��� �ο��� ����� 0���� �����ؼ� ���� 1�� �����Ǿ� �����ȴ�.

�������� ����� ����� �̿��� ���� ������ �������� �̸� ��ü�� ������ ��������� ����Ÿ���� �ȴ�.

���������� ���� ������ �ش� �������� ��Ͽ� ������ ���� ������ ������ �� �ִ�.

�������� �⺻������ 4byte��.
*/

enum SRP {
	SCISSOR = 1,
	ROCK,
	PAPER
};

// ���������� ������ ������ �����ϴ�.
enum class SRP1 : unsigned char {
	SCISSOR1 = 1,
	ROCK1,
	PAPER1
};

/*
switch: �б⹮�� �� �����̴�.
����
switch(�б⸦ �ϰ��� �ϴ� ��)
{
case üũ�� ���(������ ������ �ȵȴ�.):
	���۽�ų �ڵ�
	break; break�� switch���� ���������� ������ �Ѵ�.
case üũ�� ���(������ ������ �ȵȴ�.):
	���۽�ų �ڵ�
	break;
case üũ�� ���(������ ������ �ȵȴ�.):
	���۽�ų �ڵ�
	break;
}
*/

int main()
{
	// ����ȯ: (��ȯ�� Ÿ��)�� ���·� ����ϸ�, � ���̳� ������ ������ Ÿ������ �Ͻ������� �νĽ����ִ� ���
	srand((unsigned int)time(0));
	rand();

	std::cout << "1. ����" << std::endl;
	std::cout << "2. ����" << std::endl;
	std::cout << "3. ��" << std::endl;
	std::cout << "�����ϼ���" << std::endl;

	// �÷��̾� ����
	int player = 0;
	std::cin >> player;

	// ��ǻ�� ��������
	int com = rand() % 3 + 1;

	switch (com) {
	case SCISSOR:
		std::cout << "com: ����\n";
		break;
	case ROCK:
		std::cout << "com: ����\n";
		break;
	case PAPER:
		std::cout << "com: ��\n";
		break;
}
	/*
	if (player == SCISSOR)
		std::cout << "�÷��̾� ����: 1.���� " << std::endl;
	else if (player == SCISSOR)
		std::cout << "�÷��̾� ����: 2.���� " << std::endl;
	else if (player == PAPER)
		std::cout << "�÷��̾� ����: 3.�� " << std::endl;

	if (com == SCISSOR)
		std::cout << "AI ����: 1.����" << std::endl;
	else if (com == SCISSOR)
		std::cout << "AI ����: 2.���� " << std::endl;
	else if (com == PAPER)
		std::cout << "AI ����: 3.�� " << std::endl;
	*/

	std::cout << "\n";

	SRP srp; // = 100;
	srp = SCISSOR;

	SRP1 srp1;
	srp1 = SRP1::SCISSOR1;

	// player = SRP1::ROCK1;  // �Ҵ� ���Ѵ�.

	std::cout << "SRP Size: " << sizeof(SRP) << std::endl;
	std::cout << "SRP1 Size: " << sizeof(SRP1) << std::endl;

	int Result = player - com;
	
	if(Result == 1 || Result == -2)
	/*if ((player == SCISSOR && com == PAPER) ||
		(player == SCISSOR && com == 1) || 
		(player == PAPER && com == SCISSOR))
		*/
		std::cout << "����� �̰���ϴ�." << std::endl;
	else if (player == com)
		std::cout << "�����ϴ�." << std::endl;
	else
		std::cout << "����� �����ϴ�." << std::endl;


	
	return 0;
}