#pragma once
#include "Ñonstants.h"
class Tail
{
public:	//protedcted???
	Position _prev_pos;
	Position _pos;
	Tail* _pNext;
private:
public:
	Tail(const Position& pos = { WIDTH / 2, HEIGHT / 2 }, Tail* pNext = nullptr);
};

