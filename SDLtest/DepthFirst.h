/// \file DepthFirst.h
/// \brief defines functions for depth first
/// \author Martin Dean

#ifndef _DEPTHFIRST_H_
#define _DEPTHFIRST_H_
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "node.h"
#include "pathgen.h"

std::vector<node*> DepthFirst(std::vector<std::vector<node>> *_grid, node* _start);
void SearchNodes(node *_front, std::vector<node*> *_open, std::vector<std::vector<node>> *_grid);
#endif //_DEPTHFIRST_H_
