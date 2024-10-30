#include "headerFile.h"

void artilleryMove(PLAYER* currentPlayer, PLAYER* opposingPlayer,INPUT* input)
{
    if (opposingPlayer->shipsLeft > 4) { // i can only access this move if at least 1 ship is sunk
        printf("Artillery conditions are not met.\n");
        return;
    }
    //check the validation of the input
    if (isInBound(input)==0)
    {
        printf("Invalid coord\n");
        return;
    }
    

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            // Check the 2x2 area starting from inputed coordinates
            input->row+= i ;
            input->column+=j;
            // Make sure I dont go out of bounds
            if (input->row < GRID_SIZE && input->column < GRID_SIZE)
            {
                // Check for a hit in the grid
                if (opposingPlayer->grid[input->row][input->column] == 'X')
                {
                    printf("Hit!\n");
                    currentPlayer->hitsAndMissesGrid[input->row][input->column] = '*'; // Mark the location of the hit
                    addHitOnShip(currentPlayer, opposingPlayer,input); //update the hit count of the ship
                }
                else
                {
                    printf("Miss.\n");
                    currentPlayer->hitsAndMissesGrid[input->row][input->column] = 'o';
                    
                }
            }
        }
    }
//printGrid(opposingPlayer->hitsAndMissesGrid);
}

//checking if we can use this move
void checkArtillery(PLAYER* currentPlayer)
{
    if(currentPlayer->artillery==2 )
    {
        currentPlayer->artillery=0;
    }

     if(currentPlayer->artillery==1)
    {
        printf("Special move unlocked for 1 turn: artillery!\n");
        currentPlayer->artillery=2;

    }
}
