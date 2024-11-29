// //this file is for the bot implmentation
// #include "headerFile.h"

// int isInBound2(int row, int column) {
//     if (row < 0 || row >= GRID_SIZE) {
//         return 0;
//     }

//     if (column < 0 || column >= GRID_SIZE) {
//         return 0;
//     }

//     return 1;
// }

// // Check horizontally for a possible hit
// int foundHitHorizontal(int row, int col, int shipSize, PLAYER* currentPlayer) {
//     for (int colShift = 0; colShift < shipSize; ++colShift) {
//         if (!isInBound2(row, col + colShift)) {
//             return 1;  // Out of bounds, stop checking
//         }
//         if (currentPlayer->hitsAndMissesGrid[row][col + colShift] == '*') {
//             return 1;  // A hit is detected
//         }
//         if(difficulty==EASY)
//         {
//             if(currentPlayer->hitsAndMissesGrid[row][col+colShift]=='o')
//             {
//                 return 1; //there was a miss
//             }
//         }
//     }
//     return 0;  // No hit detected
// }

// // Check vertically for a possible hit
// int foundHitVertical(int row, int col, int shipSize, PLAYER* currentPlayer) {
//     for (int rowShift = 0; rowShift < shipSize; ++rowShift) {
//         if (!isInBound2(row + rowShift, col)) {
//             return 1;  // Out of bounds, stop checking
//         }
//         if (currentPlayer->hitsAndMissesGrid[row + rowShift][col] == '*') {
//             return 1;  // A hit is detected
//         }

//         if(difficulty==EASY)
//         {
//             if(currentPlayer->hitsAndMissesGrid[row+rowShift][col]=='o')
//             {
//                 return 1; //there was a miss
//             }
//         }
//     }
//     return 0;  // No hit detected
// }

// void calculateProbability(PLAYER* currentPlayer, PLAYER* opposingPlayer) {
//     printf("Calculating probability...\n");

//     initializeProbGrid(currentPlayer->probGrid);
//     for (int shipIndex = 0; shipIndex < NUMBEROFSHIPS; ++shipIndex) {
//         SHIP currentShip = opposingPlayer->ships[shipIndex];

//         // Only consider ships that have not fallen
//         if (currentShip.hasFallen == 0) {
//             int currentShipSize = currentShip.size;

//             // Loop through every possible cell in the grid
//             for (int row = 0; row < GRID_SIZE; ++row) {
//                 for (int col = 0; col < GRID_SIZE; ++col) {
                    
//                     int foundHit = 0;

//                     // Check for horizontal placement
//                     if (!foundHitHorizontal(row, col, currentShipSize, currentPlayer)) {
//                         // Update probability grid if no hit was found
//                         if (isInBound2(row, col + currentShipSize - 1)) {  // Ensure horizontal ship can fit
//                             for (int colShift = 0; colShift < currentShipSize; ++colShift) {
//                                 ++currentPlayer->probGrid[row][col + colShift];
//                             }
//                         }
//                     }

//                     // Reset found hit for vertical check
//                     foundHit = 0;

//                     // Check for vertical placement
//                     if (!foundHitVertical(row, col, currentShipSize, currentPlayer)) {
//                         // Update probability grid if no hit was found
//                         if (isInBound2(row + currentShipSize - 1, col)) {  // Ensure vertical ship can fit
//                             for (int rowShift = 0; rowShift < currentShipSize; ++rowShift) {
//                                 ++currentPlayer->probGrid[row + rowShift][col];
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }

  
// }
