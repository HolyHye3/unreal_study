#include <iostream>

int main() {

	/*
		중첩 for문: for문 안쪽에 다른 for문을 추가하여 사용하는 방식이다.
	*/
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << "i = " << i << ", j = " << j << std::endl;
		}
	}

	// 구구단을 2 ~ 9단까지 이중 for문을 이용해서 출력
	for (int i = 1; i <= 9; i++) {
		
		std::cout << "====== " << i << "단 시작 ======" << std::endl;
		
		for (int j = 1; j <= 9; j++) {
			
			std::cout << i << " X " << j << " = "
				<< i * j << std::endl;
		
		}
	}

	// 별찍기
	int num = 0;

	std::cout << "숫자를 입력하세요." << std::endl;
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