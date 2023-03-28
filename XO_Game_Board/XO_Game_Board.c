#include"xo_Game_board.h"
uint8_t position;
uint8_t board[9] = {'1','2','3','4','5','6','7','8','9'};



void drawBoard(uint8_t *board)
{

    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

void updateBoard(uint8_t *board, uint8_t position, uint8_t value)
{
    board[position - 1] = value;
}
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t *symbol) {
    // Prompt the player to choose a symbol
    printf("Player %d, choose your symbol (X/O): ", playerNumber);
    scanf(" %c", symbol);

    // Convert the symbol to uppercase
    *symbol = toupper(*symbol);

    // Check if the symbol is valid
    if (*symbol != 'X' && *symbol != 'O') {
        return 1;
    }

    return 0;
}
void setPlayerConfig(uint8_t *configArray) {
    uint8_t symbol1, symbol2;

    // Get player 1 symbol
    while (getPlayerSymbol(1, &symbol1)) {
        printf("Invalid input.\n");
    }
    configArray[0] = symbol1;

    // Get player 2 symbol
    while (getPlayerSymbol(2, &symbol2) || symbol2 == symbol1) {
        if (symbol2 == symbol1) {
            printf("Symbol already chosen. Please choose a different symbol.\n");
        } else {
            printf("Invalid input.\n");
        }
    }
    configArray[1] = symbol2;
}

void loadAndUpdate(uint8_t playerNumber) {
          printf("player Number %d enter your position: ", playerNumber);
    scanf("%d", &position);

}
void getGameState(uint8_t *board, uint8_t *gameState)
{
    if(board[0] == board[1] && board[1] == board[2])
    {
        *gameState = 0;
    }
    else if(board[3] == board[4] && board[4] == board[5])
    {
        *gameState = 0;
    }
    else if(board[6] == board[7] && board[7] == board[8])
    {
        *gameState = 0;
    }
    else if(board[0] == board[3] && board[3] == board[6])
    {
        *gameState = 0;
    }
    else if(board[1] == board[4] && board[4] == board[7])
    {
        *gameState = 0;
    }
    else if(board[2] == board[5] && board[5] == board[8])
    {
        *gameState = 0;
    }
    else if(board[0] == board[4] && board[4] == board[8])
    {
        *gameState = 0;
    }
    else if(board[2] == board[4] && board[4] == board[6])
    {
        *gameState = 0;
    }
    else if(board[3] == board[4] && board[4] == board[5])
    {
        *gameState = 0;
    }
    else if(board[0] != '1' && board[1] != '2' && board[2] != '3' &&
            board[3] != '4' && board[4] != '5' && board[5] != '6' &&
            board[6] != '7' && board[7] != '8' && board[8] != '9')
            {
                *gameState = 1;
            }

    else
    {
        *gameState = 2;
    }
}
