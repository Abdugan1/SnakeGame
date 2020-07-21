#include "Snake.h"

void Snake::MoveLogic()
{
	_head->_prev_pos = _head->_pos;

	for (size_t i = 1; i < _size; i++)
	{
		this->PrevPos(i) = this->Pos(i);
		this->Pos(i) = this->PrevPos(i - 1);
	}

	switch (_dir)
	{
	case UP: _head->_pos.y--; break;
	case DOWN: _head->_pos.y++; break;
	case LEFT: _head->_pos.x--; break;
	case RIGHT: _head->_pos.x++; break;
	}

	if (_head->_pos.x <= 0) { _head->_pos.x = WIDTH - 2; }
	else if (_head->_pos.x >= WIDTH - 1) { _head->_pos.x = 1; }
	else if (_head->_pos.y <= 0) { _head->_pos.y = HEIGHT - 2; }
	else if (_head->_pos.y >= HEIGHT - 1) { _head->_pos.y = 1; }
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
	_head = new Tail();
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
	Tail* current = _head;
	while (current->_pNext != nullptr)
	{
		current = current->_pNext;
	}
	current->_pNext = new Tail();
	_size++;
}

Position& Snake::Pos(const int& index) const
{
	int counter = 0;
	Tail* current = _head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->_pos;
		}
		current = current->_pNext;
		counter++;
	}
}

Position& Snake::PrevPos(const int& index) const
{
	int counter = 0;
	Tail* current = _head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->_prev_pos;
		}
		current = current->_pNext;
		counter++;
	}
}

