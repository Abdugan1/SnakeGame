#include "Tail.h"

Tail::Tail(const Position& pos, Tail* pNext)
{
	_prev_pos = _pos = pos;
	_pNext = pNext;
}
