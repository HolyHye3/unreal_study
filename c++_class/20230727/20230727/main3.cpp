#include <iostream>

void Test(int* Pointer)
{
	Pointer = new int;
}

void Test1(int** Pointer)
{
	*Pointer = new int;
}

int main()
{
	/*
	��������� : ������ ����� �о���� ���� ����̴�.
	C��� ��İ� C++����� �����ȴ�.
	*/
	FILE* FileStream = nullptr;

	/*
	fopen_s���� Mode�� 2���� �κ����� ���еȴ�.
	2���� ���ĺ� �������� ó���ȴ�.
	
	1�� ����
	w: ������ ���� ������� ��
	r: ���� ������ �о�� ��
	a: ���� ������ �о�ͼ� �� �ڿ� ������ �߰����� ��

	2�� ����
	t: �ؽ�Ʈ ����
	b: ���̳ʸ� ����

	*/
	fopen_s(&FileStream, "Test.txt", "wt");

	if (FileStream)
	{
		// ���Ͽ� ���ڸ� �߰��� ��
		// fputc: ���� �ϳ��� �߰��� ��
		// fgets: ���ڿ��� �߰��� ��
		
		/*fputs("���ڿ� �߰�\n", FileStream);
		fputc('T', FileStream);*/

		char Text[256] = {};
		fgets(Text, 256, FileStream);

		std::cout << Text;

		char Text1 = fgetc(FileStream);

		std::cout << Text1 << std::endl;

		// �۾��� �Ϸ�� ���� ��Ʈ���� ������ �ݾ���� �Ѵ�.
		fclose(FileStream);
	}

	int* Num = nullptr;

	//Test(Num);

	Test1(&Num);

	return 0;
}