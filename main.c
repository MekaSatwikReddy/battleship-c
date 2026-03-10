#include <stdio.h>
#include "board_logic.h"
#include "game_loop.h"
#include "history.h"

int main()
{
    int input, winner;
    char player1[50], player2[50], target[50];
    int player_1_tries = 0, player_2_tries = 0;
    while (1)
    {
        input = start();
        clear();
        switch (input)
        {
        case 1:
            printf("Starting game...\n");

            char board1[10][10][2];
            char board2[10][10][2];
            int a, b;

            init_board(board1);
            init_board(board2);

            addplyname(player1, player2);
            clear();

            printf("%s'S TURN PLACE YOUR SHIPS\n", player1);
            placing_ships(board1);

            printf("THESE ARE THE POSITIONS OF YOUR SHIPS\n");
            printf("PRESS ENTRE AND GIVE TO %s\n", player2);
            fflush(stdout);

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            ch = getchar();
            clear();
            printf("%s'S TURN PLACE YOUR SHIPS\n", player2);
            placing_ships(board2);

            printf("THESE ARE THE POSITIONS OF YOUR SHIPS\n");
            printf("PRESS ENTRE TO START PLAYING GAME\n");
            fflush(stdout);

            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            ch = getchar();

            winner = game(board1, board2,
                          player1, player2,
                          0, 0, &player_1_tries, &player_2_tries);

            if (winner == 1)
            {
                addtxt(player1, player2, (100 - player_1_tries));
                playerhistory(player1, player2);
                printf("PRESS ENTRE TO CONTIUE");
                fflush(stdout);

                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                ch = getchar();
                clear();
            }
            else if (winner == 2)
            {
                addtxt(player2, player1, (100 - player_2_tries));
                playerhistory(player2, player1);
                printf("PRESS ENTRE TO CONTIUE");
                fflush(stdout);

                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                ch = getchar();
                clear();
            }
            break;

        case 2:
            clear();
            printhis();
            printf("PRESS ENTER TO CONTINUE\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            getchar();
            clear();
            break;
        case 5:
            hisclear();
            break;
        case 6:
            clear();
            gameexit();
            return 0;
        case 4:
            printf("PLEASE ENTER A PLAYER NAME TO DELETE PLAYER HISTORY\n");
            scanf(" %49[^\n]", target);
            sanitize(target);
            deletePlayerhistory(target);
            break;
        case 3:
            print_history();
            printf("PRESS ENTER TO CONTINUE\n");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            getchar();
            clear();
            break;

        default:
            printf("INVALID CHOICE! TRY AGAIN.\n");
        }
    }
    return 0;
}