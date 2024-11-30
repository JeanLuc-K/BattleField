
#include "headerFile.h"

int lastRadarRow = -1;
int lastRadarCol = -1;
int lastRadarFoundShip = 0;

// Requires: Valid PLAYER objects for currentPlayer and opposingPlayer and valid INPUT object input.
// Returns: Updates hit or miss on the grid and adjusts targeting strategy based on previous hits based on bot's strategy.
void fireMoveBot(PLAYER *currentPlayer, PLAYER *opposingPlayer, INPUT *input)
{
    int row = -1, col = -1;

    if (!findNextTarget(currentPlayer, &row, &col))
    {
        // If no valid target found, randomly pick
        chooseHighestProbability(&row, &col);
    }
    if (RadarSweep == 1)
    {
        // Ships are found, so target the detected area
        lastRadarRow = row;
        lastRadarCol = col;
        lastRadarFoundShip = 1; // Mark the area as containing ships
        targetDetectedShipArea(currentPlayer, opposingPlayer, row, col, input);
    }
    else if (RadarSweep == 0)
    {
        // No ships found, avoid re-targeting this area
        lastRadarFoundShip = 0; // Mark as no ships found

        do
        {
            randomFire(opposingPlayer, &row, &col);
        } while (row >= lastRadarRow && row < lastRadarRow + 2 &&
                 col >= lastRadarCol && col < lastRadarCol + 2);
    }

    // since i pass pointer of row and column so original value of input will be updates in the findNextTarget
    //  Process hit or miss
    fireMove(currentPlayer, opposingPlayer, input);
}

// Requires: The current player object and pointers to row and column variables
// Returns: Updates the bot's input based on previouses hits to hit adjacent cells and returns 0 if no valid target found
int findNextTarget(PLAYER *currentPlayer, int *row, int *col)
{
    // -1: unknown
    static int lastHitRow = -1, lastHitCol = -1;
    static int orientation = -1;

    if (lastHitRow != -1 && lastHitCol != -1)
    {
        if (orientation == HORIZONTAL || orientation == -1)
        { // if it horizontal or unknown try searching horizontally
            if (isValidAndUnguessed(currentPlayer, lastHitRow, lastHitCol + 1))
            {
                *row = lastHitRow;
                *col = lastHitCol + 1;
                orientation = HORIZONTAL;
                return 1;
            }
            if (isValidAndUnguessed(currentPlayer, lastHitRow, lastHitCol - 1))
            {
                *row = lastHitRow;
                *col = lastHitCol - 1;
                orientation = HORIZONTAL;
                return 1;
            }
        }
        if (orientation == VERTICAL || orientation == -1)
        { // if it vertical or unknown try searching vertically
            if (isValidAndUnguessed(currentPlayer, lastHitRow + 1, lastHitCol))
            { // check grid after hit
                *row = lastHitRow + 1;
                *col = lastHitCol;
                orientation = VERTICAL;
                return 1;
            }
            if (isValidAndUnguessed(currentPlayer, lastHitRow - 1, lastHitCol))
            { // check grid before hit
                *row = lastHitRow - 1;
                *col = lastHitCol;
                orientation = VERTICAL;
                return 1;
            }
        }
    }
    // Reset if no valid adjacent cells found
    lastHitRow = -1;
    lastHitCol = -1;
    orientation = -1;
    return 0; // No valid targets found in targeting phase
}

// Requires: Valid PLAYER objects for currentPlayer and opposingPlayer and valid INPUT object input.
// Returns: Adds missed coordinates to the bot's strategy for more intelligent targeting and applies artillery move
void artilleryBot(PLAYER *currentPlayer, PLAYER *opposingPlayer, INPUT *input)
{
    int row, col;

    // Try to target areas near recent misses
    if (targetNearRecentMisses(currentPlayer, &row, &col))
    {
        input->row = row;
        input->column = col;
        artilleryMove(currentPlayer, opposingPlayer, input);
        return;
    }

chooseHighestProbability(&row, &col);

    input->row = row;
    input->column = col;

    artilleryMove(currentPlayer, opposingPlayer, input);
}

// Requires: The current player object and pointers to row and column variables
// Returns: Updates the bot's input based on previouses misses to search adjacent cells and returns 0 if no valid target found
int targetNearRecentMisses(PLAYER *currentPlayer, int *row, int *col)
{
    // Iterate through previously missed cells and attempt to strike nearby
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (currentPlayer->hitsAndMissesGrid[i][j] == 'o')
            {
                // If we have a miss attempt to target adjacent cells
                if (isValidAndUnguessed(currentPlayer, i + 1, j))
                {
                    *row = i + 1;
                    *col = j;
                    return 1;
                }
                if (isValidAndUnguessed(currentPlayer, i - 1, j))
                {
                    *row = i - 1;
                    *col = j;
                    return 1;
                }
                if (isValidAndUnguessed(currentPlayer, i, j + 1))
                {
                    *row = i;
                    *col = j + 1;
                    return 1;
                }
                if (isValidAndUnguessed(currentPlayer, i, j - 1))
                {
                    *row = i;
                    *col = j - 1;
                    return 1;
                }
            }
        }
    }
    return 0; // No valid target near recent misses
}

// Require: Valid PLAYER object currentPlayer and coordinates of row and col within grid bounds (0-9).
// Returns: Returns 1 if the coordinate is valid and unguessed, otherwise 0.

int isValidAndUnguessed(PLAYER *currentPlayer, int row, int col)
{
    if (row >= 0 && row < 10 && col >= 0 && col < 10)
    {
        if (currentPlayer->hitsAndMissesGrid[row][col] == ' ')
        {
            return 1; // Valid and unguessed
        }
    }
    return 0; // Invalid or already guessed
}

// Requires: Valid PLAYER objects and INPUT within grid bounds.
// Returns: Scans 2x2 area for enemy ships, ignoring smoke and displays result and increments radarSweep (max 3 uses).
void radarSweepBot(PLAYER *currentPlayer, PLAYER *opposingPlayer, INPUT *input)
{
    int row, col;

    // Prioritize sweeping near recent missed cells
    if (targetNearRecentMisses(currentPlayer, &row, &col))
    {
        input->row = row;
        input->column = col;
        radarSweep(currentPlayer, opposingPlayer, input);
        lastRadarRow = row;
        lastRadarCol = col;
        return;
    }

  chooseHighestProbability(&row, &col);

    input->row = row;
    input->column = col;

    // Perform the radar sweep on a 2x2 grid centered around the chosen cell
    RadarSweep(currentPlayer, opposingPlayer, input);
    lastRadarRow = row;
    lastRadarCol = col;
}

// Function to target the detected ship area
// pass the same coordinated i pass for radar sweep if enemyship found
void targetDetectedShipArea(PLAYER *currentPlayer, PLAYER *opposingPlayer, int row, int col, INPUT *input)
{
    for (int i = row; i < row + 2; i++)
    { // Check a 2x2 area
        for (int j = col; j < col + 2; j++)
        {
            if (isValidAndUnguessed(currentPlayer, i, j))
            {
                input->row = i;
                input->column = j;
                return; // Return once a valid target is found
            }
        }
    }
}

int findTorpedoTarget(PLAYER* currentPlayer, int* row, int* col, int* getOrientation) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (currentPlayer->hitsAndMissesGrid[i][j] == '*') {  // Found a recent hit
                *row = i;
                *col = j;
                // Determine ship orientation based on adjacent cells (vertical or horizontal)
                if (i > 0 && currentPlayer->hitsAndMissesGrid[i - 1][j] == '*') {  // Check row above for vertical
                    *getOrientation = VERTICAL;  // Ship is vertical
                } else if (i < GRID_SIZE - 1 && currentPlayer->hitsAndMissesGrid[i + 1][j] == '*') {  // Check row below for vertical
                    *getOrientation = VERTICAL;  // Ship is vertical
                } else if (j > 0 && currentPlayer->hitsAndMissesGrid[i][j - 1] == '*') {  // Check left for horizontal
                    *getOrientation = HORIZONTAL;  // Ship is horizontal
                } else if (j < GRID_SIZE - 1 && currentPlayer->hitsAndMissesGrid[i][j + 1] == '*') {  // Check right for horizontal
                    *getOrientation = HORIZONTAL;  // Ship is horizontal
                }

                // If orientation is determined, stop searching
                if (*getOrientation != -1) {
                    return 1;  // Return 1 to indicate we found a target
                }
            }
        }
    }
    return 0;  // Return 0 if no target found
}

void torpedoBot(PLAYER* currentPlayer, PLAYER* opposingPlayer) {
    if (currentPlayer->torpedo >= 2) {  // Limit torpedo uses
        printf("No torpedo moves remaining.\n");
        return;
    }

    int row = -1, col = -1;
    int orientation = -1;  // -1 means undetermined 

    // Try to find a recent hit to guide torpedo targeting
    if (!findTorpedoTarget(currentPlayer, &row, &col, &orientation)) {
        chooseHighestProbability(&row, &col);  // Ensure this method works as intended
    }

    // Create the INPUT struct
      INPUT input={row,col};

    // Execute the torpedo move, attacking the entire row or column based on orientation
    if (orientation == VERTICAL) {
        // Attack entire column
        for (int i = 0; i < GRID_SIZE; i++) {
            input.row = i;
            torpedo(currentPlayer, opposingPlayer, &input); 
        }
    } else if (orientation == HORIZONTAL) {
        // Attack entire row
        for (int j = 0; j < GRID_SIZE; j++) {
            input.col = j;
            torpedo(currentPlayer, opposingPlayer, &input);  
        }
    } else {
        // If orientation isn't determined, just attack the current cell
        torpedo(currentPlayer, opposingPlayer, &input);
    }
}
