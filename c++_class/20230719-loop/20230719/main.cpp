#include <iostream>

int main()
{
	/*
		�ݺ���: ������ �ڵ带 ������ �ݺ��ؼ� ���۽����ִ� ���.
		for, while, do while

		for�� ����
		for(�ʱⰪ; ���ǽ�; ����)
		{
			������ �ڵ�
		}
		�ʱⰪ: for���� ������ �� 1���� �����Ѵ�.
		���ǽ�: for���� �ݺ��ؼ� �����Ҷ����� üũ�Ѵ�.
				���ǽ��� ����� true/false�� ���� �� �ְ� �����Ѵ�.
				���� �ݺ��� ���۵Ǳ� ������ ���ǽ��� �����Ѵ�.
				���ǽ��� true�̸� ���� �ڵ尡 �����ϰ� ���ǽ��� false�� for���� ����������.
		����: for���� �ݺ��ؼ� �����Ҷ����� ������ �Ѵ�.
				���� �ݺ��� ����ǰ� �Ŀ� ������ ó���Ѵ�.

		���۹��
		�ʱⰪ -> ���ǽ� -> �ڵ���� -> ���� -> ���ǽ� -> �ڵ� ���� -> ...
		�ݺ����� ���ǽ��� false�� �Ǹ� for���� ����������.

		���ǽ��� ��� true�� �ȴٸ� for���� �������� �� ���� ������ ���ǽ��� �� �����ؾ� �Ѵ�.

		�ǵ������� ���ѷ����� ������ ���� ���
		for(;;)
		{
		}

		�ʱⰪ, ���ǽ�, ��� ��� ����θ� ���ѷ����� ���� �� �ִ�.

	*/
	for (int i = 0; i < 10; i++) {
		std::cout << i << std::endl;
	}

	std::cout << "\n" << std::endl;

	for (int i = 0; i < 10; i += 2) {
		std::cout << i << std::endl;
	}

	std::cout << "\n" << std::endl;

	for (int i = 0; i < 100; i++) {
		if (i % 4 == 0 && i % 7 == 0) {
			std::cout << i << std::endl;
		}
	}
	
	std::cout << "\n" << std::endl;

	for (int i = 0; i < 100; i++) {

		// break�� if������ ������ �� �� ����.
		// switch, for, while, do while�� ���������� �뵵�� ����Ѵ�.
		if (i == 30)
			break;

		// continue: ���� �ݺ��� ��ŵ���ش�.
		else if (i % 2 == 0)
			continue;

		std::cout << i << std::endl;
	}

	// c++�� �ڵ�����ܿ����� ���� ��밡��
	{int num = 0;}
	// std::cout << num << std::endl;


	return 0;
}