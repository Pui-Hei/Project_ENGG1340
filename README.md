group 91
1. Team member

Chan Pui Hei
Hu Xiaobang
Yu Siyuan

2. Description

Our game has three difficulty levels: 3 times 3, 4 times 4, and 5 times 5. 
3 by 3 is a total of 9 squares, need to move 1 to 8 eight numbers and one “O”.
4 by 4 is a total of 16 squares, need to move 1 to 15 fifteen numbers and one “O”.
5 by 5 is a total of 25 squares, need to move 1 to 24 twenty-four numbers and one “O”.
Before introducing the steps, let's talk about the rules of the game, which are as follows:
  1.The numbers and “O” are entirely disordered at the beginning.
  2.One number is moved at a time.
  3.Numbers can only swap places with adjacent “O”.
  4.All the numbers and “O” are in order in the end.
Let's take the simplest three-by-three as an example to talk about the steps. 
There are 9 squares, and then only eight of them hold the number boards, 1-8, with one “O” in them. We can slide the board around to change its position on the grid.
If you swap a number with an “O”, the original position of that number becomes an “O” and you can swap the number next to it with the “O”. 
The goal is to arrange the number boards in order from 1-8 “O”, top to bottom and left to right in order of number size by moving them around. 
Of course, 3 by 3 is only a beginner's guide, and the difficulty level slowly increases. 4 by 4 and 5 by 5 are the rules, and so on.

3. Implemented Features
3.1. Generation of random game sets or events

A function named mapgentidy.cpp is created to make random maps.
mapgentidy.cpp takes in the current time and map size, then creates true random moves random between(1-4) and then move the empty space if it is a vaild move. 
This way, true random of game sets can be implemented.


3.2. Data structures for storing game status

Vectors are the most used data type to store the game status.
All objects on the map with its own value and the objects that is adjacent to up, down, left, and right, are stored in a vector. The vector saves all the pointers to the variables containing the map status.
The map is stored in the form of linked lists, when swapping adjacent value with space, we will change the linked list to determine the map.
So, in summary, the vector is used to store pointer of the linked list, and the linked list is used to store the values within the Klotiski Puzzle

3.3. Dynamic memory management

In the function mapgentidy.cpp, a linked list is implemented to handle the map size and respective movements.
The function gamemain.cpp uses a linked list to create the outline of the required puzzle, and then uses vector to store the pointers of objects. By using vectors, we ensured that the memory containing objects will be deleted after each game. We also used 'new' to create objects and arrays and 'delete' them after their mission is achieved. Dynamic memory management is mainly achieved by the two ways above.
This way, the game is able to handle different puzzle sizes such as 3\*3, 4\*4, and 5\*5 with the use of Dynamic memory management.

3.4. File input/output (e.g., for loading/saving game status)

A newly created map will be stored into the text file map.txt for reading purpose
The player can also store their current game into the file last.txt to play the same map at the same progress next time.

3.5. Program codes in multiple files

The program is split into a few components and their respective header files:
mapgentidy.cpp: to create a true random map and store it into a text file
menutidy.cpp: The main menu that allows players to navigate the game and start various game modes
clearscreen.cpp: A simple utility function made to clear screen.
helpsection.cpp: This file outputs the help section of the game
getch.cpp: This function handles the non-blocking input of the game
gamemain.cpp: This is the main body of the game, the actions of playing/loading/saving the game is also implemented here

4. List of non-standard C/C++ libraries

5. Compilation technique:

To compile the game, use the following command:

make game

To run the game, using the following command:

./game.exe

To remove the compiled game.exe, use the following command:

make clean
