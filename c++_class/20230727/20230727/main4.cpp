#include <iostream>

int main()
{
	FILE* FileStream = nullptr;

	fopen_s(&FileStream, "PlayerInfo.txt", "rt");

	if (FileStream) {
		// �̸�/����/���ݷ�/���� �̷��� ����Ǿ� �ִ�.
		int Count = 0;

		char Line[256] = {};
		fgets(Line, 256, FileStream);


		// ���ڿ��� ���ڰ� ���� ��� �� ���ڸ� int�� �������ش�.
		Count = atoi(Line);

		fgets(Line, 256, FileStream);
		std::cout << Line << std::endl;

		for (int i = 0; i < Count; i++) {
			fgets(Line, 256, FileStream);
			
			char* Context = nullptr;
			char* Result = strtok_s(Line, "/", &Context);

			int a = 0;
		}

		fclose(FileStream);


	}
}