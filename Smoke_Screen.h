#ifndef SMOKE_SCREEN_H
#define SMOKE_SCREEN_H

void smokeScreen(char** grid, char** smokeGrid, int smokeScreenCounter, int shipsSunk, int* coord );
int inBound(int* coord);
void updateCoordBySquare(int* coord,int iteration);

#endif