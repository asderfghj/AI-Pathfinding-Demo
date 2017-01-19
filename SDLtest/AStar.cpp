///  @file AStar.cpp
///  @brief The functions to make a path using A*

#include "AStar.h"

//compares f distances of two nodes for sorting 
struct less_that_Fdistance
{
	inline bool operator() (node* node1, node* node2)
	{
		return(node1->Getm_fDist() < node2->Getm_fDist());
	}
};


//entry function for A*
std::vector<node*> AStar(std::vector<std::vector<node>> *_grid, node* _start, node* _end)
{
	std::vector<node*> open;
	std::vector<node*> closed;
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
			SearchNodesAS(open.front(), &open, &closed, _grid, _end);
			open.front()->Setm_isOpen(false);
			open.front()->Setm_explored(true);
			closed.push_back(open.front());
			open.erase(open.begin());
		}
		std::sort(open.begin(), open.end(), less_that_Fdistance());
	}
	return path;
}



void SearchNodesAS(node *_front, std::vector<node*> *_open, std::vector<node*> *_closed, std::vector<std::vector<node>> *_grid, node* _end)
{
	if (_front->Getm_yHeu() != 0)
	{
		node *above = &_grid->at(_front->Getm_yHeu() - 1).at(_front->Getm_xHeu());
		OpenCheck(above, _front, 10, _end);
		ClosedCheck(above, _front, 10, _end, _open, _closed);
		if (above->Getm_isOpen() != true && above->Getm_explored() != true && above->Getm_isObject() != true)
		{
			above->Setm_parNode(_front);
			above->Setm_isOpen(true);
			above->Calculatem_hDist(_end);
			above->Calculatem_gDist(above->Getm_parNode(), 10);
			above->Calculatem_fDist();
			_open->push_back(above);
		}
	}

	if (_front->Getm_yHeu() != 0 && _front->Getm_xHeu() != 29)
	{
		node *diagUpRight = &_grid->at(_front->Getm_yHeu() - 1).at(_front->Getm_xHeu() + 1);
		OpenCheck(diagUpRight, _front, 14, _end);
		ClosedCheck(diagUpRight, _front, 14, _end, _open, _closed);
		if (diagUpRight->Getm_isOpen() != true && diagUpRight->Getm_explored() != true && diagUpRight->Getm_isObject() != true)
		{
			diagUpRight->Setm_parNode(_front);
			diagUpRight->Setm_isOpen(true);
			diagUpRight->Calculatem_hDist(_end);
			diagUpRight->Calculatem_gDist(diagUpRight->Getm_parNode(), 14);
			diagUpRight->Calculatem_fDist();
			_open->push_back(diagUpRight);
		}
	}

	if (_front->Getm_xHeu() != 29)
	{
		node *right = &_grid->at(_front->Getm_yHeu()).at(_front->Getm_xHeu() + 1);
		OpenCheck(right, _front, 10, _end);
		ClosedCheck(right, _front, 10, _end, _open, _closed);
		if (right->Getm_isOpen() != true && right->Getm_explored() != true && right->Getm_isObject() != true)
		{
			right->Setm_parNode(_front);
			right->Setm_isOpen(true);
			right->Calculatem_hDist(_end);
			right->Calculatem_gDist(right->Getm_parNode(), 10);
			right->Calculatem_fDist();
			_open->push_back(right);
		}
	}

	if (_front->Getm_yHeu() != 30 && _front->Getm_xHeu() != 29)
	{
		node *diagDownRight = &_grid->at(_front->Getm_yHeu() + 1).at(_front->Getm_xHeu() + 1);
		OpenCheck(diagDownRight, _front, 14, _end);
		ClosedCheck(diagDownRight, _front, 14, _end, _open, _closed);
		if (diagDownRight->Getm_isOpen() != true && diagDownRight->Getm_explored() != true && diagDownRight->Getm_isObject() != true)
		{
			diagDownRight->Setm_parNode(_front);
			diagDownRight->Setm_isOpen(true);
			diagDownRight->Calculatem_hDist(_end);
			diagDownRight->Calculatem_gDist(diagDownRight->Getm_parNode(), 10);
			diagDownRight->Calculatem_fDist();
			_open->push_back(diagDownRight);
		}
	}

	if (_front->Getm_yHeu() != 30)
	{
		node *down = &_grid->at(_front->Getm_yHeu() + 1).at(_front->Getm_xHeu());
		OpenCheck(down, _front, 10, _end);
		ClosedCheck(down, _front, 10, _end, _open, _closed);
		if (down->Getm_isOpen() != true && down->Getm_explored() != true && down->Getm_isObject() != true)
		{
			down->Setm_parNode(_front);
			down->Setm_isOpen(true);
			down->Calculatem_hDist(_end);
			down->Calculatem_gDist(down->Getm_parNode(), 10);
			down->Calculatem_fDist();
			_open->push_back(down);
		}
	}

	if (_front->Getm_yHeu() != 30 && _front->Getm_xHeu() != 0)
	{
		node *diagDownLeft = &_grid->at(_front->Getm_yHeu() + 1).at(_front->Getm_xHeu() - 1);
		OpenCheck(diagDownLeft, _front, 14, _end);
		ClosedCheck(diagDownLeft, _front, 14, _end, _open, _closed);
		if (diagDownLeft->Getm_isOpen() != true && diagDownLeft->Getm_explored() != true && diagDownLeft->Getm_isObject() != true)
		{
			diagDownLeft->Setm_parNode(_front);
			diagDownLeft->Setm_isOpen(true);
			diagDownLeft->Calculatem_hDist(_end);
			diagDownLeft->Calculatem_gDist(diagDownLeft->Getm_parNode(), 14);
			diagDownLeft->Calculatem_fDist();
			_open->push_back(diagDownLeft);
		}
	}

	if (_front->Getm_xHeu() != 0)
	{
		node *left = &_grid->at(_front->Getm_yHeu()).at(_front->Getm_xHeu() - 1);
		OpenCheck(left, _front, 10, _end);
		ClosedCheck(left, _front, 10, _end, _open, _closed);
		if (left->Getm_isOpen() != true && left->Getm_explored() != true && left->Getm_isObject() != true)
		{
			left->Setm_parNode(_front);
			left->Setm_isOpen(true);
			left->Calculatem_hDist(_end);
			left->Calculatem_gDist(left->Getm_parNode(), 10);
			left->Calculatem_fDist();
			_open->push_back(left);
		}
	}

	if (_front->Getm_yHeu() != 0 && _front->Getm_xHeu() != 0)
	{
		node *diagUpLeft = &_grid->at(_front->Getm_yHeu() - 1).at(_front->Getm_xHeu() - 1);
		OpenCheck(diagUpLeft, _front, 14, _end);
		ClosedCheck(diagUpLeft, _front, 14, _end, _open, _closed);
		if (diagUpLeft->Getm_isOpen() != true && diagUpLeft->Getm_explored() != true && diagUpLeft->Getm_isObject() != true)
		{
			diagUpLeft->Setm_parNode(_front);
			diagUpLeft->Setm_isOpen(true);
			diagUpLeft->Calculatem_hDist(_end);
			diagUpLeft->Calculatem_gDist(diagUpLeft->Getm_parNode(), 14);
			diagUpLeft->Calculatem_fDist();
			_open->push_back(diagUpLeft);
		}
	}
}

void OpenCheck(node* checknode, node* front, int value, node* end)
{
	if (checknode->Getm_isOpen() == true)
	{
		if (front->Getm_gDist() + value < checknode->Getm_gDist())
		{
			checknode->Setm_parNode(front);
			checknode->Calculatem_hDist(end);
			checknode->Calculatem_gDist(checknode->Getm_parNode(), value);
			checknode->Calculatem_fDist();
		}

	}
}

void ClosedCheck(node* checknode, node* front, int value, node* end, std::vector<node*> *open, std::vector<node*> *closed)
{
	if (checknode->Getm_explored() == true)
	{
		if (front->Getm_gDist() + value < checknode->Getm_gDist())
		{
			bool found = false;
			int i = 0;
			while (found == false)
			{
				if (closed->at(i)->Getm_xHeu() == checknode->Getm_xHeu() && closed->at(i)->Getm_yHeu() == checknode->Getm_yHeu())
				{
					closed->erase(closed->begin() + i);
					found = true;
				}
				else
				{
					i++;
				}
			}
			checknode->Setm_parNode(front);
			checknode->Setm_isOpen(true);
			checknode->Setm_explored(false);
			checknode->Calculatem_hDist(end);
			checknode->Calculatem_gDist(checknode->Getm_parNode(), value);
			checknode->Calculatem_fDist();
			open->push_back(checknode);
		}
	}
}