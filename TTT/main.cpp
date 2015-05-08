#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include "Interface.h"

#define DllImport __declspec( dllimport )
//GameIsFinished
typedef DllImport short (*LPFNDLLGIS) (const short *);
//MiniMaxAlg
typedef DllImport void (*LPFNDLLECM) (short *);
//ComputerMove
typedef DllImport void (*LPFNDLLCM) (short *);

//Handle to DLL
HINSTANCE h_dll;
//GameIsFinished pointer
LPFNDLLGIS gis;
//easyComputerMove pointer
LPFNDLLECM ecm;
//ComputerMove pointer
LPFNDLLCM cm;

short game_field[FIELD_SIZE] = {EMPTY};
 
//Starts game using LIB and DLL functions
void StartGame() {
  srand(time(NULL));
  //LIB usage
  char turn_control = WhoIsFirst();
  char mode = SelectMode();
  for(size_t i = 0; i < FIELD_SIZE; ++i) {
    //DLL usage
    if(gis(game_field) != 0) {
      break;
    }
    if((i+turn_control) % 2 == 0) {
      //easy
      if(mode == 1) ecm(game_field);
      //medium(1/3 of easy moves)
      if(mode == 2) {
        if(rand() % 10 < 3) {
          ecm(game_field);
        } else {
          cm(game_field);
        }
      }
      //hardmode(if you want to lose few times)
      if(mode == 3) {
        cm(game_field);
      }
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

bool InitializeDll() {
  //Loading DLL
  h_dll = LoadLibrary(TEXT("TicTacToe_DLL"));
  if (h_dll)
  {
    gis = (LPFNDLLGIS)GetProcAddress(h_dll, "GameIsFinished");
    ecm = (LPFNDLLECM)GetProcAddress(h_dll, "EasyComputerMove");
    cm = (LPFNDLLCM)GetProcAddress(h_dll, "ComputerMove");
    if(gis && ecm && cm) {
      printf("DLL functions were successfully loaded!\n\n");
      return true;
    } else {
      return false;
    }
  }
}

int main() {
  if(InitializeDll()) {
    StartGame();
  } else {
    printf("No library => No game\n");
  }
  system("pause");
}
