/// \file Dijkstras.h
/// \brief defines functions for Dijkstras 
/// \author Martin Dean

#ifndef _DIJKSTRAS_H_
#define _DJIKSTRAS_H_


#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include "pathgen.h"
#include "node.h"

std::vector<node*> Djikstras(std::vector<std::vector<node>> *_grid, node* _start);
void SearchNodesD(node *_front, std::vector<node*> *_open, std::vector<std::vector<node>> *_grid);
#endif //_DIJKSTRAS_H_