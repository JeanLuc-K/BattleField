#ifndef HEADERFILE_H
#define HEADERFILE_H

//FOR ALL FILES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>





//for INPUT.C
#define INPUT struct Input
struct Input
{
    char orientation[10];
    char moveName[10];

    int column;
    int row;
    int valid;
};
void getInput(struct Input*);
void getInputForPlacingShips(struct Input*);
int getColumn(char);
int getOrientation(char*);
int getDigit(char);
int getRow(char*, int,int);
int getTrailingCharachterIndex(char*, int );
int getLeadingCharachterIndex(char* , int );
void clearInput(char* , int);


//for initialize_game
#define GRID_SIZE 10
#define EASY 0
#define HARD 1

#define PLAYER struct Player
struct Player
{
    char grid[GRID_SIZE][GRID_SIZE]; 
    char hitsAndMissesGrid[GRID_SIZE][GRID_SIZE];
    char smokeGird[GRID_SIZE][GRID_SIZE];
    char name[50];
    
    int shipsLocations[4][4];
    int shipsLeft;
    int smokeScreenCounter;
};
void game(PLAYER* player1, PLAYER* player2);
void initializePlayer(PLAYER* player,int number);
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void assignStartingPlayer(PLAYER*,PLAYER*);
int getDifficultyLevel();
void getName(char*, int,int);
void initializeGridHelper(char[GRID_SIZE][GRID_SIZE],char[GRID_SIZE][GRID_SIZE],char[GRID_SIZE][GRID_SIZE]);






//for place_ships.C
#define HORIZONTAL 0
#define VERTICAL 1
void createGrid(PLAYER* );
void printGrid(char grid[GRID_SIZE][GRID_SIZE]);
int checkBounds(char [GRID_SIZE][GRID_SIZE], int ,int ,  int ,int );
void addShip(char [GRID_SIZE][GRID_SIZE] , int ,int ,  int ,int );


//for smoke_screen.C
int smokeScreen(char grid[GRID_SIZE][GRID_SIZE], char smokeGrid[GRID_SIZE][GRID_SIZE], int smokeScreenCounter, int shipsSunk, struct Input input );
int isInBound(struct Input);
void updateCoordBySquare(struct Input* input ,int iteration);


#endif