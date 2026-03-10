#include <stdio.h>
#include "game_loop.h"
#include <string.h>

typedef struct
{
    char winner[50];
    char loser[50];
    int score;
} MatchRecord;

int start()
{
    for (int i = 0; i < 60; i++)
        printf("=");

    int input;
    printf("\n");
    printf("                 WELCOME TO BATTLESHIP GAME                \n");

    for (int j = 0; j < 60; j++)
        printf("=");

    printf("\n");
    printf("1. TO ENTER GAME\n");
    printf("2. TO VIEW MATCH HISTORY\n");
    printf("3. TO VIEW PLAYER HISTORY\n");
    printf("4. TO DELETE PARTICULAR PLAYER HISTORY\n");
    printf("5. TO CLEAR COMPLETE HISTORY\n");
    printf("6. TO EXIT\n");
    printf("ENTER YOUR CHOICE\n");

    scanf("%d", &input);
    return input;
}
void sanitize(char *s)
{
    for (int i = 0; s[i]; i++)
        if (s[i] == ' ')
            s[i] = '_';
}

void desanitize(char *s)
{
    for (int i = 0; s[i]; i++)
        if (s[i] == '_')
            s[i] = ' ';
}

void addtxt(char *winnername, char *losername, int score)
{
    MatchRecord r;
    strcpy(r.winner, winnername);
    strcpy(r.loser, losername);
    r.score = score;

    FILE *fptr = fopen("text.txt", "a");
    fprintf(fptr, "%s %s %d\n", r.winner, r.loser, r.score);
    fclose(fptr);
}

void addplyname(char *name1, char *name2)
{
    char player1[50], player2[50];

    printf("ENTER PLAYER 1 NAME: ");
    scanf(" %49[^\n]", player1);
    sanitize(player1);
    printf("ENTER PLAYER 2 NAME: ");
    scanf(" %49[^\n]", player2);
    sanitize(player2);

    strcpy(name1, player1);
    strcpy(name2, player2);
}



void printhis()
{
    FILE *fptr = fopen("text.txt", "r");
    MatchRecord r;

    if (!fptr)
    {
        printf("NO HISTORY FOUND\n");
        return;
    }

    while (fscanf(fptr, "%s %s %d", r.winner, r.loser, &r.score) != EOF)
    {
        printf("|------------------------------------------|\n");
        printf("|   %s  VS  %s\n", r.winner, r.loser);
        printf("|   WINNER: %s\n", r.winner);
        printf("|   SCORE : %d\n", r.score);
        printf("|------------------------------------------|\n");
    }

    fclose(fptr);
}

void hisclear()
{
    FILE *fptr1 = fopen("text.txt", "w");
    FILE *fptr2 = fopen("players.txt", "w");
    fclose(fptr1);
    fclose(fptr2);
    printf("HISTORY CLEARED SUCCESSFULLY ;)\n");
}

void gameexit()
{
    printf("YOU HAVE SUCCESSFULLY EXITED\n");
}

void playerhistory(char *winner, char *loser)
{
    FILE *fp = fopen("players.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    char name[50];
    int m, w;
    int wf = 0, lf = 0;

    while (fp && fscanf(fp, "%s %d %d", name, &m, &w) != EOF)
    {

        if (strcmp(name, winner) == 0)
        {
            m++;
            w++;
            wf = 1;
        }
        else if (strcmp(name, loser) == 0)
        {
            m++;
            lf = 1;
        }

        fprintf(temp, "%s %d %d\n", name, m, w);
    }

    if (!wf)
        fprintf(temp, "%s 1 1\n", winner);

    if (!lf)
        fprintf(temp, "%s 1 0\n", loser);

    if (fp)
        fclose(fp);
    fclose(temp);

    remove("players.txt");
    rename("temp.txt", "players.txt");
}

void print_history()
{
    FILE *fp;
    char name[50];
    int matches;
    int won;
    fp = fopen("players.txt", "r");
    int q = 1;
    while (fscanf(fp, "%s %d %d", name, &matches, &won) != EOF)
    {
        printf("|--------------------------------------------|\n");
        printf("|PLAYER NAME : %s\n", name);
        printf("|TOTAL MATCHES PLAYED : %d\n", matches);
        printf("|WON : %d\n", won);
        printf("|LOST : %d\n", matches - won);
        printf("|--------------------------------------------|\n");
        q += 1;
    }
    fclose(fp);
}

void deletePlayerhistory(char *target)
{
    FILE *fp = fopen("players.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    char name[50];
    int m, w;
    int found = 0;

    while (fscanf(fp, "%49s %d %d", name, &m, &w) != EOF)
    {

        if (strcmp(name, target) == 0)
        {
            found = 1;
            continue;
        }

        fprintf(temp, "%s %d %d\n", name, m, w);
    }

    if (found == 0)
    {
        printf("Name does not exist in history\n");
        int c;
        printf("PRESS ENTER TO CONTINUE\n");
        while ((c = getchar()) != '\n' && c != EOF);
        getchar();
        clear();
    }
    else
    {
        printf("Name exists and deleted successfully\n");
        int c;
        printf("PRESS ENTER TO CONTINUE\n");
        while ((c = getchar()) != '\n' && c != EOF);
        getchar();
        clear();
    }

    fclose(fp);
    fclose(temp);

    remove("players.txt");
    rename("temp.txt", "players.txt");
}