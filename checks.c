#include "constants.h"
#include "checks.h"

/* checks if there is a draw game situation
   where every location on the board is filled

   returns true (1) if there is a draw game (ie: all spots on board are filled by X or O pieces)
   returns false (0) if there is not a draw game (ie: moves still available)
   */
int check_draw(char board[][BOARD_SIZE]) {
   int i, j, draw_game = 1;

   /* kinda quick and dirty but we're assuming a draw game occurs if every position filled up and
      no winners declared*/
   for(i = 0; i < BOARD_SIZE; i++) {
      for(j = 0; j < BOARD_SIZE; j++) {
         if(board[i][j] == '-') {
            draw_game = 0;
            break;
         }
      }
      /* quick and dirty break out of outer loop*/
      if(!draw_game) {
         break;
      }
   }

   return draw_game;
}

int check_all(char board[][BOARD_SIZE]) {
   /* initializing for funsies cause o ya the checks_ return a 0 for no winner lol */
   int winner = 0, horizontal = 0, vertical = 0, diagonal = 0;
   diagonal = check_diagonal(board);
   horizontal = check_horizontal(board);
   vertical = check_vertical(board);

   /* possible to get conflicting winners with this check? or, due to rules that
    shouldn't be possible since a check should occur after every move*/

   /* maybe just have all these return instead of continuing to check everything? */
   if(diagonal == PLAYER_1) {
      winner = PLAYER_1;
   } else if(diagonal == PLAYER_2) {
      winner = PLAYER_2;
   }

   if(horizontal == PLAYER_1) {
      winner = PLAYER_1;
   } else if(horizontal == PLAYER_2) {
      winner = PLAYER_2;
   }

   if(vertical == PLAYER_1) {
      winner = PLAYER_1;
   } else if(vertical == PLAYER_2) {
      winner = PLAYER_2;
   }

   return winner;
}

/*
   checks spot to see if piece is already there
   returns true (1) if the spot is free
   returns false (0) if the spot isn't free
   */
int check_spot(char board[][BOARD_SIZE], int location) {
   int status;
   /* should probably extract to a function since it's copy pasta-ed. also ugh gross
    this code is gross*/
   switch(location) {
      case LOWER_LEFT:
         status = board[2][0] == '-';
         break;
      case LOWER_CENTER:
         status = board[2][1] == '-';
         break;
      case LOWER_RIGHT:
         status = board[2][2] == '-';
         break;
      case CENTER_LEFT:
         status = board[1][0] == '-';
         break;
      case CENTER:
         status = board[1][1] == '-';
         break;
      case CENTER_RIGHT:
         status = board[1][2] == '-';
         break;
      case UPPER_LEFT:
         status = board[0][0] == '-';
         break;
      case UPPER_CENTER:
         status = board[0][1] == '-';
         break;
      case UPPER_RIGHT:
         status = board[0][2] == '-';
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
      - 12/6 note: not just an initialized board, ex: if player chooses position 1,
         this thing is going to think there is an immediate winner

   fuckin' problems fixed/possible fixes:
   - possible fix for board check: ignore '-'? feel like it'll cause problems
      need to think more
   */
int check_horizontal(char board[][BOARD_SIZE]) {
   int i, j, winner = 0;

   for(i = 0; i < BOARD_SIZE; i++) {
      for(j = 0; j < BOARD_SIZE; j++) {
         /*if all three in a row match... we have potential winner*/
         /*short circuit on false which is fine*/
         if(board[j][0] == board[j][1] && board[j][1] == board[j][2]) {
            /* if all three are '-', then we got a false positive, so skip */
            if(board[j][0] == '-' && board[j][1] == '-' && board[j][2] == '-') {
               continue;
            } else {
               /*just going to look at last piece since the previous i,j search was grabbing
                 wrong pieces*/
               if(board[j][2] == X_PIECE) {
                  winner = PLAYER_1;
               } else {
                  winner = PLAYER_2;
               }
               break;
            }
         }
      }
      /* slight reverse in logic compared to check_draw heh */
      if(winner) {
         break;
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
   int i, j, winner = 0;

   for(i = 0; i < BOARD_SIZE; i++) {
      for(j = 0; j < BOARD_SIZE; j++) {
         if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if(board[0][j] == '-' && board[1][j] == '-' && board[2][j] == '-') {
               continue;
            } else {
               if(board[2][j] == X_PIECE) {
                  winner = PLAYER_1;
               } else {
                  winner = PLAYER_2;
               }
               break;
            }
         }
      }
      /* slight reverse in logic compared to check_draw heh */
      if(winner) {
         break;
      }
   }

   return winner;
}

/*
   checks board diagonally if there is a winner
   returns 0 if no winner
   returns PLAYER_1 if p1 won
   returns PLAYER_2 if p2 won
   */
int check_diagonal(char board[][BOARD_SIZE]) {
   int winner = 0;

   if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
      if(!(board[0][0] == '-' && board[1][1] == '-' && board[2][2] == '-')) {
         if(board[2][2] == X_PIECE) {
            winner = PLAYER_1;
         } else {
            winner = PLAYER_2;
         }
      } 
   }

   if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
      if(!(board[0][2] == '-' && board[1][1] == '-' && board[2][0] == '-')) {
         if(board[2][0] == X_PIECE) {
            winner = PLAYER_1;
         } else {
            winner = PLAYER_2;
         }
      }
   }

   /* checks i think should naturally fail and be kept to a single player
      need to double check tho*/

   return winner;
}

/* keep for now ionno */
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
