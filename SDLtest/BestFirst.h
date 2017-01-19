/// \file BestFirst.h
/// \brief defines functions for Best First 
/// \author Martin Dean

#ifndef _BESTFIRST_H_
#define _BESTFIRST_H_

#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include "pathgen.h"
#include "node.h"

std::vector<node*> BestFirst(std::vector<std::vector<node>> *_grid, node* _start, node* _end);
void SearchNodesBF(node *_front, std::vector<node*> *_open, std::vector<std::vector<node>> *_grid, node* _end);
#endif //_BESTFIRST_H_