#include <iostream>

int main()
{
	/*
	while(���ǽ�)
	{

	}
	���ǽ��� true�̸� ����
	���ǽ��� false�̸� while���� ����������.

	for��ó�� break�� continue�� �����帧�� ������ �� �ִ�.
	*/
	int Number = 0;
	while (Number < 10) {
		Number++;
	}

	/*while (true)
	{

	}*/

	/*
	do
	{
		�ݺ��� �ڵ�
	}while(���ǽ�);

	ó�� 1���� ���ǽİ� ������� ������ �ڵ尡 ������ �ȴ�.
	*/

	do
	{
		std::cout << Number << std::endl;
		++Number;
	} while (Number < 10);


	return 0;
}