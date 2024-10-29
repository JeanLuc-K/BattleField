#include "headerFile.h"

//radar sweep function checks in a 2x2 area if it exists enemy ships and display result

void RadarSweep(PLAYER* currentPlayer, PLAYER* opposingPlayer,INPUT* input){
    //every player is allowed 3 radar sweeps per entire game

    if (currentPlayer->radarSweep >= 3){
        printf("No radar sweeps remaining.\n");
            return;
    }
    //check the validation of the input
    int row = input->row;
    int col = input->column;
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE)
    {
        printf("Invalid coordinates");
            return;
    }
    int enemyFound = 0; //creating a boolean if we found it updates to 1
    //checking the 2x2 grid starting from the row and col provided
    for (int i = row; i < row +2 && i < GRID_SIZE; i++)
    {
        for (int j = col; j < col + 2 && j < GRID_SIZE; j++){
        if (opposingPlayer->grid[i][j] == 'X')
        {
            if(opposingPlayer->smokeGird[i][j]!='X') //check if its not hidden by smoke
            {
                enemyFound = 1;
                break; //we exist the loop when we find an enemy
            }
            
        }
    }
    if (enemyFound)
    {
        printf("Enemy ships found");
    }
    else
    {
        printf("No enemy ships found");
    }
        currentPlayer->radarSweep++; //adding to check after if it exceeds 3
    }
}