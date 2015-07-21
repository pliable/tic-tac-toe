#include <stdio.h>

/*
   * tic-tac-toe
   * -----------
   * breaking the rust bruh
   *
   * @author Steve Choo
*/
void prompt();

int main(int argc, char *argv[]) {
   char choice;

   prompt();
   scanf(" %c", &choice);

   switch(choice) {
      case '1':
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

void prompt() {
   printf("Hello, welcome to this game of the tic tac toens\n");
   printf("------------------------------------------------\n");
   printf("                1 - Start game\n");
   printf("                2 - Quit\n");
   printf("                3 - Credits\n");
   printf("Your number is my command, master: ");
}

