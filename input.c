#include "headerFile.h"

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
        row = row/10;
        row--;
        return row;
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

    if(INPUTOVERFLOW==0)
    {
        return;
    }
    
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
            if(difficulty==HARD)
            {
                if(grid[i][j]=='o')
                {
                    printf("~ ");
                }else 
                {
                    printf("%c ", grid[i][j]);
                }
            }else{
                 printf("%c ", grid[i][j]);
            }
           
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
        return -1;
    }

}

int getOrientation(char* input)
 {

    if (strcmp(input, "horizontal") == 0) {
        return HORIZONTAL;
    } else if (strcmp(input, "vertical") == 0) {
        return VERTICAL;
    } else {
        printf("Please enter either 'horizontal' or 'vertical' for the orientation.\n");
        return -1;
    }


   
}

void getInputForPlacingShips(INPUT* input)
{
    char stringInput[20];

    fgets(stringInput,sizeof(stringInput),stdin);
    clearInput(stringInput,sizeof(stringInput));
    //each leading and trailing are the leading and trailing whitespaces respectively

    int leading1 = getLeadingCharachterIndex(stringInput,0);
    int trailing1 = getTrailingCharachterIndex(stringInput,leading1);

    input->column= getColumn(stringInput[leading1]);

    int leading2 = getLeadingCharachterIndex(stringInput, leading1+1);
    int trailing2 = getTrailingCharachterIndex(stringInput,leading2);

    
    input->row = getRow(stringInput, leading2, trailing2);
    
    int leading3 = getLeadingCharachterIndex(stringInput, trailing2);
    int trailing3 = getTrailingCharachterIndex(stringInput,leading3);
    
    for(int i = 0; i < trailing3-leading3;i++)
    {
        input->orientation[i]= stringInput[leading3+i];
        
    }
    input->orientation[trailing3-leading3] = '\0';
    

}

//input for placing ship is the opposit of that to make moves
void getInput(INPUT* input)
{
    char stringInput[20];

    fgets(stringInput,sizeof(stringInput),stdin);
    clearInput(stringInput,sizeof(stringInput));

    int leading1 = getLeadingCharachterIndex(stringInput,0);
    int trailing1 = getTrailingCharachterIndex(stringInput,leading1);

    for(int i = 0; i < trailing1-leading1;i++)
    {
        input->moveName[i]= stringInput[leading1+i];
    }
    input->moveName[trailing1-leading1]='\0';

    int leading2 = getLeadingCharachterIndex(stringInput, trailing1);
    int trailing2 = getTrailingCharachterIndex(stringInput,leading2);

    if(strcmp(input->moveName,"torpedo")==0)
    {
        input->row = getRow(stringInput,leading2,trailing2);
        input->column = getColumn(stringInput[leading2]);
        return;
    }
    
    int leading3 = getLeadingCharachterIndex(stringInput, leading2+1);
    int trailing3 = getTrailingCharachterIndex(stringInput,leading3);
    
    input->column= getColumn(stringInput[leading2]);
    input->row = getRow(stringInput, leading3, trailing3);

}

int getLeadingCharachterIndex(char*input , int start)
{
    while(input[start]== ' ')
    {
        start++;
    }

    return start;
}

int getTrailingCharachterIndex(char*input, int start)
{
    while(input[start]!= ' ' && input[start]!= '\n'&& input[start]!= EOF )
    {
        start++;
    }

    return start;
}

//function to check the validation of the given input
int isInBound(INPUT* input)
{
     if (input->row < 0 || input->row >= GRID_SIZE) {
        return 0;
    }

    
    if (input->column < 0 || input->column >= GRID_SIZE) {
        return 0;
    }

    return 1;
}
//function to update the coordinates to move around the square area
void updateCoordBySquare(struct Input*input ,int iteration)
{
    if(iteration ==0)
    {
        input->column++; //move right
    }else if(iteration ==1)
    { 
        input->row++; //down
    }else if(iteration ==2)
    {
        input->column--; //left

    }else if (iteration == 3) 
    {
        input->row--;    //up even though unecessary
    }
}
