#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "Interface.h"

#define DllImport __declspec( dllimport )
//GameIsFinished
typedef DllImport short (*LPFNDLLGIS) (const short *);
//MiniMaxAlg
typedef DllImport short (*LPFNDLLMMA) (const short *, short);
//ComputerMove
typedef DllImport void (*LPFNDLLCM) (const short *);

//Handle to DLL
HINSTANCE h_dll;
//GameIsFinished pointer
LPFNDLLGIS gis;
//MiniMaxAlg pointer
LPFNDLLMMA mma;
//ComputerMove pointer
LPFNDLLCM cm;

short game_field[FIELD_SIZE] = {EMPTY};
 
//Starts game using LIB and DLL functions
void StartGame() {
  //LIB usage
  unsigned short turn_control = WhoIsFirst();

  for(size_t i = 0; i < FIELD_SIZE; ++i) {
	//DLL usage
    if(gis(game_field) != 0) {
      break;
    }
    if((i+turn_control) % 2 == 0) {
      cm(game_field);
	//LIB usage
	} else {
      PrintField(game_field);
      PrintMoves(game_field);
      PlayerMove(game_field);
    }
  }
  //DLL usage
  switch(gis(game_field)) {
  //LIB usage
    case 0: {
	  PrintField(game_field);
      printf("\n>>>>> DRAW <<<<<\n\n");
      break;
	}
    case 1: {
      PrintField(game_field);
      printf("\n>>>>> COMPUTER WIN :( <<<<<\n\n");
      break;
	}
    case -1: {
	  PrintField(game_field);
      printf("\n>>>>> YOU WIN <<<<<\n\n");
      break;
	}
  }
}

int main() {
  //Loading DLL
  h_dll = LoadLibrary(TEXT("TicTacToe_DLL"));
  if (h_dll)
  {
	gis = (LPFNDLLGIS)GetProcAddress(h_dll, "GameIsFinished");
	mma = (LPFNDLLMMA)GetProcAddress(h_dll, "MiniMaxAlg");
	cm = (LPFNDLLCM)GetProcAddress(h_dll, "ComputerMove");
	if(gis && mma && cm) {
	  printf("Functions were successfully loaded!\n\n");
	  //Start the game!
      StartGame();
	} else {
	  printf("No library => No game\n");
	}
  }
  system("pause");
}
