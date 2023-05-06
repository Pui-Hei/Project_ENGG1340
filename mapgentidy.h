#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include<iostream>
#include<fstream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

//a header file to enable easy access to the function mapgentidy

using namespace std;
struct block{};
block * headInsert (block *h, int v);
int replace(block *head, int v, int step);
void swap (int x, int y, int direction, int size, block *head);
void runlist (block *head);
void exportmap(block *head, int s);
void mapgen(int size);
