#include <iostream>

struct item
{
	char Name[32];
	int Price;
	int Sell;
};

int main() {

	FILE* FileStream = nullptr;

	fopen_s(&FileStream, "TestBinary.ssc", "wb");

	if (FileStream)
	{
		item item = {};
		strcpy_s(item.Name, "티켓");
		item.Price = 10000;
		item.Sell = 5000;

		fwrite(&item, sizeof(item), 1, FileStream);

		fclose(FileStream);
	}

	fopen_s(&FileStream, "TestBinary.ssc", "rb");

	if (FileStream)
	{
		item item = {};

		fread(&item, sizeof(item), 1, FileStream);

		
		std::cout << "이름: " << item.Name << std::endl;
		std::cout << "Price: " << item.Price << std::endl;
		std::cout << "Sell : " << item.Sell << std::endl;

		fclose(FileStream);

	}

	return 0;

}