#include <iostream>

/*
����ü: �������� ������ �ϳ��� ��� ����� �� �ְ� ���ִ� ����

struct ����ü�̸�
{
	���ϴ� ���� ����.
};

��������� ���� Ÿ���� ������ش�.
����ü�̸��� ���� Ÿ���� �ȴ�.

*/


// #define: ��ó�����. �Ʒ��� ���� �������� ���
// NAME_SIZE�� ����� ��� �κп� ������ ���� 32�� ��� ��ü�Ͽ� �������� �����Ѵ�.
#define NAME_SIZE 32

// �������� ���� �ʱ� ������ �ǵ��� �Ʒ��� ���� �ڵ� ���� �ʴ� ���� ����,,
// ������� �ȵȴٴ� ������ �ִ�.
#define TEST  std::cout << "TEST" << std::endl

enum class CharacterType
{
	Type1,
	Type2,
	Type3
};

struct TestStruct
{
	// ����ü ������ ���� ����
	int Test1;
	int Test2;
	int Test3;
};

// �ַ� �ڵ� �ٱ��ʿ� �����.
struct Player
{
	// int nameSize = 32; // �迭 ������ �����ȵ�..
	char Name[NAME_SIZE];
	

	CharacterType Type;

	int Option1;
	int Option2;
	int Option3;

	TestStruct TestStr;

};

int main()
{
	// �����Ϸ��� �Ʒ��� ���� TEST�� �ڿ� �ִ� �ڵ带 ���̰� �������� �����Ѵ�.
	TEST;

	// ����ü�� �迭�� ���� �ʱ�ȭ�� �����ϴ�.
	Player player = {}; // ��� ������ 0���� �ʱ�ȭ�Ѵ�.
	//Player player = {"aa", CharacterType::Type1};


	// ����ü�� .�� �̿��ؼ� ����� �����Ѵ�.
	// Name�� char �迭�̴�. char�迭�� �迭 �̸��� ����ϸ� �ش� �迭�� ����� ��� ���ڸ� �� ����Ѵ�.
	// ���ڿ��� ���� �ν��ϱ� ���ؼ��� �ݵ�� �������� �ι���(0)�� �־��־�� �Ѵ�.
	// �׷��� ���� �迭�� 32�������� ���� ���ڸ� ������ �� �ִ� ������ 31���̴�.
	std::cout << player.Name << std::endl;
	// std::cout << player.Type << std::endl;

	return 0;
}