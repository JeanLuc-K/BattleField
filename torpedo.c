#include "headerFile.h"
#include <stdio.h>

void Torpedo(PLAYER* currentPlayer, PLAYER* opposingPlayer, INPUT* input) {
    int torpedoUsed = 0; // when its 1 then we cant do the move

    // check if torpedo can be used: allow only if not used and condition met
    if (torpedoUsed && currentPlayer->shipsLeft > 3) {
        printf("torpedo already used or conditions are not met.\n");
        return;
    }

    char direction = input->direction;
    int rowOrCol = input->rowOrCol;

    // handeling cases where row or column is -1
    if (input->row == -1 && input->column == -1) {
        printf(" row and column are out of bounds.\n");
        return;
    }

    // targeting an entire row if column = -1
    if (direction == 'R' || direction == 'r') {
        if (input->column == -1) {
            int row = rowOrCol;
            if (row < 0 || row >= GRID_SIZE) {
                printf("Invalid row index.\n");
                return;
            }
            for (int col = 0; col < GRID_SIZE; col++) {
                if (opposingPlayer->grid[row][col] == '*') { 
                    opposingPlayer->grid[row][col] = 'X'; // mark hit
                    printf("Hit at row %d, col %d\n", row, col);
                } else {
                    opposingPlayer->grid[row][col] = 'o'; // mark miss w bl hard betdall wave
                    printf("Miss at row %d, col %d\n", row, col);
                }
            }
        }
    }
    // targeting an entire column if row = -1
    else if (direction == 'C' || direction == 'c') {
        if (input->row == -1) {
            int col = rowOrCol;
            if (col < 0 || col >= GRID_SIZE) {
                printf("Invalid column index.\n");
                return;
            }
            for (int row = 0; row < GRID_SIZE; row++) {
                if (opposingPlayer->grid[row][col] == '*') {
                    opposingPlayer->grid[row][col] = 'X';
                    printf("Hit at row %d, col %d\n", row, col);
                } else {
                    opposingPlayer->grid[row][col] = 'o';
                    printf("Miss at row %d, col %d\n", row, col);
                }
            }
        }
    } else {
        printf("Invalid direction. Use 'R' for row or 'C' for column\n");
        return;
    }

    // mark torpedo used
    torpedoUsed = 1;
    printf("Torpedo used successfully.\n");
}
