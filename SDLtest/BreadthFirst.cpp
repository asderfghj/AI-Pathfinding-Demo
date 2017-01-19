///  @file BreadthFirst.cpp
///  @brief The functions to make a path using breadth first

#include "breadthfirst.h"

std::vector<node*> BreadthFirst(std::vector<std::vector<node>> *_grid, node* _start)
{
	std::queue<node*> open;
	std::vector<node*> path;
	bool goal = false;
	open.push(_start);

	while (goal == false && open.size() > 0)
	{
		if (open.front()->Getm_endNode() == true)
		{
			goal = true;
			path = GeneratePath(open.front());
		}
		else 
		{
			SearchNodes(open.front(), &open, _grid);
			open.pop();
		}
	}

	return path;
}


void SearchNodes(node *_front, std::queue<node*> *_open, std::vector<std::vector<node>> *_grid)
{
	if (_front->Getm_yHeu() != 0)
	{
		node *above = &_grid->at(_front->Getm_yHeu() - 1).at(_front->Getm_xHeu());
		if (above->Getm_isOpen() != true && above->Getm_isObject() != true)
		{
			above->Setm_parNode(_front);
			above->Setm_isOpen(true);
			_open->push(above);
		}
	}

	if (_front->Getm_yHeu() != 0 && _front->Getm_xHeu() != 29)
	{
		node *diagUpRight = &_grid->at(_front->Getm_yHeu() - 1).at(_front->Getm_xHeu() + 1);
		if (diagUpRight->Getm_isOpen() != true && diagUpRight->Getm_isObject() != true)
		{
			diagUpRight->Setm_parNode(_front);
			diagUpRight->Setm_isOpen(true);
			_open->push(diagUpRight);
		}
	}

	if (_front->Getm_xHeu() != 29)
	{
		node *right = &_grid->at(_front->Getm_yHeu()).at(_front->Getm_xHeu() + 1);
		if (right->Getm_isOpen() != true && right->Getm_isObject() != true)
		{
			right->Setm_parNode(_front);
			right->Setm_isOpen(true);
			_open->push(right);
		}
	}

	if (_front->Getm_yHeu() != 30 && _front->Getm_xHeu() != 29)
	{
		node *diagDownRight = &_grid->at(_front->Getm_yHeu() + 1).at(_front->Getm_xHeu() + 1);
		if (diagDownRight->Getm_isOpen() != true && diagDownRight->Getm_isObject() != true)
		{
			diagDownRight->Setm_parNode(_front);
			diagDownRight->Setm_isOpen(true);
			_open->push(diagDownRight);
		}
	}

	if (_front->Getm_yHeu() != 30)
	{
		node *down = &_grid->at(_front->Getm_yHeu() + 1).at(_front->Getm_xHeu());
		if (down->Getm_isOpen() != true && down->Getm_isObject() != true)
		{
			down->Setm_parNode(_front);
			down->Setm_isOpen(true);
			_open->push(down);
		}
	}
	
	if (_front->Getm_yHeu() != 30 && _front->Getm_xHeu() != 0)
	{
		node *diagDownLeft = &_grid->at(_front->Getm_yHeu() + 1).at(_front->Getm_xHeu() - 1);
		if (diagDownLeft->Getm_isOpen() != true && diagDownLeft->Getm_isObject() != true)
		{
			diagDownLeft->Setm_parNode(_front);
			diagDownLeft->Setm_isOpen(true);
			_open->push(diagDownLeft);
		}
	}

	if (_front->Getm_xHeu() != 0)
	{
		node *left = &_grid->at(_front->Getm_yHeu()).at(_front->Getm_xHeu() - 1);
		if (left->Getm_isOpen() != true && left->Getm_isObject() != true)
		{
			left->Setm_parNode(_front);
			left->Setm_isOpen(true);
			_open->push(left);
		}
	}

	if (_front->Getm_yHeu() != 0 && _front->Getm_xHeu() != 0)
	{
		node *diagUpLeft = &_grid->at(_front->Getm_yHeu() - 1).at(_front->Getm_xHeu() - 1);
		if (diagUpLeft->Getm_isOpen() != true && diagUpLeft->Getm_isObject() != true)
		{
			diagUpLeft->Setm_parNode(_front);
			diagUpLeft->Setm_isOpen(true);
			_open->push(diagUpLeft);
		}
	}
}