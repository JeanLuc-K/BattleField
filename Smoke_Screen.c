#include "headerFile.h"

int smokeScreen(PLAYER* currentPlayer, PLAYER* opposingPlayer,INPUT input )
{
    int shipsSunk = 4- opposingPlayer->shipsLeft;
    if(currentPlayer->smokeScreenCounter>= shipsSunk)
    {
        printf("You cannot hide more than you have sunk ships!Stand Strong!");
        return 0;
    }else{

        int hiddenSquares = 0;
        for(int i = 0 ; i < 4 ; i++)
        {
            if(isInBound(input))
            {
                currentPlayer->smokeGird[input.row][input.column]='X';
                hiddenSquares++;
            }

            updateCoordBySquare(&input, i);
        }
        if(hiddenSquares==0)
        {
            printf("you have hidden absolutely nothing, great job!");
        }
        
    }

    printf("\n");

    
    return 1;

    
}

int isInBound(struct Input input)
{
     if (input.row < 0 || input.row >= GRID_SIZE) {
        return 0;
    }

    
    if (input.column < 0 || input.column >= GRID_SIZE) {
        return 0;
    }

    return 1;
}

void updateCoordBySquare(struct Input*input ,int iteration)
{
    if(iteration ==0)
    {
        input->column++; //move right
    }else if(iteration ==1)
    { 
        input->row++; //down
    }else if(iteration ==2)
    {
        input->column--; //left

    }else if (iteration == 3) 
    {
        input->row--;    //up even though unecessary
    }
}

