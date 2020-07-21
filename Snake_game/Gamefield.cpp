#include "Gamefield.h"

void Gamefield::Initialize()
{
	_snake.Move();
	if (_snake.Head() == _fruit.Pos())
	{
		_snake.Grow();
		_fruit.GetNewPos();
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
				snake_pos = _snake.Head();
				_field[snake_pos.y][snake_pos.x] = '@';
				continue;
			}
			else if (current == _fruit.Pos())
			{
				_field[i][j] = 'a';
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
}

bool Gamefield::FruitWasEaten()
{
	return _snake.Head() == _fruit.Pos();
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

	Position snake_head = _snake.Head();
	_game_status = false;
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
	std::cout << Gamefield_str << std::endl;
}
