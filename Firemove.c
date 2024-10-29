#include "headerFile.h"

void fireMove(PLAYER* currentPlayer, PLAYER* opposingPlayer,INPUT input)
{
 
    //extracting the row and col from input
    int row = input.row;
    int col = input.column;
  //  printf("%d", row); debug line
  //checking validation
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE)
    {
        printf("Invalid coordinates");
            return;
    }
    // Check hit or miss
    if (opposingPlayer->grid[row][col] == 'X')
    {
        printf("Hit!\n");
        currentPlayer->hitsAndMissesGrid[row][col] = '*'; // Mark the location of the hit
        addHitOnShip(currentPlayer,opposingPlayer,&input);
    }
    else
    {
        printf("Miss.\n");
       currentPlayer->hitsAndMissesGrid[row][col] = 'o'; // Mark the miss
    }
    // printGrid(opposingPlayer->hitsAndMissesGrid); // Print hits/misses grid
}

//function to register a hit on the ship for the player
void addHitOnShip(PLAYER* currentPlayer,PLAYER* opposingPlayer, INPUT* input)
{

    int hitCoord = input->row*10+input->column; //converting coordinates to integers
    SHIP* currentShip ;
    // loop through each ship the player has
    for(int  i =0;i< 4; i++)
    {
        currentShip= &opposingPlayer->ships[i];
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
                    printf("%s has fallen!\n",currentShip->name); //ship is destroyed
                    currentShip->hasFallen=1;
                    shipFallen(currentPlayer,opposingPlayer,input); //reprecussions of a fallenSHIP


                }
                
            }
        }

        
    }
}

void shipFallen(PLAYER* currentPlayer,PLAYER* opposingPlayer, INPUT* input)
{
    
    opposingPlayer->shipsLeft--;
    currentPlayer->artillery =1;

    if(opposingPlayer->shipsLeft==1)
    {
        currentPlayer->torpedo=1;
    }
}
