#include "headerFile.h"

void artilleryMove(PLAYER* currentPlayer, PLAYER* opposingPlayer,INPUT* input)
{
    if (currentPlayer->artillery!=2) { // i can only access this move if at least 1 ship is sunk
        printf("Artillery conditions are not met.\n");
        return;
    }
    //check the validation of the input
    if (isInBound(input)==0)
    {
        printf("Invalid coord\n");
        return;
    }
    

    for (int i = 0; i < NUMBEROFSHIPS; i++)
    {
        
            // Make sure I dont go out of bounds
            if (isInBound(input)==1)
            {
                // Check for a hit in the grid
                if (opposingPlayer->grid[input->row][input->column] == 'X')
                {
                    printf("Hit!\n");
                    if(currentPlayer->hitsAndMissesGrid[input->row][input->column]!='*')
                    {
                        currentPlayer->hitsAndMissesGrid[input->row][input->column] = '*'; // Mark the location of the hit
                        addHitOnShip(currentPlayer, opposingPlayer,input); //update the hit count of the ship
               
                    }
                }
                else
                {
                    printf("Miss.\n");
                    currentPlayer->hitsAndMissesGrid[input->row][input->column] = 'o';
                    
                }
            }

            updateCoordBySquare(input,i);
    }

    
//printGrid(opposingPlayer->hitsAndMissesGrid);
}

//checking if we can use this move
//first when artillery can be used , it is set to one, the first iteration its updated to 2 so that the second itert=ation its back to 0 so ca't be used again
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
