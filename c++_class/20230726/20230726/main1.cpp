#include <iostream>

/*
�Լ������� : �Լ��� �ּҰ� �ִ�.
	�Լ��� �ּҸ� �����ϴ� ���� �Լ� �������̴�.
*/
void Output() {
	std::cout << "Oputput Function" << std::endl;
}
void Output1() {
	std::cout << "Oputput1 Function" << std::endl;
}

int Sum(int Num1, int Num2) {
	return Num1 + Num2;
}

int Minus(int Num1, int Num2) {
	return Num1 - Num2;
}

int Sum1(int Num1, int Num2=100) {
	return Num1 + Num2;
}

int main() {

	// �Ʒ��� ���� �Լ��� ȣ���ϸ� �Լ��� �̸��� �� �ּ��̱� ������ �ش� �ּҷ� �ڵ��� �����帧�� �̵��ǰ�, �ش� �Լ��� ȣ��� �� ���ƿ��� ������ ������ �޸� �ּҰ� ����ǰ� �ȴ�.
	// �Լ��� ȣ���� �Լ��ּ�(����);�� ȣ���ϰ� �Ǵ� ���̴�.
	Output();

	std::cout << Output << std::endl;
	std::cout << Output1 << std::endl;
	std::cout << Sum << std::endl;
	std::cout << Minus << std::endl;


	// �Լ������� ������
// ��ȯŸ�� (*�������̸�)(����Ÿ��); ���� �����Ѵ�.
	void (*Func)();

	Func = Output;

	Func();

	Func = Output1;

	Func();

	int   (*Func1)(int, int);

	Func1 = Sum;
	std::cout << Func1(10, 20) << std::endl;

	Func1 = Minus;
	std::cout << Func1(10, 20) << std::endl;

	Func1 = Sum1;
	std::cout << Func1(10, 20) << std::endl;




	return 0;
}