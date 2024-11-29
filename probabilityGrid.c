#include "headerFile.h"


/************************************
    To calculate the probabilty GRID
*************************************/

int isInBound2(int row, int column) {
    if (row < 0 || row >= GRID_SIZE) {
        return 0;
    }

    if (column < 0 || column >= GRID_SIZE) {
        return 0;
    }

    return 1;
}

// Check horizontally for a possible hit
int foundHitHorizontal(int row, int col, int shipSize, PLAYER* currentPlayer) {
    for (int colShift = 0; colShift < shipSize; ++colShift) {
        if (!isInBound2(row, col + colShift)) {
            return 1;  // Out of bounds, stop checking
        }
        if (currentPlayer->hitsAndMissesGrid[row][col + colShift] == '*') {
            return 1;  // A hit is detected
        }
        if(difficulty==EASY)
        {
            if(currentPlayer->hitsAndMissesGrid[row][col+colShift]=='o')
            {
                return 1; //there was a miss
            }
        }
    }
    return 0;  // No hit detected
}

// Check vertically for a possible hit
int foundHitVertical(int row, int col, int shipSize, PLAYER* currentPlayer) {
    for (int rowShift = 0; rowShift < shipSize; ++rowShift) {
        if (!isInBound2(row + rowShift, col)) {
            return 1;  // Out of bounds, stop checking
        }
        if (currentPlayer->hitsAndMissesGrid[row + rowShift][col] == '*') {
            return 1;  // A hit is detected
        }

        if(difficulty==EASY)
        {
            if(currentPlayer->hitsAndMissesGrid[row+rowShift][col]=='o')
            {
                return 1; //there was a miss
            }
        }
    }
    return 0;  // No hit detected
}

void calculateProbability(PLAYER* currentPlayer, PLAYER* opposingPlayer) {
    printf("Calculating probability...\n");

    initializeProbGrid(currentPlayer->probGrid);
    for (int shipIndex = 0; shipIndex < NUMBEROFSHIPS; ++shipIndex) {
        SHIP currentShip = opposingPlayer->ships[shipIndex];

        // Only consider ships that have not fallen
        if (currentShip.hasFallen == 0) {
            int currentShipSize = currentShip.size;

            // Loop through every possible cell in the grid
            for (int row = 0; row < GRID_SIZE; ++row) {
                for (int col = 0; col < GRID_SIZE; ++col) {
                    
                    int foundHit = 0;

                    // Check for horizontal placement
                    if (!foundHitHorizontal(row, col, currentShipSize, currentPlayer)) {
                        // Update probability grid if no hit was found
                        if (isInBound2(row, col + currentShipSize - 1)) {  // Ensure horizontal ship can fit
                            for (int colShift = 0; colShift < currentShipSize; ++colShift) {
                                ++currentPlayer->probGrid[row][col + colShift];
                            }
                        }
                    }

                    // Reset found hit for vertical check
                    foundHit = 0;

                    // Check for vertical placement
                    if (!foundHitVertical(row, col, currentShipSize, currentPlayer)) {
                        // Update probability grid if no hit was found
                        if (isInBound2(row + currentShipSize - 1, col)) {  // Ensure vertical ship can fit
                            for (int rowShift = 0; rowShift < currentShipSize; ++rowShift) {
                                ++currentPlayer->probGrid[row + rowShift][col];
                            }
                        }
                    }
                }
            }
        }
    }

  
}



/************************************
    to calculate the sum of a 2x2 grid starting at (i, j)
*************************************/
int calculateSum(int grid[GRID_SIZE][GRID_SIZE], int i, int j) {
    int sum = 0;

    // Iterate through the 2x2 grid
    for (int row = i; row < i + 2; row++) {
        for (int col = j; col < j + 2; col++) {
            // Only add values if they are within bounds
            if (row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE) {
                sum += grid[row][col];
            }
        }
    }
    return sum;
}

// Function to find and return the list of coordinates of the 2x2 subgrids with the max sum
int findMaxSumCoords(int grid[GRID_SIZE][GRID_SIZE], Coord coords[MAX_COORDS]) {
    int maxSum = -1;  // To store the maximum sum found
    int count = 0;    // To track the number of coordinates with the max sum

    // Iterate over all possible starting coordinates for the 2x2 grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int sum = calculateSum(grid, i, j);  // Calculate sum of 2x2 grid starting at (i, j)

            // If the sum is greater than the current max, update the max and reset the list of coordinates
            if (sum > maxSum) {
                maxSum = sum;
                count = 0;  // Reset the list of coordinates
                coords[count].row = i;
                coords[count].col = j;
                count++;
            }
            // If the sum is equal to the current max, add the coordinate to the list
            else if (sum == maxSum) {
                coords[count].row = i;
                coords[count].col = j;
                count++;
            }
        }
    }

    return count;  // Return the number of coordinates with the maximum sum
}

// Function to get the coordinates with the maximum sum from the probGrid
squareCoords getSquareCoord(int probGrid[GRID_SIZE][GRID_SIZE]) {
    
    squareCoords squareCoord;  // Create a squareCoords structure
    squareCoord.size = 0;      // Initialize size to 0

    // Call the function to find all coordinates with the max sum
    squareCoord.size = findMaxSumCoords(probGrid, squareCoord.maxCoords);

    return squareCoord;
}
