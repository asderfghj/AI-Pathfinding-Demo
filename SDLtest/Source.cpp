///  @file Source.cpp
///  @brief The main loop of the program

#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "node.h"
#include "breadthfirst.h"
#include "depthfirst.h"
#include "bestfirst.h"
#include "dijkstras.h"
#include "AStar.h"
#undef main

const int SCREEN_WIDTH = 658;
const int SCREEN_HEIGHT = 658;

bool Init();

void Close();

void InitialiseGrid(SDL_Rect *_nodeDr, std::vector<std::vector<node>> *_grid);

void DrawGrid(SDL_Rect *_nodeDr, std::vector<std::vector<node>> *_grid);

void DrawPath(std::vector<node*> _path);

void RenderStartAndEnd(node* _start, node* _end, SDL_Rect *_nodeDr);

void RunProg();

bool Restart();

SDL_Window* g_window = NULL;

SDL_Renderer* g_renderer = NULL;

int main( int argc, char* args[] )
{
	if( !Init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{	
		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}
			printf("CONTROLS (Please Read)\n");
			printf("(1) Will run Breadth First when pathfinding (will notify)\n");
			printf("(2) Will run Depth First (with search limit of 43) when pathfinding (will notify)\n");
			printf("(3) Will run Best First when pathfinding (will notify)\n");
			printf("(4) Will run Dijkstra's when pathfinding (will notify)\n");
			printf("(5) Will run A* when pathfinding (will notify)\n");
			printf("(s) Will place start node on clicked square\n");
			printf("(g) Will place goal node on clicked square\n");
			printf("(w) Will place a wall on the clicked square (click again to delete the wall)\n");
			printf("After placing everything press enter to view path\n");
			printf("After path is created press enter to be prompted on restart\n");
			RunProg();

			quit = Restart();
		}
	}

	Close();

	return 0;
}

bool Init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		g_window = SDL_CreateWindow("AI Pathfinding", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (g_window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
			if (g_renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
		}
	}

	return success;
}

void Close()
{

	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);
	g_window = NULL;
	g_renderer = NULL;

	SDL_Quit();
}

void InitialiseGrid(SDL_Rect *_nodeDr, std::vector<std::vector<node>> *_grid)
{
	node *tnode;
	std::vector<node> *temp;
	for (int i = 0; i < 31; i++)// y loop
	{
		temp = new std::vector<node>;
		for (int j = 0; j < 30; j++)// x loop
		{
			tnode = new node;
			_nodeDr->x = j * 22;
			tnode->Setm_x(_nodeDr->x);
			tnode->Setm_y(_nodeDr->y);
			tnode->Setm_xHeu(j);
			tnode->Setm_yHeu(i);
			temp->push_back(*tnode);
			delete tnode;
		}
		if (i != 30)
		{
			_nodeDr->x = 0;
			_nodeDr->y = i * 22;
		}
		_grid->push_back(*temp);
		delete temp;
	}
}

void DrawGrid(SDL_Rect *_nodeDr, std::vector<std::vector<node>> *_grid)
{
	_nodeDr->w = 20;
	_nodeDr->h = 20;
	_nodeDr->x = 0;
	_nodeDr->y = 0;



	for (int i = 0; i < 31; i++)// y loop
	{
		for (int j = 0; j < 30; j++)// x loop
		{
			_nodeDr->x = _grid->at(i).at(j).Getm_x();
			if (_grid->at(i).at(j).Getm_isObject() == true)
			{
				SDL_SetRenderDrawColor(g_renderer, 0x00, 0x00, 0x00, 0xff);
			}
			else
			{
				SDL_SetRenderDrawColor(g_renderer, 0x73, 0x73, 0x73, 0xff);
			}
			SDL_RenderFillRect(g_renderer, _nodeDr);
		}
		if (i != 30)
		{
			_nodeDr->x = 0;
			_nodeDr->y = i * 22;
			SDL_RenderFillRect(g_renderer, _nodeDr);
		}
	}

}

void DrawPath(std::vector<node*> _path)
{
	SDL_Rect nodeDrawer;
	nodeDrawer.w = 20;
	nodeDrawer.h = 20;
	node* currentpathpoint;
	currentpathpoint = _path.front();
	int i = 1;
	SDL_SetRenderDrawColor(g_renderer, 0x6f, 0xce, 0xff, 0xff);
	for (int i = _path.size()-1; i >= 0; i--)
	{
		nodeDrawer.x = _path.at(i)->Getm_x();
		nodeDrawer.y = _path.at(i)->Getm_y();
		SDL_RenderFillRect(g_renderer, &nodeDrawer);
	}

}

void RenderStartAndEnd(node* _start, node* _end, SDL_Rect *_nodeDr)
{
	if (_start != NULL)
	{
		SDL_SetRenderDrawColor(g_renderer, 0x00, 0xff, 0x00, 0xff);
		_nodeDr->x = _start->Getm_x();
		_nodeDr->y = _start->Getm_y();
		SDL_RenderFillRect(g_renderer, _nodeDr);
	}
	if (_end != NULL)
	{
		SDL_SetRenderDrawColor(g_renderer, 0xff, 0x00, 0x00, 0xff);
		_nodeDr->x = _end->Getm_x();
		_nodeDr->y = _end->Getm_y();
		SDL_RenderFillRect(g_renderer, _nodeDr);
	}
}

void RunProg()
{
	bool quit = false, end = false, startplaced = false, endplaced = false, wallcomplete = false, startbrush = true, goalbrush = false, wallbrush = false, runbreadth = true, rundepth = false, runbest = false, rundijk = false, runastar = false;
	SDL_Event e;
	SDL_Rect nodeDrawer;
	std::vector<node*> path;

	std::vector<std::vector<node>> Grid;
	node *nodeStart = NULL;
	node *nodeEnd = NULL;
	int X = 0;
	InitialiseGrid(&nodeDrawer, &Grid);

	while (!quit && !end)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (startbrush == true && wallcomplete == false)
				{
					if (nodeStart != NULL)
					{
						nodeStart->Setm_startNode(false);
					}
					nodeStart = &Grid.at(floor(e.button.y / 22 + 1)).at(floor(e.button.x / 22));
					nodeStart->Setm_startNode(true);
					startplaced = true;
				}
				else if (goalbrush == true && wallcomplete == false)
				{
					if (nodeEnd != NULL)
					{
						nodeEnd->Setm_endNode(false);
					}
					nodeEnd = &Grid.at(floor(e.button.y / 22) + 1).at(floor(e.button.x / 22));
					nodeEnd->Setm_endNode(true);
					endplaced = true;
				}
				else if (wallbrush == true && wallcomplete == false)
				{
					if (Grid.at((floor(e.button.y / 22)) + 1).at(floor(e.button.x / 22)).Getm_isObject() == true)
					{
						Grid.at((floor(e.button.y / 22)) + 1).at(floor(e.button.x / 22)).Setm_isObject(false);
					}
					else if (Grid.at((floor(e.button.y / 22)) + 1).at(floor(e.button.x / 22)).Getm_isObject() == false)
					{
						Grid.at((floor(e.button.y / 22)) + 1).at(floor(e.button.x / 22)).Setm_isObject(true);
					}
				}
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
					case SDLK_RETURN:
					{
						if (wallcomplete == false)
						{
							if (startplaced == true && endplaced == true)
							{
								wallcomplete = true;
								system("CLS");
							}
							else if (startplaced == true && endplaced == false)
							{
								printf("You need to place an end node\n");
							}
							else if (startplaced == false && endplaced == true)
							{
								printf("You need to place an start node\n");
							}
							else if (startplaced == false && endplaced == false)
							{
								printf("You need to place a start and end node\n");
							}
						}
						else if (wallcomplete == true)
						{
							end = true;
						}
						break;
					}
					case SDLK_s:
					{
						startbrush = true;
						goalbrush = false;
						wallbrush = false;
						break;
					}
					case SDLK_g:
					{
						startbrush = false;
						goalbrush = true;
						wallbrush = false;
						break;
					}
					case SDLK_w:
					{
						startbrush = false;
						goalbrush = false;
						wallbrush = true;
						break;
					}
					case SDLK_1:
					{
						if (wallcomplete == false)
						{
							runbreadth = true;
							rundepth = false;
							runbest = false;
							rundijk = false;
							runastar = false;
							printf("BREADTH FIRST ACTIVE\n");
						}
						break;
					}
					case SDLK_2:
					{
						if (wallcomplete == false)
						{
							runbreadth = false;
							rundepth = true;
							runbest = false;
							rundijk = false;
							runastar = false;
							printf("DEPTH FIRST ACTIVE\n");
						}
						break;
					}
					case SDLK_3:
					{
						if (wallcomplete == false)
						{
							runbreadth = false;
							rundepth = false;
							runbest = true;
							rundijk = false;
							runastar = false;
							printf("BEST FIRST ACTIVE\n");
						}
						break;
					}
					case SDLK_4:
					{
						if (wallcomplete == false)
						{
							runbreadth = false;
							rundepth = false;
							runbest = false;
							rundijk = true;
							runastar = false;
							printf("DIJKSTRA'S ACTIVE\n");
						}
						break;
					}
					case SDLK_5:
					{
						if (wallcomplete == false)
						{
							runbreadth = false;
							rundepth = false;
							runbest = false;
							rundijk = false;
							runastar = true;
							printf("A* ACTIVE\n");
						}
						break;
					}
				}
			}
		}

		SDL_SetRenderDrawColor(g_renderer, 0x00, 0x00, 0x00, 0xff);
		SDL_RenderClear(g_renderer);
		DrawGrid(&nodeDrawer, &Grid);

		if (wallcomplete == true)
		{
			if (X == 0)
			{
				if (runbreadth == true)
				{
					path = BreadthFirst(&Grid, nodeStart);
				}
				else if (rundepth == true)
				{
					path = DepthFirst(&Grid, nodeStart);
				}
				else if (runbest == true)
				{
					path = BestFirst(&Grid, nodeStart, nodeEnd);
				}
				else if (rundijk == true)
				{
					path = Djikstras(&Grid, nodeStart);
				}
				else if (runastar == true)
				{
					path = AStar(&Grid, nodeStart, nodeEnd);
				}
				X++;
			}

			if (X == 1 && path.size() == 0)
			{
				printf("Path cannot be found, please try again\n");
				X++;
			}
			else if (X > 0 && path.size() > 0)
			{
				DrawPath(path);
			}

		}

		RenderStartAndEnd(nodeStart, nodeEnd, &nodeDrawer);
		//how to draw to a single space on a grid. This should help...
		/*SDL_SetRenderDrawColor(g_renderer, 0x00, 0xff, 0x00, 0xff);

		node *nodus = &gGrid[30][29];//grid[y][x]

		nodeDrawer.x = nodus->getmX();
		nodeDrawer.y = nodus->getmY();
		SDL_RenderFillRect(g_renderer, &nodeDrawer);*/

		SDL_RenderPresent(g_renderer);

	}
}

bool Restart()
{
	bool quit = false, decision = false, restartvalue = false;
	int X = 0;
	SDL_Event e;
	while (!quit && !decision)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
					case SDLK_y:
					{
						restartvalue = false;
						decision = true;
						break;
					}
					case SDLK_n:
					{
						restartvalue = true;
						decision = true;
						break;
					}
				
				}

			}
		}
		if (X == 0)
		{
			printf("Restart?(y/n)");
			X++;
		}
	}
	system("CLS");
	return restartvalue;
}