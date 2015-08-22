#include <stdio.h>
#include "draw.h"

void init_board(int board[][BOARD_SIZE]) {
   int i, j;

   for(i = 0; i < BOARD_SIZE; i++) {
      for(j = 0; j < BOARD_SIZE; j++) {
         board[i][j] = 0;
      }
   }
}

void draw_board(int board[][BOARD_SIZE]) {
   int i, j;

   for(i = 0; i < BOARD_SIZE; i++) {
      for(j = 0; j < BOARD_SIZE; j++) {
         if(board[i][j] == EMPTY_SPACE) {
            printf(" - ");
         } else if(board[i][j] == X_PIECE) {
            printf(" X ");
         } else if(board[i][j] == O_PIECE) {
            printf(" O ");
         }

         //this is hacky and i don't like it but it works so hooray
         if(j < BOARD_SIZE - 1) {
            printf("|");
         } else {
            continue;
         }
      }

      //ugh also gross and hacky ugh
      if(i < BOARD_SIZE - 1) {
         printf("\n-----------\n");
      } else {
         continue;
      }
   }

}

void prompt() {
   printf("Hello, welcome to this game of the tic tac toens\n");
   printf("------------------------------------------------\n");
   printf("                1 - Start game\n");
   printf("                2 - Quit\n");
   printf("                3 - Credits\n");
   printf("Your number is my command, master: ");
}
