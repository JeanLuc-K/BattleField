
#include "headerFile.h"

//Requires: Valid PLAYER objects for currentPlayer and opposingPlayer and valid INPUT object input.
//Returns: Updates hit or miss on the grid and adjusts targeting strategy based on previous hits based on bot's strategy.
void fireMoveBot(PLAYER* currentPlayer, PLAYER* opposingPlayer, INPUT* input) {
    int row = -1, col = -1;

    
    if (!findNextTarget(currentPlayer, &row, &col)) {
        // If no valid target found, randomly pick
        randomFire(opposingPlayer, &row, &col);
    }
    //since i pass pointer of row and column so original value of input will be updates in the findNextTarget
    // Process hit or miss
   fireMove(currentPlayer,opposingPlayer,input);
}


//Requires: The current player object and pointers to row and column variables
//Returns: Updates the bot's input based on previouses hits to hit adjacent cells and returns 0 if no valid target found
int findNextTarget(PLAYER* currentPlayer, int* row, int* col) {
    // Search adjacent cells if there's a last hit
    // -1: unknown
    static int lastHitRow = -1, lastHitCol = -1;
    static int orientation = -1; 

    if (lastHitRow != -1 && lastHitCol != -1) {
        if (orientation == HORIZONTAL || orientation == -1) { // Check horizontally
            if (isValidAndUnguessed(currentPlayer, lastHitRow, lastHitCol + 1)) {
                *row = lastHitRow;
                *col = lastHitCol + 1;
                orientation = HORIZONTAL;
                return 1;
            }
            if (isValidAndUnguessed(currentPlayer, lastHitRow, lastHitCol - 1)) {
                *row = lastHitRow;
                *col = lastHitCol - 1;
                orientation = HORIZONTAL;
                return 1;
            }
        }
        if (orientation == VERTICAL|| orientation == -1) { // Check vertically
            if (isValidAndUnguessed(currentPlayer, lastHitRow + 1, lastHitCol)) { //check grid after hit
                *row = lastHitRow + 1;
                *col = lastHitCol;
                orientation = VERTICAL;
                return 1;
            }
            if (isValidAndUnguessed(currentPlayer, lastHitRow - 1, lastHitCol)) { //check grid before hit
                *row = lastHitRow - 1;
                *col = lastHitCol;
                orientation = VERTICAL;
                return 1;
            }
        }
    }
    return 0; // No valid targets found in targeting phase
}

//Requires:The current player object and pointers to row and column variables
//Returns: A random input for row and column if not valid input was found
void randomFire(PLAYER* opposingPlayer, int* row, int* col) {
    int attempts = 0;
    do {
        *row = rand() % GRID_SIZE;
        *col = rand() % GRID_SIZE;
        attempts++;// prevents infinite loops 
    } while (opposingPlayer->hitsAndMissesGrid[*row][*col] != ' ' && attempts < GRID_SIZE * GRID_SIZE);

    // If a random spot was not found or all random cells checked are already guessed, it systematically searches the entire grid
    if (opposingPlayer->hitsAndMissesGrid[*row][*col] != ' ') {
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (opposingPlayer->hitsAndMissesGrid[i][j] == ' ') {
                    *row = i;
                    *col = j;
                    return;
                }
            }
        }
    }
}



//Requires: Valid PLAYER objects for currentPlayer and opposingPlayer and valid INPUT object input.
//Returns: Adds missed coordinates to the bot's strategy for more intelligent targeting and applies artillery move
void artilleryBot(PLAYER* currentPlayer, PLAYER* opposingPlayer, INPUT* input) {
    int row, col;
    
    // Try to target areas near recent misses
    if (targetNearRecentMisses(currentPlayer, &row, &col)) {
        input->row = row;
        input->column = col;
        artilleryMove(currentPlayer, opposingPlayer, input);
        return;
    }

    // If no valid area near recent misses, fallback to random targeting
    randomFireWithBias(currentPlayer, opposingPlayer, &row, &col);

    input->row = row;
    input->column = col;

   
    artilleryMove(currentPlayer, opposingPlayer, input);
}

//Requires: The current player object and pointers to row and column variables
//Returns: Updates the bot's input based on previouses misses to search adjacent cells and returns 0 if no valid target found
int targetNearRecentMisses(PLAYER* currentPlayer, int* row, int* col) {
    // Iterate through previously missed cells and attempt to strike nearby
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (currentPlayer->hitsAndMissesGrid[i][j] == 'o') {  
                // If we have a miss attempt to target adjacent cells
                if (isValidAndUnguessed(currentPlayer, i + 1, j)) {
                    *row = i + 1;
                    *col = j;
                    return 1;
                }
                if (isValidAndUnguessed(currentPlayer, i - 1, j)) {
                    *row = i - 1;
                    *col = j;
                    return 1;
                }
                if (isValidAndUnguessed(currentPlayer, i, j + 1)) {
                    *row = i;
                    *col = j + 1;
                    return 1;
                }
                if (isValidAndUnguessed(currentPlayer, i, j - 1)) {
                    *row = i;
                    *col = j - 1;
                    return 1;
                }
            }
        }
    }
    return 0; // No valid target near recent misses
}



//Require: Valid PLAYER object currentPlayer and coordinates of row and col within grid bounds (0-9).
//Returns: Returns 1 if the coordinate is valid and unguessed, otherwise 0.

int isValidAndUnguessed(PLAYER* currentPlayer, int row, int col) {
    if (row >= 0 && row < 10 && col >= 0 && col < 10) {
        if (currentPlayer->hitsAndMissesGrid[row][col] == ' ') {
            return 1; // Valid and unguessed
        }
    }
    return 0; // Invalid or already guessed
}

// Requires: Valid PLAYER objects and INPUT within grid bounds.  
// Returns: Scans 2x2 area for enemy ships, ignoring smoke and displays result and increments radarSweep (max 3 uses).  
void radarSweepBot(PLAYER* currentPlayer, PLAYER* opposingPlayer, INPUT* input) {
    int row, col;

    // Prioritize sweeping near recent missed cells
    if (targetNearRecentMisses(currentPlayer, &row, &col)) {
        input->row = row;
        input->column = col;
        radarSweep(currentPlayer, opposingPlayer, input);
        return;
    }

    randomTargetWithBias(currentPlayer, opposingPlayer, &row, &col);

    input->row = row;
    input->column = col;

    // Perform the radar sweep on a 2x2 grid centered around the chosen cell
    radarSweep(currentPlayer, opposingPlayer, input);
}

