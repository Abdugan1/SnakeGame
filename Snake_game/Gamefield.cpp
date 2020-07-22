#include "Gamefield.h"

void Gamefield::Initialize()
{
	_snake.Move();
	if (_snake.Head() == _fruit.Pos())
	{
		_snake.Grow();
		_fruit.GetNewPos();
		_score += 10;
	}
	else if (_field[_snake.Head().y][_snake.Head().x] == 'o')
	{
		_game_status = true;
	}

	Position current, snake_pos;
	for (int i = 1; i < HEIGHT - 1; i++)
	{
		for (int j = 1; j < WIDTH - 1; j++)
		{
			current = { j, i };
			if (current == _snake.Head())
			{
				_field[i][j] = 'O';
				continue;
			}

			for (size_t k = 1; k < _snake.Size(); k++)
			{
				snake_pos = _snake.Pos(k);
				_field[snake_pos.y][snake_pos.x] = 'o';
			}
			_field[i][j] = ' ';
		}
	}
	GenerateFruit();
}

bool Gamefield::FruitWasEaten()
{
	return _snake.Head() == _fruit.Pos();
}

void Gamefield::GenerateFruit()
{
	Position fruit_pos = _fruit.Pos();
	while (_field[fruit_pos.y][fruit_pos.x] == 'O' || _field[fruit_pos.y][fruit_pos.x] == 'o')
	{
		fruit_pos = _fruit.GetNewPos();
	}
	_field[fruit_pos.y][fruit_pos.x] = 'a';
}

Gamefield::Gamefield() : _field(HEIGHT)
{
	for (size_t i = 0; i < _field.size(); i++)
	{
		_field[i].resize(WIDTH);
	}

	for (size_t i = 0; i < WIDTH; i++)
	{
		_field[0][i] = '#';
	}

	for (size_t i = 0; i < HEIGHT; i++)
	{
		_field[i][0] = '#';
	}

	for (size_t i = 0; i < HEIGHT; i++)
	{
		_field[i][WIDTH - 1] = '#';
	}

	for (size_t i = 0; i < WIDTH; i++)
	{
		_field[HEIGHT - 1][i] = '#';
	}

	_game_status = false;
	_score = 0;
}

void Gamefield::Show()
{
	system("cls");
	std::string Gamefield_str;
	for (size_t i = 0; i < HEIGHT; i++)
	{
		for (size_t j = 0; j < WIDTH; j++)
		{
			Gamefield_str += _field[i][j];
		}
		Gamefield_str += '\n';
	}
	std::cout << Gamefield_str;
	std::cout << "Score: " << _score << std::endl;
}
