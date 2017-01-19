/// \file AStar.h
/// \brief defines functions for a* 
/// \author Martin Dean

#ifndef _ASTAR_H_
#define _ASTAR_H_


#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include "pathgen.h"
#include "node.h"


std::vector<node*> AStar(std::vector<std::vector<node>> *_grid, node* _start, node* _end);
void SearchNodesAS(node *_front, std::vector<node*> *_open, std::vector<node*> *_closed, std::vector<std::vector<node>> *_grid, node* _end);
void OpenCheck(node* _checkNode, node* _front, int _value, node* _end);
void ClosedCheck(node* _checknode, node* _front, int _value, node* _end, std::vector<node*> *_open, std::vector<node*> *_closed);
#endif //_ASTAR_H_