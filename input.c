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
        return -1;
    }

}

int getOrientation(char* input)
 {
//     int whiteSpaceBefore = whiteSpaceIndex;
//     while(input[whiteSpaceBefore] == ' ' && input[whiteSpaceBefore] != '\0')
//     {
//         whiteSpaceBefore++;
//     }

//     int endOfOrientationInput = whiteSpaceBefore+1;
//     while(input[endOfOrientationInput]!= ' ' && input[endOfOrientationInput]!= '\n' && input[endOfOrientationInput] != '\0')
//     {
//         endOfOrientationInput++;
//     }

//     if(endOfOrientationInput-whiteSpaceBefore >10)
//     {
//         return -1;
//     }


//     char orientation[11];

//     strncpy(orientation, input + whiteSpaceBefore, endOfOrientationInput - whiteSpaceBefore);
//     orientation[endOfOrientationInput - whiteSpaceBefore] = '\0'; // Null-terminate the substring

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