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

struct Vector2DInt {
	int x;
	int y;
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
};



#include "Board.hpp"
