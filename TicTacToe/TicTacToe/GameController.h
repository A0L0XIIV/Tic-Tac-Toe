#include <iostream>
#include <vector>

using namespace std;

class GameController {
	// Game matrix
	vector<vector<char>> gameMatrix;
	char winnerCharacter;

public:
	// Constructer
	GameController();
	// Functions
	vector<vector<char>> getGameMatrix();
	char getGameMatrixCharacter(int row, int column);
	void setGameMatrix(int row, int column, char c);
	char getWinnerCharacter();
	void printGameMatrix();
	bool isGameOver();
};

// Constructer
GameController::GameController() {
	this->gameMatrix = { {'\0', '\0', '\0'}, {'\0', '\0', '\0'}, {'\0', '\0', '\0'} };
	this->winnerCharacter = '\0';
}

// Get game matrix function
vector<vector<char>> GameController::getGameMatrix() {
	return this->gameMatrix;
}

// Get game matrix's selected character function
char GameController::getGameMatrixCharacter(int row, int column) {
	return this->gameMatrix[row][column];
}

// Get winner character
char GameController::getWinnerCharacter() {
	return this->winnerCharacter;
}

// Set function
void GameController::setGameMatrix(int row, int column, char c) {
	if (c == 'X' || c == 'O')
		this->gameMatrix[row][column] = c;
}

// Print function
void GameController::printGameMatrix() {

	cout << "-----" << endl;

	for (int i = 0; i < 3; i++) {
		cout << '|';
		for (int j = 0; j < 3; j++) {
			if (gameMatrix[i][j] == '\0')
				cout << "_";
			else
				cout << gameMatrix[i][j];
		}
		cout << '|' << endl;
	}

	cout << "-----" << endl;
}

// Game status check function
bool GameController::isGameOver() {
	vector<vector<char>> currentGameMatrix = this->gameMatrix;

	// Column check
	for (int i = 0; i < 3; i++) {
		// Row's first column is not empty --> could be full row
		if (currentGameMatrix[i][0] != '\0') {
			// Check row's all characters are equal or not
			if (currentGameMatrix[i][0] == currentGameMatrix[i][1] &&
				currentGameMatrix[i][1] == currentGameMatrix[i][2]) {
				this->winnerCharacter = currentGameMatrix[i][0];
				return true;
			}
		}
		else
			continue;
	}

	// Row check
	for (int j = 0; j < 3; j++) {
		// Column's first row is not empty --> could be full column
		if (currentGameMatrix[0][j] != '\0') {
			// Check column's all characters are equal or not
			if (currentGameMatrix[0][j] == currentGameMatrix[1][j] &&
				currentGameMatrix[1][j] == currentGameMatrix[2][j]) {
				this->winnerCharacter = currentGameMatrix[0][j];
				return true;
			}
		}
		else
			continue;
	}

	// Diagonal check
	if (currentGameMatrix[0][0] != '\0') {
		// 1-1, 2-2, 3-3 check
		if (currentGameMatrix[0][0] == currentGameMatrix[1][1] &&
			currentGameMatrix[1][1] == currentGameMatrix[2][2]) {
			this->winnerCharacter = currentGameMatrix[0][0];
			return true;
		}
	}
	else if (currentGameMatrix[0][2] != '\0') {
		// 3-1, 2-2, 1-3 check
		if (currentGameMatrix[2][0] == currentGameMatrix[1][1] &&
			currentGameMatrix[1][1] == currentGameMatrix[0][2]) {
			this->winnerCharacter = currentGameMatrix[2][0];
			return true;
		}
	}

	return false;
}