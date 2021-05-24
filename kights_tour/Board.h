/******************************************************************
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.

File Name: Board.h
Project: Lab 9 - Knights Tour
Author: Kevin Wright
Creation date: 1/29/21
******************************************************************/

#pragma once

#include <queue>
#include <list>

struct Vector2DInt {
	int x;
	int y;

	constexpr bool operator==(Vector2DInt vec2) const noexcept
	{
		return x == vec2.x && y == vec2.y;
	}

	constexpr Vector2DInt operator+(Vector2DInt vec2) const noexcept
	{
		return Vector2DInt{ x + vec2.x, y + vec2.y };
	}
};


template<int WIDTH, int HEIGHT>
class Board {
public:
	Board();
	~Board();
	void SolveKnightsTour(Vector2DInt start, Vector2DInt end);
	void PrintPath();
private:
    // Add your own private data
	bool** board;
	std::list<Vector2DInt> path;
	void setBoard();
	void SolveKnightsTourFunction(Vector2DInt point, std::list<std::list<Vector2DInt>> paths);
	bool isAblePoint(Vector2DInt pos);
};



#include "Board.hpp"
