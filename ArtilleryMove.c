
#include "headerFile.h"
//functio to perfom an artillery attack on a 2x2 area
void artilleryMove(PLAYER* currentPlayer, PLAYER* opposingPlayer,INPUT input)
{
    //check if the move is allowed, it requiered at least one ship on the sunk
    if (opposingPlayer->shipsLeft > 4) { // i can only access this move if at least 1 ship is sunk
        printf("Artillery conditions are not met.\n");
        return;
    }
    //define the starting point from the input
    int startrow = input.row-1;
    int startcol = input.column;
    //check the validation of the input
    if (startrow < 0 || startrow >= GRID_SIZE || startcol < 0 || startcol >= GRID_SIZE)
    {
        printf("Invalid coordinates");
        return;
     
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            // Check the 2x2 area starting from inputed coordinates
            int row = startrow + i;
            int column = startcol + j;
            // Make sure I dont go out of bounds
            if (row < GRID_SIZE && column < GRID_SIZE)
            {
                // Check for a hit in the grid
                if (opposingPlayer->grid[row][column] == 'X')
                {
                    printf("Hit!\n");
                    opposingPlayer->hitsAndMissesGrid[row][column] = '*'; // Mark the location of the hit
                    addHitOnShip(opposingPlayer,&input); //update the hit count of the ship
                }
                else
                {
                    printf("Miss.\n");
                    opposingPlayer->hitsAndMissesGrid[row][column] = 'o';
                    
                }
            }
        }
    }
//printGrid(opposingPlayer->hitsAndMissesGrid);

}
