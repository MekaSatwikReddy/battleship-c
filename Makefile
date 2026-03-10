run: battleship
	./battleship

battleship : main.o board_logic.o game_loop.o history.o
	gcc main.o board_logic.o game_loop.o history.o -o battleship

board_logic.o : board_logic.c board_logic.h
	gcc -c board_logic.c

game_loop.o : game_loop.c board_logic.h game_loop.h
	gcc -c game_loop.c

history.o : history.c history.h
	gcc -c history.c

main.o : main.c game_loop.h history.h board_logic.h
	gcc -c main.c