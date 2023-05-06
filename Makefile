game: 
	g++ menutidy.cpp mapgentidy.cpp gamemain.cpp getch.cpp helpSection.cpp clearScreen.cpp -o game.exe

clean:
	rm -f game.exe

.PHONY: clean
