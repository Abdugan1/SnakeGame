#pragma once
#include <iostream>
#include <vector>
#include "Ñonstants.h"
#include "Snake.h"
#include "Fruit.h"
class Gamefield
{
private:
	Snake _snake;
	Fruit _fruit;
	size_t _score;
	std::vector<std::vector<char>> _field;
	bool FruitWasEaten();
	void GenerateFruit();
	bool _game_status;
public:
	Gamefield();
	void Initialize();
	void Show();
	bool GameOver() const { return _game_status; }
};

