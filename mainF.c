#include "headerFile.h"

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
