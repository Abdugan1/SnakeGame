#pragma once
#include <conio.h>
#include "Ñonstants.h"
#include "Tail.h"
class Snake
{
private:
	Tail* _head;
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
	const Position& Head() const { return _head->_pos; }
	const size_t& Size() const { return _size; }
	Position& Pos(const int& index) const;
	Position& PrevPos(const int& index) const;
};

