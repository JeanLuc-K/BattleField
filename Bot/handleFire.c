#include "../headerFile.h"


// Define the PLAYER structure with a probability grid
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

//returns the highest prob square to shoot it
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

//update the cood and the squares up down left right prob
void updateProbabilityCross(PLAYER* currentPlayer,int row,int col)
{
    printf("\nthe gird of the fallen ship is : \n");
    printGridInt(currentPlayer->shipSunkGrid);
    INPUT currentInput;
    currentInput.row = row;
    currentInput.column = col;

    for(int  i = 0 ; i<5; i++) //to updatte all 
    {
        
        
        if(isInBound(&currentInput))
        {
            printf("condition 0");
                if(currentPlayer->hitsAndMissesGrid[currentInput.row][currentInput.column]=='*') //don;t forget to check 
                {
            printf("condition 1");

                    //if its hit and not part of the sunk ship, target it
                    if(currentPlayer->shipSunkGrid[currentInput.row][currentInput.column]==0)
                    {
            printf("condition 2");

                        currentPlayer->probGrid[currentInput.row][currentInput.column]=-2;
                    }else{
                        currentPlayer->probGrid[currentInput.row][currentInput.column]= 0;
                    }
                }else if(currentPlayer->hitsAndMissesGrid[currentInput.row][currentInput.column]=='~')
                {
            printf("condition 3");

                    printf("i am checking a ~ block ");
                    currentPlayer->probGrid[currentInput.row][currentInput.column]=-1;
                }else if(currentPlayer->hitsAndMissesGrid[currentInput.row][currentInput.column]=='o')
                {
            printf("condition 4");

                    currentPlayer->probGrid[currentInput.row][currentInput.column]=0;
                }
        }

        
        updateCoordByCross(&currentInput,i);
    }
    printf("the probgrid after updating is :");
    printGridInt(currentPlayer->probGrid);
    
}

//this functions update the probability of the adjacent rows and cols of a hit   but is that hit not part of the missed ship.
void updateProbOfHit(PLAYER* currentPlayer,int row,int col)
{
    if(!isInBound2(row,col))
    {return;}
    
    
    if(currentPlayer->hitsAndMissesGrid[row][col]=='*') //don;t forget to check 
    {
        //if its hit and not part of the sunk ship, target it
        if(currentPlayer->shipSunkGrid[row][col]==0)
        {
            currentPlayer->probGrid[row][col]=-2;
        }else{
            currentPlayer->probGrid[row][col]= 0;
        }
    }else if(currentPlayer->hitsAndMissesGrid[row][col]=='~')
    {
        currentPlayer->probGrid[row][col]=-1;
    }else if(currentPlayer->hitsAndMissesGrid[row][col]=='o')
    {
        currentPlayer->probGrid[row][col]=0;
    }
            
}
//after we sink a ship, this functions updates the probGrid around the shipSunk;

void updateProbabilityGridAroundShip(PLAYER* currentPlayer, INPUT* input, int lastHitRow, int lastHitCol, int SHIPSUNKSIZE) {
    //in here the currentPlayer->hitsBeforeSunk is still unchanged
    // Update the probability grid around the original input (the new hit position)
    
    printf("i am now in the function that checks after w e sink a ship\n");
    int row = input->row;
    int col = input->column;


    /* this is the irgoinal code for updateProbabilityCross
    // Check and update the surrounding cells (up, down, left, right) of the input position
    if (isInBound2(row, col)) {
        // Update the current hit position
        if (currentPlayer->probGrid[row][col] < 0) {
            currentPlayer->probGrid[row][col]++;
        } else if (currentPlayer->probGrid[row][col] >= 0) {
            currentPlayer->probGrid[row][col] = 9999;
        }

        // Check up (row-1, col)
        if (isInBound2(row - 1, col)) {
            if (currentPlayer->probGrid[row - 1][col] < 0) {
                currentPlayer->probGrid[row - 1][col]++;
            } else if (currentPlayer->probGrid[row - 1][col] >= 0) {
                currentPlayer->probGrid[row - 1][col] = 9999;
            }
        }

        // Check down (row+1, col)
        if (isInBound2(row + 1, col)) {
            if (currentPlayer->probGrid[row + 1][col] < 0) {
                currentPlayer->probGrid[row + 1][col]++;
            } else if (currentPlayer->probGrid[row + 1][col] >= 0) {
                currentPlayer->probGrid[row + 1][col] = 9999;
            }
        }

        // Check left (row, col-1)
        if (isInBound2(row, col - 1)) {
            if (currentPlayer->probGrid[row][col - 1] < 0) {
                currentPlayer->probGrid[row][col - 1]++;
            } else if (currentPlayer->probGrid[row][col - 1] >= 0) {
                currentPlayer->probGrid[row][col - 1] = 9999;
            }
        }

        // Check right (row, col+1)
        if (isInBound2(row, col + 1)) {
            if (currentPlayer->probGrid[row][col + 1] < 0) {
                currentPlayer->probGrid[row][col + 1]++;
            } else if (currentPlayer->probGrid[row][col + 1] >= 0) {
                currentPlayer->probGrid[row][col + 1] = 9999;
            }
        }
    }
    */
    
    updateProbabilityCross(currentPlayer,input->row,input->column);

    // Direction of movement (vertical or horizontal)
    int direction = 0;  // 1 for vertical, 0 for horizontal
    int step = 0;       // Used to keep track of the distance covered by the ship size

    // Determine if the hit is vertical or horizontal by comparing row or column
    if (input->row == lastHitRow) {
        direction = 0; // Horizontal movement
    } else if (input->column == lastHitCol) {
        direction = 1; // Vertical movement
    }

    // Move in the direction of the last hit depending on the ship size (SHIPSUNKSIZE)
    for (;step < currentPlayer->hitsBeforeShipSunk;step++) 
    {
        if (direction == 0) {
            // Horizontal movement (left-right)
            if (input->column > lastHitCol) {
                // Moving right (increasing column)
                lastHitCol++;
            } else if (input->column < lastHitCol) {
                // Moving left (decreasing column)
                lastHitCol--;
            }

        } else if (direction == 1) {
            // Vertical movement (up-down)
            if (input->row > lastHitRow) {
                // Moving down (increasing row)
                lastHitRow++;
            } else if (input->row < lastHitRow) {
                // Moving up (decreasing row)
                lastHitRow--;
            }
        }
        currentPlayer->shipSunkGrid[lastHitRow][lastHitCol]=1;

        if(step>SHIPSUNKSIZE)
        {
            printf("i am in the part where i am checking unhit spots");
            INPUT currentInput;
            currentInput.row=lastHitRow;
            currentInput.column = lastHitCol;

            for(int  i = 0 ; i<4 ;i++)
            {
            
            updateCoordByCross(&currentInput,i);
            updateProbOfHit(currentPlayer,row,col);

            }
            //check if that coord is hit
            
            continue;
        }
        

            // // Update probability grid based on new position
        if (isInBound2(lastHitRow, lastHitCol)) {
            if (currentPlayer->probGrid[lastHitRow][lastHitCol] < 0) {
                currentPlayer->probGrid[lastHitRow][lastHitCol]++;
            } else if (currentPlayer->probGrid[lastHitRow][lastHitCol] >= 0) {
                currentPlayer->probGrid[lastHitRow][lastHitCol] = 9999;
            }
        }
            
    }
    printGridInt(currentPlayer->shipSunkGrid);
        // Increment step to move in the direction
        
}

    
    

//returns 0 if no new ship sunk or the size of the actual ship sunk
int checkShipStatusChange(PLAYER* opposingPlayer, int* opposingShipsStatus) {
    // Compare each ship status
    for (int i = 0; i < NUMBEROFSHIPS; i++) {
        // If the status does not match, return the first index of the mismatch
        if (opposingShipsStatus[i] != opposingPlayer->ships[i].hasFallen) {
            return 5-i;  // Return the size of the ship where the change occurred
        }
    }

    // If no changes are found, return 0
    return 0;
}


void printShipInfo(PLAYER* opposingPlayer) {
    for (int i = 0; i < 4; i++) {  // Loop over the 4 ships
        SHIP* ship = &opposingPlayer->ships[i];

        printf("Ship %d:\n", i + 1);

        printf("Coordinates: ");
        for (int j = 0; j < 6; j++) {
            if (ship->coord[j] != 0) {  // Only print non-zero coordinates
                printf("%d ", ship->coord[j]);
            }
        }

        printf("\nHas Fallen: %s\n\n", ship->hasFallen ? "Yes" : "No");
    }
}

void hitOutcome(PLAYER *currentPlayer,PLAYER* opposingPlayer, INPUT* input,int* opposingShipsStatus,Coord* lastHit ) {

    //if we hit a random spot
    if(currentPlayer->probGrid[input->row][input->column]>=0)
    {
        for(int i =0 ;i<4;i++)
        {
            updateCoordByCross(input,i);
            processSurroundingCell(currentPlayer,input);
        }
        return;
    }

    //if we hit a marked spot
    //if we hit a ship at that marked spot that means its connected to another hit ship
    if(currentPlayer->hitsAndMissesGrid[input->row][input->column]=='*')
    {
        currentPlayer->probGrid[input->row][input->column]=9999;// make it 0 so that the next time the prob grid changes it to 0 because its a hit

        
        int lastHitRow = lastHit->row;
        int lastHitCol = lastHit->col;

        

        //if the new hit is on the same row as the last hit
        if(input->row == lastHitRow)//don't forget bound checking
        {
           
            //to make the -1 up and down the last hit 0 so they will be changed again
            if(isInBound2(lastHitRow+1,lastHitCol))
            {
                currentPlayer->probGrid[lastHitRow+1][lastHitCol]=888;
            }

            if(isInBound2(lastHitRow-1,lastHitCol))
            {
                currentPlayer->probGrid[lastHitRow-1][lastHitCol]=888;
            }
            
            //this is to add -1 next to the new hit on the right box **-1
            if(input->column-lastHitCol>0)
            {
                if(isInBound2(input->row,input->column+1))
                {
                    if(currentPlayer->hitsAndMissesGrid[input->row][input->column+1]=='~')//this means its already hit don't change it or miss don't changeit  only if untouched we change it
                    {
                        currentPlayer->probGrid[input->row][input->column+1]=-1;
                    }
                } 
            }else{ //-1**
                if(isInBound2(input->row,input->column-1))
                {
                    if(currentPlayer->hitsAndMissesGrid[input->row][input->column-1]=='~')//this means its already hit don't change it or miss don't changeit  only if untouched we change it
                    {
                        currentPlayer->probGrid[input->row][input->column-1]=-1;
                    }
                }
                
            }

        }
        else //if they are not on the same row automaticly means they are on the same colmun
        {   //bade enebeth 23ml -1 eza azghar men 0
            if (isInBound2(lastHitRow, lastHitCol + 1)) {
                currentPlayer->probGrid[lastHitRow][lastHitCol + 1]++;
            }
            if (isInBound2(lastHitRow, lastHitCol - 1)) {
                currentPlayer->probGrid[lastHitRow][lastHitCol - 1]++;
            }
            
            // Handle vertical neighbor (down or up) based on input row
            if (input->row - lastHitRow > 0) { // Input is below the last hit
                if (isInBound2(input->row + 1, input->column)) {
                    if (currentPlayer->hitsAndMissesGrid[input->row + 1][input->column] == '~') {
                        currentPlayer->probGrid[input->row + 1][input->column] = -1;
                    }
                }
            } 
            else
            { // Input is above the last hit
                if (isInBound2(input->row - 1, input->column)) {
                    if (currentPlayer->hitsAndMissesGrid[input->row - 1][input->column] == '~') {
                        currentPlayer->probGrid[input->row - 1][input->column] = -1;
                    }
                }
            }

        }
        
        //i  now check around it
        // i have to check the orientation of the next shot as well;
        // i have to check if its next to a hit and i have to be careful not to check hit ships from long before

        // we check if any ship sunk

        int result = checkShipStatusChange(opposingPlayer,opposingShipsStatus);


        if(result ==0) //no ship sunk
        {
            return ;//i cannot know anything so next
        }
        else if (currentPlayer->hitsBeforeShipSunk>= result)
        {
            for (int row = 0; row < GRID_SIZE; row++) 
            {
                for (int col = 0; col < GRID_SIZE; col++) 
                {
                    // Check if the current position is a hit ('*') and the ship is not sunk (shipSunkGrid[row][col] == 0)
                    if (currentPlayer->hitsAndMissesGrid[row][col] == '*' && currentPlayer->shipSunkGrid[row][col] == 0) {
                    currentPlayer->probGrid[row][col]=-1;
                    }else{
                        currentPlayer->probGrid[row][col]=0;
                    }
                }
            }

            printf("the probability grid after checking the hits but not sunk\n");
            printGridInt(currentPlayer->probGrid);
            for (int row = 0; row < GRID_SIZE; row++) 
            {
                for (int col = 0; col < GRID_SIZE; col++) 
                {
                
                //updae the -1 only the coord surrownding them
                    if (currentPlayer->probGrid[row][col]==-1) 
                    {
                        INPUT tempInput;
                        tempInput.row= input->row;
                        tempInput.column =input->column;
                        for(int  i = 0 ;i<4;i++)
                        {
                            
                            updateCoordByCross(&tempInput,i);
                            updateProbOfHit(currentPlayer,tempInput.row,tempInput.column);
                        }
                    }
                }
                
            }

            printf("the probability grid afterupdating  the hits but not sunk around them\n");
            printGridInt(currentPlayer->probGrid);

         
        
    
            // updateProbabilityGridAroundShip(currentPlayer,input,lastHitRow,lastHitCol,result);
            //ana hon i have sunk the ship and didn;t hit any other ship at the same time 
                
                /*
                // if (currentPlayer->hitsBeforeShipSunk== result)
                // {

                //     //make all the -1 into 0 adjacent to the ship or maybe +1 so maybe if one had 2 but won;t ever happen ma baarf 3m 5arref
                        
                //     int lastHitRow = lastHit->row;
                //     int lastHitCol = lastHit->col;

                //     if(input->row == lastHitRow)//don't forget bound checking
                //     {
                //         currentPlayer->probGrid[lastHitRow--][lastHitCol]++;
                //         currentPlayer->probGrid[lastHitRow++][lastHitCol]++;
                //         if(input->column-lastHitCol>0)
                //         {
                //             currentPlayer->probGrid[input->row][input->column+1]=-1;
                //         }else{
                //             currentPlayer->probGrid[input->row][input->column-1]=-1;
                //         }

                */


        }
        else if(currentPlayer->hitsBeforeShipSunk > result)
        {   
            
            //i have hit more ships than i sunk, on of the hits was for another ship.

        }


        if(result>0) //a ship has sunk;
        {
            currentPlayer->hitsBeforeShipSunk-= result;


            
        }
        
    }// if we misses the hitandmiss will become 'o' and the probgrid will change the -1 to 0
    else{
        currentPlayer->probGrid[input->row][input->column]=0;
    }

    printShipInfo(opposingPlayer);
}
    
    

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

void saveOpposingShipsStatus(PLAYER* opposingPlayer,int* opposingShipsStatus)
{
    

    for(int  i = 0 ; i < NUMBEROFSHIPS ;i++)
    {
        opposingShipsStatus[i]=opposingPlayer->ships[i].hasFallen;   
    }
    

}

void handleFire(PLAYER* currentPlayer, PLAYER* opposingPlayer) 
{
    INPUT input;

    Coord coord=getHighestProbSquare(currentPlayer,opposingPlayer);
    
    input.row=coord.row;
    input.column = coord.col;

    //to save the state of the ooponent ships before hit
    int opposingShipsStatus[NUMBEROFSHIPS];
    saveOpposingShipsStatus(opposingPlayer,opposingShipsStatus);

    //to save last hit
    Coord lastHit;
    lastHit.row = currentPlayer->lastHit.row;
    lastHit.col = currentPlayer->lastHit.col;

    printf("The bot plays Fire %d,%c\n",input.row+1, input.column+97);
    fireMove(currentPlayer,opposingPlayer,&input);


    if(currentPlayer->hitsAndMissesGrid[input.row][input.column]=='*')
    {
        currentPlayer->hitsBeforeShipSunk++;
        printf("the number of hits before sink ; %d\n", currentPlayer->hitsBeforeShipSunk);

        hitOutcome(currentPlayer,opposingPlayer,&input,opposingShipsStatus,&lastHit);

    }else {
        currentPlayer->probGrid[input.row][input.column]=0;
        printf("No hit at (%d, %d), no change to probGrid.\n", input.row, input.column);
    }


        int negativeCounter = 0; 

        for(int i = 0 ; i < GRID_SIZE;i++)
        {
            for (int j = 0 ; j <GRID_SIZE ;j++)
            {
                if (currentPlayer->probGrid[i][j]<0)
                {
                    negativeCounter++;
                }
            }
        }

        int hitsButNotSunkCounter =0;
        {
            for (int row = 0; row < GRID_SIZE; row++) 
            {
                for (int col = 0; col < GRID_SIZE; col++) 
                {
                    // Check if the current position is a hit ('*') and the ship is not sunk (shipSunkGrid[row][col] == 0)
                    if (currentPlayer->hitsAndMissesGrid[row][col] == '*' && currentPlayer->shipSunkGrid[row][col] == 0) {
                    hitsButNotSunkCounter++;
                    }
                }
        }
    

        

        if(negativeCounter ==0 && hitsButNotSunkCounter >0)
        {


            printf("\n\ni am entering this condition that there are no negative porb but the hitsbut not sunk counter is > 0 from the end of the firemove\n");
            printGridInt(currentPlayer->probGrid);

            printGridInt(currentPlayer->shipSunkGrid);
            for (int row = 0; row < GRID_SIZE; row++) 
            {
                for (int col = 0; col < GRID_SIZE; col++) 
                {
                    // Check if the current position is a hit ('*') and the ship is not sunk (shipSunkGrid[row][col] == 0)
                    if (currentPlayer->hitsAndMissesGrid[row][col] == '*' && currentPlayer->shipSunkGrid[row][col] == 0) {
                    currentPlayer->probGrid[row][col]=-1;
                    }else{
                        currentPlayer->probGrid[row][col]=0;
                    }
                }
            }
            printf("the probability grid after checking the hits but not sunk\n");
            printGridInt(currentPlayer->probGrid);

            int tempGRID[GRID_SIZE][GRID_SIZE];

    // Copy values from probGrid to tempGRID
    for (int row = 0; row < GRID_SIZE; row++)
    {
        for (int col = 0; col < GRID_SIZE; col++)
        {
            tempGRID[row][col] = currentPlayer->probGrid[row][col];
        }
    }

            
            for (int row = 0; row < GRID_SIZE; row++) 
            {
                for (int col = 0; col < GRID_SIZE; col++) 
                {
                
                //updae the -1 only the coord surrownding them
                    if (tempGRID[row][col]==-1) 
                    {
                        
                        updateProbabilityCross(currentPlayer,row,col) ;
                            printf("THE COORD I AM CHECKING ARE %d,%d",row, col);
                        

                        currentPlayer->probGrid[row][col]=0;
                    }
                }
                
            }

            printf("the probability grid afterupdating  the hits but not sunk around them\n");
            printGridInt(currentPlayer->probGrid);

         
        
    
            }
        }
    
    

}


