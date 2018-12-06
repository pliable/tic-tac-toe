#include <stdio.h>
#include <stdlib.h>
#include "draw.h"
#include "constants.h"
#include "checks.h"

void move(char board[][BOARD_SIZE], int move, int player);
/*
 * tic-tac-toe
 * -----------
 * the bane of my existence 
 *
 * @author Steve Choo
 */
int main(int argc, char *argv[]) {
   /* this assumes player 1 is x and player 2 is o*/
   /*keeping board in main scope to avoid them pesky global vars*/
   char board[BOARD_SIZE][BOARD_SIZE];
   /* i think i used this to keep track of whose turn it is? */
   /* redo initialized to zero to trigger else */
   int choice, next_move, player_flag = PLAYER_1;

   /* initialize and prompt */
   init_board(board);
   prompt();

   scanf(" %d", &choice);

   /* no checky input here, should checky input maybe */

   switch(choice) {
      case START_GAME:
         draw_board(board);
         print_controls();
         break;
      case QUIT_GAME:
         printf("Okay bye bye!\n");
         exit(EXIT_SUCCESS);
         break;
      default:
         /* a kind of shitty check if person puts in something else */
         printf("you broke the game i leave now\n");
         exit(EXIT_FAILURE);
         break;
   }

   while(FOREVER_LOOP) {
      switch(player_flag) {
         case PLAYER_1:
            printf("Player 1 move: ");
            player_flag = PLAYER_2;
            break;
         case PLAYER_2:
            printf("Player 2 move: ");
            player_flag = PLAYER_1;
            break;
         default:
            printf("uh no");
            break;
      }

      scanf(" %d", &next_move);

      /*since you can only put your piece on a free spot, this
        **should** hopefully be sufficient check but i'll think about it more*/
      if(check_spot(board, next_move)) {
         move(board, next_move, player_flag);
      } else {
         printf("Invalid move, try again!\n");

         /*switch flag to redo the move*/
         if(player_flag == PLAYER_1) {
            player_flag = PLAYER_2;
         } else {
            player_flag = PLAYER_1;
         }
      }
   }

   return 0;
}

/*
   used to move a piece on the board
   no checks implemented to see if piece is already there
   maybe i should do dat.
   6/9 (heh) update: i did dat via check_spot (i 
   apparently even wrote another function to check oh boy fancy lol)
   */
void move(char board[][BOARD_SIZE], int move, int player) {
   char piece;

   if(player == PLAYER_1) {
      piece = X_PIECE;
   } else if(player == PLAYER_2) {
      piece = O_PIECE;
   }

   /*
      this is some magic numbers shit and i don't like it
      */
   switch(move) {
      case LOWER_LEFT:
         board[2][0] = piece;
         break;
      case LOWER_CENTER:
         board[2][1] = piece;
         break;
      case LOWER_RIGHT:
         board[2][2] = piece;
         break;
      case CENTER_LEFT:
         board[1][0] = piece;
         break;
      case CENTER:
         board[1][1] = piece;
         break;
      case CENTER_RIGHT:
         board[1][2] = piece;
         break;
      case UPPER_LEFT:
         board[0][0] = piece;
         break;
      case UPPER_CENTER:
         board[0][1] = piece;
         break;
      case UPPER_RIGHT:
         board[0][2] = piece;
         break;
   }
}

