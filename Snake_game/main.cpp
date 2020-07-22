#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include "Gamefield.h"

int main() {
	using namespace std;
	srand(time(0));

	Gamefield gamefield;
	clock_t delay = 60;
	clock_t start;
	while (!gamefield.GameOver())
	{
		start = clock();
		gamefield.Initialize();
		gamefield.Show();
		while (clock() - start < delay);		
	}
	cout << "GameOver!\n";
	system("pause");
	return 0;
}