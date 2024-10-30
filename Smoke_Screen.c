#include "headerFile.h"
//this function hide a 2x2 area on the player's grid
void smokeScreen(PLAYER* currentPlayer, PLAYER* opposingPlayer,INPUT input )
{   //calculating the number of lost ships
    int shipsSunk = 4- opposingPlayer->shipsLeft;
    //check if the player has used this function >= to the number of sunk ships
    if(currentPlayer->smokeScreenCounter>= shipsSunk)
    {
        printf("You cannot hide more than you have sunk ships!Stand Strong\n!");
        return;
    }
    else if (isInBound(&input)==0)
    {
        printf("Invalid coord\n");
        return;
    }
    else
    {

        int hiddenSquares = 0; // counter for squares that are hidder successfully
         //looping from the given coordinates
        for(int i = 0 ; i < 4 ; i++)
        {
            if(isInBound(&input))
            {
                currentPlayer->smokeGird[input.row][input.column]='X';
                hiddenSquares++;
            }

            updateCoordBySquare(&input, i);
        }
        //check if no squares were hidden
        if(hiddenSquares==0)
        {
            printf("let it be known that you have hidden absolutely no square, great job!");
        }
        
    }

    printf("\n");

    //increament the counter to track the number of times this move has been used
    currentPlayer->smokeScreenCounter++;

    
}
//function to check the validation of the given input
int isInBound(INPUT* input)
{
     if (input->row < 0 || input->row >= GRID_SIZE) {
        return 0;
    }

    
    if (input->column < 0 || input->column >= GRID_SIZE) {
        return 0;
    }

    return 1;
}
//function to update the coordinates to move around the square area
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
