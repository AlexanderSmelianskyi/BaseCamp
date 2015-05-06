#include "dll.h"

short GameIsFinished(const short *game_field) {
  //row, columns, diagonals positions
  size_t positions[ORDER * 2 + 2][ORDER] = {
  {0,1,2},{3,4,5},{6,7,8}, //rows
  {0,3,6},{1,4,7},{2,5,8}, //columns
  {0,4,8},{2,4,6}		   //diagonals
  };

  short win_flag;
  for(size_t i = 0; i < FIELD_SIZE - 1; ++i) {
    win_flag = 1;
    if(game_field[positions[i][0]] == EMPTY) {
      win_flag = 0;
    }

    for(size_t j = 0; j < ORDER - 1; ++j) {
      if(game_field[positions[i][j]] != game_field[positions[i][j+1]]) {
        win_flag = 0;
      }
    }

    if(win_flag == 1) {
	  //winner was determinated
      return game_field[positions[i][2]];
    }
  }
  //game is not finished or there is a draw
  return 0;
}

short MiniMaxAlg(short *game_field, short current_player) {
  short move = -1;
  short move_score;
  short best_score = -2;
  //check the result after move
  short result = GameIsFinished(game_field);
  //if somebody won
  if(result != 0) return result*current_player;
 
  //try every position
  for(size_t i = 0; i < 9; ++i) {
    if(game_field[i] == EMPTY) {
      game_field[i] = current_player;
	  /*PrintField(game_field);
	  system("pause");*/
	  //change player
      move_score = -MiniMaxAlg(game_field, current_player*-1);
	  //if this move is better then others
      if(move_score > best_score) {
      best_score = move_score;
      move = i;
      }
	//remove cross/zero from current position
    game_field[i] = EMPTY;
    }
  }
  //if move was not changed - score is 0
  if(move == -1) return 0;
  return best_score;
}

void ComputerMove(short *game_field) {
  short move;
  short move_score;
  short best_score = -2;
  //try every position
  for(size_t i = 0; i < 9; ++i) {
    if(game_field[i] == 0) {
	  //place zero on current position
      game_field[i] = ZERO;
	  //check the result of this move
      move_score = -MiniMaxAlg(game_field, CROSS);
	  //remove zero from current position
      game_field[i] = EMPTY;
	  //if this move is better then others
      if(move_score > best_score) {
        best_score = move_score;
        move = i;
      }
    }
  }
  //when best move was found - do it
  game_field[move] = 1;
}