#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include "Gamefield.h"

int main() {
	using namespace std;
	srand(time(0));

	Gamefield gamefield;
	while (!gamefield.GameOver())
	{
		gamefield.Initialize();
		gamefield.Show();
		Sleep(30);
	}
	cout << "GameOver!\n";
	system("pause");
	return 0;
}