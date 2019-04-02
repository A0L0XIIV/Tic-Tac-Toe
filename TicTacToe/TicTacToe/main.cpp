#include <iostream>
#include <string>
#include "Start.h"
#include "Characters.h"

using namespace std;

int main() {
	//Object of the start page
	StartPage startPage;
	//Print game name -> Tic Tac Toe
	cout << startPage.getTicTacToe() << endl;
	//Welcome message
	cout << "\nWelcome to the game!" << endl << endl;

	//----------Variables----------

	//User input
	char userInput = ' ';
	//User's game character
	char userGameCharacter = '\0';

	//Game matrix for tic tac toe
	char gameMatrix[3][3] = { '\0' };

	//Row and column counter for print operations
	int gameRowCounter = 0;
	int gameColumnCounter = 0;

	//Users row and column inputs
	int userInputRow = 0;
	int userInputColumn = 0;

	//For printing the correct line of the game character
	int gameCharacterLineCounter = 0;

	//----------Character selection----------
	userGameCharacter = startPage.characterSelection();

	//----------Game loop----------
	while (true) {

		cout << "Please select a row for a movement (1-3): ";
		cin >> userInputRow;
		userInputRow--; //Minus one for arrays

		cout << "Please select a column for a movement (1-3): ";
		cin >> userInputColumn;
		userInputColumn--; //Minus one for arrays

		//Player's movement into the game matrix
		if (1 <= userInputRow <= 3 && 1 <= userInputColumn <= 3
			&& gameMatrix[userInputRow][userInputColumn] == '\0' )
			gameMatrix[userInputRow][userInputColumn] = userGameCharacter;
		else
			cout << "Please enter between 1 and 3." << endl;

		/*for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << gameMatrix[i][j];
			}
			cout << endl;
		}*/

		Characters gameCharacters;
		//7 character + 1 tab = 8 -> 9th place -> 0-8
		int verticalLine = 9;

		//26 char -> row print ( 7(game character) + 1(tab) + 1(vertical line) + 1(tab) + 7... ) 
		for (int i = 0; i < 15; i++) {

			//x char -> column print ( 4(game character) + 1(empty) + 1(empty) + 4... )
			for (int j = 0; j < 26; j++) {

				//Print vertical line
				if (j != 0 && j % verticalLine == 0) {
					cout << "|";
					gameRowCounter++;
				}

				//Print empty spaces before and after the vertical line
				else if (j == (verticalLine - 1) ||
					j == (verticalLine + 1) ||
					j == (2 * verticalLine - 1) ||
					j == (2 * verticalLine + 1))
					cout << "\t";

				//Print game characters
				else {
					//Get matrix's 1 box
					char box = gameMatrix[gameRowCounter][gameColumnCounter];
					//Check game matrix's elements for print

					//ÇALÞIMIYOR -> USERINPUT ÝLE ÇALIÞIYORDU!!!!

					if (box == 'X' || box == 'O')
					{
						j += 7;
						gameCharacterLineCounter++;
						switch (gameCharacterLineCounter)
						{
						case 1:
							if (box == 'X')
								cout << gameCharacters.characterXLine1;
							else
								cout << gameCharacters.characterOLine1;
							break;
						case 2:
							if (box == 'X')
								cout << gameCharacters.characterXLine2;
							else
								cout << gameCharacters.characterOLine2;
							break;
						case 3:
							if (box == 'X')
								cout << gameCharacters.characterXLine3;
							else
								cout << gameCharacters.characterOLine3;
							break;
						case 4:
							if (box == 'X')
								cout << gameCharacters.characterXLine4;
							else
								cout << gameCharacters.characterOLine4;
							break;
						default:
							gameCharacterLineCounter = 0;
							break;
						}
					}
				}
			}

			//End of every line
			cout << endl;

			//Reset row counter
			gameRowCounter = 0;

			//Print horizantel line
			if (i == 4 || i == 9) {
				cout << "-------------------------------------------------" << endl;
				gameColumnCounter++;
			}

		}
		
	}


	//ORTA SÜTUNDA YANLIÞ YAZDIRIYOR


	return 0;
}