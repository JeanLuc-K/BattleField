#include "headerFile.h"

void fireMove(PLAYER* currentPlayer, PLAYER* opposingPlayer,INPUT input)
{
    printf("\n");
  
    //check the validation of the input
    int row = input.row;
    int col = input.column;
  //  printf("%d", row); debug line
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE)
    {
        printf("Invalid coordinates");
            return;
    }
    // Check hit or miss
    if (opposingPlayer->grid[row][col] == 'X')
    {
        printf("Hit!\n");
        opposingPlayer->hitsAndMissesGrid[row][col] = '*'; // Mark the location of the hit
        addHitOnShip(opposingPlayer,&input);
    }
    else
    {
        printf("Miss.\n");
       opposingPlayer->hitsAndMissesGrid[row][col] = 'o'; // Mark the miss
    }
    // printGrid(opposingPlayer->hitsAndMissesGrid); // Print hits/misses grid
}


void addHitOnShip(PLAYER* player, INPUT* input)
{
    int hitCoord = input->row*10+input->column;
    SHIP* currentShip ;
    for(int  i =0;i< 4; i++)
    {
        currentShip= &player->ships[i];
        if(currentShip->hasFallen==1) //skip if the ship has fallen
        {
            continue;
        }

        for(int  j = 0 ; j < currentShip->size;j++)
        {

            if(currentShip->coord[j]==hitCoord)
            {
                currentShip->hits++;

                if(currentShip->hits == currentShip->size)
                {
                    currentShip->hasFallen=1;
                    player->shipsLeft--;
                    printf("%s has fallen!\n",currentShip->name);
                }
                return;
            }
        }

        
    }
}