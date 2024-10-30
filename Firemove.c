#include "headerFile.h"

void fireMove(PLAYER* currentPlayer, PLAYER* opposingPlayer,INPUT* input)
{
 
    //extracting the row and col from input
    int row = input->row;
    int col = input->column;
  //  printf("%d", row); debug line
    
    //checking validation
    if (isInBound(input)==0)
    {
        printf("Invalid coordinates\n");
            return;
    }

    // Check hit or miss
    if (opposingPlayer->grid[row][col] == 'X')
    {
        if(currentPlayer->hitsAndMissesGrid[row][col]=='*')
        {
            printf("congrats on hitting the same place twice!\n");
            return;
        }
        printf("Hit!\n");
        currentPlayer->hitsAndMissesGrid[row][col] = '*'; // Mark the location of the hit
        addHitOnShip(currentPlayer,opposingPlayer,input);
    }
    else
    {
        if(currentPlayer->hitsAndMissesGrid[row][col]=='o')
        {
            if(difficulty=EASY)
            {
                printf("why?\n");
                return;
            }
        }
        printf("Miss.\n");
       currentPlayer->hitsAndMissesGrid[row][col] = 'o'; // Mark the miss
    }
}

//function to register a hit on the ship for the player
void addHitOnShip(PLAYER* currentPlayer,PLAYER* opposingPlayer, INPUT* input)
{

    int hitCoord = input->row*10+input->column; //converting coordinates to integers
    SHIP* currentShip ;
    //loop over each ship 
    for(int  i =0;i< NUMBEROFSHIPS; i++)
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
