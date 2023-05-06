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



using namespace std;



//The purpose of this code is to randomize a QiYi Klotski Puzzle, by making randomized steps to reverse a completed QiYi Klotski puzzle.
//In this code, file I/O, Dynamic memory management and Generation of random game sets or events has been implemented, mapping to objectives 1,3,4
//Note that in this code, block value -1 means the empty block, direction 0 means empty block going up,  1 going right, 2 going down, 3 going left
//A 3*3 solved QiYi Klotski will have the following arrangment
//_______________________
//   1  |   2    |   3
//______|________|_______
//   4  |   5    |   6
//______|________|_______
//   7  |   8    |   X
//______|________|_______

//define a structure block to create a linked list for the QiYi Klotski Puzzle map
struct block{
	int value;
	block *next;

};

//This function allows the addition of new blocks into existing QiYi Klotski Puzzle map
block * headInsert (block *h, int v){
	block *Node = new block;
	Node -> value = v;
	Node -> next = h;
	h = Node;
	return h;
}

//This function replaces a particular value in the linked list with the given value. This way, by using replace twice, a swap between an empty space and a block can be achieved.
int replace(block *head, int v, int step){
	block *current = head;
	int tempvalue;
	int index = 1;
	while (current != NULL){
		if (index == step){
			tempvalue = current->value;
			current->value = v;   
			return tempvalue;
		}
		current = current->next;
		index++;
	}
	return -1;
}

//This function calculates which two blocks should have their values swapped, and passes both of them to the replace() function
void swap (int x, int y, int direction, int size, block *head){
	int destx, desty;
	//calculating the destination of the block that should be replaced with value -1
	switch(direction){
		case 0:
			destx=x;
			desty=y-1;
			break;
		case 1:
			destx=x+1;
			desty=y;
			break;
		case 2:
			destx=x;
			desty=y+1;
			break;
		case 3:
			destx=x-1;
			desty=y;
			break;
	}
	int step = size*(desty-1)+destx;
	int replacedvalue;
	//replace the value of the destination by -1, and retrieve the value of that destination. After retrieving, replace the value of original block by the retrieved value.
	replacedvalue = replace(head, -1, step);
	step = size*(y-1)+x;
	replace(head, replacedvalue,step);
}

//a tool developed during debug process to see the dyanmic list
void runlist (block *head){
	block *current;
	current = head;


	while (current != NULL){

		cout << current-> value << endl;
		current = current -> next;
	}
}

//A function that exports the final randomized QiYi Klotski into a text file
void exportmap(block *head, int s){
	ofstream fout;
	fout.open("map.txt");
	if ( fout.fail() ){
		cout << "Failed to create map" << endl;
	}else{
		//fout<<s<< endl;

		block *current;
		current = head;


		while (current != NULL){

			fout << current-> value <<" ";
			current = current -> next;
		}




	}   
	fout.close();
}



//the part that handles generation of randomness and steps regarding how the QiYi Klotski would be randomized
void mapgen(int size){




	//initializing variables and dyanmic linked list
	int loc_x, loc_y;
	int length = size*size-1;
	loc_x = size;
	loc_y = size;
	block *head = NULL;
	//create a solved QiYi Klotski puzzle by the given dimensions
	head = headInsert(head, -1);

	for (int j = length; j>0;j--){
		head = headInsert(head, j);

	}
	//randomize the solved QiYi Klotski puzzle to make it not solved
	std::srand(std::time(nullptr));
	for (int i = 0; i < 20000; i++) {
		int direction = std::rand() % 4;

		if (direction==0 && loc_y!=1){
			swap(loc_x, loc_y, direction, size, head);
			loc_y=loc_y-1;
		}
		if (direction==1 && loc_x!=size){
			swap(loc_x, loc_y, direction, size, head);
			loc_x=loc_x+1;
		}
		if (direction==2 && loc_y!=size){
			swap(loc_x, loc_y, direction, size, head);
			loc_y=loc_y+1;
		}
		if (direction==3 && loc_x!=1){
			swap(loc_x, loc_y, direction, size, head);
			loc_x=loc_x-1;
		}


	}
	//export the randomized map to a text file   
	exportmap(head, size);
}
