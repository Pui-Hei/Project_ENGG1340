#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <chrono>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;
//This menu.cpp handles the user input to choose game mode, get help, see credits and to exit the game.

//a simple function copied from stackoverflow to clear screen
void clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    
    std::system ("clear");
#endif
//from https://stackoverflow.com/questions/228617/how-do-i-clear-the-console-in-both-windows-and-linux-using-c
}


void mapgen(int x){
    cout<<"mapgen of"<<x;
    Sleep(1000);
    
}

//This function is a sub-menu under main meun which allows players to choose game difficulty and load last saved game
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
    			break;
    		case 1:
    			cout << "You are playing 4 game\n";
                mapgen(4);
    			break;
            case 2:
    			cout << "You are playing 4 game\n";
                mapgen(5);
    			break;
            case 3:
                cout << "you are playing last saved game\n";
                break;
    		case 4:
                cout << "Returning Back to Main Menu\n";
                Sleep(2000);
                break;
            }
        clear_screen();
    } while (gamechoice != 4);
}




//this function shows the main menu, which handles user's input and allow them to choose from game, help, credits, and exit the game
void Menu()
{
	int choice;
    
	do 
	{
        string empty;
		cout << "QiYi Klotski\n\n\n0. Play\n1. Help\n2. About us\n3. Exit\n\n";
		cin >> choice;
        clear_screen();
		switch (choice)
		{
		case 0:
			Playmenu();
			break;
		case 1:
			cout << "You're in the Help section\nInput 0 to Continue\n";
            
            cin>>empty;
            clear_screen();
			break;
		case 2:
			cout << "by Chan Pui Hei, Hu Xiao Bang, Yu \n";
            cout << "Input 0 to Continue\n";
            cin>>empty;
            clear_screen();
            
			break;
		case 3:
            cout << "Closing application now...\nBye Bye!\n";
            Sleep(2000);
			
			break;
		}


	} while (choice != 3);
	
}

int main()
{
    //a brief introduction on the project
    cout<<"COMP1340 Group Project\n";
    Sleep(1000);
    cout<<"By Chan Pui Hei, Hu Xiao Bang, Yu\n";
    Sleep(1000);
    
    cout<<"Presenting: QiYi Klotski in C++\n";
    Sleep(2000);
    clear_screen();
	Menu();
}