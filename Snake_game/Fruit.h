#pragma once
#include <cstdlib>
#include "Ñonstants.h"
class Fruit
{
private:
	Position _pos;
public:
	Fruit();
	const Position& GetNewPos();
	const Position& Pos() const { return _pos; }
};

