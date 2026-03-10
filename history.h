#ifndef HISTORY_H
#define HISTORY_H

int start();

void addtxt(char *winnername, char *losername, int score);

void addplyname(char *name1, char *name2);

void printhis();

void sanitize(char *s);

void hisclear();

void gameexit();

void print_history();

void playerhistory(char *winner, char *loser);

void deletePlayerhistory(char *target);

#endif