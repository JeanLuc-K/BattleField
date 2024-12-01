#include "../headerFile.h"



/*
requires: A reference to `currentPlayer`, which includes the player's probability grid (`probGrid`)
          A reference to `negativeCount`, which will store the count of negative values found in the grid.
effects:  
          If no negative cells are found, it prints a message and returns `NULL`.
          If negative cells are found, the function allocates memory for an array of `Coord` structures, stores the coordinates of negative cells 
          in the array, and sorts them in descending order of their values in `probGrid`. 
          The sorted array of coordinates is then printed and returned. If memory allocation fails, it prints an error message and returns `NULL`.
*/
Coord* countAndSortNegativeCells(PLAYER* currentPlayer, int* negativeCount) {
    // Step 1: Count negative cells
    *negativeCount = 0;
    
    // First pass to count how many negative cells we have
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (currentPlayer->probGrid[i][j] < 0) {
                (*negativeCount)++;
            }
        }
    }

    // If no negative cells, return NULL and notify
    if (*negativeCount == 0) {
        printf("No negative cells found in probGrid.\n");
        return NULL;
    }

    // Step 2: Allocate memory based on the number of negative cells
    Coord* negativeCells = malloc(*negativeCount * sizeof(Coord));  // Allocate memory for the negative cells

    if (negativeCells == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;  // Return NULL if allocation fails
    }

    // Step 3: Store coordinates of negative cells
    int index = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (currentPlayer->probGrid[i][j] < 0) {
                negativeCells[index].row = i;
                negativeCells[index].col = j;
                index++;
            }
        }
    }

    // Step 4: Sort the negative cells in descending order of probGrid values
    // Bubble sort algorithm for sorting by probGrid values (descending order)
    for (int i = 0; i < *negativeCount - 1; i++) {
        for (int j = i + 1; j < *negativeCount; j++) {
            int row1 = negativeCells[i].row;
            int col1 = negativeCells[i].col;
            int row2 = negativeCells[j].row;
            int col2 = negativeCells[j].col;

            if (currentPlayer->probGrid[row1][col1] < currentPlayer->probGrid[row2][col2]) {
                // Swap the coordinates if probGrid[i] < probGrid[j]
                Coord temp = negativeCells[i];
                negativeCells[i] = negativeCells[j];
                negativeCells[j] = temp;
            }
        }
    }

    // Step 5: Print the sorted negative cells
    printf("Negative cells sorted by probGrid values (descending):\n");
    for (int i = 0; i < *negativeCount; i++) {
        printf("Row: %d, Column: %d, Value: %d\n", 
            negativeCells[i].row, 
            negativeCells[i].col, 
            currentPlayer->probGrid[negativeCells[i].row][negativeCells[i].col]);
    }

    return negativeCells;  // Return the array of sorted negative cells
}

//returns the highest prob square to shoot if no squares are marked as <0
/*
requires: A reference to `currentPlayer`, which includes the player's probability grid (`probGrid`), 
          representing the likelihood of a ship being placed at each grid location.
effects:   prints the coordinates of these highest-probability squares and then selects one randomly by generating 
          a random index. The selected coordinate is returned. If multiple squares have the highest probability, one of them 
          is chosen randomly.
*/
Coord getHighestPositiveProbSquare(PLAYER* currentPlayer)
{
     //if does not have <0
        int count =0;
        Coord* highestProbCoords = findHighestProbCoords(currentPlayer,&count);

        printf("Coordinates with the highest probability (%d occurrences):\n", count);
        for (int i = 0; i < count; i++) {
            printf("Row: %d, Column: %d\n", highestProbCoords[i].row, highestProbCoords[i].col);
        }

        srand(time(NULL));
        int randomNumber=rand()%count; //create random number
        return highestProbCoords[randomNumber];
}


/*
requires: 
    - A reference to `currentPlayer`, which includes the player's probability grid (`probGrid`), 
    - A reference to `opposingPlayer`, which contains information about the opponent's ships.
    
effects: returns the highest prob square to shoot it depending on:
    - If negative probability values are found , it returns the coordinate of the first negative cell (the one with the most negative probability).
    - If no negative cells are found, it calls  return a coordinate with the highest positive probability.
*/
Coord getHighestProbSquare(PLAYER* currentPlayer, PLAYER* opposingPlayer)
{
    //check if it has -1
    int negativeCount =0;
    Coord* negativeCells = countAndSortNegativeCells(currentPlayer,&negativeCount);
    if(negativeCount>0)
    {
        return negativeCells[0];

    }else
    {
        return getHighestPositiveProbSquare(currentPlayer);
    }
   
    
}

//returns all the coord that have the same max prob
/*
requires: A reference to `currentPlayer`, which includes the player's probability grid (`probGrid`). and ount parameter is used to keep track of how many coordinates on the grid have the highest probability value.
    
returns: A pointer to an array of `Coord` structures containing the coordinates of all cells with the highest probability.
         If memory allocation fails, the program exits.
*/
Coord* findHighestProbCoords(PLAYER* currentPlayer, int* count) {
    int maxProb = -1;  // Initialize the maximum probability to a very low value
    *count = 0;  // Initialize the count of coordinates with the highest probability

    // First, we loop through the grid to find the maximum probability
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (currentPlayer->probGrid[i][j] > maxProb) {
                maxProb = currentPlayer->probGrid[i][j];  // Update max probability
            }
        }
    }

    // Now we loop again to collect all coordinates with the highest probability
    Coord* highestProbCoords = malloc(GRID_SIZE * GRID_SIZE * sizeof(Coord));  // Allocate memory for the coordinates
    if (highestProbCoords == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);  // Exit if memory allocation fails
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (currentPlayer->probGrid[i][j] == maxProb) {
                // If this cell has the highest probability, add it to the list
                highestProbCoords[*count].row = i;
                highestProbCoords[*count].col = j;
                (*count)++;  // Increment the count of coordinates
            }
        }
    }

    return highestProbCoords;  // Return the dynamically allocated array of coordinates
}

/*
requires:
    - A reference to `opposingPlayer` .
    - A reference to `opposingShipsStatus`, which is an array tracking the fallen status of each ship.
returns: 
    - The size of the ship that was sunk or 0 if no ship was sunk.
*/

int checkShipStatus
int checkShipStatusChange(PLAYER* opposingPlayer, int* opposingShipsStatus) {
    // Compare each ship status
    for (int i = 0; i < NUMBEROFSHIPS; i++) {
        // If the status does not match, return the first index of the mismatch
        if (opposingShipsStatus[i] != opposingPlayer->ships[i].hasFallen) {
            return 4-i;  // Return the size of the ship where the change occurred
        }
    }

    // If no changes are found, return 0
    return 0;
}
/*
requires:
    - ` A reference to `opposingPlayer` .
    -  A reference to `opposingShipsStatus`, which is an array tracking the fallen status of each ship.
    -  The input containing the coordinates of the shot.
    - `opposingShipsStatus`: The status array for the opponent's ships.
    - `lastHit`: The last successful hit coordinates.

effects:
   - Updates the game state based on the hit or miss outcome, including adjusting the probability grid.
   -If a ship is sunk but another ship is still hit, the game continues without adjusting the probability grid further for the sunk ship.
*/
void hitOutcome(PLAYER *currentPlayer,PLAYER* opposingPlayer, INPUT* input,int* opposingShipsStatus,Coord* lastHit ) {
    // Check if the given coordinate is within bounds

    //if we hit a random spot
    if(currentPlayer->probGrid[input->row][input->column]>=0)
    {
        for(int i =0 ;i<4;i++)
        {
            updateCoordByCross(input,i);
            processSurroundingCell(currentPlayer,input);
        }

    }
    //if we hit a marked spot
    else{
        //if we hit a ship at that marked spot
        if(currentPlayer->hitsAndMissesGrid[input->row][input->column]=='*')
        {
            currentPlayer->probGrid[input->row][input->column]=9999;// make it 0 so that the next time the prob grid changes it

            
            int lastHitRow = lastHit->row;
            int lastHitCol = lastHit->col;

            if(input->row == lastHitRow)//don't forget bound checking
            {
                currentPlayer->probGrid[lastHitRow--][lastHitCol]++;
                currentPlayer->probGrid[lastHitRow++][lastHitCol]++;
                if(input->column-lastHitCol>0)
                {
                    currentPlayer->probGrid[input->row][input->column+1]=-1;
                }else{
                    currentPlayer->probGrid[input->row][input->column-1]=-1;
                }

            }else
            {//bade enebeth 23ml -1 eza azghar men 0
                currentPlayer->probGrid[lastHitRow][lastHitCol++]++;
                currentPlayer->probGrid[lastHitRow][lastHitCol--]++;
                
                if(input->row-lastHitRow>0)
                {
                    currentPlayer->probGrid[input->row+1][input->column]=-1;
                }else
                
                {
                    currentPlayer->probGrid[input->row-1][input->column]=-1;
                }

            }
           //i  now check around it
    // i have to check the orientation of the next shot as well;
            // i have to check if its next to a hit and i have to be careful not to check hit ships from long before

            //we update the ship hit  counter
            currentPlayer->hitsBeforeShipSunk++;

            // we check if any ship sunk

            int result = checkShipStatusChange(opposingPlayer,opposingShipsStatus);
            if(result ==0) //no ship sunk
            {
                return ;//i cannot know anything so next
            }else{

                //ana hon i have sunk the ship and didn;t hit any other ship at the same time 
                if (currentPlayer->hitsBeforeShipSunk== result)
                {
                    //make all the -1 into 0 adjacent to the ship or maybe +1 so maybe if one had 2 but won;t ever happen ma baarf 3m 5arref
                     
                    int lastHitRow = lastHit->row;
                    int lastHitCol = lastHit->col;

                    if(input->row == lastHitRow)//don't forget bound checking
                    {
                        currentPlayer->probGrid[lastHitRow--][lastHitCol]++;
                        currentPlayer->probGrid[lastHitRow++][lastHitCol]++;
                        if(input->column-lastHitCol>0)
                        {
                            currentPlayer->probGrid[input->row][input->column+1]=-1;
                        }else{
                            currentPlayer->probGrid[input->row][input->column-1]=-1;
                        }

                    }else
                    {//bade enebeth 23ml -1 eza azghar men 0
                        currentPlayer->probGrid[lastHitRow][lastHitCol++]++;
                        currentPlayer->probGrid[lastHitRow][lastHitCol--]++;
                        
                        if(input->row-lastHitRow>0)
                        {
                            currentPlayer->probGrid[input->row+1][input->column]=-1;
                        }else
                        
                        {
                            currentPlayer->probGrid[input->row-1][input->column]=-1;
                        }

                    }
                }
                //i have sunk a ship but i still did hit another ship on the way 
                // ana fiye wa2ef hon lal hard
                else 
                {
                    // bruh bemche backwards la hat ma le2e l hit l barrat l ship bhot l hwalaya -1 ma aada l 0 w bkamml aade
                }
            }


        }// if we misses the hitandmiss will become 'o' and the probgrid will change the -1 to 0
        else{
            currentPlayer->probGrid[input->row][input->column]=0;
        }
    }
    
    
}
*
requires:
    - currentPlayer`reference
    - input refence :The coordinates of the shot.

effects:
    -if the cell is a hit ('*'), it updates the `probGrid` for the surrounding cells, marking them with `-1` if they are not already marked.
    - Updates the probability grid based on surrounding cells and removes  unlikely shots around previously marked hit cells..
*/
void processSurroundingCell(PLAYER *currentPlayer, INPUT* input) {
    // Check if the coordinate is within bounds
    if(!isInBound(input))
    {
        return;
    }

    // Check if the cell in hitsAndMissesGrid is a hit ('*')
    if (currentPlayer->hitsAndMissesGrid[input->row][input->column] == '~') {
        if (currentPlayer->probGrid[input->row][input->column] < 0) {
            currentPlayer->probGrid[input->row][input->column] -= 1;  // Add -1 if < 0
        }
        else {
            currentPlayer->probGrid[input->row][input->column] = -1;  // Set to -1 if valid
        }
        printf("Marked cell (%d, %d) as -1.\n", input->row, input->column);
    } 
}
/*
requires:
    - `input`: The coordinates of the shot.
    - `iteration`: The iteration step that determines the direction of the update.

effects:
    - Adjusts the `input` coordinates based on the current iteration (0-3) which represents the directions (right, down, left, up).
    
*/
void updateCoordByCross(INPUT* input ,int iteration)
{
    if(iteration ==0)
    {
        input->column++; //move right 
    }else if(iteration ==1)
    {   
        input->column--;
        input->row++; //down
    }else if(iteration ==2)
    {
        input->row--;
        input->column--; //left

    }else if (iteration == 3) 
    {
        input->column++;
        input->row--;    //up 
    }
}
/*
requires:
    - `opposingPlayer`: The opponent's player object, containing the current ship statuses.
    - `opposingShipsStatus`: The array to store the status of the opponent's ships.

returns: 
    - Updates the `opposingShipsStatus` array with the current status of the opponent's ships.
*/
void saveOpposingShipsStatus(PLAYER* opposingPlayer,int* opposingShipsStatus)
{
    

    for(int  i = 0 ; i < NUMBEROFSHIPS ;i++)
    {
        opposingShipsStatus[i]=opposingPlayer->ships[i].hasFallen;
    }
    

}
/*
requires:
    - currentPlayer and opposing player reference
returns: 
    - This function handles the entire process of firing a shot, including choosing the target, processing the hit outcome, and updating the probability grid.
*/
void handleFire(PLAYER* currentPlayer, PLAYER* opposingPlayer) 
{
    INPUT input;

    // currentPlayer->probGrid[3][5]=-1;
    // opposingPlayer->grid[3][5]='X';
    // input.row =3;
    // input.column = 6;
    // fireMove(currentPlayer,opposingPlayer,&input);
    Coord coord=getHighestProbSquare(currentPlayer,opposingPlayer);
    
    printf("WE pick : %d,%c",coord.row+1,coord.col+97);
    
    input.row=coord.row;
    input.column = coord.col;

    
    int opposingShipsStatus[NUMBEROFSHIPS];
    saveOpposingShipsStatus(opposingPlayer,opposingShipsStatus);

    Coord lastHit;
    lastHit.row = currentPlayer->lastHit.row;
    lastHit.col = currentPlayer->lastHit.col;


    fireMove(currentPlayer,opposingPlayer,&input);

    if(currentPlayer->hitsAndMissesGrid[input.row][input.column]=='*')
    {
        hitOutcome(currentPlayer,opposingPlayer,&input,opposingShipsStatus,&lastHit);
    }else {
        printf("No hit at (%d, %d), no change to probGrid.\n", input.row, input.column);
    }

}


