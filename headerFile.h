#ifndef HEADERFILE_H
#define HEADERFILE_H

//FOR ALL FILES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// TO REMOVE CLEARING INPUT OVERFLOW CHANGE TO 0
#define INPUTOVERFLOW 1


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
#define SHIP struct Ship
#define PLAYER struct Player
extern int difficulty ;

struct Ship
{
    char name[15];
    int coord[4];
    int hits;
    int size;
    int hasFallen;
};


struct Player
{
    char grid[GRID_SIZE][GRID_SIZE]; 
    char hitsAndMissesGrid[GRID_SIZE][GRID_SIZE];
    char smokeGird[GRID_SIZE][GRID_SIZE];
    char name[50];
    SHIP ships[4];
    int shipsLocations[4][4];
    
    int shipsLeft;
    int smokeScreenCounter;
    int radarSweep;

    int torpedo;
    int artillery;
};


int game(PLAYER* player1, PLAYER* player2);
void initializePlayer(PLAYER* player,int number);
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void assignStartingPlayer(PLAYER*,PLAYER*);
int getDifficultyLevel();
void getName(char*, int,int);
void initializeGridHelper(char[GRID_SIZE][GRID_SIZE],char[GRID_SIZE][GRID_SIZE],char[GRID_SIZE][GRID_SIZE]);






//for place_ships.C
#define HORIZONTAL 0
#define VERTICAL 1
void placeShips(PLAYER* );
void printGrid(char grid[GRID_SIZE][GRID_SIZE]);
void addShip(PLAYER* ,INPUT*,const char* ,int );
int checkBounds(PLAYER* ,INPUT*,int );



//for firemove.c

void fireMove(PLAYER* currentPlayer, PLAYER* opposingPlayer,INPUT input);
void addHitOnShip(PLAYER*, PLAYER* , INPUT*);
void shipFallen(PLAYER* currentPlayer,PLAYER* opposingPlayer, INPUT* input);


//for smoke_screen.C
void smokeScreen(PLAYER*,PLAYER*,INPUT);
int isInBound(INPUT*);
void updateCoordBySquare(struct Input* input ,int iteration);

// for radarSweep.c
void RadarSweep(PLAYER*,PLAYER*,INPUT*);

//for torpedo.c
void torpedo(PLAYER*,PLAYER*,INPUT*);

//for arilleryMove.c
void checkArtillery(PLAYER* currentPlayer);
void artilleryMove(PLAYER* currentPlayer, PLAYER* opposingPlayer,INPUT* input);






#endif