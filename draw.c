#include <stdio.h>
#include "draw.h"

/*
   Just initializing the board with "blank" values
   */
void init_board(char board[][BOARD_SIZE]) {
   int i, j;

   for(i = 0; i < BOARD_SIZE; i++) {
      for(j = 0; j < BOARD_SIZE; j++) {
         board[i][j] = '-';
      }
   }
}

/*
   Drawing the board
   */
void draw_board(char board[][BOARD_SIZE]) {
   int i, j;

   for(i = 0; i < BOARD_SIZE; i++) {
      for(j = 0; j < BOARD_SIZE; j++) {

         printf(" %c ", board[i][j]);

         /*this is hacky and i don't like it but it works so hooray*/
         if(j < BOARD_SIZE - 1) {
            printf("|");
         } else {
            continue;
         }
      }

      /*ugh also gross and hacky ugh*/
      if(i < BOARD_SIZE - 1) {
         printf("\n-----------\n");
      } else {
         continue;
      }
   }
}

/*
   displaying controls to place piece
   */
void print_controls() {
   printf("\n\nHit the corresponding number (hit it as hard as you can, bonus if you break your keyboard) to put your piece there\n\n");
   printf(" 7 | 8 | 9 \n");
   printf("-----------\n");
   printf(" 4 | 5 | 6 \n");
   printf("-----------\n");
   printf(" 1 | 2 | 3 \n");
}

/*
   main prompt
   */
void prompt() {
   printf("Hello, welcome to this game of the tic tac toens\n");
   printf("------------------------------------------------\n");
   printf("                1 - Start game\n");
   printf("                2 - Quit\n");
   printf("                3 - Credits\n");
   printf("Your number is my command, master: ");
}
