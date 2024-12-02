#include "headerFile.h"

#include "input.c"
#include "GameSetup/initializeGame.c"
#include "GameSetup/placeShips.c"

#include "Moves/moveFire.c"
#include "Moves/moveSmokeScreen.c"
#include "Moves/moveRadarSweep.c"
#include "Moves/moveTorpedo.c"
#include "Moves/moveArtillery.c"

#include "Bot/probabilityGrid.c"
#include "Bot/botThinking.c"
#include "Bot/handleRadar.c"
#include "Bot/handleTorpedo.c"
#include "Bot/handleArtillery.c"
#include "Bot/handleFire.c"


int difficulty =0;
int main()
{
    

    PLAYER player1;
    PLAYER player2;

    difficulty = getDifficultyLevel();

    initializePlayer(&player1, 1);
    initializePlayer(&player2, 2);

    player2.isBot=1;

    printf("\n");

    assignStartingPlayer(&player1, &player2);

// Place ships for both players
    if (player2.isBot)
    {
        if (difficulty == EASY)
        {
            placeShipsEasy(&player2); // Bot automatically places ships
            placeShipsHuman(&player1);
        }
        else if (difficulty == HARD)
        {
            placeShipsHard(&player2); // Bot automatically places ships
            placeShipsHuman(&player1);
        }
        else
        {
            placeShipsMedium(&player2); // Bot automatically places ships
            placeShipsHuman(&player1);
        }
    }
    else
    {
        if (difficulty == EASY)
        {
            placeShipsEasy(&player1); // Bot automatically places ships
            placeShipsHuman(&player2);
        }
        else if (difficulty == HARD)
        {
            placeShipsHard(&player1); // Bot automatically places ships
            placeShipsHuman(&player2);
        }
        else
        {
            placeShipsMedium(&player1); // Bot automatically places ships
            placeShipsHuman(&player2);
        }
    }



    initializeProbGrid(player1.probGrid);
    calculateProbability(&player1,&player2);

    initializeProbGrid(player2.probGrid);
    calculateProbability(&player2,&player1);

    printf("ooo5");
    for(int  i = 0 ; i < 4 ;i++)
    {
        printf("the player1 ships sizes is %d , %d", i, player1.ships[i].size);
    }

   for (int i = 0; player1.shipsLeft > 0 && player2.shipsLeft > 0;)
    {
        // Check if the current turn results in a successful move
        int turnSuccess;
        if (i % 2 == 0)
        {
            turnSuccess = game(&player1, &player2,i);
        }
        else
        {
            turnSuccess = game(&player2, &player1,i);
        }

        // Only increment i if the turn was successful (when i dont enter help)
        if (turnSuccess) {
            i++;
        }
        
    printf("\n\n");

    }

    if(player1.shipsLeft==0)
    {
        printf("Congrats %s, you have won!",player2.name);
    }else{
        printf("Congrats %s, you have defeated %s!",player1.name,player2.name);
    }
    return 0;
}
/*int game(PLAYER *currentPlayer, PLAYER *opposingPlayer,int turnNumber)
requires: reference to the current player and opposing player of type PLAYER, and int turn number of the game
effects: returns 1 when a successful turn, 0 when "help"
*/
int game(PLAYER *currentPlayer, PLAYER *opposingPlayer,int turnNumber)
{
   
    
    currentPlayer->artillery=1;
    printf("%s, what is your move?\n", currentPlayer->name);
    printf("for a list of moves, enter \"help\"\n");



    checkArtillery(currentPlayer);
    checkTorpedo(currentPlayer);

    printGrid(currentPlayer->hitsAndMissesGrid);
    if(currentPlayer->isBot==0)
    {
        return 1;
    }
    if(currentPlayer->isBot)
    {
        botThinking(currentPlayer,opposingPlayer);
        calculateProbability(currentPlayer,opposingPlayer);   
        printGrid(currentPlayer->hitsAndMissesGrid);
        printf("THE TURN HAS ENDED\n\n");
        //go to bot thinking
        return 1 ;
    }
    INPUT input;
    getInput(&input);


    
    
    
    if (strcasecmp(input.moveName, "fire") == 0)
    {
        fireMove(currentPlayer, opposingPlayer, &input);
        
    }
    else if (strcasecmp(input.moveName, "radar") == 0)
    {
        RadarSweep(currentPlayer, opposingPlayer, &input);
        
    }
    else if (strcasecmp(input.moveName, "smoke") == 0)
    {
        smokeScreen(currentPlayer, opposingPlayer, &input);
        
    }
    else if (strcasecmp(input.moveName, "artillery") == 0)
    { 
     
        artilleryMove(currentPlayer, opposingPlayer, &input);
        

    }
    else if (strcasecmp(input.moveName, "torpedo") == 0)
    {
        torpedo(currentPlayer, opposingPlayer, &input);
        
    }
    else if (strcasecmp(input.moveName, "help") == 0)
    {
        printf("Moves are:\n");
        printf("1) Fire.\n");
        printf("2) Radar Sweep(you are only allowed 3 radar sweeps).\n");
        printf("3) Smoke Screen(you are allowed one smoke screen per ship opponent have sunk).\n");
        printf("4) Artillery(can be accessed after sinking opponent's ship ).\n");
        printf("5) Torpedo(can be accessed after sinking opponent's third ship).\n");
        return 0; // "Help" does not end the turn
    }
    else
    {
        printf("Invalid input. Turn skipped.\n");
        printf("THE TURN HAS ENDED\n\n");
        return 1; 
    }

    printGrid(currentPlayer->hitsAndMissesGrid);
    printf("THE TURN HAS ENDED\n\n");
    return 1; //successful turn

}
