#include <stdio.h>
#include <stdlib.h>
#include "draw.h"
#include "constants.h"

void move(char board[][BOARD_SIZE], int move, int player);
int check_spot(char board[][BOARD_SIZE], int location);
int check_horizontal(char board[][BOARD_SIZE]);
int check_vertical(char board[][BOARD_SIZE]);
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
   char board[BOARD_SIZE][BOARD_SIZE], choice;
   /* i think i used this to keep track of whose turn it is? */
   int player_flag = PLAYER_1;

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
      }

      scanf(" %d", &move);
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

/* boolean check to see if spot on the board is occupied 
   this assumes board sanity
   returns GOOD (or true, or 1) if spot is valid and clear
   returns BAD (or false, or 0) if spot isn't clear

   6/9/18 note: don't remember implementing this shit at all, but i guess
   i did it. this implementation is dependent on passing/using rows and columns,
   vs a "map".

   man, this makes me want to implement this shit in Python or something so i can return dicts or tuples
   */
/*int check_spot(char board[][BOARD_SIZE], int row, int col) {
   return board[row][col] == '-' ? GOOD : BAD;
}
*/
/*
   checks spot to see if piece is already there
   returns true (1) if the spot is free
   returns false (0) if the spot isn't free
   */
int check_spot(char board[][BOARD_SIZE], char location) {
   int status;
   /* should probably extract to a function since it's copy pasta-ed. also ugh gross
    this code is gross*/
   switch(location) {
      case LOWER_LEFT:
         if(board[2][0] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case LOWER_CENTER:
         if(board[2][1] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case LOWER_RIGHT:
         if(board[2][2] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case CENTER_LEFT:
         if(board[1][0] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case CENTER:
         if(board[1][1] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case CENTER_RIGHT:
         if(board[1][2] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case UPPER_LEFT:
         if(board[0][0] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case UPPER_CENTER:
         if(board[0][1] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case UPPER_RIGHT:
         if(board[0][2] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
   }

   return status;
}

/*
   checks board horizontally if there is a winner
   returns 0 if no winner
   returns PLAYER_1 if p1 won
   returns PLAYER_2 if p2 won
 
   fuckin problems:
   - it's gonna return a false positive with an initialized board
   - short circuit and where you don't want to short circuit
   */
int check_horizontal(char board[][BOARD_SIZE]) {
   int i, j, winner = 0;

   for(i = 0; i < BOARD_SIZE; i++) {
      for(j = 0; j < BOARD_SIZE; j++) {
         /* short circuit and? might not wanna do dat */
         if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if(board[i][j] == X_PIECE) {
               winner = PLAYER_1;
            } else {
               winner = PLAYER_2;
            }
         }
      }
   }

   return winner;
}

/*
   checks board vertically if there is a winner
   returns 0 if no winner
   returns PLAYER_1 if p1 won
   returns PLAYER_2 if p2 won
   */
int check_vertical(char board[][BOARD_SIZE]) {
   /*todo*/

   return 0;
}
