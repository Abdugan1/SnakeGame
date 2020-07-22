#pragma once
#include <conio.h>
#include <vector>
#include "Ñonstants.h"
#include "Tail.h"
class Snake
{
private:
	std::vector<Tail> _tail;
	size_t _size;
	enum Direction
	{
		UP, DOWN, LEFT, RIGHT
	} _dir;

	//	Private Methods
	void MoveLogic();
	void RotationLogic(const Direction& prev_dir);
public:
	Snake();
	~Snake() {}

	void Move();
	void Grow();
	const Position& Head() const { return _tail[0]._pos; }
	const size_t& Size() const { return _size; }
	Position& Pos(const int& index);
	Position& PrevPos(const int& index);
};

