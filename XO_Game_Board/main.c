
#include <stdio.h>
#include "xo_Game_board.h"
uint8_t config[2];
int main ()
{
    static uint8_t State ;
 printf("Welcome to XO_game!\n");
 printf("-----------------------\n");
    drawBoard(board);
    getGameState(board, &State);
setPlayerConfig(config);
static uint8_t player=1;
        // game loop

do
    {



        player = (player % 2) ? 1 : 2;
        // get player move

        loadAndUpdate(player);
        // update board
        updateBoard(board,position,config[player-1]);



        getGameState(board, &State);

        player++;
        drawBoard(board);
    } while (State == 2);
if(State == 0)
    {
        printf("Player %d win", --player);
    }
    else if(State == 1)
    {
        printf("Game Draw\n");
    }

}
