#pragma once

#include <iostream>

void PrintBoard(bool Open[], char Card[]) {

	system("cls");

	// i�� ���� �ٹ�ȣ�� �ǰ� j�� ���ι�ȣ�� �ȴ�.
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; ++j) {

			// �ε��� ����: ���ι�ȣ * ���ΰ��� + ���ι�ȣ
			int Index = i * 5 + j;

			// ī�尡 ���� ���¶�� ī�� ��ȣ�� ����Ѵ�.
			if (!Open[Index])
			{
				// ī�� ��ȣ�� ����Ѵ�.
				//std::cout << Card[Index] << "\t";
				std::cout << Index << "\t";
			}
			else {
				std::cout << Card[Index] << "\t";
			}
		}

		std::cout << std::endl;
	}
}