#ifndef BOARD_LOGIC_H
#define BOARD_LOGIC_H

void init_board(char arr[10][10][2]);

int max(int x, int y);

int min(int x, int y);

int place_ship(int n, char arr[10][10][2]);

int register_hit(char arr[10][10][2]);

#endif