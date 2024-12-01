#include "../headerFile.h"

void handleArtillery(PLAYER *currentPlayer, PLAYER *opposingPlayer)
{
    //no condition since its met throught the botThinking
    

    squareCoords squareCoord = getSquareCoord(currentPlayer->probGrid);

    INPUT input;
    input.row=squareCoord.maxCoords->row;
    input.column = squareCoord.maxCoords->col;
    
    printf("The bot plays Artillery %c%d \n", 97+input.column ,input.row+1);
    artilleryMove(currentPlayer,opposingPlayer,&input);

}
