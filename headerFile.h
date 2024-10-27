#ifndef HEADERFILE_H
#define HEADERFILE_H

//FOR ALL FILES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define GRID_SIZE 10
#define EASY 0
#define HARD 1
#define INPUT struct Input



//for MAIN.C
struct Input
{
    char orientation[11];
    char moveName[10];

    int column;
    int row;
    int valid;
};
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void assignStartingPlayer(char**,char**,char*,char*);
int getDifficultyLevel();
void getName(char*, int,int);
void initializeGridHelper(char[GRID_SIZE][GRID_SIZE],char[GRID_SIZE][GRID_SIZE],char[GRID_SIZE][GRID_SIZE]);
int getTrailingCharachterIndex(char*, int );
int getLeadingCharachterIndex(char* , int );
void getInput(struct Input*);



//for GRID_PLAYER.C
#define HORIZONTAL 0
#define VERTICAL 1
void createGrid(char grid[10][10], char *playername);
void printGrid(char grid[GRID_SIZE][GRID_SIZE]);

int getColumn(char);
int getOrientation(char* , int);

void clearInput(char* , int);
int getDigit(char);
int getRow(char*, int,int);

int checkBounds(char [GRID_SIZE][GRID_SIZE], int ,int ,  int ,int );
void addShip(char [GRID_SIZE][GRID_SIZE] , int ,int ,  int ,int );


//for SMOKE_SCREEN.C


int smokeScreen(char grid[GRID_SIZE][GRID_SIZE], char smokeGrid[GRID_SIZE][GRID_SIZE], int smokeScreenCounter, int shipsSunk, struct Input input );
int isInBound(struct Input);
void updateCoordBySquare(struct Input* input ,int iteration);


#endif