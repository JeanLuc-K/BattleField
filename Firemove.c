#include "headerFile.h"

void fireMove(PLAYER* currentPlayer, PLAYER* opposingPlayer,INPUT input)
{
    printf("\n");
  
    //extracting the row and column from the input
    int row = input.row;
    int col = input.column;
  //  printf("%d", row); debug line
    //check validation for the input
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE)
    {
        printf("Invalid coordinates");
            return;
    }
    // check if hits or miss
    if (opposingPlayer->grid[row][col] == 'X')
    {
        printf("Hit!\n");
        opposingPlayer->hitsAndMissesGrid[row][col] = '*'; // Mark the location of the hit
        addHitOnShip(opposingPlayer,&input); //call this function to mark the hit on the grid
    }
    else
    {
        printf("Miss.\n");
       opposingPlayer->hitsAndMissesGrid[row][col] = 'o'; // Mark the miss
    }
    // printGrid(opposingPlayer->hitsAndMissesGrid); // Print hits/misses grid
}

//function to register a hit on the ship for the player
void addHitOnShip(PLAYER* player, INPUT* input)
{
    int hitCoord = input->row*10+input->column; // converting the coordinates to integer
    SHIP* currentShip ;
    // loop through each ship the player has
    for(int  i =0;i< 4; i++)
    {
        currentShip= &player->ships[i];
        if(currentShip->hasFallen==1) //skip if the ship has fallen
        {
            continue;
        }
    //check if any coordinate in the ship matches the hit one
        for(int  j = 0 ; j < currentShip->size;j++)
        {

            if(currentShip->coord[j]==hitCoord) //if the current ship is hitten
            {
                currentShip->hits++; //increament the hit counter for the ship

                if(currentShip->hits == currentShip->size)
                {
                    currentShip->hasFallen=1; 
                    player->shipsLeft--;
                    printf("%s has fallen!\n",currentShip->name); //notify that the ship is destroyed
                }
                return;
            }
        }

        
    }
}
