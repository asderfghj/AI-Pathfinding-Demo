/// \file Node.h
/// \brief defines node class
/// \author Martin Dean

#ifndef _NODE_H_
#define _NODE_H_
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <vector>


class node
{
public:
	node();
	~node();
	int Getm_xHeu();
	void Setm_xHeu(int _x);
	int Getm_yHeu();
	void Setm_yHeu(int _y);
	int Getm_x();
	void Setm_x(int _x);
	int Getm_y();
	void Setm_y(int _y);
	node* Getm_parNode();
	void Setm_parNode(node *_pNode);
	bool Getm_isOpen();
	void Setm_isOpen(bool _isOpen);
	bool Getm_explored();
	void Setm_explored(bool _explored);
	bool Getm_startNode();
	void Setm_startNode(bool _start);
	bool Getm_endNode();
	void Setm_endNode(bool _end);
	bool Getm_isObject();
	void Setm_isObject(bool _isObject);
	void Calculatem_hDist(node *_endnode);
	float Getm_hDist();
	void Calculatem_gDist(node *_parent, float _addValue);
	float Getm_gDist();
	void Calculatem_fDist();
	float Getm_fDist();



private:
	int m_xHeu;
	int m_yHeu;
	int m_x;
	int m_y;
	node *m_parNode;
	bool m_isOpen;
	bool m_explored;
	bool m_startNode;
	bool m_endNode;
	bool m_isObject;
	float m_hDist;
	float m_gDist;
	float m_fDist;
};
#endif //_NODE_H_
