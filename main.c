#include <stdio.h>
#include <stdlib.h>
#include "draw.h"

/*
 * tic-tac-toe
 * -----------
 * breaking the rust bruh
 *
 * @author Steve Choo
 */
void move(char board[][BOARD_SIZE], int move, int player);

int main(int argc, char *argv[]) {
   /*keeping board in main scope to avoid them pesky global vars*/
   char board[BOARD_SIZE][BOARD_SIZE], choice;
   /* 0 is player 1, 1 is player 2 */
   int player_flag = PLAYER_1, move;
   init_board(board);

   prompt();
   scanf(" %c", &choice);

   switch(choice) {
      case '1':
         draw_board(board);
         print_controls();
         break;
      case '2':
         printf("Okay bye bye!\n");
         exit(EXIT_SUCCESS);
         break;
      case '3':
         printf("Why did you pick this option? github.com/pliable\n");
         exit(EXIT_SUCCESS);
         break;
   }

   while(1) {
      switch(player_flag) {
         case PLAYER_1:
            printf("Player 1 move: ");
            player_flag = PLAYER_2;
            break;
         case PLAYER_2:
            printf("Player 2 move: ");
            player_flag = PLAYER_1;
            break;
      }

      scanf(" %d", &move);
   }

   return 0;
}

void move(char board[][BOARD_SIZE], int move, int player) {
   char piece;

   if(player == PLAYER_1) {
      piece = X_PIECE;
   } else if(player == PLAYER_2) {
      piece = O_PIECE;
   }

   switch(move) {
      case 1:
         board[2][0] = piece;
         break;
      case 2:
         board[2][1] = piece;
         break;
      case 3:
         board[2][2] = piece;
         break;
      case 4:
         board[1][0] = piece;
         break;
      case 5:
         board[1][1] = piece;
         break;
      case 6:
         board[1][2] = piece;
         break;
      case 7:
         board[0][0] = piece;
         break;
      case 8:
         board[0][1] = piece;
         break;
      case 9:
         board[0][2] = piece;
         break;
   }
}

