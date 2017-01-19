/// \file BreadthFirst.h
/// \brief defines functions for Breadth First 
/// \author Martin Dean

#ifndef _BREADTHFIRST_H_
#define _BREADTHFIRST_H_
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include "node.h"
#include "pathgen.h"


std::vector<node*> BreadthFirst(std::vector<std::vector<node>> *_grid, node* _start);
void SearchNodes(node *_front, std::queue<node*> *_open, std::vector<std::vector<node>> *_grid);
#endif //_BREADTHFIRST_H_