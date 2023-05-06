#include "clearScreen.h"
#include <iostream>
#include "getch.h"
using namespace std;
//this helpsection function outputs the rules of Qiyi Klotski for the player to understand the game
void helpsection()
{
	clearScreen();
	cout<<"There are three difficulty levels: 3 times 3, 4 times 4, and 5 times 5. "<<endl;
	cout<<"3 times 3 is a total of 9 squares, need to move 1 to 8 eight numbers; "<<endl;
	cout<<"4 times 4 is a total of 16 squares, need to move 1 to 15 fifteen numbers;"<<endl;
	cout<<"5 times 5 is a total of 25 squares, need to move 1 to 24 twenty-four numbers."<<endl;
	cout<<"Before introducing the steps, let's talk about the rules of the game, which are as follows:"<<endl;
	cout<<"1.The numbers are entirely disordered at the beginning."<<endl;
	cout<<"2.One number is moved at a time."<<endl;
	cout<<"3.All the numbers are restored in order in the end."<<endl;
	cout<<"Press Any Key to Continue."<<endl;
	char ch=getch();
	clearScreen();
	cout<<"Let's start with the simplest three-by-three to talk about the steps. "<<endl;
	cout<<"There are 9 squares, and then only eight of them hold the number boards, 1-8, with one space in them."<<endl;
	cout<<"We can slide the board around to change its position on the grid."<<endl;
	cout<<"If you move the number pad to a space, the original number pad becomes a space again,\n"<< "and you can move the number pad next to the space."<<endl;
	cout<<"The ultimate goal is to arrange the number boards in order from 1-8, \n"<<"top to bottom and left to right in order of number size by moving them around. "<<endl;
	cout<<"Of course, 3 by 3 is only a beginner's guide, and the difficulty level slowly increases.\n"<<" 4 by 4 and 5 by 5 are the rules, and so on."<<endl;
	cout<<"Press Any Key to Continue."<<endl;
	ch=getch();
	clearScreen();
	cout<<"A completed 3*3 Qiyi Klotski puzzle should have the following appearance:"<<endl;
	cout<<"1   2   3"<<endl;
	cout<<"4   5   6"<<endl;
	cout<<"7   8   X"<<endl;
	cout<<"Here you can visualize **X** as the empty space"<<endl;
	ch=getch();
	clearScreen();
	cout<<"During the game, You can use the WASD to control the **SPACE** up,left,down and right."<<endl;
	cout<<"The space will be presented as **X**"<<endl;
	cout<<"If you want to quit the game, just press Q"<<endl;
	cout<<"If you want to see the help section again, you can press H"<<endl;
	cout<<"Thank you for reading the help section, you can quit it by pressing any key."<<endl;
	ch=getch();
	return;
}
