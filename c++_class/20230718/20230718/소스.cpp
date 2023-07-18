#include <iostream>

int main()
{
	/*
	2진수: 0 ~ 1 사이로 구성된 숫자 집합.
	0b1110111

	10진수: 0 ~ 9 사이로 구성된 숫자 집합.
	16진수: 0 ~ 15 사이로 구성된 숫자 집합.
	10 - 15까지는 a ~ f로 표현한다.
	0x1f7

	216을 진수, 16진수로 변환해보자!
	216 / 2 = 108 -- 0
	108 / 2 = 54 --- 0
	52 / 2 = 27 ---- 0
	13 / 2 = 6 ----- 1
	6 / 2 = 3 ------ 0
	3 / 2 = 1 ------ 1

	0b11011000

	1   1  0  1  1 0 0 0
	128 64 32 16 8 4 2 1

	128 + 64 + 16 + 8 = 216

	16진수 1자리는 2진수 4자리로 구성된다.(자리 부족할 시 0을 붙여서 4자리 만들어줌)
	1 1 0 1 / 1 0 0 0
	8 4 2 1   8 4 2 1

	0xd8

	13 / 2 = 6 -- 1
	6 / 2 = 3 --- 0
	3 / 2 = 1 --- 1
	1101

	8 / 2 = 4 -- 0
	4 / 2 = 2 -- 0
	2 / 2 = 1 -- 0
	1000

	11011000

	
	비트단위 논리연산자: 2진수 단위의 연산을 수행한다.
	값 대 값을 연산해서 결과로 값이 나온다.
	AND(&), OR(|), NOT(~), XOR(^)
	비트단위 논리연산자를 사용하면 피연산자들을 먼저 2진수로 변환한다.
	계산이 빠르다는 장점이 있다.


	216 & 357 = 
	  011011000
	& 101100101
	  ---------
	  001000000

	1  0  0  0 0 0 0
	64 32 16 8 4 2 1

	216 | 357 = 
	  011011000
	| 101100101
	  ---------
	  111111101

	1   1   1  1  1  1 1 0 1
	256 128 64 32 16 8 4 2 1
	256 + 128 + 64 + 32 + 16 + 8 + 4 + 1 = 509

	216이 int로 인식이 되기때문에 
	~216 =
	~ 00000000 00000000 00000000 11011000
	  11111111 11111111 11111111 00100111

	A   B   XOR
	0   0   0
	1   0   1


	216 ^ 357 = 
	   011011000
	 ^ 101100101
	   ---------
	   110111101

	1   1   0  1  1  1 1 0 1
	256 128 64 32 16 8 4 2 1

	256 + 128 + 32 + 16 + 8 + 4 + 1 = 445

	*/

	std::cout << "216 & 357 = " << (216 & 357) << std::endl;
	std::cout << "216 | 357 = " << (216 | 357) << std::endl;

	std::cout << "~216 = " << ~216 << std::endl;
	std::cout << "~216 = " << ~-217 << std::endl;
	
	std::cout << "216 ^ 357 = " << (216 ^ 357) << std::endl;

	const int State1 = 0x1;		// 0000 0001
	const int State2 = 0x2;		// 0000 0010
	const int State3 = 0x4;		// 0000 0100
	const int State4 = 0x8;		// 0000 1000
	const int State5 = 0x10;	// 0001 0000
	const int State6 = 0x20;	// 0010 0000
	const int State7 = 0x40;	// 0100 0000

	int State = 0;
	
	// OR를 이용해서 추가하고 AND를 이용해서 상태가 있는지 검사한다.
	// XOR를 이용해서 상태가 켜져있을 경우 제거하고 상태가 없을 경우 켜준다.
	// State = 000 | 100
	State = State | State3;

	// State = 00100 | 10000 = 10100
	State = State | State5;

	// State = 10100 | 10000 = 10100
	// State = State | State5;

	// State = 0010100 | 1000000 = 1010100
	State = State | State7;


	// 1010100 & 0000001 = 0000000
	std::cout << "state1 = " << (State & State1) << std::endl;
	
	// 1010100 & 0000010 = 0000000
	std::cout << "state2 = " << (State & State2) << std::endl;
	
	// 1010100 & 0000100 = 0000100
	std::cout << "state3 = " << (State & State3) << std::endl;

	// 1010100 & 0001000 = 0000000
	std::cout << "state4 = " << (State & State4) << std::endl;

	// 1010100 & 0010000 = 0010000
	std::cout << "state5 = " << (State & State5) << std::endl;

	// 1010100 & 0100000 = 0000000
	std::cout << "state6 = " << (State & State6) << std::endl;
	
	// 1010100 & 1000000 = 1000000
	std::cout << "state7 = " << (State & State7) << std::endl;


	// State = 1010100 ^ 1000000 = 0010100
	State = State ^ State7;
	std::cout << "State: " << State << std::endl;

	// State =  0010100 ^ 1000000 = 1010100
	State = State ^ State7;
	std::cout << "State: " << State << std::endl;


	/*
	쉬프트연산자: <<, >> 2가지가 있다.
	216 << 2 = 00000000 00000000 00000011 01100000
	32 + 64 + 256 + 512 = 864
	== 216 * 4

	216 << 3 = 00000000 00000000 00000110 11000000
	64 + 128 + 512 + 1024 = 1728
	== 216 * 8

	216 >> 2 = 00000000 00000000 00000000 00110110
	2 + 4 + 16 + 32 = 54
	*/

	unsigned char r = 201;
	unsigned char g = 157;
	unsigned char b = 182;
	unsigned char a = 240;

	unsigned int Color = 0;

	// 00000000 00000000 00000000 a
	Color = a;

	// 00000000 00000000 a 00000000
	Color = Color << 8;

	//   00000000 00000000 aaaaaaaa 00000000
	// | 00000000 00000000 00000000 rrrrrrrr
	//   00000000 00000000 aaaaaaaa rrrrrrrr
	Color = Color | r;

	Color = Color << 8;

	//   00000000 00000000 aaaaaaaa rrrrrrrr
	Color |= g;

	Color = Color << 8;
	Color = Color | b;

	std::cout << Color << std::endl;

	std::cout << "b = " << (Color & 0x000000ff) << std::endl;
	std::cout << "g = " << (Color & 8 & 0x000000ff) << std::endl;
	std::cout << "r = " << (Color & 16 & 0x000000ff) << std::endl;
	std::cout << "a = " << (Color & 24 & 0x000000ff) << std::endl;


	/*
	증감연산자: ++, --
	++: 변수의 값을 1 증가시킨다.
	--: 변수의 값을 1 감소시킨다.
	증감연산자는 변수의 왼쪽 혹은 오른쪽에 붙일 수 있다.
	왼쪽: 전치연산
	오른쪽: 후치연산
	*/

	int Number = 100;
	
	std::cout << ++Number << std::endl;
	std::cout << Number++ << std::endl;
	std::cout << Number << std::endl;


	std::cout << --Number << std::endl;
	std::cout << Number-- << std::endl;
	std::cout << Number << std::endl;
	
	/*
	연산자 축양형: +=, -=, &=, |=
	*/
	Number = 10;

	Number += 30;

	std::cout << Number << std::endl;


	return 0;
}
