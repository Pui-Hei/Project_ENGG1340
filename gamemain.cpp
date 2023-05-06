#include <iostream>
#include <fstream>
#include <cmath>
#include "getch.h"
#include "helpSection.h"
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "clearScreen.h"
using namespace std;
//define a required structure node so that it can be used later
struct node
{
	node *down;
	node *up;
	node *left;
	node *right;
	int value;
	node()
	{
		up=down=left=right=NULL;
		value=0;
	}
};
//opens up a game from an existing text file. The destination can be specificed. Then, convert the information in text file into a playable map.
//idestut is the directory, output is the status:whether the game is loaded or not
bool loadGame(string gameName,vector<node*> &mp,node* &st)
{
	ifstream fin;
	fin.open(gameName);
	if (fin.fail()) return 0;
	else
	{
		vector<int> MP;
		int tmp;
		while(fin>>tmp)
		{
			MP.push_back(tmp);
		}
		fin.close();
		if (MP.size()==9)
		{
			for (int i=0;i<9;i++)
			{
				mp.push_back(new node);
			}
			for (int i=0;i<9;i++)
			{
				mp[i]->value=MP[i];
			}
			for (int i=0;i<3;i++)
			{
				for (int j=0;j<3;j++)
				{
					int pos=i*3+j;
					if (i!=0)
					{
						mp[pos]->up=mp[pos-3];
					}
					if (j!=0)
					{
						mp[pos]->left=mp[pos-1];
					}
					if (i!=2)
					{
						mp[pos]->down=mp[pos+3];
					}
					if (j!=2)
					{
						mp[pos]->right=mp[pos+1];
					}
				}
			}
		}
		if (MP.size()==16)
		{
			for (int i=0;i<16;i++)
			{
				mp.push_back(new node);
			}
			for (int i=0;i<16;i++)
			{
				mp[i]->value=MP[i];
			}
			for (int i=0;i<4;i++)
			{
				for (int j=0;j<4;j++)
				{
					int pos=i*4+j;
					if (i!=0)
					{
						mp[pos]->up=mp[pos-4];
					}
					if (j!=0)
					{
						mp[pos]->left=mp[pos-1];
					}
					if (i!=3)
					{
						mp[pos]->down=mp[pos+4];
					}
					if (j!=3)
					{
						mp[pos]->right=mp[pos+1];
					}
				}
			}
		}
		if (MP.size()==25)
		{
			for (int i=0;i<25;i++)
			{
				mp.push_back(new node);
			}
			for (int i=0;i<25;i++)
			{
				mp[i]->value=MP[i];
			}
			for (int i=0;i<5;i++)
			{
				for (int j=0;j<5;j++)
				{
					int pos=i*5+j;
					if (i!=0)
					{
						mp[pos]->up=mp[pos-5];
					}
					if (j!=0)
					{
						mp[pos]->left=mp[pos-1];
					}
					if (i!=4)
					{
						mp[pos]->down=mp[pos+5];
					}
					if (j!=4)
					{
						mp[pos]->right=mp[pos+1];
					}
				}
			}
		}
		for (int i=0;i<mp.size();i++)
		{
			if (mp[i]->value==-1) st=mp[i];
		}
		return 1;
	}
}
//this function removes the game vector and frees up the current game procedure, allowing the next new map to be initialized properly
void endGame(vector<node*> &MP)
{
	for (int i=0;i<MP.size();i++)
	{
		delete MP[i];
	}
	return;
}
//this function uses depth first search(DFS) to traversal the whole map which is saved by linked lists.
//and it will put the values into the right position of the real map
void dfs(node* now,int x,int y,int len,int* &mp)
{
	int pos=x*len+y;
	if ((mp[pos])!=0)
	{
		return;
	}
	mp[pos]=now->value;
	if (x!=0)
	{
		dfs(now->up,x-1,y,len,mp);
	}
	if (y!=0)
	{
		dfs(now->left,x,y-1,len,mp);
	}
	if (x!=len-1)
	{
		dfs(now->down,x+1,y,len,mp);
	}
	if (y!=len-1)
	{
		dfs(now->right,x,y+1,len,mp);
	}
	return;
}
//This functions prints the current Klotski game puzzle for the player to view
void printmp(vector<node*> &MP,node* st)
{
	node *W=st->up,*A=st->left,*S=st->down,*D=st->right;
	int cntW=0,cntA=0,cntS=0,cntD=0;
	while(W!=NULL)
	{
		cntW++;
		W=W->up;
	}
	while(A!=NULL)
	{
		cntA++;
		A=A->left;
	}
	while(S!=NULL)
	{
		cntS++;
		S=S->down;
	}
	while(D!=NULL)
	{
		cntD++;
		D=D->right;
	}
	int len=(int)sqrt(MP.size());
	int* mp=new int[(int)MP.size()];
	for (int i=0;i<MP.size();i++)
		mp[i]=0;
	dfs(st,cntW,cntA,len,mp);
	for (int i=0;i<len;i++)
	{
		for (int j=0;j<len;j++)
		{
			int pos=i*len+j;
			if (mp[pos]!=-1)
			{
				cout<<(mp[pos])<<' ';
			}
			else
			{
				cout<<'X'<<' ';
			}
		}
		cout<<endl;
	}
	delete[] mp;
	cout<<"Press H to see help section. Press Q to quit the game."<<endl;
	return;
}

//This functions allow the export of the current map to a saved state, so the player can play again next time
void saveGame(vector<node*> &MP,node* st)
{
	ofstream fout;
	fout.open("last.txt");
	node *W=st->up,*A=st->left,*S=st->down,*D=st->right;
	int cntW=0,cntA=0,cntS=0,cntD=0;
	while(W!=NULL)
	{
		cntW++;
		W=W->up;
	}
	while(A!=NULL)
	{
		cntA++;
		A=A->left;
	}
	while(S!=NULL)
	{
		cntS++;
		S=S->down;
	}
	while(D!=NULL)
	{
		cntD++;
		D=D->right;
	}
	int* mp=new int[(int)MP.size()];
	for (int i=0;i<MP.size();i++)
	{
		mp[i]=0;
	}
	int len=(int)sqrt(MP.size());
	dfs(st,cntW,cntA,len,mp);
	for (int i=0;i<(int)MP.size();i++)
	{
		fout<<(mp[i])<<' ';
	}
	delete[] mp;
	fout.close();
	return;
}

//this is a function to check if the player has winned yet, by checking the current puzzle vector
bool checkWin(vector<node*> &MP,node *st)
{
	node *W=st->up,*A=st->left,*S=st->down,*D=st->right;
	int cntW=0,cntA=0,cntS=0,cntD=0;
	while(W!=NULL)
	{
		cntW++;
		W=W->up;
	}
	while(A!=NULL)
	{
		cntA++;
		A=A->left;
	}
	while(S!=NULL)
	{
		cntS++;
		S=S->down;
	}
	while(D!=NULL)
	{
		cntD++;
		D=D->right;
	}
	int* mp=new int[(int)MP.size()];
	for (int i=0;i<MP.size();i++)
	{
		mp[i]=0;
	}
	int len=(int)sqrt(MP.size());
	dfs(st,cntW,cntA,len,mp);
	for (int i=0;i+1<MP.size();i++)
	{
		if (mp[i]!=i+1) return 0;
	}
	return 1;
}
//this is the main of the function, it recursively askes for user idestut(their game choice) and performs actions such as changing and printing the vector map.
//It also handles player's request for saving the game or asking for help.
//at the end of every move, victory condition is also checked to see if the player has already won.
void gameMain(string gameName)
{
	vector<node*> MP;
	node *st=NULL;
	bool flag=loadGame(gameName,MP,st);
	if (!flag)
	{
		clearScreen();
		cout<<"No played game yet!"<<endl;
		cout<<"Press Any Key to return."<<endl;
		char ch=getch();
		return;
	}
	cout<<"Press Any Key to start your game!"<<endl;
	char ch=getch();
	bool errFlag=0;
	clearScreen();
	printmp(MP,st);
	while(ch=getch())
	{
		if (ch==(char)27)
		{
			ch=getch();
			ch=getch();
			if (ch=='A') ch='W';
			else if (ch=='B') ch='S';
			else if (ch=='C') ch='D';
			else ch='A';
		}
		if (ch=='h'||ch=='H')
		{
			helpsection();
			clearScreen();
			printmp(MP,st);
		}
		else if (ch=='q'||ch=='Q')
		{
			clearScreen();
			cout<<"Do you want to save the game? Y/N"<<endl;
			while(ch=getch())
			{
				if (ch=='y'||ch=='Y')
				{
					clearScreen();
					saveGame(MP,st);
					endGame(MP);
					return;
				}
				else if (ch=='n'||ch=='N')
				{
					clearScreen();
					endGame(MP);
					return;
				}
				else
				{
					clearScreen();
					cout<<"Do you want to save the game? Y/N"<<endl;
					cout<<"Please idestut y or n."<<endl;
				}
			}
		}
		else if (ch=='h'||ch=='H')
		{
			clearScreen();
			cout<<"Press Any Key to Load the Help Section."<<endl;
			char x=getch();
			clearScreen();
			//helpSection();
			continue;
		}
		else if (ch=='w'||ch=='W')
		{
			if (st->up==NULL)
			{
				errFlag=1;
			}
			else
			{
				node *dest=st->up;
				node *W1=st->up,*A1=st->left,*S1=st->down,*D1=st->right;
				node *W2=dest->up,*A2=dest->left,*S2=dest->down,*D2=dest->right;
				st->up=W2;
				st->left=A2;
				st->down=S2;
				st->right=D2;
				dest->up=W1;
				dest->left=A1;
				dest->down=S1;
				dest->right=D1;
				if (A1!=NULL)
				{
					A1->right=dest;
				}
				if (S1!=NULL)
				{
					S1->up=dest;
				}
				if (D1!=NULL)
				{
					D1->left=dest;
				}
				if (W2!=NULL)
				{
					W2->down=st;
				}
				if (A2!=NULL)
				{
					A2->right=st;
				}
				if (D2!=NULL)
				{
					D2->left=st;
				}
				st->down=dest;
				dest->up=st;
			}
			clearScreen();
			printmp(MP,st);
			if (errFlag)
			{
				cout<<"Invalid Input!"<<endl;
				errFlag=0;
			}
		}
		else if (ch=='a'||ch=='A')
		{
			if (st->left==NULL)
			{
				errFlag=1;
			}
			else
			{
				node *dest=st->left;
				node *W1=st->up,*A1=st->left,*S1=st->down,*D1=st->right;
				node *W2=dest->up,*A2=dest->left,*S2=dest->down,*D2=dest->right;
				st->up=W2;
				st->left=A2;
				st->down=S2;
				st->right=D2;
				dest->up=W1;
				dest->left=A1;
				dest->down=S1;
				dest->right=D1;
				if (W1!=NULL)
				{
					W1->down=dest;
				}
				if (S1!=NULL)
				{
					S1->up=dest;
				}
				if (D1!=NULL)
				{
					D1->left=dest;
				}
				if (W2!=NULL)
				{
					W2->down=st;
				}
				if (A2!=NULL)
				{
					A2->right=st;
				}
				if (S2!=NULL)
				{
					S2->up=st;
				}
				st->right=dest;
				dest->left=st;
			}
			clearScreen();
			printmp(MP,st);
			if (errFlag)
			{
				cout<<"Invalid Input!"<<endl;
				errFlag=0;
			}
		}
		else if (ch=='s'||ch=='S')
		{
			if (st->down==NULL)
			{
				errFlag=1;
			}
			else
			{
				node *dest=st->down;
				node *W1=st->up,*A1=st->left,*S1=st->down,*D1=st->right;
				node *W2=dest->up,*A2=dest->left,*S2=dest->down,*D2=dest->right;
				st->up=W2;
				st->left=A2;
				st->down=S2;
				st->right=D2;
				dest->up=W1;
				dest->left=A1;
				dest->down=S1;
				dest->right=D1;
				if (W1!=NULL)
				{
					W1->down=dest;
				}
				if (A1!=NULL)
				{
					A1->right=dest;
				}
				if (D1!=NULL)
				{
					D1->left=dest;
				}
				if (A2!=NULL)
				{
					A2->right=st;
				}
				if (S2!=NULL)
				{
					S2->up=st;
				}
				if (D2!=NULL)
				{
					D2->left=st;
				}
				st->up=dest;
				dest->down=st;
			}
			clearScreen();
			printmp(MP,st);
			if (errFlag)
			{
				cout<<"Invalid Input!"<<endl;
				errFlag=0;
			}
		}
		else if (ch=='d'||ch=='D')
		{
			if (st->right==NULL)
			{
				errFlag=1;
			}
			else
			{
				node *dest=st->right;
				node *W1=st->up,*A1=st->left,*S1=st->down,*D1=st->right;
				node *W2=dest->up,*A2=dest->left,*S2=dest->down,*D2=dest->right;
				st->up=W2;
				st->left=A2;
				st->down=S2;
				st->right=D2;
				dest->up=W1;
				dest->left=A1;
				dest->down=S1;
				dest->right=D1;
				if (W1!=NULL)
				{
					W1->down=dest;
				}
				if (A1!=NULL)
				{
					A1->right=dest;
				}
				if (S1!=NULL)
				{
					S1->up=dest;
				}
				if (W2!=NULL)
				{
					W2->down=st;
				}
				if (S2!=NULL)
				{
					S2->up=st;
				}
				if (D2!=NULL)
				{
					D2->left=st;
				}
				st->left=dest;
				dest->right=st;
			}
			clearScreen();
			printmp(MP,st);
			if (errFlag)
			{
				cout<<"Invalid Input!"<<endl;
				errFlag=0;
			}
		}
		else
		{
			clearScreen();
			printmp(MP,st);
		}
		if (checkWin(MP,st))
		{
			clearScreen();
			cout<<"Congratulations! You Won the GAME!"<<endl;
			sleep(5);
			cout<<"Press Any Key to Return to the Main Menu"<<endl;
			ch=getch();
			return;
		}
	}
}
