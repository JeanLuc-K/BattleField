#include "../headerFile.h"

void addShip(PLAYER* currentPlayer,INPUT* input,const char* name,int shipSize)
{   
    printf("Ship size is: %d", shipSize);
    SHIP* ships = currentPlayer->ships; //array of ships
    int shipIndex = 4-shipSize+1; //first ship is the biggest

    int sizeofName =0;
    while(name[sizeofName]!= '\0')
    {
        sizeofName++;
    }

    strncpy(ships[shipIndex].name, name, sizeofName);
    ships[shipIndex].name[sizeofName] = '\0'; //get the name coorectly

    currentPlayer->ships[shipIndex].size = shipSize;//set the size of each ship


    int orientation = getOrientation(input->orientation);
    if(orientation==HORIZONTAL)
    {
        for(int  i = 0 ; i<shipSize;i++)
        {
            currentPlayer->grid[input->row][i+input->column] = 'X';
           currentPlayer->ships[shipIndex].coord[i] = (input->row * 10) + (input->column + i);//save ship coord as an integer where the  ones place is the column and the the tens place is the row smart i know 
            
        }
    }else if(orientation==VERTICAL)
    {
        
        for(int  i = 0 ; i<shipSize;i++)
        {
            currentPlayer->grid[i+input->row][input->column] = 'X';
            currentPlayer->ships[shipIndex].coord[i] = (input->row + i) * 10 + input->column; 
        }
    }
    ships[shipIndex].hits=0;
    ships[shipIndex].hasFallen =0;

}

int checkBounds(PLAYER* currentPlayer,INPUT* input,int shipSize)
{
    int orientation = getOrientation(input->orientation);
   if(orientation==HORIZONTAL)
    {
        if(input->column + shipSize >GRID_SIZE)
        {
            printf("Ship is out of bound\n");
            return -1;
        }
    }else if(orientation ==VERTICAL)
    {
        if(input->row+shipSize > GRID_SIZE)
        {
            printf("Ship is out of bound\n");
            return -1;
        }
    }

    if(orientation==HORIZONTAL)
    {
        for(int  i = 0 ; i<shipSize;i++)
        {
            if(currentPlayer->grid[input->row][input->column+i] != '~')
            {
                printf("ships overlap\n");
                return -1;
            }
        }
    }else if(orientation==VERTICAL)
    {
        
        for(int  i = 0; i<shipSize;i++)
        {
            if(currentPlayer->grid[i+input->row][input->column] != '~')
            {
                printf("ships overlap\n");
                return -1;
            }
        }
    }

    return 1;



}

void placeShips(PLAYER* player)
{

    printf("%s, please enter your ships coordinate.\n", player->name);
    printf("First start with the square(A10), then the orienttion(horizontal, vertical).\n");

    const char *shipsNames[] = {"Carrier", "Battleship", "Destroyer", "Submarine"}; // all ships to avoid clustering if condition
    for (int i = 0; i < NUMBEROFSHIPS; i++) // 4 total ships to place
    {

        int currentShipSize = 5 - i; // reverse order size

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

        if (input.row < 0 || input.row > 9) // validate the row coordinate
        {
            printf("please enter a valid row\n");
            i--; // to repeat the loop ;
            continue;
        }


        int orientation = getOrientation(input.orientation); // 0  for horizontal 1 for vertical

        if (orientation == -1) // validate orientation
        {
            printf("please enter a valid column from A to J\n");
            i--;
            continue;
        }

        if (checkBounds(player,&input, currentShipSize) == -1)
        {
            i--;
            continue;
        }
        
        addShip(player,&input,shipsNames[i],currentShipSize);
        
        printGrid(player->grid);
        
    }

    printf("\n");
}
