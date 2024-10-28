
#include "headerFile.h"

#include "input.c"
#include "initialize_game.c"
#include "place_ships.c"
#include "smoke_screen.c"


int main()
{  

    PLAYER player1;
    PLAYER player2;

    int difficultyLevel = getDifficultyLevel();
    
    initializePlayer(&player1,1);
    initializePlayer(&player2,2);


    assignStartingPlayer(&player1,&player2);
    

    printf("\n");
    createGrid(&player1);
    printf("\n");
    createGrid(&player2);

    for(int i=0; player1.shipsLeft>0 && player2.shipsLeft>0 ;i++)
    {
        if(i%2==0)
        {
            game(&player1,&player2);
        }else
        {
            game(&player2,&player1);
        }
    }
}


void game(PLAYER* currentPlayer, PLAYER* opposingPlayer)
{
    printf("%s, what is your move?\n",currentPlayer->name);
    printf("for a list of moves, enter \"help\"\n");

    
    INPUT input;
    getInput(&input);

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
        currentPlayer->smokeScreenCounter +=smokeScreen(&currentPlayer,&opposingPlayer,input);
        
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



