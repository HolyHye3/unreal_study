/*
* #: ��ó����
* iostream -> �⺻ ����� ��� �����ϴ� �������
* 
* �������� ���� ����
* ������ -> ��ũ -> �������� ����
* ��ó����� ������ ���� ���� ó���� �ϰ� �������� ����
* 
* #include�� ������ ���� ��������� ������ ���⿡ ���Խ��Ѽ� ����� �� �ְ� ���ش�.
*/
#include <iostream> 

/*
*ȸ�翡�� �������ؼ� �������̸� �Ⱦ��°� ����...??
*namespace�� �̸��浹�� �������ֱ� ���� �����̴�. 
*�ҽ��� �������־ ���� �浹�Ǵ� ���� �����ش�. 
*using namespace�� ���ְ� �Ǹ� namespace���� ����� ���������� �������̸� ��� ���ϴ� �� ��õ
*/
 
// using namespace std;

int main()
{
	// std: standard
	// cout: console output
	// :: <== �������� ������.
	// ������ �������ش�.
	std::cout << "console output\n" << std::endl; // ���ڿ�
	std::cout << "\"test\"" << std::endl;

	/*
	�뷮�� �ּҴ��� : bit
	1bit�� 0 Ȥ�� 1 ���� �ϳ��� ���� ������ �� �ִ� �����̴�.

	1byte: 8bit
	1kbyte: 1024byte
	1mbyte: 1024kbyte
	1gbyte: 1024mbyte
	1tbyte: 1024gbtye

	��ǻ���� ������ ������ġ
	- �ֱ����ġ : �޸�(��), �ֹ߼� �޸�
		* ���α׷��� ���۽ÿ� �����͸� �����ϴٰ� ���α׷��� �����ϸ� �����͵� ���ŵȴ�.
	
	- ���������ġ : HDD, SSD, USB. ���ֹ߼� �޸�
		* �ݿ��������� �����͸� ������ �� �ִ�.
	
	����: ���� �����ϱ� ���� �����̴�.
		* ���� �� ���� ������ �� �ִ�.
	
	c++�� Ÿ�� �������� ����̴�.

	�� / ������ 0�� ���� 0�� �ƴ� ��� ���� ������ �Ǵ��Ѵ�.

	���� ������
	Ÿ�� �̸�;
	���� �̸��� Ư�����ڴ� _�� ���ȴ�.
	ù���ڴ� ���ĺ��̳� ����ٸ� �;��Ѵ�.
	ù���ڷ� ���ڸ� ����� �� ����.
	*/

	FLT_MAX;
	INT_MAX;

	// �ʱ�ȭ�� ��Ű�� ������ ���װ� �߻��� ���ɼ��� �ֱ� ������ �����Ϸ� �ܰ迡�� �ʱ�ȭ�϶�� ������ �����
	// = : ���� �������̴�. �������� ���� ���ʿ� ���Խ����ش�.
	bool Test = true;

	std::cout << Test << std::endl;

	// �����ϳ� ����
	char Text = 'C';

	std::cout << Text << std::endl;
	std::cout << (int)Text << std::endl;
	std::cout << char(Text + 1) << std::endl;

	/*  
	������ ǥ�������� ��� ��� + ������ ǥ�������� ����� -���� �ּҰ����� �̵��Ͽ� ǥ���Ѵ�.
	-������ ǥ�������� ����� +���� �ִ밪���� �̵��Ͽ� ǥ���Ѵ�.
	*/
	short Number = 32769;  // -32767 ���� �Ѿ
	std::cout << Number << std::endl;

	unsigned char r = 100;
	std::cout << r << std::endl;

	int Number1 = -2147483649;

	std::cout << Number1 << std::endl;

	__int64 Number2 = 2147483649999999999;
	std::cout << Number2 << std::endl;

	/* 
	cout�� �Ҽ��� 5��° �ڸ����� ����� �ϰ� �ȴ�.
	6��° �ڸ����� �ְ� �Ǹ� 6��° �ڸ��� �ݿø� ���Ѽ� ������ش�.
	
	*/
	float Number3 = 3.14961234f;
	std::cout << Number3 << std::endl;

	double Number4 = 3.141596231234;
	std::cout << Number4 << std::endl;

	/*
	* ���: ���� �ٲ� �� ���� ���̴�.
		* ������ ����� �ٲ㼭 ����� ���� �ִ�.
	const Ű���带 �̿��ؼ� ������ ����� �ٲ� �� �ִ�.
	const Ű����� Ÿ�� ���ʿ� �ٿ��ش�.
	������ ����� ����� �Ǹ� �ݵ�� ����� ���ÿ� ���� �ʱ�ȭ ���Ѿ� �Ѵ�.
	���� ���Ŀ��� ���� ������ �� ����.
	*/

	// ���� �ٲ��� ���Ѵ�. �߿��� ���̱� ������ �ٲ��� ���ϰ� �ϴ� ��.
	// Number5 = 300;
	const int Number5 = 1010;

	/*
	��Ģ������ : +, -, *, /, %(������ ������)
	10 / 3 = 3.333333333333
	������ ���꿡�� ������ ���� 10/3ó�� �� ���� ��� ������ ������ ���
	������� �Ҽ��� �ڸ��� ©�� ���� �κи� ������ �ȴ�.
	���� ������� �Ҽ��������� ���� ���;� �Ѵٸ� �� �� �ϳ��� �Ǽ����� �Ѵ�.

	0���� ���� ��쵵 �����ؾ� �Ѵ�.
	0���� ���� ��� nan�� ���� �� �ִ�.

	������ �����ڴ� ���� ���길 �����Ѵ�.
	3.14f % 302.2f; -> �ȵ�
	A % B�� �� ��� A�� B�� ���� ������ ���� �����ش�.
	10 % 3 = 1
	*/

	std::cout << "10 / 3 = " << 10 / 3 << std::endl;
	std::cout << "10 / 3 = " << 10 / 3.0f << std::endl;

	std::cout << "10 % 3 = " << 10 % 3 << std::endl;

	std::cout << "10 + 2 * 4 = " << (10 + 2) * 4 << std::endl;
	std::cout << "((10 + 2) - 5) * 4 = " << ((10 + 2) - 5) * 4 << std::endl;
	
	/*
	���迬���� : >, <, >=, <=, ==(����), !=(�ٸ���)
	�� �� ���� �����ؼ� ����� ��/������ ������ �ȴ�.

	10 < 20 = true
	10 > 20 = false
	10 <= 20 = true
	10 >= 20 = false
	10 == 20 = false
	10 != 20 = true
	*/

	
	std::cout << "10 / 3 = " << 10 / 3 << std::endl;
	
	std::cout << "10 < 20  = " << (10 < 20) << std::endl;
	std::cout << "10 > 20  = " << (10 > 20) << std::endl;
	std::cout << "10 <= 20 = " << (10 <= 20) << std::endl;
	std::cout << "10 >= 20 = " << (10 >= 20) << std::endl;
	std::cout << "10 == 20 = " << (10 == 20) << std::endl;
	std::cout << "10 != 20 = " << (10 != 20) << std::endl;

	/*
	����������: AND(&&), OR(||), NOT(!)
	�� / ���� �� �� / ���� �� �����ؼ� ����� �� / ������ ������ �ȴ�.
	A    B    AND     OR
	0    0     0      0
	1    0     0      1
	0    1     0      1
	1    1     1      1

	A   NOT
	0    1
	1    0
	*/

	std::cout << "false && false = " <<
		(false && false) << std::endl;
	std::cout << "true && false = " <<
		(true && false) << std::endl;
	std::cout << "false && true = " <<
		(false && true) << std::endl;
	std::cout << "true && true = " <<
		(true && true) << std::endl;
	

	std::cout << "false || false = " <<
		(false || false) << std::endl;
	std::cout << "true || false = " <<
		(true || false) << std::endl;
	std::cout << "false || true = " <<
		(false || true) << std::endl;
	std::cout << "true || true = " <<
		(true || true) << std::endl;

	std::cout << "!false = " << !false << std::endl;
	std::cout << "!true = " << !true << std::endl;

	return 0;
}