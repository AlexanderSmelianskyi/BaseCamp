#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996);

#define CROSS		-1
#define ZERO		1
#define EMPTY		0
//field order
#define ORDER		3
#define FIELD_SIZE	ORDER*ORDER

extern short game_field[FIELD_SIZE];

//Converts integer value to symbol
//Parameters: integer value from game field
//Returns symbol
char itos(short);
//Prints game field
//Parameters: pointer to game field
void PrintField(short *);
//Prints available moves
//Parameters: pointer to game field
void PrintMoves(short *);
//Prints hints for user
//Parameters: message number
//1 - wrong move
//2 - out fo range
//3 - wrong game start
void PrintHelp(size_t message);
//Allow player to make moves
//Parameters: pointer to game field
void PlayerMove(short *game_field);
//Checks if move is correct (position is free) and move is not out of range
//Parameters: pointer to game field
//			  move number
//Returns true if move is correct and false otherwise
bool MoveIsCorrect(short *, short);
//Let player to make choice who will make move first
//returns "turn controller"
short WhoIsFirst();
