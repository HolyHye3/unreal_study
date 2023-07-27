#include <iostream>

int main()
{
	FILE* FileStream = nullptr;

	fopen_s(&FileStream, "PlayerInfo.txt", "rt");

	if (FileStream) {
		// 이름/직업/공격력/방어력 이렇게 저장되어 있다.
		int Count = 0;

		char Line[256] = {};
		fgets(Line, 256, FileStream);


		// 문자열에 숫자가 잇을 경우 이 숫자를 int로 변경해준다.
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