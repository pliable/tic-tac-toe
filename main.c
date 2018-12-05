#include <stdio.h>
#include <stdlib.h>
#include "draw.h"

void move(char board[][BOARD_SIZE], char move, int player);
int check_spot(char board[][BOARD_SIZE], char location);
int check_horizontal(char board[][BOARD_SIZE]);
/*
 * tic-tac-toe
 * -----------
 * breaking the rust bruh
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

   /*
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
   */

   return 0;
}

/*
   used to move a piece on the board
   no checks implemented to see if piece is already there
   maybe i should do dat.
   6/9 (heh) update: i did dat via check_spot (i 
   apparently even wrote another function to check oh boy fancy lol)
   */
void move(char board[][BOARD_SIZE], char move, int player) {
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
      case '1':
         board[2][0] = piece;
         break;
      case '2':
         board[2][1] = piece;
         break;
      case '3':
         board[2][2] = piece;
         break;
      case '4':
         board[1][0] = piece;
         break;
      case '5':
         board[1][1] = piece;
         break;
      case '6':
         board[1][2] = piece;
         break;
      case '7':
         board[0][0] = piece;
         break;
      case '8':
         board[0][1] = piece;
         break;
      case '9':
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
      case '1':
         if(board[2][0] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case '2':
         if(board[2][1] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case '3':
         if(board[2][2] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case '4':
         if(board[1][0] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case '5':
         if(board[1][1] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case '6':
         if(board[1][2] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case '7':
         if(board[0][0] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case '8':
         if(board[0][1] == '-') {
            status = 1;
         } else {
            status = 0;
         }
         break;
      case '9':
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

