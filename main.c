#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Grid_player.c"


#define GRID_SIZE 10
#define EASY 0
#define HARD 1

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);

void assignStartingPlayer(char**,char**,char*,char*);
int getDifficultyLevel();
void getName(char*, int,int);
void initializeGridHelper(char[GRID_SIZE][GRID_SIZE],char[GRID_SIZE][GRID_SIZE],char[GRID_SIZE][GRID_SIZE]);

int main()
{
    char grid1[GRID_SIZE][GRID_SIZE]; // for player 1
    char hitsAndMissesGrid1[GRID_SIZE][GRID_SIZE];
    char smokeGird1[GRID_SIZE][GRID_SIZE];

    initializeGridHelper(grid1,hitsAndMissesGrid1,smokeGird1);

    char grid2[GRID_SIZE][GRID_SIZE]; // For player 2
    char hitsAndMissesGrid2[GRID_SIZE][GRID_SIZE];
    char smokeGrid2[GRID_SIZE][GRID_SIZE];

    initializeGridHelper(grid2,hitsAndMissesGrid2,smokeGrid2);

    int difficultyLevel = getDifficultyLevel();

    char name1[50];
    getName(name1,sizeof(name1), 1);
    char name2[50];
    getName(name2, sizeof(name2), 2);

    char *firstPlayerName;
    char *secondPlayerName;

    assignStartingPlayer(&firstPlayerName, &secondPlayerName, name1, name2);
    


    printf("\n");
    createGrid(grid1, firstPlayerName);
    printf("\n");
    createGrid(grid2, secondPlayerName);


    int shipsLeft1=4;
    int shipsLeft2=4;

    while(shipsLeft1>0 && shipsLeft2>0)
    {

    }


    
    
   
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

void initializeGridHelper(char grid1[GRID_SIZE][GRID_SIZE],char grid2[GRID_SIZE][GRID_SIZE] ,char grid3[GRID_SIZE][GRID_SIZE]) 
{
    initializeGrid(grid1);
    initializeGrid(grid2);
    initializeGrid(grid3);
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


int getDifficultyLevel()
{
   char difficulty[6];
   printf("Please enter your difficulty level: ");

    while(1)
    {
        
        fgets(difficulty,sizeof(difficulty),stdin);
        clearInput(difficulty,sizeof(difficulty));


        if(strcmp(difficulty, "easy\n") == 0){
            return 0;
        }else if(strcmp(difficulty, "hard\n")==0) {
            return 1;
        }else{
        printf("difficulty level unknow, try again.\n");
        }

    }
}

void getName(char* name, int size, int number)
{
    
    printf("Please enter name of Player %d(%d max characters): ",number,size);
    fgets(name, sizeof(name), stdin);
    clearInput(name, sizeof(name));
}
