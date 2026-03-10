#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <stdio.h>

void clear();

void print_board_initial(char arr[10][10][2]);

void print_two_boards(char left[10][10][2], char right[10][10][2],
                      const char *leftName, const char *rightName);

int game(char player_1_board[10][10][2], char player_2_board[10][10][2],
         const char *player1, const char *player2,
         int hits_by_player_1, int hits_by_player_2, int* player_1_tries,int* player_2_tries);

void placing_ships(char arr[10][10][2]);

#endif