#include <iostream>

int main() {

	/*
		��ø for��: for�� ���ʿ� �ٸ� for���� �߰��Ͽ� ����ϴ� ����̴�.
	*/
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << "i = " << i << ", j = " << j << std::endl;
		}
	}

	// �������� 2 ~ 9�ܱ��� ���� for���� �̿��ؼ� ���
	for (int i = 1; i <= 9; i++) {
		
		std::cout << "====== " << i << "�� ���� ======" << std::endl;
		
		for (int j = 1; j <= 9; j++) {
			
			std::cout << i << " X " << j << " = "
				<< i * j << std::endl;
		
		}
	}

	// �����
	int num = 0;

	std::cout << "���ڸ� �Է��ϼ���." << std::endl;
	std::cin >> num;

	std::cout << "\n1" << std::endl;

	/*
		  *
		  **
		  ***
		  ****
		  *****
	 */
	for (int i = 0; i <= num; i++) {
			std::cout << "\n";
		for (int j = 0; j <= i; j++)
			std::cout << "*";
	}
	std::cout << std::endl;
	std::cout << "\n2" << std::endl;

	
	/*
		 *****
		 ****
		 ***
		 **
		 *
	 */

	for (int i = num; i >= 0; i--) {
		std::cout << "\n";
		for (int j = 0; j <= i; j++)
			std::cout << "*";
	}

	std::cout << std::endl;
	std::cout << "\n3" << std::endl;

	/*
	  *****
	   ****
		***
		 **
		  *
	 */


	for (int i = num; i >= 0; i--) {
		std::cout << "\n";
		for (int j = 0; j <= i; j++)
			std::cout << " ";
		for (int k = 0; k <= i; k++)
			std::cout << "*";
	}


	std::cout << std::endl;
	std::cout << "\n4" << std::endl;

	/*
		 *
		**
	   ***
	  ****
	 *****
	*/
	for (int i = 0; i <= num; i++) {
		std::cout << "\n";
		for (int j = num; j >= i; j--)
				std::cout << " ";
		for (int k = 0; k <= i; k++)
				std::cout << "*";
	}

	std::cout << std::endl;
	std::cout << "\n5" << std::endl;


	/*
		   *
		  ***
		 *****
		*******
	*/

	for (int i = 0; i <= num+1; i+=2) {
		std::cout << "\n";
		for (int j = num; j >= i; j-=2)
			std::cout << " ";
		for (int k = 0; k <= i; k++)
			std::cout << "*";
	}


	/*
	   *
	  ***
	 *****
	*******
	 *****
	  ***
	   *
	*/

	std::cout << std::endl;
	std::cout << "\n6" << std::endl;


	for (int i = 0; i <= num + 1; i += 2) {
		std::cout << "\n";
		for (int j = num; j >= i; j -= 2)
			std::cout << " ";
		for (int k = 0; k <= i; k++)
			std::cout << "*";
	}
	for (int i = num - 1; i >= 0; i -= 2) {
		std::cout << "\n";
		for (int j = num; j >= i; j -= 2)
			std::cout << " ";
		for (int k = 0; k <= i; k++)
			std::cout << "*";
	}

	return 0;
}