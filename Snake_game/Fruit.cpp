#include "Fruit.h"

Fruit::Fruit()
{
	GetNewPos();
}

const Position& Fruit::GetNewPos()
{
	_pos.x = (rand() % (WIDTH - 2)) + 1;
	_pos.y = (rand() % (HEIGHT - 2)) + 1;
	return _pos;
}
