#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRID_SIZE 10

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void printGrid(char grid[GRID_SIZE][GRID_SIZE]);
int getColumn(char[2]);
int getOrientation(char[11]);

int main() {
    char grid1[GRID_SIZE][GRID_SIZE]; // For player 1
    initializeGrid(grid1);
    char grid2[GRID_SIZE][GRID_SIZE]; // For player 2
    initializeGrid(grid2);

    char name1[50];
    char name2[50];
    printf("Please enter name of Player 1: ");
    scanf("%s", name1);
    while (getchar() != '\n'); // Flush input buffer

    printf("Please enter name of Player 2: ");
    scanf("%s", name2);
    while (getchar() != '\n'); // Flush input buffer

    printf("\n");

    char *firstPlayerName;
    char *secondPlayerName;

    srand(time(NULL));
    int randomNumber = rand() % 2; // Create random number
    if (randomNumber == 0) { // Chooses randomly which player to start
        printf("The first player is %s\n", name1);
        firstPlayerName = name1;
        secondPlayerName = name2;
    } else {
        printf("The first player is %s\n", name2);
        firstPlayerName = name2;
        secondPlayerName = name1;
    }

    printf("\n");

    printf("%s, please enter your ships coordinates\n", firstPlayerName);
    printf("First start with the square (A10), then the orientation (horizontal, vertical)\n");

    const char *shipsNames[] = {"Carrier", "Battleship", "Destroyer", "Submarine"}; // All ships
    int currentShipSize;
    int column;
    int row;
    char inputStartingColumn[2];
    char inputOrientation[11];

    for (int i = 0; i < 4; i++) { // 4 total ships to place
        currentShipSize = 4 - i; // Reverse order size

        printf("Where would you like to place your %s (%d cells)?\n", shipsNames[i], currentShipSize);

        printf("Enter the column: ");
        fgets(inputStartingColumn, sizeof(inputStartingColumn), stdin);
        
        // Remove newline if present
        inputStartingColumn[strcspn(inputStartingColumn, "\n")] = '\0';

        column = getColumn(inputStartingColumn); // Transform into coord
        
        if (column == -1) { // Validate the column coordinate
            i--; // To repeat the loop
            continue;
        }

        printf("Enter the row: ");
        scanf("%d", &row); // Cast into coordinate with respect to the 2D array indexes
        
        if (row < 1 || row > 10) { // Validate the row coordinate
            i--; // To repeat the loop
            continue;
        }

        row--; // Adjust to zero-based index

        // Clear the newline character from the input buffer
        while (getchar() != '\n');

        printf("Enter the orientation: ");
        fgets(inputOrientation, sizeof(inputOrientation), stdin);
        inputOrientation[strcspn(inputOrientation, "\n")] = '\0'; // Remove newline

        int orientation = getOrientation(inputOrientation); // 0 for horizontal, 1 for vertical

        if (orientation == -1) { // Validate orientation
            i--;
            continue;
        }

        // Place the ship logic can be added here
    }

    return 0;
}