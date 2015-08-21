#define EMPTY_SPACE 0
#define X_PIECE 1
#define O_PIECE 2
#define BOARD_SIZE 3

void prompt();
void init_board(int board[][BOARD_SIZE]);
void draw_board(int board[][BOARD_SIZE]);
