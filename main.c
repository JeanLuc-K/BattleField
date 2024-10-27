#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Grid_player.c"


struct Input
{
    char orientation[11];
    char moveName[10];

    int column;
    int row;
    int valid;
};

#define GRID_SIZE 10
#define EASY 0
#define HARD 1
#define INPUT struct Input

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void assignStartingPlayer(char**,char**,char*,char*);
int getDifficultyLevel();
void getName(char*, int,int);
void initializeGridHelper(char[GRID_SIZE][GRID_SIZE],char[GRID_SIZE][GRID_SIZE],char[GRID_SIZE][GRID_SIZE]);
int getTrailingCharachterIndex(char*, int );
int getLeadingCharachterIndex(char* , int );
void getInput(struct Input*);


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
        printGrid(hitsAndMissesGrid1);
        printf("%s, what is your move?\n",firstPlayerName);
        printf("for a list of moves, enter \"help\"\n");

        
        INPUT input;
        getInput(&input);

        printf("input move is : %s.",input.moveName);
        if (strcasecmp(input.moveName, "fire") == 0)
        {
            printf("najah");
            //fireMove(grid, playerName,gridHitsandMisses);
        }
        else if (strcasecmp(input.moveName, "radar") == 0)
        {
            // radarSweep(grid, playerName);
        }
        else if (strcasecmp(input.moveName, "smoke") == 0)
        {
            // smokeScreen(grid, playerName);
        }
        else if (strcasecmp(input.moveName, "artillery") == 0)
        {
            // artillery(grid, playerName);
        }
        else if (strcasecmp(input.moveName, "torpedo") == 0)
        {
            // torpedo(grid, playerName);
        }
        else
        {
            printf("Invalid input. Turn skipped.. \n");
    }

    }
}


// int compareStrings(char*s1, char* s2)
// {
//    // compareStrings(s1,s2,0,sizeof(s1));
// }

// int compareStrings(char* s1, char* s2, int startIndex1,int endIndex1)
// {
//     for(int i = 0; i< endIndex1-startIndex1;i++)
//     {
//        if( s1[startIndex1+i] != s2[i])
//        {
//             return -1;
//        }
//     }

//     return 0;
// }

int getLeadingCharachterIndex(char*input , int start)
{
    while(input[start]== ' ')
    {
        start++;
    }

    return start;
}

int getTrailingCharachterIndex(char*input, int start)
{
    while(input[start]!= ' ' && input[start]!= '\n'&& input[start]!= EOF )
    {
        start++;
    }

    return start;
}

void getInput(INPUT* input)
{
    char stringInput[20];

    fgets(stringInput,sizeof(stringInput),stdin);
    clearInput(stringInput,sizeof(stringInput));

    int leading1 = getLeadingCharachterIndex(stringInput,0);
    int trailing1 = getTrailingCharachterIndex(stringInput,leading1);

    for(int i = 0; i < trailing1-leading1;i++)
    {
        input->moveName[i]= stringInput[leading1+i];
    }

    int leading2 = getLeadingCharachterIndex(stringInput, trailing1);
    int trailing2 = getTrailingCharachterIndex(stringInput,leading2);

    
    int leading3 = getLeadingCharachterIndex(stringInput, leading2+1);
    int trailing3 = getTrailingCharachterIndex(stringInput,leading3);
    
    input->column= getColumn(stringInput[leading2]);
    input->row = getRow(stringInput, leading3, trailing3);

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
