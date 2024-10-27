#include "headerFile.h"

void addShip(char grid[GRID_SIZE][GRID_SIZE], int column,int row,int orientation,int shipSize)
{
    
    if(orientation==HORIZONTAL)
    {
        for(int  i = 0 ; i<shipSize;i++)
        {
            grid[row][i+column] = 'X';
            
        }
    }else if(orientation==VERTICAL)
    {
        
        for(int  i = 0 ; i<shipSize;i++)
        {
            grid[i+row][column] = 'X';
        }
    }
}

int checkBounds(char grid[GRID_SIZE][GRID_SIZE], int column,int row,  int orientation,int shipSize)
{
   if(orientation==HORIZONTAL)
    {
        if(column + shipSize >GRID_SIZE)
        {
            printf("Ship is out of bound\n");
            return -1;
        }
    }else if(orientation ==VERTICAL)
    {
        if(row+shipSize > GRID_SIZE)
        {
            printf("Ship is out of bound\n");
            return -1;
        }
    }

    if(orientation==HORIZONTAL)
    {
        for(int  i = 0 ; i<shipSize;i++)
        {
            if(grid[row][column+i] != '~')
            {
                printf("ships overlap\n");
                return -1;
            }
        }
    }else if(orientation==VERTICAL)
    {
        
        for(int  i = 0; i<shipSize;i++)
        {
            if(grid[i+row][column] != '~')
            {
                printf("ships overlap\n");
                return -1;
            }
        }
    }

    return 1;



}


void createGrid(PLAYER* player)
{

    printf("%s, please enter your ships coordinate.\n", player->name);
    printf("First start with the square(A10), then the orienttion(horizontal, vertical).\n");

    const char *shipsNames[] = {"Carrier", "Battleship", "Destroyer", "Submarine"}; // all ships to avoid clustering if condition
    for (int i = 0; i < 4; i++) // 4 total ships to place
    {

        int currentShipSize = 4 - i; // reverse order size

        printf("Where would you like to place your %s (%d cells)?\n", shipsNames[i], currentShipSize);

        INPUT input;
        getInputForPlacingShips(&input);        

        // transform into coord
        if (input.column == -1)             // validate the column coordinate
        {
            i--; // to repeat the loop ;
            printf("please enter a valid column\n");

            continue;
        }

        if (input.row <= 0 || input.row > 10) // validate the row coordinate
        {
            printf("please enter a valid row\n");
            i--; // to repeat the loop ;
            continue;
        }

        input.row--; // to accomodate for the index that starts at 0;

        int orientation = getOrientation(input.orientation); // 0  for horizontal 1 for vertical

        if (orientation == -1) // validate orientation
        {
            i--;
            continue;
        }

        if (checkBounds(player->grid, input.column, input.row, orientation, currentShipSize) == -1)
        {
            i--;
            continue;
        }
        
        addShip(player->grid, input.column, input.row, orientation, currentShipSize);
        printGrid(player->grid);
        
    }
}
