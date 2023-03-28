#include "STD_TYPES.h"
#include <stdio.h>
#include <string.h>


extern uint8_t board[9];
extern uint8_t position;
void drawBoard(uint8_t *board);
void updateBoard (uint8_t *board, uint8_t position, uint8_t value);



uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol);
void setPlayerConfig(uint8_t *configArray);


void loadAndUpdate(uint8_t playerNumber);
void getGameState(uint8_t *board, uint8_t *gameState);

