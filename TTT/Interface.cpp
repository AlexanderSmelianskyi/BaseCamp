#include "Interface.h"

char itos(short value) {
  if (value == -1) {
    return 'X';
  } else if (value == 0) {
    return ' ';
  } else {
    return 'O';
  }
}

void PrintField(short *field) {
  system("cls");
  printf("Game field:\n");
  printf("\n-------------\n");
  for (size_t i = 0; i < FIELD_SIZE; ++i) {
    printf("| %c ", itos(field[i]));
    if((i + 1) % ORDER == 0) {
      printf("|\n-------------\n");
    }
  }
}

void PrintMoves(short *field)
{
  printf("\nAvailable moves:\n");
  printf("\n-------------\n");
  for (size_t i = 0; i < FIELD_SIZE; ++i)
  {
    if (field[i] == EMPTY) {
      printf("| %d ", i + 1);
    } else {
      printf("| %c ", ' ');
    }
    if ((i + 1) % ORDER == 0) {
      printf("|\n-------------\n");
    }
  }
}

void PrintHelp(size_t message) {
  switch (message) {
    case 1: {
      system("cls");
      printf("Wrong move! Position is busy!\n");
      PrintMoves(game_field);
      system("pause");
      PrintField(game_field);
      PrintMoves(game_field);
      fflush(stdin);
      break;
    }
    case 2: {
      system("cls");
      printf("Wrong button!\n");
      printf("You cin use only %d - %d button to make move\n", 1, FIELD_SIZE);
      system("pause");
      PrintField(game_field);
      PrintMoves(game_field);
      fflush(stdin);
      break;
    }
    case 3: {
      system("cls");
      printf("Please press this button:\n");
      printf("%c%c%c%c%c%c%c\n",201,205,205,205,205,205,187);
      printf("%cY    %c\n",186,186);
      printf("%c    H%c\n",186,186);
      printf("%c%c%c%c%c%c%c\n",200,205,205,205,205,205,188);

      printf("Or this button:\n");
      printf("%c%c%c%c%c%c%c\n",201,205,205,205,205,205,187);
      printf("%cN    %c\n",186,186);
      printf("%c    T%c\n",186,186);
      printf("%c%c%c%c%c%c%c\n",200,205,205,205,205,205,188);
      break;
    }
    default: {
      printf("Unexpected error\n");
      break;
    }
  }
}

void PlayerMove(short *game_field) {
  char move = 0;
  do {
    printf("\nYour move: ");
    move = getch();
    move -= '0';
    --move;
  printf("\n");
  } while (!MoveIsCorrect(game_field, move));
  game_field[move] = CROSS;
}

bool MoveIsCorrect(short *game_field, short move) {
  if(move < 0 || move > 8) {
    //Out of range
    PrintHelp(2);
    return false;
  }
  if(game_field[move] == EMPTY) {
    return true;
  } else {
    //Wrong move
    PrintHelp(1);
    return false;
  }
}

short WhoIsFirst() {
char choice;
  size_t bad_choice = 0;
  printf("Do you want to move first? ");
  do {
    ++bad_choice;
    if(bad_choice < 3) {
      printf("\nPress 'y' or 'n'");
    } else {
    PrintHelp(3);
    }
    choice = getch();
  } while (choice != 'y' && choice != 'Y' &&
           choice != 'n' && choice != 'N');
  printf("\n");

  switch (choice) {
    case 'y': case 'Y': {
      return 1;
    }
    case 'n': case 'N': {
      return 2;
    }
  }
}

char SelectMode() {
  char mode = '0';
  system("cls");
  printf("Select game mode:\n1. Easy\n2. Medium\n3. Hard\n");
  do {
    mode = getch();
  } while (mode < '1' || mode > '3');
  printf("\n");

  switch (mode) {
    case '1': {
      return 1; 
    }
    case '2': {
      return 2;
    }
    case '3': {
      return 3;
    }
  }
}