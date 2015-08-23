#include <stdio.h>
#include "draw.h"

/*
 * tic-tac-toe
 * -----------
 * breaking the rust bruh
 *
 * @author Steve Choo
 */

int main(int argc, char *argv[]) {
   //keeping board in main scope to avoid them pesky global vars
   char board[BOARD_SIZE][BOARD_SIZE];
   init_board(board);
   char choice;

   prompt();
   scanf(" %c", &choice);

   switch(choice) {
      case '1':
         draw_board(board);
         break;
      case '2':
         printf("Okay bye bye!\n");
         break;
      case '3':
         printf("Why did you pick this option? github.com/pliable\n");
         break;
   }
   
   return 0;
}
