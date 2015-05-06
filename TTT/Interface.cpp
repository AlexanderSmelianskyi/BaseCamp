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
	  break;
    }
	case 2: {
      system("cls");
      printf("Out of range!\n");
      printf("Range is: %d - %d\n", 1, FIELD_SIZE);
      system("pause");
      PrintField(game_field);
      PrintMoves(game_field);
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

      printf("And press Enter then\n");
      printf("%c%c%c%c%c%c%c\n",201,205,205,205,205,205,187);
      printf("%c     %c\n",186,186);
      printf("%c <%c%c %c\n",186,205,188,186);
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
  short move = 0;
  do {
    printf("\nYour move: ");
    scanf("%d", &move);
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
      printf("Press 'y' or 'n' and 'Enter' button then\n");
	} else {
	PrintHelp(3);
	}
	fflush(stdin);
    scanf("%c", &choice);
  } while (choice != 'y' && choice != 'Y' &&
		   choice != 'n' && choice != 'N');
  printf("\n");

  unsigned short turn_control;

  switch (choice) {
    case 'y': case 'Y': {
      turn_control = 1; 
      break;
    }
    case 'n': case 'N': {
      turn_control = 2; 
      break;
    }
  }

  return turn_control;
}