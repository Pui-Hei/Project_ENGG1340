# Project_ENGG1340
ENGG1340
1.Team Member
  Chan Pui Hei
  Hu Xiao Bang
  Yu Si Yuan
2.Description
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
3.Implemented features
4.list of non-standard C/C++ libraries
  No non-standard C/C++ libraries used.
5.Compilation and execution instructions
  make game-> Compile the program
  make clean-> Clear existing game data
  ./game.exe-> Run the game
