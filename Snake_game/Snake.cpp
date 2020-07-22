#include "Snake.h"

void Snake::MoveLogic()
{
	_tail[0]._prev_pos = _tail[0]._pos;

	for (size_t i = 1; i < _size; i++)
	{
		this->PrevPos(i) = this->Pos(i);
		this->Pos(i) = this->PrevPos(i - 1);
	}

	switch (_dir)
	{
	case UP: _tail[0]._pos.y--; break;
	case DOWN: _tail[0]._pos.y++; break;
	case LEFT: _tail[0]._pos.x--; break;
	case RIGHT: _tail[0]._pos.x++; break;
	}

	if (_tail[0]._pos.x <= 0) { _tail[0]._pos.x = WIDTH - 2; }
	else if (_tail[0]._pos.x >= WIDTH - 1) { _tail[0]._pos.x = 1; }
	else if (_tail[0]._pos.y <= 0) { _tail[0]._pos.y = HEIGHT - 2; }
	else if (_tail[0]._pos.y >= HEIGHT - 1) { _tail[0]._pos.y = 1; }
}

void Snake::RotationLogic(const Direction& prev_dir)
{
	switch (prev_dir)
	{
	case UP:
		if (_dir == DOWN)
			_dir = prev_dir;
		break;
	case DOWN:
		if (_dir == UP)
			_dir = prev_dir;
		break;
	case LEFT:
		if (_dir == RIGHT)
			_dir = prev_dir;
		break;
	case RIGHT:
		if (_dir == LEFT)
			_dir = prev_dir;
		break;
	}
}

Snake::Snake()
{
	_tail.reserve(70);
	_tail.push_back(Tail());
	_dir = RIGHT;
	_size = 1;
}

void Snake::Move()
{
	Direction prev_dir = _dir;
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'W': case 'w': _dir = UP; break;
		case 'S': case 's': _dir = DOWN; break;
		case 'A': case 'a': _dir = LEFT; break;
		case 'D': case 'd': _dir = RIGHT; break;
		}
	}
	RotationLogic(prev_dir);
	MoveLogic();
}

void Snake::Grow()
{
	_tail.push_back(_tail[_size - 1]._prev_pos);
	_size++;
}

Position& Snake::Pos(const int& index)
{
	return _tail[index]._pos;
}

Position& Snake::PrevPos(const int& index) 
{
	return _tail[index]._prev_pos;;
}

