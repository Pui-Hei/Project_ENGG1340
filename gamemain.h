#include <iostream>
#include <fstream>
#include <cmath>
#include "getch.h"
#include "helpSection.h"
#include "clearScreen.h"
#include <cstdlib>
#include <algorithm>
#include <vector>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;
//headerfile for gamemain,cpp
void clearScreen();
struct node{};
bool loadGame(string gameName,vector<node*> &mp,node* &st);
void endGame(vector<node*> &V);
void dfs(node* st,int x,int y,int len,int* &mp);
void printmp(vector<node*> &V,node* st);
bool checkWin(vector<node*> &V,node *st);
void saveGame(vector<node*> &V,node* st);
void gameMain(string gameName);
