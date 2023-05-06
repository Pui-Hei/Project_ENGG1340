#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <chrono>
#include "getch.h"
#include "gamemain.h"
#include "mapgentidy.h"
#include "helpSection.h"
#include "clearScreen.h"
using namespace std;
//This menu.cpp handles the user input to choose game mode, get help, see credits and to exit the game.

//This function is a sub-menu under main meun which allows players to choose game difficulty and load last saved game.
//Input is choice of player, and will be directed to different output options
void Playmenu(){
	int gamechoice;
	do{
		cout << "QiYi Klotski\n\n\n0. Play a 3*3 Game\n1. Play a 4*4 Game\n2. Play a 5*5 Game\n3. Play Last Saved game\n4. Return\n\n";

		cin >> gamechoice;
		switch (gamechoice)
		{
			case 0:
				cout << "You are playing 3 game\n";
				mapgen(3);
				gameMain("map.txt");
				break;
			case 1:
				cout << "You are playing 4 game\n";
				mapgen(4);
				gameMain("map.txt");
				break;
			case 2:
				cout << "You are playing 5 game\n";
				mapgen(5);
				gameMain("map.txt");
				break;
			case 3:
				cout << "you are playing last saved game\n";
				gameMain("last.txt");
				break;
			case 4:
				cout << "Returning Back to Main Menu\n";
				sleep(2);
				break;
		}
		clearScreen();
	} while (gamechoice != 4);
}




//this function shows the main menu, which handles user's input and allow them to choose from game, help, credits, and exit the game
//Input is choice of player, and will be directed to different output options
void Menu()
{
	int choice;

	do 
	{
		string empty;
		cout << "QiYi Klotski\n\n\n0. Play\n1. Help\n2. About us\n3. Exit\n\n";
		cin >> choice;
		clearScreen();
		switch (choice)
		{
			case 0:
				Playmenu();
				break;
			case 1:
				cout << "You're in the Help section\nInput 0 to Continue\n";

				cin>>empty;
				helpsection();
				clearScreen();
				break;
			case 2:
				cout << "by Chan Pui Hei, Hu Xiao Bang, Yu \n";
				cout << "Input 0 to Continue\n";
				cin>>empty;
				clearScreen();

				break;
			case 3:
				cout << "Closing application now...\nBye Bye!\n";
				sleep(2);

				break;
		}


	} while (choice != 3);

}

int main()
{
	//a brief introduction on the project
	cout<<"COMP1340 Group Project\n";
	sleep(1);
	cout<<"By Chan Pui Hei, Hu Xiao Bang, Yu\n";
	sleep(1);

	cout<<"Presenting: QiYi Klotski in C++\n";
	sleep(2);
	clearScreen();
	Menu();
}
