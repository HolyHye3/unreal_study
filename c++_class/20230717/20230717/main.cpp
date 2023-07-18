/*
* #: 전처리기
* iostream -> 기본 입출력 기능 지원하는 헤더파일
* 
* 실행파일 제작 순서
* 컴파일 -> 링크 -> 실행파일 생성
* 전처리기는 컴파일 전에 먼저 처리를 하고 컴파일을 수행
* 
* #include는 컴파일 전에 헤더파일의 내용을 여기에 포함시켜서 사용할 수 있게 해준다.
*/
#include <iostream> 

/*
*회사에서 안좋아해서 가급적이면 안쓰는게 좋음...??
*namespace는 이름충돌을 방지해주기 위한 문법이다. 
*소스를 지정해주어서 서로 충돌되는 것을 막아준다. 
*using namespace를 해주게 되면 namespace없이 사용이 가능하지만 가급적이면 사용 안하는 것 추천
*/
 
// using namespace std;

int main()
{
	// std: standard
	// cout: console output
	// :: <== 범위지정 연산자.
	// 범위를 지정해준다.
	std::cout << "console output\n" << std::endl; // 문자열
	std::cout << "\"test\"" << std::endl;

	/*
	용량의 최소단위 : bit
	1bit는 0 혹은 1 둘중 하나의 값을 저장할 수 있는 공간이다.

	1byte: 8bit
	1kbyte: 1024byte
	1mbyte: 1024kbyte
	1gbyte: 1024mbyte
	1tbyte: 1024gbtye

	컴퓨터의 데이터 저장장치
	- 주기억장치 : 메모리(램), 휘발성 메모리
		* 프로그램에 동작시에 데이터를 저장하다가 프로그램이 종료하면 데이터도 제거된다.
	
	- 보조기억장치 : HDD, SSD, USB. 비휘발성 메모리
		* 반영구적으로 데이터를 보존할 수 있다.
	
	변수: 값을 저장하기 위한 공간이다.
		* 원할 때 값을 변경할 수 있다.
	
	c++은 타입 의존적인 언어이다.

	참 / 거짓은 0은 거짓 0이 아닌 모든 수는 참으로 판단한다.

	변수 선언방법
	타입 이름;
	변수 이름은 특수문자는 _만 허용된다.
	첫글자는 알파벳이나 언더바만 와야한다.
	첫글자로 숫자를 사용할 수 없다.
	*/

	FLT_MAX;
	INT_MAX;

	// 초기화를 시키지 않으면 버그가 발생할 가능성이 있기 때문에 컴파일러 단계에서 초기화하라고 문제를 잡아줌
	// = : 대입 연산자이다. 오른쪽의 값을 왼쪽에 대입시켜준다.
	bool Test = true;

	std::cout << Test << std::endl;

	// 문자하나 저장
	char Text = 'C';

	std::cout << Text << std::endl;
	std::cout << (int)Text << std::endl;
	std::cout << char(Text + 1) << std::endl;

	/*  
	변수의 표현범위를 벗어날 경우 + 값으로 표현범위가 벗어나면 -값의 최소값으로 이동하여 표현한다.
	-값으로 표현범위가 벗어나면 +값의 최대값으로 이동하여 표현한다.
	*/
	short Number = 32769;  // -32767 값이 넘어감
	std::cout << Number << std::endl;

	unsigned char r = 100;
	std::cout << r << std::endl;

	int Number1 = -2147483649;

	std::cout << Number1 << std::endl;

	__int64 Number2 = 2147483649999999999;
	std::cout << Number2 << std::endl;

	/* 
	cout은 소수점 5번째 자리까지 출력을 하게 된다.
	6번째 자리까지 넣게 되면 6번째 자리는 반올림 시켜서 출력해준다.
	
	*/
	float Number3 = 3.14961234f;
	std::cout << Number3 << std::endl;

	double Number4 = 3.141596231234;
	std::cout << Number4 << std::endl;

	/*
	* 상수: 값을 바꿀 수 없는 수이다.
		* 변수를 상수로 바꿔서 사용할 수도 있다.
	const 키워드를 이용해서 변수를 상수로 바꿀 수 있다.
	const 키워드는 타입 왼쪽에 붙여준다.
	변수를 상수로 만들게 되면 반드시 선언과 동시에 값을 초기화 시켜야 한다.
	선언 이후에는 값을 지정할 수 없다.
	*/

	// 값을 바꾸지 못한다. 중요한 값이기 때문에 바꾸지 못하게 하는 것.
	// Number5 = 300;
	const int Number5 = 1010;

	/*
	사칙연산자 : +, -, *, /, %(나머지 연산자)
	10 / 3 = 3.333333333333
	나눗셈 연산에서 주의할 점은 10/3처럼 두 수가 모두 정수로 구성된 경우
	결과값도 소수점 자리가 짤린 정수 부분만 나오게 된다.
	만약 결과값이 소수점단위의 값이 나와야 한다면 둘 중 하나는 실수여야 한다.

	0으로 나눌 경우도 주의해야 한다.
	0으로 나눌 경우 nan이 나올 수 있다.

	나머지 연산자는 정수 연산만 지원한다.
	3.14f % 302.2f; -> 안됨
	A % B를 할 경우 A를 B로 나눈 나머지 값을 구해준다.
	10 % 3 = 1
	*/

	std::cout << "10 / 3 = " << 10 / 3 << std::endl;
	std::cout << "10 / 3 = " << 10 / 3.0f << std::endl;

	std::cout << "10 % 3 = " << 10 % 3 << std::endl;

	std::cout << "10 + 2 * 4 = " << (10 + 2) * 4 << std::endl;
	std::cout << "((10 + 2) - 5) * 4 = " << ((10 + 2) - 5) * 4 << std::endl;
	
	/*
	관계연산자 : >, <, >=, <=, ==(같다), !=(다르다)
	값 대 값을 연산해서 결과로 참/거짓이 나오게 된다.

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
	논리연산자: AND(&&), OR(||), NOT(!)
	참 / 거짓 대 참 / 거짓 을 연산해서 결과로 참 / 거짓이 나오게 된다.
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