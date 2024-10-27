
#include "headerFile.h"

#include "mainF.c"
#include "Grid_player.c"
#include "Smoke_Screen.c"

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
    int smokeScreenCounter1 =0;
    int smokeScreenCounter2 =0;

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
            smokeScreenCounter1 +=smokeScreen(grid1,smokeGird1,smokeScreenCounter1,shipsLeft2,input);
            
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



