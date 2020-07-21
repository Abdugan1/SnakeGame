#pragma once

const int HEIGHT = 20;
const int WIDTH = 40;

struct Position
{
	int x, y;
	bool operator==(const Position& p) const
	{
		return (x == p.x && y == p.y);
	}
};