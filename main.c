
#include "headerFile.h"

#include "input.c"
#include "initialize_game.c"
#include "place_ships.c"

#include "firemove.c"
#include "smoke_screen.c"
#include "RadarSweep.c"
#include "torpedo.c"
#include "ArtilleryMove.c"

int main()
{

    PLAYER player1;
    PLAYER player2;

    int difficultyLevel = getDifficultyLevel();

    initializePlayer(&player1, 1);
    initializePlayer(&player2, 2);

    assignStartingPlayer(&player1, &player2);

    placeShips(&player1);
    placeShips(&player2);

   for (int i = 0; player1.shipsLeft > 0 && player2.shipsLeft > 0;)
    {
        // Check if the current turn results in a successful move
        int turnSuccess;
        if (i % 2 == 0)
        {
            turnSuccess = game(&player1, &player2);
        }
        else
        {
            turnSuccess = game(&player2, &player1);
        }

        // Only increment i if the turn was successful (when i dont enter help)
        if (turnSuccess) {
            i++;
        }
    }
    return 0;
}

int game(PLAYER *currentPlayer, PLAYER *opposingPlayer)
{
    printf("%s, what is your move?\n", currentPlayer->name);
    printf("for a list of moves, enter \"help\"\n");

    printGrid(currentPlayer->hitsAndMissesGrid);
    INPUT input;
    getInput(&input);
    input.row--;

    if (strcasecmp(input.moveName, "fire") == 0)
    {
        fireMove(currentPlayer, opposingPlayer, input);
        return 1; // Successful turn
    }
    else if (strcasecmp(input.moveName, "radar") == 0)
    {
        RadarSweep(currentPlayer, opposingPlayer, &input);
        return 1; // Successful turn
    }
    else if (strcasecmp(input.moveName, "smoke") == 0)
    {
        smokeScreen(currentPlayer, opposingPlayer, input);
        return 1; // Successful turn
    }
    else if (strcasecmp(input.moveName, "artillery") == 0)
    { 
     
        artilleryMove(currentPlayer, opposingPlayer, input);
        

        return 1; // Successful turn
    }
    else if (strcasecmp(input.moveName, "torpedo") == 0)
    {
        torpedo(currentPlayer, opposingPlayer, &input);
        return 1; // Successful turn
    }
    else if (strcasecmp(input.moveName, "help") == 0)
    {
        printf("Moves are:\n");
        printf("1) Fire.\n");
        printf("2) Radar Sweep(you are only allowed 3 radar sweeps).\n");
        printf("3) Smoke Screen(you are allowed one smoke screen per ship they have sunk).\n");
        printf("4) Artillery(can be accessed after sinking opponent's ship ).\n");
        printf("5) Torpedo(can be accessed after sinking opponent's third ship).\n");
        return 0; // "Help" does not end the turn
    }
    else
    {
        printf("Invalid input. Turn skipped.\n");
        return 1; 
    }
}
