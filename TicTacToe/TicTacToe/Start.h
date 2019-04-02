#include <iostream>
#include <string>

using namespace std;

class StartPage {
	/*string Tic = "
		 _______   _
		|__   __| |_|
		   | |     _    _____
		   | |    | |  /  ___\
		   | |    | |  | |___
		   |_|    |_|  \_____/";

	string Tac = "
		 _______   ____
		|__   __| /___ \
		   | |     __| |   _____
		   | |   /  _  |  /  ___\
		   | |   | |_| |  | |___
		   |_|   \_____/  \_____/";

	string Toe = "
		 _______
		|__   __|            _____
		   | |              /  _  \
		   | |     _____    | |_| |
		   | |    /  _  \   |  ___|
		   | |    | |_| |   | |___
		   |_|    \_____/   \_____/";*/

	/*string Tic = " _______   _\n|__   __| |_|\n   | |     _    _____\n   | |    | |  /  ___\\\n   | |    | |  | |___\n   |_|    |_|  \\_____/";

	string Tac = " _______   ____\n|__   __| /___ \\\n   | |     __| |   _____\n   | |   /  _  |  /  ___\\\n   | |   | |_| |  | |___\n   |_|   \\_____/  \\_____/";

	string Toe = " ______\n|__   __|            _____\n   | |              /  _  \\\n   | |     _____    | |_| |\n   | |    /  _  \\   |  ___|\n   | |    | |_| |   | |___\n   |_|    \\_____/   \\_____/";
	*/

	string line1 = " _______   _			 _______   ____				 _______";
	string line2 = "|__   __| |_|			|__   __| /___ \\			|__   __|            _____";
	string line3 = "   | |     _    _____		   | |	   __| |   _____		   | |     _____    /  _  \\";
	string line4 = "   | |    | |  /  ___\\		   | |   /  _  |  /  ___\\		   | |    /  _  \\   | |_| |";
	string line5 = "   | |    | |  | |___		   | |   | |_| |  | |___		   | |    | |_| |   | |___";
	string line6 = "   |_|    |_|  \\_____/		   |_|   \\_____/  \\_____/		   |_|    \\_____/   \\_____/";
	string TicTacToe = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6;

public:
	StartPage() = default;
	string getTicTacToe() { return TicTacToe; };
	char characterSelection();

};

//Function
char StartPage::characterSelection() {
	char userInput = '\0';
	char userGameCharacter = '\0';

	while (true) {
		cout << "Please select your character [X] or [O]." << endl;

		cin >> userInput;
		userGameCharacter = toupper(userInput);

		cout << "Your character is: " << userGameCharacter << endl;

		if (userGameCharacter == 'X' || userGameCharacter == 'O')
			break;
	}

	return userGameCharacter;
}