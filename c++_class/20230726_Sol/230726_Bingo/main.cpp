
#include "Bingo.h"
#include "Puzzle.h"

int main()
{
	srand((unsigned int)time(0));
	rand();

	while (true)
	{
		EMainMenu Menu = MainMenu();

		switch (Menu)
		{
		case EMainMenu::Bingo:
			BingoMain();
			break;
		case EMainMenu::Puzzle:
			PuzzleMain();
			break;
		case EMainMenu::Pair:
			break;
		case EMainMenu::Lotto:
			break;
		case EMainMenu::Exit:
			return 0;
		}
	}

	return 0;
}