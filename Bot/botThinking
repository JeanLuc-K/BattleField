#include "../headerFile.h"

void botThinking(PLAYER *currentPlayer, PLAYER *opposingPlayer)
{
    
    printf("\n\n THE PROBABILITY GRID IS: \n\n");
    printGridInt(currentPlayer->probGrid);
    
    //first we do the radars

    int radarResult = handleRadar(currentPlayer,opposingPlayer);
    if(radarResult==1)
    {
       
        calculateProbability(currentPlayer,opposingPlayer);
        
        return;
    }



     
    calculateProbability(currentPlayer,opposingPlayer);
}
