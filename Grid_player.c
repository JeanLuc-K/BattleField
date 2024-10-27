//this function is used to be able to create grid for each player to insert there battleships
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grid_player.h"
#define GRID_SIZE 10

void addShip(char grid[GRID_SIZE][GRID_SIZE], int column,int row,int orientation,int shipSize)
{
    
    if(orientation==0)
    {
        for(int  i = 0 ; i<shipSize;i++)
        {
            grid[row][i+column] = 'X';
            
        }
    }else if(orientation==1)
    {
        
        for(int  i = 0 ; i<shipSize;i++)
        {
            grid[i+row][column] = 'X';
        }
    }
}
// 0  for horizontal 1 for vertical
int checkBounds(char grid[GRID_SIZE][GRID_SIZE], int column,int row,  int orientation,int shipSize)
{
   if(orientation==0)
    {
        if(column + shipSize >GRID_SIZE)
        {
            printf("Ship is out of bound\n");
            return -1;
        }
    }else if(orientation ==1)
    {
        if(row+shipSize > GRID_SIZE)
        {
            printf("Ship is out of bound\n");
            return -1;
        }
    }

    if(orientation==0)
    {
        for(int  i = 0 ; i<shipSize;i++)
        {
            if(grid[row][column+i] != '~')
            {
                printf("ships overlap\n");
                return -1;
            }
        }
    }else if(orientation==1)
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

int getRow(char* input,int startCoord, int whiteSpaceIndex)
{
    if(whiteSpaceIndex-startCoord ==0 || whiteSpaceIndex-startCoord >2) //check if no character entered or more than 2 characters
    {
        return -1;
    }else{
        int row  = 0;
        for(int i = startCoord ; i <whiteSpaceIndex;i++)
        {
            int digit = getDigit(input[i]); //get each digit seperately
            if(digit != -1) 
            {
                row +=digit; //get the row using complexe algorithm that took me 3 hours
                row *=10;
            }else return -1;
            
        }
        return row/10-1;
    }
    

    
}

int getDigit(char c)
{
    int digit = c-'0';
    for(int i = 0 ; i <= 9 ; i++)
    {
        if(digit ==i)
        {
            return i;
        }
    }
    return -1;
}

void clearInput(char* input, int size) //removes any overflow in the input
{
    int hasNewLine = 0;
    for(int i = 0 ; i < size; i++) //check if the input has a newline charachter
    {
        if(input[i] =='\n')
        {
            hasNewLine=1;
            break;
        }

    }
    char charachter;
    if(hasNewLine==0)
    {
       
        while(charachter = getchar()!='\n' && charachter!=EOF);
    }
}

void printGrid(char grid[GRID_SIZE][GRID_SIZE])
{

    printf("    A B C D E F G H I J\n");

    for (int i = 0; i < GRID_SIZE; i++)
    {
        if (i != 9){
            printf("%d   ", i + 1);
        }
        else{
             printf("%d  ", i + 1);
        }
        for (int j = 0; j < GRID_SIZE; j++)
        {

            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}


int getColumn(char input)
{
   
        if (input == 'A' || input == 'a') {
        return 0;
    } else if (input == 'B' || input == 'b') {
        return 1;
    } else if (input == 'C' || input == 'c') {
        return 2;
    } else if (input == 'D' || input == 'd') {
        return 3;
    } else if (input == 'E' || input == 'e') {
        return 4;
    } else if (input == 'F' || input == 'f') {
        return 5;
    } else if (input == 'G' || input == 'g') {
        return 6;
    } else if (input == 'H' || input == 'h') {
        return 7;
    } else if (input == 'I' || input == 'i') {
        return 8;
    } else if (input == 'J' || input == 'j'){
        return 9;  
    }else 
    {
         printf("Please enter a letter between A and J for the column\n");
        return -1;
    }

}

int getOrientation(char* input ,int whiteSpaceIndex)
{
    int whiteSpaceBefore = whiteSpaceIndex;
    while(input[whiteSpaceBefore] == ' ' && input[whiteSpaceBefore] != '\0')
    {
        whiteSpaceBefore++;
    }

    int endOfOrientationInput = whiteSpaceBefore+1;
    while(input[endOfOrientationInput]!= ' ' && input[endOfOrientationInput]!= '\n' && input[endOfOrientationInput] != '\0')
    {
        endOfOrientationInput++;
    }

    if(endOfOrientationInput-whiteSpaceBefore >10)
    {
        return -1;
    }


    char orientation[11];

    strncpy(orientation, input + whiteSpaceBefore, endOfOrientationInput - whiteSpaceBefore);
    orientation[endOfOrientationInput - whiteSpaceBefore] = '\0'; // Null-terminate the substring

    if (strcmp(orientation, "horizontal") == 0) {
        return 0;
    } else if (strcmp(orientation, "vertical") == 0) {
        return 1;
    } else {
        printf("Please enter either 'horizontal' or 'vertical' for the orientation.\n");
        return -1;
    }


   
}

void createGrid(char grid[10][10], char *playername)
{

    printf("%s, please enter your ships coordinate.\n", playername);
    printf("First start with the square(A10), then the orienttion(horizontal, vertical).\n");

    const char *shipsNames[] = {"Carrier", "Battleship", "Destroyer", "Submarine"}; // all ships to avoid clustering if condition
    int currentShipSize;
    int column;
    int row;
    char input[20];
    for (int i = 0; i < 4; i++) // 4 total ships to place
    {

        currentShipSize = 4 - i; // reverse order size

        printf("Where would you like to place your %s (%d cells)?\n", shipsNames[i], currentShipSize);

        fgets(input, sizeof(input), stdin);

        column = getColumn(input[0]); // transform into coord
        if (column == -1)             // validate the column coordinate
        {

            i--; // to repeat the loop ;
            clearInput(input, sizeof(input));
            continue;
        }

        int whiteSpaceIndex = 1;
        while (input[whiteSpaceIndex] != ' ' && whiteSpaceIndex < sizeof(input) - 1 && input[whiteSpaceIndex] != '\n') // get the index of the first white space
        {
            whiteSpaceIndex++;
        }

        row = getRow(input,1, whiteSpaceIndex);
        if (row <= 0 || row > 10) // validate the row coordinate
        {
            printf("please enter a valid row\n");
            clearInput(input, sizeof(input));
            i--; // to repeat the loop ;
            continue;
        }

        row--; // to accomodate for the index that starts at 0;

        int orientation = getOrientation(input, whiteSpaceIndex); // 0  for horizontal 1 for vertical

        if (orientation == -1) // validate orientation
        {
            i--;
            clearInput(input, sizeof(input));
            continue;
        }

        if (checkBounds(grid, column, row, orientation, currentShipSize) == -1)
        {
            i--;
            continue;
        }
        addShip(grid, column, row, orientation, currentShipSize);
        printGrid(grid);
        //Clear input buffer for player 2
        clearInput(input, sizeof(input));
    }
}
