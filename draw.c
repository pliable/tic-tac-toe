#include <stdio.h>
#include "constants.h"
#include "draw.h"

/*
   main prompt
   */
void prompt() {
   printf("Hello, welcome to this shitty game of tic-tac-toe\n");
   printf("------------------------------------------------\n");
   printf("                1 - Start game\n");
   printf("                2 - Quit\n");
   printf("just gimme a number and let\'s get it on (oh yeahhhh...): ");
}

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
   i was told by a very cool dude that this isn't hacky so hooray.
   i'm still gonna leave the comments there though because i'm soOoOoOo wacky
   */
void draw_board(char board[][BOARD_SIZE]) {
   int i, j;

   /* for a newline for a clean look, shoutout to JDS */
   puts("");

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
   printf("\n\nSmash that corresponding number to put your piece there!\n\n");
   printf(" 7 | 8 | 9 \n");
   printf("-----------\n");
   printf(" 4 | 5 | 6 \n");
   printf("-----------\n");
   printf(" 1 | 2 | 3 \n\n");
}

