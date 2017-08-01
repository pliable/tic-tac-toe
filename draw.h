#define EMPTY_SPACE 0
#define X_PIECE 'X'
#define O_PIECE 'O'
#define BOARD_SIZE 3
#define PLAYER_1 1
#define PLAYER_2 2

void prompt();
void init_board(char board[][BOARD_SIZE]);
void draw_board(char board[][BOARD_SIZE]);
void print_controls();
