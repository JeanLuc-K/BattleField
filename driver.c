#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRID_SIZE 10

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void printGrid(char grid[GRID_SIZE][GRID_SIZE]);
void allocateMemory(char grid[GRID_SIZE][GRID_SIZE]);
int getColumn(char[4]);
int getRow(char[4]);
int getOrientation(char[11]);

int main()
{

    char grid1[GRID_SIZE][GRID_SIZE];//for player 1
    initializeGrid(grid1);
    char grid2[GRID_SIZE][GRID_SIZE];// For player 2
    initializeGrid(grid2);

    char name1[50];
    char name2[50];
    printf("Please enter name of Player 1: ");
    scanf("%s",name1);
    printf("Please enter name of Player 2: ");
    scanf("%s",name2);

    printf("\n");

    char* firstPlayerName;
    char* SecondPlayerName;

    srand(time(NULL));
    int randomNumber=rand()%2; //create random number 
    if(randomNumber) //chooses randoml which player to start
    {
        printf("The first player is %s\n",name1);
        firstPlayerName = name1;
        SecondPlayerName = name2;
        
    }else
    {
        printf("The first player is %s\n", name2);
        firstPlayerName= name2;
        SecondPlayerName = name1;
    }
   

    printf("\n");

    printf("%s, please enter your ships coordinates\n",firstPlayerName);
    printf("first start with the square(A10), then the orienttion(horizontal, vertical\n)");
    
    const char* shipsNames[]={"Carrier","Battleship","Destroyer","Submarine"}; //all ships to avoid clustering if condition
    int currentShipSize;
    int column;
    int row;
    char inputStartingCoordinates[4];
    char inputOrientation[11];

    for(int i = 0 ;i<4 ; i++) //4 total ships to place
    {
        currentShipSize = 4-i; //reverse order size

        printf("Where would you like to place your %s (%d cells)?\n",shipsNames[i],currentShipSize);

        scanf("%s", &inputStartingCoordinates);

        if(inputStartingCoordinates[0] =='\n')
        {
            printf("Coordinate is invalid\n");
            i--;
            continue;
        }
        
        column = getColumn(inputStartingCoordinates); // transform into coord
        
        if(column ==-1) //validate the column coordinate
        {
           
            i--; //to repeat the loop ;
            continue;
        }

        row = getRow(inputStartingCoordinates); // cast into coordinate with respect to the 2D array indexes;
       
       if(row ==-1) //validate the row coordinate
        {
            
            i--; //to repeat the loop ;
            continue;
        }

        scanf("%s", &inputOrientation);

        if(inputOrientation[0] =='\n')
        {
            printf("orientation is invalid\n");
            i--;
            continue;
        }

        int orientation = getOrientation(inputOrientation); // 0  for horizontal 1 for vertical

        if(orientation==-1) //valiat orientation
        {
            i--;
            continue;
        }




        
    }
   


    
   
}

int getColumn(char input[4])
{
        if (input[0] == 'A' || input[0] == 'a') {
        return 0;
    } else if (input[0] == 'B' || input[0] == 'b') {
        return 1;
    } else if (input[0] == 'C' || input[0] == 'c') {
        return 2;
    } else if (input[0] == 'D' || input[0] == 'd') {
        return 3;
    } else if (input[0] == 'E' || input[0] == 'e') {
        return 4;
    } else if (input[0] == 'F' || input[0] == 'f') {
        return 5;
    } else if (input[0] == 'G' || input[0] == 'g') {
        return 6;
    } else if (input[0] == 'H' || input[0] == 'h') {
        return 7;
    } else if (input[0] == 'I' || input[0] == 'i') {
        return 8;
    } else if (input[0] == 'J' || input[0] == 'J'){
        return 9;  
    }else 
    {
         printf("Please enter a letter between A and J for the column\n");
        return -1;
    }

}

int getRow(char input[4])
{
    if(input[1]==0)
    {
        return input[2]; //the user entered a number from 01 ..09
    }

    if(input[1]== 1) //if the first digitit is 1 there is a chace that the coord is 10;
    {
        if(input[2]==0)//then the user entered 10
        {
            return 10;
        }else
        {
            printf("Plase enter a number betwwen 1 and 10 for the row\n");
            return -1; //the first digit was 1 and the second is not 0 so >10 so invalid
        }
    }

    return input[1]; 

    
}

int getOrientation(char input[11])
{
    if(strcmp(input,"horizontal"))
    {
        return 0;
    }else if(strcmp(input,"vertical"))
    {
        return 1;
    }else{
        printf("please enter either horizontal or vertical for the orientation\n");
        return -1;
    }
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

int difficultyLevel(){
   char difficulty[5];
   printf("Please enter your difficulty level: ");
   scanf("%s ",difficulty);

   if(strcmp(difficulty, "easy") == 0){
    return 0;
   }else{
    return 1;
   }
}