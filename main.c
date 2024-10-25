#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRID_SIZE 10

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void printGrid(char grid[GRID_SIZE][GRID_SIZE]);
void allocateMemory(char grid[GRID_SIZE][GRID_SIZE]);
int getColumn(char);
int getOrientation(char* , int);
void clearInput();
void assignStartingPlayer(char**,char**,char*,char*);
int getDigit(char);
int getRow(char*, int);

int main()
{

    char grid1[GRID_SIZE][GRID_SIZE];//for player 1
    initializeGrid(grid1);
    char grid2[GRID_SIZE][GRID_SIZE];// For player 2
    initializeGrid(grid2);

    char name1[50];
    char name2[50];

    printf("Please enter name of Player 1(49 max characters): ");
    fgets(name1, sizeof(name1), stdin);
    

    printf("Please enter name of Player 2(49 max characters): ");
    fgets(name2, sizeof(name2), stdin);

    printf("\n");

    char* firstPlayerName;
    char* secondPlayerName;

    assignStartingPlayer(&firstPlayerName,&secondPlayerName,name1,name2);
    printf("\n");

    printf("%s, please enter your ships coordinate.\n",firstPlayerName);
    printf("First start with the square(A10), then the orienttion(horizontal, vertical).\n");
    
    const char* shipsNames[]={"Carrier","Battleship","Destroyer","Submarine"}; //all ships to avoid clustering if condition
    int currentShipSize;
    int column;
    int row;
    char input[20];
    for(int i = 0 ;i<4 ; i++) //4 total ships to place
    {
        currentShipSize = 4-i; //reverse order size

        printf("Where would you like to place your %s (%d cells)?\n",shipsNames[i],currentShipSize);

        fgets(input, sizeof(input), stdin);
        
        column = getColumn(input[0]); // transform into coord
        if(column ==-1) //validate the column coordinate
        {
           
            i--; //to repeat the loop ;
            continue;
        }

        int whiteSpaceIndex =1; 
        while(input[whiteSpaceIndex]!=' ' && whiteSpaceIndex<sizeof(input)-1) //get the index of the first white space 
        {
            whiteSpaceIndex++;
        }

        row = getRow(input,whiteSpaceIndex);
        if(row <= 0 || row >10) //validate the row coordinate
        {
            printf( "please enter a valid row\n");
            i--; //to repeat the loop ;
            continue;
        }

        row--; // to accomodate for the index that starts at 0;

        int orientation = getOrientation(input,whiteSpaceIndex); // 0  for horizontal 1 for vertical

        if(orientation==-1) //validate orientation
        {
            i--;
            continue;
        }

        




        
    }
   


    
   
}

int getRow(char* input,int whiteSpaceIndex)
{
    if(whiteSpaceIndex-1 ==0 || whiteSpaceIndex-1 >2) //check if no character entered or more than 2 characters
    {
        return -1;
    }else{
        int row  = 0;
        for(int i = 1 ; i <whiteSpaceIndex;i++)
        {
            int digit = getDigit(input[i]); //get each digit seperately
            if(digit != -1) 
            {
                row +=digit; //get the row using complexe algorithm that took me 3 hours
                row *=10;
            }else return -1;
            
        }
        return row/10;
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

void assignStartingPlayer(char** firstPlayerName, char** secondPlayerName, char*name1, char*name2)
{

    name1[strcspn(name1,"\n")] = '\0';
    name2[strcspn(name2,"\n")] = '\0';

    srand(time(NULL));
    int randomNumber=rand()%2; //create random number 
    if(randomNumber==0) //chooses randoml which player to start
    {
        printf("The first player is %s\n",name1);
        *firstPlayerName = name1;
        *secondPlayerName = name2;
        
    }else
    {
        printf("The first player is %s\n", name2);
        *firstPlayerName= name2;
        *secondPlayerName = name1;
    }
}

void clearInput()
{
    while (getchar() != '\n');
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
    } else if (input == 'J' || input == 'J'){
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