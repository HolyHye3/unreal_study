#include <iostream>
#include <time.h>

int main()
{
	// srand(0);
	srand(time(0));
	rand();
	std::cout << rand() % 100 + 100 << std::endl;
	std::cout << rand() % 100 + 100 << std::endl;
	std::cout << rand() % 100 + 100 << std::endl;
	std::cout << rand() % 100 + 100 << std::endl;
	std::cout << rand() % 100 + 100 << std::endl;
	/*
	if��: ������ üũ�Ͽ� ���ϴ� �ڵ带 ���۽�ų�� ������ ������ �� �ִ�.
	����
	if(���ǽ�)
	{
		������ true�� �� ������ �ڵ�
	}
	*/
	if (true) {
		std::cout << "if���� true �Դϴ�." << std::endl;
	}

	int Number = 100;

	// if�� ���� �ڵ尡 1���� ��� �ڵ����� ���� ����
	if (Number < 0)
		std::cout << "���ڰ� 0���� �۴�." << std::endl;
	/*
	else�� if�� ���ǽ��� false�� �� �����ϴ� ����̴�.
	else�� ȥ�ڼ� ����� �Ұ����ϴ�. �ݵ�� if���� �Բ� ����ؾ��Ѵ�.
	else
	{
	}
	�� �����ȴ�.
	*/
	else {
		std::cout << "���ڰ� 0���� ũ��." << std::endl;
	}

	/*
	else if�� ȥ�ڼ� ����� �Ұ����ϴ�. �ݵ�� if���� �Բ� ����ؾ��Ѵ�.
	else if�� ��� �߰��� �� �ִ�.
	else ���� ���� �־�� �Ѵ�.

	����
	else if(���ǽ�)
	{
	}
	*/

	const int State1 = 0x1;		// 0000 0001
	const int State2 = 0x2;		// 0000 0010
	const int State3 = 0x4;		// 0000 0100
	const int State4 = 0x8;		// 0000 1000
	const int State5 = 0x10;	// 0001 0000
	const int State6 = 0x20;	// 0010 0000
	const int State7 = 0x40;	// 0100 0000

	int State = 0;

	State |= State2;
	State |= State3;
	State |= State6;

	if (State & State1)
		std::cout << "State1 On\n";
	if (State & State2)
		std::cout << "State2 On\n";
	if (State & State3)
		std::cout << "State3 On\n";
	if (State & State4)
		std::cout << "State4 On\n";
	if (State & State5)
		std::cout << "State5 On\n";
	if (State & State6)
		std::cout << "State6 On\n";

	Number = 30;
	// cin : �ܼ�â���� �Է¹��� �� �ְ� ���ִ� ����̴�.
	std::cin >> Number;

	if (Number < 10)
		std::cout << "���ڰ� 10���� �۴�\n";
	else if (Number < 20)
		std::cout << "���ڰ� 20���� �۴�\n";



	return 0;
}