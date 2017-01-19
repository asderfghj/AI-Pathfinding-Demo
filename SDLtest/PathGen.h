/// \file PathGen.h
/// \brief defines functions for path generation 
/// \author Martin Dean

#ifndef _PATHGEN_H_
#define _PATHGEN_H_
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "node.h"

std::vector<node*> GeneratePath(node *_endnode);
#endif //_PATHGEN_H_