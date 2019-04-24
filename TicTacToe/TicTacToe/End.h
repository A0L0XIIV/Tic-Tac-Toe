#include <iostream>
#include <string>

using namespace std;

class EndPage {

	string line1 = " ______    ______    __        __    ______      ______   _        _   ______    ______";
	string line2 = "/  ____\\  |  __  |  |  \\      /  |  |  ____|    | ____ | \\ \\      / / |  ____|  | ___  \\";
	string line3 = "| /  __   | |  | |  |   \\    /   |  | |____     | |  | |  \\ \\    / /  | |____   | |__| |";
	string line4 = "| | |_ |  | |__| |  | |\\ \\  / /| |  |  ____|    | |  | |   \\ \\  / /   |  ____|  | |__  /";
	string line5 = "| \\__/ |  |  __  |  | | \\ \\/ / | |  | |____     | |__| |    \\ \\/ /    | |____   | |  \\ \\";
	string line6 = "\\______/  |_|  |_|  |_|  \\__/  |_|  |______|    |______|     \\__/     |______|  |_|  |_|";
	string GameOver = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6;

public:
	EndPage() = default;
	string getGameOver() { return GameOver; };

};