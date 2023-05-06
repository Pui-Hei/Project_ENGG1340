#include<cstdlib>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

//a simple clearscreen utility function to improve player experience
void clearScreen()
{
#ifdef WINDOWS
	std::system("cls");
#else

	std::system("clear");
#endif
	//from https://stackoverflow.com/questions/228617/how-do-i-clear-the-console-in-both-windows-and-linux-using-c
}
