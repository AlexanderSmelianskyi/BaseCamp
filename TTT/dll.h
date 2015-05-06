#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996);

#define CROSS		-1
#define ZERO		1
#define EMPTY		0
//field order
#define ORDER		3
#define FIELD_SIZE	ORDER*ORDER

extern "C"  {
  //Checks if game is finished (there are winner or draw)
  //parameters: pointer to game field
  //returns -1 if player win, 0 - if draw, 1 - if computer win
  __declspec( dllexport ) short GameIsFinished(const short *);
  //Analyzes game field using minimax algorithm
  //parameters: pointer to game field
  //			current player (-1 - player, 0 - computer)
  //returns score of move, best score means best move to do
  __declspec( dllexport ) short MiniMaxAlg(short *, short);
  //Allows to play against computer. This function call
  //MiniMaxAlg to find best move to do.
  //parameters: pointer to game field
  __declspec( dllexport ) void ComputerMove(short *);
}