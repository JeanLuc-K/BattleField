#define GRID_SIZE 10
#ifndef GRID_PLAYER_H
#define GRID_PLAYER_H

void createGrid(char grid[10][10], char *playername);
void printGrid(char grid[GRID_SIZE][GRID_SIZE]);

int getColumn(char);
int getOrientation(char* , int);

void clearInput(char* , int);
int getDigit(char);
int getRow(char*, int);

int checkBounds(char [GRID_SIZE][GRID_SIZE], int ,int ,  int ,int );
void addShip(char [GRID_SIZE][GRID_SIZE] , int ,int ,  int ,int );

 #endif
