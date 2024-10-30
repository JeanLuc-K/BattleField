#include "headerFile.h"

void torpedo(PLAYER* currentPlayer, PLAYER* opposingPlayer, INPUT* input) {
    // check if torpedo can be used: allow only if not used and condition met

    
    if (currentPlayer->torpedo!=2) {
        printf("conditions are not met.\n");
        return;
    }
    // handeling cases where row or column is -1
    if (input->row == -1 && input->column == -1) {
        printf(" row and column are out of bounds.\n");
        return;
    }

// Targeting an entire row if column = -1
if (input->column == -1) 
{
    if (input->row < 0 || input->row >= GRID_SIZE) {
        printf("Invalid row index.\n");
        return;
    }
    for (int col = 0; col < GRID_SIZE; col++) {  // Loop through each column
        if (opposingPlayer->grid[input->row][col] == 'X') { 
            currentPlayer->hitsAndMissesGrid[input->row][col] = '*'; // Mark the location of the hit
            
            input->column = col;

            addHitOnShip(currentPlayer, opposingPlayer, input); // Update the hit count of the ship

            printf("Hit at row %d, col %d\n", input->row, col);
        } else {
            currentPlayer->hitsAndMissesGrid[input->row][col] = 'o'; // Mark miss
            printf("Miss at row %d, col %d\n", input->row, col);
        }
    }
}
// Targeting an entire column if row = -1
else if (input->row == -1) 
{
    if (input->column < 0 || input->column >= GRID_SIZE) {
        printf("Invalid column index.\n");
        return;
    }
    for (int row = 0; row < GRID_SIZE; row++) { // Loop through each row
        if (opposingPlayer->grid[row][input->column] == 'X') {
            currentPlayer->hitsAndMissesGrid[row][input->column] = '*'; // Mark the location of the hit
            
            input->row=row;

            addHitOnShip(currentPlayer, opposingPlayer, input); // Update the hit count of the ship

            printf("Hit at row %d, col %d\n", row, input->column);
        } else {
            currentPlayer->hitsAndMissesGrid[row][input->column] = 'o'; // Mark miss
            printf("Miss at row %d, col %d\n", row, input->column);
        }
    }


    } else {
        printf("Invalid direction. Use 'R' for row or 'C' for column\n");
        return;
    }

}

void checkTorpedo(PLAYER* currentPlayer)
{
    if(currentPlayer ->torpedo==2)
    {
        currentPlayer->torpedo =0;
    }
   if(currentPlayer->torpedo ==1)
    {
        printf("Special move unlocked for 1 turn: torpedo!\n");
        currentPlayer->torpedo=2;
    }
}