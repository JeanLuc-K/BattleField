#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Grid_player.h"


#define GRID_SIZE 10

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);

void assignStartingPlayer(char**,char**,char*,char*);

int main()
{
char grid1[GRID_SIZE][GRID_SIZE]; // for player 1
    initializeGrid(grid1);
    char grid2[GRID_SIZE][GRID_SIZE]; // For player 2
    initializeGrid(grid2);

    char name1[50];
    char name2[50];

    printf("Please enter name of Player 1(49 max characters): ");
    fgets(name1, sizeof(name1), stdin);
    clearInput(name1, sizeof(name1));

    printf("Please enter name of Player 2(49 max characters): ");
    fgets(name2, sizeof(name2), stdin);
    clearInput(name2, sizeof(name2));

    printf("\n");

    char *firstPlayerName;
    char *secondPlayerName;

    assignStartingPlayer(&firstPlayerName, &secondPlayerName, name1, name2);
    printf("\n");
    printf("Player 1 please fill your grid: ");
    createGrid(grid1, firstPlayerName);
    printf("\n");
    printf("Player 2 please fill your grid: ");
    createGrid(grid2, secondPlayerName);
    
   
}

void assignStartingPlayer(char** firstPlayerName, char** secondPlayerName, char*name1, char*name2)
{

    name1[strcspn(name1,"\n")] = '\0';
    name2[strcspn(name2,"\n")] = '\0';

    srand(time(NULL));
    int randomNumber=rand()%2; //create random number 
    if(randomNumber==0) //chooses randoml which player to start
    {
        printf("The first player is %s\n",name1);
        *firstPlayerName = name1;
        *secondPlayerName = name2;
        
    }else
    {
        printf("The first player is %s\n", name2);
        *firstPlayerName= name2;
        *secondPlayerName = name1;
    }
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = '~';
        }
    }
}


int difficultyLevel(){
   char difficulty[5];
   printf("Please enter your difficulty level: ");
   scanf("%s ",difficulty);

   if(strcmp(difficulty, "easy") == 0){
    return 0;
   }else{
    return 1;
   }
}
