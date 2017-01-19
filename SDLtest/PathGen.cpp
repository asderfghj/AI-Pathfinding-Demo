///  @file PathGen.cpp
///  @brief The function to generate a path

#include "pathgen.h"

std::vector<node*> GeneratePath(node *_endnode)
{
	std::vector<node*> path;
	node* currentpathpoint;
	path.push_back(_endnode);
	currentpathpoint = path.front();
	while (currentpathpoint->Getm_startNode() != true && currentpathpoint->Getm_parNode() != NULL)
	{
		path.push_back(currentpathpoint->Getm_parNode());
		//currentpathpoint = path.front() - i; <--- Don't do that
		currentpathpoint = currentpathpoint->Getm_parNode();
	}
	return path;
}