#include <iostream>

/*
구조체: 여러개의 변수를 하나로 묶어서 사용할 수 있게 해주는 문법

struct 구조체이름
{
	원하는 변수 선언.
};

사용자정의 변수 타입을 만들어준다.
구조체이름이 변수 타입이 된다.

*/


// #define: 전처리기다. 아래와 같이 선언했을 경우
// NAME_SIZE를 사용한 모든 부분에 컴파일 전에 32로 모두 교체하여 컴파일을 진행한다.
#define NAME_SIZE 32

// 가독성이 좋지 않기 때문에 되도록 아래와 같은 코드 쓰지 않는 것이 좋음,,
// 디버깅이 안된다는 단점이 있다.
#define TEST  std::cout << "TEST" << std::endl

enum class CharacterType
{
	Type1,
	Type2,
	Type3
};

struct TestStruct
{
	// 열거체 가져다 쓰기 가능
	int Test1;
	int Test2;
	int Test3;
};

// 주로 코드 바깥쪽에 만든다.
struct Player
{
	// int nameSize = 32; // 배열 갯수에 지정안됨..
	char Name[NAME_SIZE];
	

	CharacterType Type;

	int Option1;
	int Option2;
	int Option3;

	TestStruct TestStr;

};

int main()
{
	// 컴파일러는 아래와 같이 TEST의 뒤에 있는 코드를 붙이고 컴파일을 진행한다.
	TEST;

	// 구조체도 배열과 같이 초기화가 가능하다.
	Player player = {}; // 모든 변수를 0으로 초기화한다.
	//Player player = {"aa", CharacterType::Type1};


	// 구조체는 .을 이용해서 멤버에 접근한다.
	// Name은 char 배열이다. char배열은 배열 이름만 사용하면 해당 배열에 저장된 모든 문자를 다 출력한다.
	// 문자열의 끝은 인식하기 위해서는 반드시 마지막에 널문자(0)을 넣어주어야 한다.
	// 그래서 실제 배열은 32개이지만 실제 문자를 저장할 수 있는 공간은 31개이다.
	std::cout << player.Name << std::endl;
	// std::cout << player.Type << std::endl;

	return 0;
}