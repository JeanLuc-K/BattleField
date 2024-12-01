#include "headerFile.h"

void printSquareCoords(squareCoords *sc) {
    if (sc == NULL) {
        printf("Null squareCoords structure passed.\n");
        return;
    }

    printf("Number of coordinates: %d\n", sc->size);
    printf("Coordinates (row, column):\n");

    // Loop through and print each valid coordinate
    for (int i = 0; i < sc->size; i++) {
        printf("Coord %d: Row = %d, Column = %d\n", i + 1, sc->maxCoords[i].row, sc->maxCoords[i].col);
    }
}

int handleRadar(PLAYER *currentPlayer, PLAYER *opposingPlayer)
{

    //if bot already used all radarsweeps skip
    if(currentPlayer->radarSweep >=3 )
    {
        return ILLEGALMOVE;
    }
    //get what square to radar
    

    squareCoords squareCoord = getSquareCoord(currentPlayer->probGrid);
    
    printSquareCoords(&squareCoord);


    INPUT input;
    input.row=squareCoord.maxCoords->row;
    input.column = squareCoord.maxCoords->col;
    
    printf("The bot plays Radar %c%d \n", 97+input.column ,input.row+1);

    int moveResult = RadarSweep(currentPlayer,opposingPlayer,&input); //use radar
    
    //this means that the opponent didn't hide anything so we can trsut in the misses and hits of our radar
    
    if(opposingPlayer->smokeScreenCounter==0)
    {
        
        if(moveResult==SHIPSNOTFOUND)
        {
            for(int  i = 0; i < 4 ;++i )
            {
                currentPlayer->hitsAndMissesGrid[input.row][input.column]='o';
                updateCoordBySquare(&input,i);
            }
        }else if(moveResult ==SHIPSFOUND)
        {
             //update the probabilty of the four sqaures to -1 to represent the certanty that a ship might be there
            for(int  i = 0; i < 4 ;++i )
            {
                currentPlayer->probGrid[input.row][input.column]=-1;
                updateCoordBySquare(&input,i);
            }

           
           
        }

    }else
    {
        if(moveResult ==SHIPSFOUND)
        {
            for(int  i = 0; i < 4 ;++i )
            {
                currentPlayer->probGrid[input.row][input.column]=-1;
                updateCoordBySquare(&input,i);
            }
            //update the prob of the four squares
        }
    }
    return 1;
    

}
