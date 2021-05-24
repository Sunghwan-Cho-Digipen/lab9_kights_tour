/******************************************************************
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.

File Name: Board.hpp
Project: Lab 9 - Knights Tour
Author: Sunghwan Cho
Creation date: 05/24/21
******************************************************************/


#include "Board.h"

template <int WIDTH, int HEIGHT>
Board<WIDTH, HEIGHT>::Board()
{
	board = new bool* [WIDTH];
	for(int i = 0; i < HEIGHT; ++i)
	{
		board[i] = new bool[HEIGHT];
	}
	setBoard();
}

template <int WIDTH, int HEIGHT>
Board<WIDTH, HEIGHT>::~Board()
{
	delete[] board;
}

template <int WIDTH, int HEIGHT>
void Board<WIDTH, HEIGHT>::SolveKnightsTour(Vector2DInt start, Vector2DInt end)
{
	if(isAblePoint(end) == false)
	{
		std::cout << "End position is not valid" << std::endl;
		return;
	}

	if (isAblePoint(start) == false)
	{
		std::cout << "Start position is not valid" << std::endl;
		return;
	}

	std::list<Vector2DInt> tempPath{ end };
	std::list<std::list<Vector2DInt>> gatheredPath{ tempPath };
	SolveKnightsTourFunction(start, gatheredPath);
}

template <int WIDTH, int HEIGHT>
void Board<WIDTH, HEIGHT>::PrintPath()
{
	if(path.empty() == true)
	{
		std::cout << "There are no valid paths" << std::endl;
		return;
	}
	
	for (Vector2DInt& iter : path)
	{
		if(iter == *std::prev(path.end(),1))
		{
			std::cout << "(" << iter.x << ", " << iter.y << ")" << std::endl;
			return;
		}
		std::cout << "(" << iter.x << ", " << iter.y << "), ";
	}
}

template<int WIDTH, int HEIGHT>
void Board<WIDTH, HEIGHT>::setBoard()
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			new(&board[i][j]) bool(false);
		}
	}
}

template <int WIDTH, int HEIGHT>
void Board<WIDTH, HEIGHT>::SolveKnightsTourFunction(Vector2DInt point, std::list<std::list<Vector2DInt>> paths)
{
	if(board[point.y][point.x] == true)
	{
		return;
	}
	if(paths.empty() == true)
	{
		return;
	}
	
	std::list<Vector2DInt> frontPath = paths.front();
	paths.pop_front();
    const Vector2DInt frontPoint = frontPath.front();
	
	std::list<Vector2DInt> CheckingList{ {frontPoint + Vector2DInt{2,1}} ,  {frontPoint + Vector2DInt{2,-1}}, {frontPoint + Vector2DInt{ -2,1 }}, {frontPoint + Vector2DInt{ -2,-1 }},
		{frontPoint + Vector2DInt{ 1,2 }}, {frontPoint + Vector2DInt{ 1,-2 }}, {frontPoint + Vector2DInt{ -1,2 }}, {frontPoint + Vector2DInt{-1,-2 } }};

	for(Vector2DInt& iter : CheckingList)
	{
		if(isAblePoint(iter) == true)
		{
			if(board[iter.y][iter.x] == true)
			{
				continue;
			}

			std::list<Vector2DInt> newPath = frontPath;
			newPath.push_front(iter);
			paths.push_back(newPath);

			board[iter.y][iter.x] = true;

			if(iter == point)
			{
				path = paths.back();
				return;
			}
		}
	}

	SolveKnightsTourFunction(point, paths);
}

template <int WIDTH, int HEIGHT>
bool Board<WIDTH, HEIGHT>::isAblePoint(Vector2DInt pos)
{
	if (pos.x >= WIDTH || pos.y >= HEIGHT || pos.x < 0 || pos.y < 0)
	{
		return false;
	}
	return true;
}
