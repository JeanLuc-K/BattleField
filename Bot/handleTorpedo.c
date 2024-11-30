#include "../headerFile.h"
#define MAX_COORD_SIZE 10

// Define the maxCoord structure
struct maxCoord {
    int isRow;             // 1 for rows, 0 for columns
    int coords[MAX_COORD_SIZE];    // Coordinates (row or column index)
    int sums[MAX_COORD_SIZE];      // Sum of values in the row or column
    int minusCounters[MAX_COORD_SIZE];  // Counter for negative values (such as -1)
};

// Function to print the contents of the maxCoord structure
void printCoord(struct maxCoord *coord) {
    if (coord == NULL) {
        printf("Null structure passed.\n");
        return;
    }

    printf("Is Row: %d\n", coord->isRow);  // Print if it's a row (1) or column (0)

    // Print the coordinates, sums, and -1 counters
    printf("Coordinates (Index): ");
    for (int i = 0; i < MAX_COORD_SIZE; i++) {
        if (coord->coords[i] != -1) {  // Assume -1 means unused position
            printf("%d ", coord->coords[i]);
        }
    }
    printf("\n");

    printf("Sums: ");
    for (int i = 0; i < MAX_COORD_SIZE; i++) {
        if (coord->sums[i] != -1) {  // Only print used sums
            printf("%d ", coord->sums[i]);
        }
    }
    printf("\n");

    printf("Minus One Counters: ");
    for (int i = 0; i < MAX_COORD_SIZE; i++) {
        if (coord->minusCounters[i] != -1) {  // Only print used counters
            printf("%d ", coord->minusCounters[i]);
        }
    }
    printf("\n");
}

// Function to sum the rows and track negative numbers
void sumRows(PLAYER* currentPlayer, struct maxCoord *rows) {
    for (int i = 0; i < GRID_SIZE; i++) {
        rows->coords[i] = i;
        rows->sums[i] = 0;     // Initialize sum to 0
        rows->minusCounters[i] = 0;  // Initialize negative counter to 0

        for (int j = 0; j < GRID_SIZE; j++) {
            if (currentPlayer->probGrid[i][j] < 0) {
                rows->minusCounters[i]++;  // Count negative values
            } else {
                rows->sums[i] += currentPlayer->probGrid[i][j];  // Add to sum
            }
        }
    }
}

// Function to sum the columns and track negative numbers
void sumCols(PLAYER* currentPlayer, struct maxCoord *cols) {
    for (int i = 0; i < GRID_SIZE; i++) {
        cols->coords[i] = i;
        cols->sums[i] = 0;     // Initialize sum to 0
        cols->minusCounters[i] = 0;  // Initialize negative counter to 0

        for (int j = 0; j < GRID_SIZE; j++) {
            if (currentPlayer->probGrid[j][i] < 0) {
                cols->minusCounters[i]++;  // Count negative values
            } else {
                cols->sums[i] += currentPlayer->probGrid[j][i];  // Add to sum
            }
        }
    }
}

// Function to compare two `maxCoord` entries by minusCounters and then by sum
int compareCoord(const void *a, const void *b) {
    struct maxCoord *coordA = (struct maxCoord *)a;
    struct maxCoord *coordB = (struct maxCoord *)b;

    // Compare by the count of negative values first (descending order)
    if (coordA->minusCounters[0] != coordB->minusCounters[0]) {
        return coordB->minusCounters[0] - coordA->minusCounters[0]; 
    }
    // If the negative counters are the same, compare by sum (descending order)
    return coordB->sums[0] - coordA->sums[0]; 
}
// Function to sort the rows/columns manually based on minusCounters and then by sum
void sortMaxCoord(struct maxCoord *coord) {
    for (int i = 0; i < GRID_SIZE - 1; i++) {
        for (int j = i + 1; j < GRID_SIZE; j++) {
            // First, compare by minusCounters (descending)
            if (coord->minusCounters[i] < coord->minusCounters[j]) {
                // Swap coords, sums, and minusCounters
                int tempCoord = coord->coords[i];
                int tempSum = coord->sums[i];
                int tempMinus = coord->minusCounters[i];

                coord->coords[i] = coord->coords[j];
                coord->sums[i] = coord->sums[j];
                coord->minusCounters[i] = coord->minusCounters[j];

                coord->coords[j] = tempCoord;
                coord->sums[j] = tempSum;
                coord->minusCounters[j] = tempMinus;
            }
            // If the minusCounters are the same, compare by sum (ascending)
            else if (coord->minusCounters[i] == coord->minusCounters[j]) {
                if (coord->sums[i] > coord->sums[j]) {
                    // Swap coords, sums, and minusCounters
                    int tempCoord = coord->coords[i];
                    int tempSum = coord->sums[i];
                    int tempMinus = coord->minusCounters[i];

                    coord->coords[i] = coord->coords[j];
                    coord->sums[i] = coord->sums[j];
                    coord->minusCounters[i] = coord->minusCounters[j];

                    coord->coords[j] = tempCoord;
                    coord->sums[j] = tempSum;
                    coord->minusCounters[j] = tempMinus;
                }
            }
        }
    }
}

// Function to handle the Torpedo phase
void playTorpedoRow(PLAYER* currentPlayer, PLAYER* opposingPlayer, struct maxCoord* rows, INPUT* input) {
    input->row = rows->coords[0];  // Select the row based on the sorted row coordinates
    input->column = -1;  // No column is selected
    printf("The bot plays torpedo at row %d\n", input->row);
    torpedo(currentPlayer, opposingPlayer, input);  // Call the torpedo function
}

// Function to play torpedo based on column selection
void playTorpedoColumn(PLAYER* currentPlayer, PLAYER* opposingPlayer, struct maxCoord* cols, INPUT* input) {
    input->row = -1;  // No row is selected
    input->column = cols->coords[0];  // Select the column based on the sorted column coordinates
    printf("The bot plays torpedo at column %c\n", cols->coords[0] + 97);  // Convert to 'a'-'j' range for column names
    torpedo(currentPlayer, opposingPlayer, input);  // Call the torpedo function
}


void decideTorpedoAction(PLAYER* currentPlayer, PLAYER* opposingPlayer, struct maxCoord* rows, struct maxCoord* cols, INPUT* input) {
    // If the row has more negative counters than the column
    if (rows->minusCounters[GRID_SIZE-1] > cols->minusCounters[GRID_SIZE-1]) {
        playTorpedoRow(currentPlayer, opposingPlayer, rows, input);
    }
    // If the column has more negative counters than the row
    else if (rows->minusCounters[GRID_SIZE-1] < cols->minusCounters[GRID_SIZE-1]) {
        playTorpedoColumn(currentPlayer, opposingPlayer, cols, input);
    }
    // If they are equal, compare sums
    else {
        if (rows->sums[GRID_SIZE-1] > cols->sums[GRID_SIZE-1]) {
            playTorpedoRow(currentPlayer, opposingPlayer, rows, input);
        } else {
            playTorpedoColumn(currentPlayer, opposingPlayer, cols, input);
        }
    }
}


// Function to play torpedo based on row selection

void handleTorpedo(PLAYER* currentPlayer, PLAYER* opposingPlayer) {
    struct maxCoord rows;
    rows.isRow = 1;
    
    struct maxCoord cols;
    cols.isRow = 0;

    // Sum the rows and columns and keep track of -1 
    sumRows(currentPlayer, &rows);
    sumCols(currentPlayer, &cols);

    //sort based on minusCounter then sums
    sortMaxCoord(&rows);
    sortMaxCoord(&cols);

    printCoord(&rows);
    printCoord(&cols);
    

    INPUT input;
    decideTorpedoAction(currentPlayer,opposingPlayer,&rows,&cols,&input);

}

