///  @file Node.cpp
///  @brief The functions for the node class

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstdlib>
#include "node.h"


node::node()
{
	m_xHeu = NULL;
	m_yHeu = NULL;
	m_x = NULL;
	m_y = NULL;
	m_parNode = nullptr;
	m_isOpen = false;
	m_explored = false;
	m_startNode = false;
	m_endNode = false;
	m_isObject = false;
	m_hDist = NULL;
	m_gDist = 0;
	m_fDist = 0;
}

node::~node()
{
}

int node::Getm_xHeu()
{
	return m_xHeu;
}

void node::Setm_xHeu(int _x)
{
	m_xHeu = _x;
}

int node::Getm_yHeu()
{
	return m_yHeu;
}

void node::Setm_yHeu(int _y)
{
	m_yHeu = _y;
}

int node::Getm_x()
{
	return m_x;
}

void node::Setm_x(int _x)
{
	m_x = _x;
}

int node::Getm_y()
{
	return m_y;
}

void node::Setm_y(int _y)
{
	m_y = _y;
}

node* node::Getm_parNode()
{
	return m_parNode;
}

void node::Setm_parNode(node *_pnode)
{
	m_parNode = _pnode;
}


bool node::Getm_isOpen() 
{
	return m_isOpen;
}

void node::Setm_isOpen(bool _isOpen)
{
	m_isOpen = _isOpen;
}

bool node::Getm_explored()
{
	return m_explored;
}

void node::Setm_explored(bool _explored)
{
	m_explored = _explored;
}

bool node::Getm_startNode()
{
	return m_startNode;
}

void node::Setm_startNode(bool _start)
{
	m_startNode = _start;
}

bool node::Getm_endNode()
{
	return m_endNode;
}

void node::Setm_endNode(bool _end)
{
	m_endNode = _end;
}

bool node::Getm_isObject()
{
	return m_isObject;
}


void node::Setm_isObject(bool _isOpen)
{
	m_isObject = _isOpen;
}

void node::Calculatem_hDist(node *_endnode)
{
	float xdif, ydif;
	xdif = std::abs(m_xHeu - _endnode->Getm_xHeu());

	ydif = std::abs(m_yHeu - _endnode->Getm_yHeu());

	
	m_hDist = xdif + ydif;
}

float node::Getm_hDist()
{
	return m_hDist;
}

void node::Calculatem_gDist(node *_parent, float _addvalue)
{
	m_gDist = _parent->Getm_gDist() + _addvalue;
}

float node::Getm_gDist()
{
	return m_gDist;
}

void node::Calculatem_fDist()
{
	m_fDist = m_gDist + m_hDist;
}

float node::Getm_fDist()
{
	return m_fDist;
}