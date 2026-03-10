#include <stdio.h>
#include "board_logic.h"

void clear()
{
    printf("\033[H\033[J\033[3J");
    fflush(stdout);
}

void print_board_initial(char arr[10][10][2])
{
    printf("    1   2   3   4   5   6   7   8   9   10\n");
    char rows[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    for (int i = 0; i < 10; i++)
    {
        printf("%c   ", rows[i]);
        for (int j = 0; j < 10; j++)
        {
            printf("%c   ", arr[i][j][0]);
        }
        printf("\n");
    }
}

void print_two_boards(char left[10][10][2], char right[10][10][2],
                      const char *leftName, const char *rightName)
{
    printf("        %-20s               %-20s\n", leftName, rightName);
    printf("      1 2 3 4 5 6 7 8 9 10          1 2 3 4 5 6 7 8 9 10\n");

    char rows[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    for (int r = 0; r < 10; r++)
    {
        printf("  %c   ", rows[r]);
        for (int c = 0; c < 10; c++)
            printf("%c ", left[r][c][1]);

        printf("      ");

        printf("%c   ", rows[r]);
        for (int c = 0; c < 10; c++)
            printf("%c ", right[r][c][1]);

        printf("\n");
    }
}

int game(char player_1_board[10][10][2], char player_2_board[10][10][2],
         const char *player1, const char *player2,
         int hits_by_player_1, int hits_by_player_2, int *player_1_tries, int *player_2_tries)
{
    while (1)
    {
        clear();
        printf("\n===== %s's TURN =====\n", player1);
        print_two_boards(player_1_board, player_2_board, player1, player2);
        printf("%s, enter your hit:\n", player1);

        if (register_hit(player_2_board) == 2)
            hits_by_player_1++;

        (*player_1_tries)++;

        if (hits_by_player_1 == 20)
        {
            printf("\n>>> %s WINS THE GAME! <<<\n", player1);
            return 1;
        }
        clear();
        printf("\n===== %s's TURN =====\n", player2);

        print_two_boards(player_1_board, player_2_board, player1, player2);
        printf("%s, enter your hit:\n", player2);

        if (register_hit(player_1_board) == 2)
        {
            clear();
            print_two_boards(player_1_board, player_2_board, player1, player2);
            hits_by_player_2++;
        }

        (*player_2_tries)++;

        if (hits_by_player_2 == 20)
        {
            clear();
            print_two_boards(player_1_board, player_2_board, player1, player2);
            printf("\n>>> %s WINS THE GAME! <<<\n", player2);
            return 2;
        }
    }
}

void placing_ships(char arr[10][10][2])
{
    for (int i = 6; i > 1; i--)
    {

        print_board_initial(arr);
        place_ship(i, arr);
        clear();
    }
    clear();
    print_board_initial(arr);
}