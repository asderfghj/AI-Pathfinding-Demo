///  @file BestFirst.cpp
///  @brief The functions to make a path using BestFirst

#include "bestfirst.h"

struct less_that_Hdistance
{
	inline bool operator() (node* node1, node* node2)
	{
		return(node1->Getm_hDist() < node2->Getm_hDist());
	}
};

std::vector<node*> BestFirst(std::vector<std::vector<node>> *_grid, node* _start, node* _end)
{
	std::vector<node*> open;
	std::vector<node*> path;
	bool goal = false;
	open.push_back(_start);

	while (goal == false && open.size() > 0)
	{
		if (open.front()->Getm_endNode() == true)
		{
			goal = true;
			path = GeneratePath(open.front());
		}
		else
		{
			SearchNodesBF(open.front(), &open, _grid, _end);
			open.erase(open.begin());
		}
		std::sort(open.begin(), open.end(), less_that_Hdistance());
	}
	return path;
}

void SearchNodesBF(node *_front, std::vector<node*> *_open, std::vector<std::vector<node>> *_grid, node* _end)
{
	if (_front->Getm_yHeu() != 0)
	{
		node *above = &_grid->at(_front->Getm_yHeu() - 1).at(_front->Getm_xHeu());
		if (above->Getm_isOpen() != true && above->Getm_isObject() != true)
		{
			above->Setm_parNode(_front);
			above->Setm_isOpen(true);
			above->Calculatem_hDist(_end);
			_open->push_back(above);
		}
	}

	if (_front->Getm_yHeu() != 0 && _front->Getm_xHeu() != 29)
	{
		node *diagUpRight = &_grid->at(_front->Getm_yHeu() - 1).at(_front->Getm_xHeu() + 1);
		if (diagUpRight->Getm_isOpen() != true && diagUpRight->Getm_isObject() != true)
		{
			diagUpRight->Setm_parNode(_front);
			diagUpRight->Setm_isOpen(true);
			diagUpRight->Calculatem_hDist(_end);
			_open->push_back(diagUpRight);
		}
	}

	if (_front->Getm_xHeu() != 29)
	{
		node *right = &_grid->at(_front->Getm_yHeu()).at(_front->Getm_xHeu() + 1);
		if (right->Getm_isOpen() != true && right->Getm_isObject() != true)
		{
			right->Setm_parNode(_front);
			right->Setm_isOpen(true);
			right->Calculatem_hDist(_end);
			_open->push_back(right);
		}
	}

	if (_front->Getm_yHeu() != 30 && _front->Getm_xHeu() != 29)
	{
		node *diagDownRight = &_grid->at(_front->Getm_yHeu() + 1).at(_front->Getm_xHeu() + 1);
		if (diagDownRight->Getm_isOpen() != true && diagDownRight->Getm_isObject() != true)
		{
			diagDownRight->Setm_parNode(_front);
			diagDownRight->Setm_isOpen(true);
			diagDownRight->Calculatem_hDist(_end);
			_open->push_back(diagDownRight);
		}
	}

	if (_front->Getm_yHeu() != 30)
	{
		node *down = &_grid->at(_front->Getm_yHeu() + 1).at(_front->Getm_xHeu());
		if (down->Getm_isOpen() != true && down->Getm_isObject() != true)
		{
			down->Setm_parNode(_front);
			down->Setm_isOpen(true);
			down->Calculatem_hDist(_end);
			_open->push_back(down);
		}
	}

	if (_front->Getm_yHeu() != 30 && _front->Getm_xHeu() != 0)
	{
		node *diagDownLeft = &_grid->at(_front->Getm_yHeu() + 1).at(_front->Getm_xHeu() - 1);
		if (diagDownLeft->Getm_isOpen() != true && diagDownLeft->Getm_isObject() != true)
		{
			diagDownLeft->Setm_parNode(_front);
			diagDownLeft->Setm_isOpen(true);
			diagDownLeft->Calculatem_hDist(_end);
			_open->push_back(diagDownLeft);
		}
	}

	if (_front->Getm_xHeu() != 0)
	{
		node *left = &_grid->at(_front->Getm_yHeu()).at(_front->Getm_xHeu() - 1);
		if (left->Getm_isOpen() != true && left->Getm_isObject() != true)
		{
			left->Setm_parNode(_front);
			left->Setm_isOpen(true);
			left->Calculatem_hDist(_end);
			_open->push_back(left);
		}
	}

	if (_front->Getm_yHeu() != 0 && _front->Getm_xHeu() != 0)
	{
		node *diagUpLeft = &_grid->at(_front->Getm_yHeu() - 1).at(_front->Getm_xHeu() - 1);
		if (diagUpLeft->Getm_isOpen() != true && diagUpLeft->Getm_isObject() != true)
		{
			diagUpLeft->Setm_parNode(_front);
			diagUpLeft->Setm_isOpen(true);
			diagUpLeft->Calculatem_hDist(_end);
			_open->push_back(diagUpLeft);
		}
	}
}
