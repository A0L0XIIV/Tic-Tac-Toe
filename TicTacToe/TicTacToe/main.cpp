#include <iostream>
#include <string>
#include "Start.h"
#include "Characters.h"
#include "GameController.h"

using namespace std;

int main() {
	// Object of the start page
	StartPage startPage;
	// Print game name -> Tic Tac Toe
	cout << startPage.getTicTacToe() << endl;
	// Welcome message
	cout << "\nWelcome to the game!" << endl << endl;

	// ----------Variables----------

	// User input
	char userInput = ' ';
	// User's game character
	char userGameCharacter = '\0';

	// Game matrix for tic tac toe
	GameController *gameController = new GameController();

	// Row and column counter for print operations
	int gameRowCounter = 0;
	int gameColumnCounter = 0;

	// Users row and column inputs
	int userInputRow = 0;
	int userInputColumn = 0;

	/* For printing the correct line of the game character
	*  Every column of the row needs their own line counter
	*/
	int gameCharacterLineCounter[3] = { 0, 0, 0 };

	// ----------Character selection----------
	userGameCharacter = startPage.characterSelection();

	// ----------Game loop----------
	while (true) {

		// ---------- User Inputs ----------

		cout << "Please select a row for a movement (1-3): ";
		cin >> userInputRow;
		userInputRow--; // Minus one for array indexes

		cout << "Please select a column for a movement (1-3): ";
		cin >> userInputColumn;
		userInputColumn--; // Minus one for array indexes

		// Player's movement into the game matrix
		// Between 0 and 2 check
		if (0 <= userInputRow && userInputRow <= 2 && 
			0 <= userInputColumn && userInputColumn <= 2) {
			// Already fulled with other charcter check
			if (gameController->getGameMatrixCharacter(userInputRow, userInputColumn) == '\0') {
				gameController->setGameMatrix(userInputRow, userInputColumn, userGameCharacter);
			

				// ---------- Printing ----------

				//Print small game matrix
				gameController->printGameMatrix();

				Characters gameCharacters;
				// 7 character + 1 tab = 8 -> 9th place
				int verticalLine1 = 9;
				// 7 char + 1 tab + 1 verLine + 1 tab + 7 char + 1 tab = 18 -> 19th place
				int verticalLine2 = 19;

				// 4 character + 1 empty row = 5 -> 6th place but its in i's for loop so 6-1=5
				int horizontalLine1 = 5;
				// 4 char + 1 empty + 1 horLine + 4 char + 1 empty = 11 -> 12th place but its in i's for loop so 12-1=11
				int horizontalLine2 = 11;
 
				/* Vertical loop --> rows
				* gC=Game Character, e=empty row, hL=Horizontal Line
				* 16 char -> column print ( 4gC + 1e + 1hL + 4gC + 1e + 1hL + 4gC )
				*/
				for (int i = 1; i < 17; i++) {

					/* Horizontal loop --> columns
					* gC=Game Character, t=tab character, vL=Vertical Line
					* 27 char -> row print ( 7gC + 1t + 1vL + 1t + 7gC + 1t + 1vL + 1t + 7gC ) 
					*/
					for (int j = 1; j < 28; j++) {

						// Print vertical line
						if (j == verticalLine1 || j == verticalLine2) {
							cout << "|";
							gameColumnCounter++;
						}

						// Print empty spaces before and after the vertical line
						else if (j == (verticalLine1 - 1) ||
							j == (verticalLine1 + 1) ||
							j == (verticalLine2 - 1) ||
							j == (verticalLine2 + 1))
							cout << "\t";

						// Print game characters
						else {
							// Get matrix's current box's character
							char box = gameController->getGameMatrixCharacter(gameRowCounter, gameColumnCounter);

							/* If print loop reachs here, it will either print character
							* or blank empty. Either way, it can skip 6 column parts. Because,
							* game characters are 7 column character long. (j+6 + j++ = j+7)
							* Therefore, increase the j value with 6.
							*/
							j += 6;

							// Check game matrix's elements for print
							if (box == 'X' || box == 'O')
							{
								gameCharacterLineCounter[gameColumnCounter]++;
								switch (gameCharacterLineCounter[gameColumnCounter])
								{
								// Print game characters' first line
								case 1:
									if (box == 'X')
										cout << gameCharacters.characterXLine1;
									else
										cout << gameCharacters.characterOLine1;
									break;
								// Print game characters' second line
								case 2:
									if (box == 'X')
										cout << gameCharacters.characterXLine2;
									else
										cout << gameCharacters.characterOLine2;
									break;
								// Print game characters' third line
								case 3:
									if (box == 'X')
										cout << gameCharacters.characterXLine3;
									else
										cout << gameCharacters.characterOLine3;
									break;
								// Print game characters' fourth line
								case 4:
									if (box == 'X')
										cout << gameCharacters.characterXLine4;
									else
										cout << gameCharacters.characterOLine4;
									break;
								// Stop printing the game character
								default:
									gameCharacterLineCounter[gameColumnCounter] = 0;
									break;
								}
							}
						}
					}

					// End of every line
					cout << endl;

					// Reset column counter at the end of the each row for (j)
					gameColumnCounter = 0;

					// Print horizantel line
					if (i == horizontalLine1 || i == horizontalLine2) {
						//Increase i because we used that row for printing the horizontal line
						i++;
						cout << "-------------------------------------------------" << endl;
						// After each horizontal line increase game matrix's column counter (1-->2)
						gameRowCounter++;

						//Reset all column's character line counters
						gameCharacterLineCounter[0] = 0;
						gameCharacterLineCounter[1] = 0;
						gameCharacterLineCounter[2] = 0;
					}

				}

				// Reset row counter at the end of the each print operation for (i)
				gameRowCounter = 0;
		
			} else
			 cout << "This cell is already full. Please try another one." << endl;
		} else if (userInputRow < 0 || userInputColumn < 0) // Not a number
			break;
		else
		 cout << "Please enter between 1 and 3." << endl;
	}

	return 0;
}