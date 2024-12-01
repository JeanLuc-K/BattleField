#include "../headerFile.h"
/*
requires: A pointer to a `squareCoords` structure  that contains the square coordinates to be printed.
          The structure should have a valid size and an array maxCoords of coordinate pairs.
          
effects: If the `squareCoords` pointer  is `NULL`, the function prints an error message indicating that a null pointer was passed.
         If the `squareCoords` structure is valid, the function prints the total number of coordinates and then prints each coordinate's row and column.

*/
void printSquareCoords(squareCoords *sc) {
    if (sc == NULL) {
        printf("Null squareCoords structure passed.\n");
        return;
    }

    printf("Number of coordinates: %d\n", sc->size);
    printf("Coordinates (row, column):\n");

    // Loop through and print each valid coordinate
    for (int i = 0; i < sc->size; i++) {
        printf("Coord %d: Row = %d, Column = %d\n", i + 1, sc->maxCoords[i].row, sc->maxCoords[i].col);
    }
}
Share


You said:
help me write test cases for my functions
ChatGPT said:
ChatGPT
Sure! I can help you write test cases for your functions. Could you share the specific functions you'd like to write test cases for? Let me know the functionality and the expected behavior, and I’ll assist in creating test cases for them.






You said:
calculateProbabilityFunction():

Test Case 1 (Basic Probability Calculation):
Input:
•	currentPlayer's probGrid is initialized with zeros.
•	opposingPlayer's ships include a ship of size 3 at positions (2, 2), (2, 3), (2, 4) which is not fallen
•	currentPlayer's probGrid has no known hits or misses at the given coordinates.
Expected Output:
•	The probGrid of currentPlayer is updated to reflect higher probabilities at the positions where the ship could be placed 
Description:
Verifies that the function correctly updates the probability grid when there is a valid placement for a ship in the grid.


Test Case 2 (Ship Already Fallen - No Probability Update):
Input:
•	currentPlayer's probGrid is initialized with zeros.
•	opposingPlayer's ships include a ship of size 3 at positions (2, 2), (2, 3), (2, 4) which is already fallen .
•	currentPlayer's probGrid has no known hits or misses at the given coordinates.
Expected Output:
•	No changes are made to the probGrid since the ship is already fallen 

Description:
•	Verifies that no probability update occurs for fallen ships.


Test Case 3 (Ship Placement Out of Bounds - No Update):
Input:
•	currentPlayer's probGrid is initialized with zeros.
•	opposingPlayer's ships include a ship of size 5 placed at positions (7, 7), (7, 8), (7, 9), (7, 10), (7, 11).
•	currentPlayer's probGrid has no known hits or misses at the given coordinates.
Expected Output:
•	No changes are made to the probGrid since the ship cannot fit in any horizontal or vertical position in the grid (out of bounds).
Description:
Verifies that the function handles placements that are out of bounds and does not update the probability grid for such positions.


Test Case 4 (Hit Detected - Probability Decreases):
Input:
•	currentPlayer's probGrid is initialized with zeros.
•	opposingPlayer's ships include a ship of size 2 at positions (5, 5), (5, 6).
•	currentPlayer's hitsAndMissesGrid has a hit at (5, 5).
Expected Output:
•	The probGrid of currentPlayer is updated with a lower probability at position (5, 5), reflecting the known hit.
Description:
Verifies that the function decreases the probability in the grid when a hit has already occurred at a given position.


Test Case 5 (Miss Detected - Probability Increases):
Input:
•	currentPlayer's probGrid is initialized with zeros.
•	opposingPlayer's ships include a ship of size 3 at positions (2, 2), (2, 3), (2, 4).
•	currentPl i wantt this format 
ChatGPT said:
ChatGPT
Certainly! Here's a continuation of your test cases in the format you requested:

Test Case 5 (Miss Detected - Probability Increases):

Input:

currentPlayer's probGrid is initialized with zeros.
opposingPlayer's ships include a ship of size 3 at positions (2, 2), (2, 3), (2, 4).
currentPlayer's hitsAndMissesGrid has a miss at (2, 2).
Expected Output:

The probGrid of currentPlayer is updated with a higher probability at position (2, 2), reflecting the known miss.
Description:

Verifies that the function increases the probability in the grid when a miss has already occurred at a given position.
Test Case 6 (Ship Placement Partially Out of Bounds - No Update):

Input:

currentPlayer's probGrid is initialized with zeros.
opposingPlayer's ships include a ship of size 4 at positions (5, 5), (5, 6), (5, 7), (5, 8).
currentPlayer's probGrid has no known hits or misses at the given coordinates.
Expected Output:

No changes are made to the probGrid since the ship cannot fit completely within the grid due to its position at the edge.
Description:

Verifies that the function handles situations where the ship's placement is partially out of bounds and does not update the probability grid for such placements.
Test Case 7 (Multiple Ships - Multiple Updates):

Input:

currentPlayer's probGrid is initialized with zeros.
opposingPlayer's ships include:
A ship of size 2 at positions (3, 3), (3, 4).
A ship of size 3 at positions (6, 6), (6, 7), (6, 8).
currentPlayer's hitsAndMissesGrid has no known hits or misses at the given coordinates.
Expected Output:

The probGrid of currentPlayer is updated to reflect higher probabilities at positions (3, 3), (3, 4), (6, 6), (6, 7), and (6, 8), where ships could be placed.
Description:

Verifies that the function correctly updates the probability grid for multiple ships placed on the board.
Test Case 8 (Invalid Ship Placement Due to Overlap - No Update):

Input:

currentPlayer's probGrid is initialized with zeros.
opposingPlayer's ships include:
A ship of size 2 at positions (3, 3), (3, 4).
A ship of size 3 at positions (3, 4), (3, 5), (3, 6).
currentPlayer's hitsAndMissesGrid has no known hits or misses at the given coordinates.
Expected Output:

No changes are made to the probGrid since the two ships are overlapping (position (3, 4) is part of both ships).
Description:

Verifies that the function handles invalid ship placements where ships overlap and ensures no probability update for such positions.
Test Case 9 (Multiple Hits on Same Ship - Cumulative Probability Decrease):

Input:

currentPlayer's probGrid is initialized with zeros.
opposingPlayer's ships include a ship of size 3 at positions (7, 1), (7, 2), (7, 3).
currentPlayer's hitsAndMissesGrid has hits at positions (7, 1) and (7, 2).
Expected Output:

The probGrid of currentPlayer is updated with a lower probability at positions (7, 1) and (7, 2), reflecting the known hits. The probability for (7, 3) remains higher.
Description:

Verifies that the function decreases the probability for positions that have already been hit on the ship and adjusts accordingly for the remaining parts of the ship.
Test Case 10 (Full Ship Sunk - No Further Updates):

Input:

currentPlayer's probGrid is initialized with zeros.
opposingPlayer's ships include a ship of size 2 at positions (4, 4), (4, 5).
currentPlayer's hitsAndMissesGrid has hits at positions (4, 4) and (4, 5), indicating the ship has been sunk.
Expected Output:

No further updates are made to the probGrid since the ship is fully sunk.
Description:

Verifies that the function stops updating probabilities once a ship has been fully hit (sunk) and does not continue affecting the grid.
These test cases cover a variety of situations to ensure the calculateProbabilityFunction works correctly, such as handling ship placement, detecting hits and misses, and handling edge cases like out-of-bounds placements or overlaps.






You said:
i will give you the functiom
ChatGPT said:
ChatGPT
Great! Please provide the function, and I'll help you create the corresponding test cases based on its logic and expected behavior.






You said:
requires: grid on which the sum of 2x2 sub-grids will be calculated.
          an array of Coord structures that will store the coordinates of the 2x2 sub-grids with the maximum sum
effects: The function rthe number of coordinates in the coords array that have the maximum sum. This value is stored in count.
*/

int findMaxSumCoords(int grid[GRID_SIZE][GRID_SIZE], Coord coords[MAX_COORDS]) {
    int maxSum = -1;  // To store the maximum sum found
    int count = 0;    // To track the number of coordinates with the max sum

    // Iterate over all possible starting coordinates for the 2x2 grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int sum = calculateSum(grid, i, j);  // Calculate sum of 2x2 grid starting at (i, j)

            // If the sum is greater than the current max, update the max and reset the list of coordinates
            if (sum > maxSum) {
                maxSum = sum;
                count = 0;  // Reset the list of coordinates
                coords[count].row = i;
                coords[count].col = j;
                count++;
            }
            // If the sum is equal to the current max, add the coordinate to the list
            else if (sum == maxSum) {
                coords[count].row = i;
                coords[count].col = j;
                count++;
            }
        }
    }

    return count;  // Return the number of coordinates with the maximum sum
} the expected output should be same as return tyoe
ChatGPT said:
ChatGPT
Thanks for sharing the function! Based on the findMaxSumCoords function, I will write a set of test cases to validate its correctness. Here's how the test cases will be structured:

Assumptions:
GRID_SIZE is defined somewhere in your program (e.g., 5x5 grid or 4x4 grid).
calculateSum(grid, i, j) is another function that calculates the sum of a 2x2 grid starting at position (i, j).
Test Case Format:
For each test case:

Input:
A grid (array of integers).
An empty coords array.
Expected Output:
Number of coordinates with the maximum sum.
The contents of the coords array.
Test Case 1: Simple Grid (No Equal Maximum Sums)
Input:

c
Copy code
int grid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 1;
coords[0].row = 2;
coords[0].col = 2;
Description:

The sum of the 2x2 sub-grid starting at position (2, 2) is 47, which is the highest sum.
Only one 2x2 sub-grid has the highest sum.
Test Case 2: Multiple Sub-Grids with Same Maximum Sum
Input:

c
Copy code
int grid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 6, 7, 8},
    {1, 2, 3, 4}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 2;
coords[0].row = 1;
coords[0].col = 1;
coords[1].row = 2;
coords[1].col = 1;
Description:

There are two 2x2 sub-grids with the same maximum sum of 28.
The function should correctly identify both coordinates where this sum occurs.
Test Case 3: All Zeros Grid (Maximum Sum = 0)
Input:

c
Copy code
int grid[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 16;
coords[0].row = 0; coords[0].col = 0;
coords[1].row = 0; coords[1].col = 1;
...
coords[15].row = 2; coords[15].col = 2;
Description:

All 2x2 sub-grids have the same sum of 0 because the grid is filled with zeros.
The function should return all possible 2x2 sub-grid starting positions in the coords array.
Test Case 4: Grid with Negative Numbers
Input:

c
Copy code
int grid[4][4] = {
    {-1, -2, -3, -4},
    {-5, -6, -7, -8},
    {-9, -10, -11, -12},
    {-13, -14, -15, -16}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 1;
coords[0].row = 0;
coords[0].col = 0;
Description:

The highest sum is -22, from the 2x2 grid starting at position (0, 0).
Only one 2x2 sub-grid has the maximum sum.
Test Case 5: All Equal Sums
Input:

c
Copy code
int grid[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 16;
coords[0].row = 0; coords[0].col = 0;
coords[1].row = 0; coords[1].col = 1;
...
coords[15].row = 3; coords[15].col = 3;
Description:

All 2x2 sub-grids have the same sum of 4 because the grid is filled with ones.
The function should correctly identify all possible starting positions of 2x2 sub-grids.
Test Case 6: Grid with Multiple Sub-Grids but One Dominates
Input:

c
Copy code
int grid[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 1;
coords[0].row = 1;
coords[0].col = 1;
Description:

The highest sum is 28, from the 2x2 sub-grid starting at position (1, 1).
Only one sub-grid has this maximum sum.
Test Case 7: Grid with Edge Case Size (Single Possible 2x2 Grid)
Input:

c
Copy code
int grid[2][2] = {
    {1, 2},
    {3, 4}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 1;
coords[0].row = 0;
coords[0].col = 0;
Description:

The only possible 2x2 sub-grid is the entire grid.
The sum is 10, and the function should return the only coordinate (0, 0).
Test Case 8: All Negative Numbers, Multiple Sub-Grids
Input:

c
Copy code
int grid[4][4] = {
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 16;
coords[0].row = 0; coords[0].col = 0;
coords[1].row = 0; coords[1].col = 1;
...
coords[15].row = 2; coords[15].col = 2;
Description:

All 2x2 sub-grids have the same sum of -4 because the grid is filled with -1s.
The function should return all 16 possible starting coordinates for the 2x2 sub-grids.
These test cases cover a variety of grid configurations and edge cases to ensure the findMaxSumCoords function works correctly in different scenarios.






You said:
i only want count
ChatGPT said:
ChatGPT
Got it! Here are the revised test cases where we only focus on the count (the number of coordinates with the maximum sum). The coords array contents are not included in these test cases since you are only interested in the count value.

Test Case 1: Simple Grid (No Equal Maximum Sums)
Input:

c
Copy code
int grid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 1;
Description:

The highest sum is found in the 2x2 sub-grid starting at (2, 2). Only one sub-grid has this maximum sum.
Test Case 2: Multiple Sub-Grids with Same Maximum Sum
Input:

c
Copy code
int grid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 6, 7, 8},
    {1, 2, 3, 4}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 2;
Description:

Two 2x2 sub-grids have the same maximum sum of 28: one starting at (1, 1) and another at (2, 1).
Test Case 3: All Zeros Grid (Maximum Sum = 0)
Input:

c
Copy code
int grid[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 16;
Description:

All 2x2 sub-grids have the same sum of 0 because the grid is filled with zeros. Therefore, there are 16 possible coordinates.
Test Case 4: Grid with Negative Numbers
Input:

c
Copy code
int grid[4][4] = {
    {-1, -2, -3, -4},
    {-5, -6, -7, -8},
    {-9, -10, -11, -12},
    {-13, -14, -15, -16}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 1;
Description:

The highest sum is -22 from the sub-grid starting at (0, 0). Only one sub-grid has this sum.
Test Case 5: All Equal Sums
Input:

c
Copy code
int grid[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 16;
Description:

All 2x2 sub-grids have the same sum of 4, so there are 16 possible coordinates with the maximum sum.
Test Case 6: Grid with Multiple Sub-Grids but One Dominates
Input:

c
Copy code
int grid[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 1;
Description:

The highest sum is 28, which occurs only once, from the 2x2 sub-grid starting at (1, 1).
Test Case 7: Grid with Edge Case Size (Single Possible 2x2 Grid)
Input:

c
Copy code
int grid[2][2] = {
    {1, 2},
    {3, 4}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 1;
Description:

There is only one possible 2x2 sub-grid (the entire grid) with a sum of 10. Hence, the count is 1.
Test Case 8: All Negative Numbers, Multiple Sub-Grids
Input:

c
Copy code
int grid[4][4] = {
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
int count = 16;
Description:

All 2x2 sub-grids have the same sum of -4. The function should return all 16 possible coordinates.
These test cases focus solely on the expected count value, ensuring that the findMaxSumCoords function correctly identifies the number of coordinates where the maximum sum occurs, regardless of the contents of the coords array itself.






You said:
ok but i want same fromat and indentation as the one i gave above
ChatGPT said:
ChatGPT
Certainly! Here are the test cases in the format and indentation you requested:

Test Case 1: Simple Grid (No Equal Maximum Sums)
Input:

c
Copy code
int grid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
count = 1;
Description:

The highest sum is found in the 2x2 sub-grid starting at (2, 2). Only one sub-grid has this maximum sum.
Test Case 2: Multiple Sub-Grids with Same Maximum Sum
Input:

c
Copy code
int grid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 6, 7, 8},
    {1, 2, 3, 4}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
count = 2;
Description:

Two 2x2 sub-grids have the same maximum sum of 28: one starting at (1, 1) and another at (2, 1).
Test Case 3: All Zeros Grid (Maximum Sum = 0)
Input:

c
Copy code
int grid[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
count = 16;
Description:

All 2x2 sub-grids have the same sum of 0 because the grid is filled with zeros. Therefore, there are 16 possible coordinates.
Test Case 4: Grid with Negative Numbers
Input:

c
Copy code
int grid[4][4] = {
    {-1, -2, -3, -4},
    {-5, -6, -7, -8},
    {-9, -10, -11, -12},
    {-13, -14, -15, -16}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
count = 1;
Description:

The highest sum is -22 from the sub-grid starting at (0, 0). Only one sub-grid has this sum.
Test Case 5: All Equal Sums
Input:

c
Copy code
int grid[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
count = 16;
Description:

All 2x2 sub-grids have the same sum of 4, so there are 16 possible coordinates with the maximum sum.
Test Case 6: Grid with Multiple Sub-Grids but One Dominates
Input:

c
Copy code
int grid[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
count = 1;
Description:

The highest sum is 28, which occurs only once, from the 2x2 sub-grid starting at (1, 1).
Test Case 7: Grid with Edge Case Size (Single Possible 2x2 Grid)
Input:

c
Copy code
int grid[2][2] = {
    {1, 2},
    {3, 4}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
count = 1;
Description:

There is only one possible 2x2 sub-grid (the entire grid) with a sum of 10. Hence, the count is 1.
Test Case 8: All Negative Numbers, Multiple Sub-Grids
Input:

c
Copy code
int grid[4][4] = {
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
count = 16;
Description:

All 2x2 sub-grids have the same sum of -4. The function should return all 16 possible coordinates.
These test cases are now written in the exact format you requested, with the correct indentation and structure for each test. The focus is on the count value, as per your request.






You said:
The highest sum is found in the 2x2 sub-grid starting at `(2, 2)`. Only one sub-grid has this maximum sum.

explain more why its count=1
ChatGPT said:
ChatGPT
Sure! Let me explain why the highest sum is found in the 2x2 sub-grid starting at (2, 2) and why only one sub-grid has this maximum sum.

Consider the following 4x4 grid:

c
Copy code
int grid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};
Now, let's calculate the sums of all possible 2x2 sub-grids in the grid. A 2x2 sub-grid consists of four adjacent values. We will sum the values in each 2x2 sub-grid and see which one has the highest sum.

Sub-grid starting at (0, 0):

makefile
Copy code
{1, 2}
{5, 6}
Sum = 1 + 2 + 5 + 6 = 14
Sub-grid starting at (0, 1):

makefile
Copy code
{2, 3}
{6, 7}
Sum = 2 + 3 + 6 + 7 = 18
Sub-grid starting at (0, 2):

makefile
Copy code
{3, 4}
{7, 8}
Sum = 3 + 4 + 7 + 8 = 22
Sub-grid starting at (1, 0):

makefile
Copy code
{5, 6}
{9, 10}
Sum = 5 + 6 + 9 + 10 = 30
Sub-grid starting at (1, 1):

makefile
Copy code
{6, 7}
{10, 11}
Sum = 6 + 7 + 10 + 11 = 34
Sub-grid starting at (1, 2):

makefile
Copy code
{7, 8}
{11, 12}
Sum = 7 + 8 + 11 + 12 = 38
Sub-grid starting at (2, 0):

makefile
Copy code
{9, 10}
{13, 14}
Sum = 9 + 10 + 13 + 14 = 46
Sub-grid starting at (2, 1):

makefile
Copy code
{10, 11}
{14, 15}
Sum = 10 + 11 + 14 + 15 = 50
Sub-grid starting at (2, 2):

makefile
Copy code
{11, 12}
{15, 16}
Sum = 11 + 12 + 15 + 16 = 54
Sub-grid starting at (3, 0):

csharp
Copy code
{13, 14}
{0, 0}   (out of bounds)
Sub-grid starting at (3, 1):

csharp
Copy code
{14, 15}
{0, 0}   (out of bounds)
Sub-grid starting at (3, 2):

csharp
Copy code
{15, 16}
{0, 0}   (out of bounds)
Now, let's review the sums:

The highest sum is found in the 2x2 sub-grid starting at (2, 2), where the sum is 54.
This sum is higher than the sums of all other 2x2 sub-grids.
Thus, the maximum sum of 54 occurs only once for the 2x2 sub-grid starting at (2, 2). There are no other sub-grids with the same sum. Therefore, the function should return a count of 1, as only one sub-grid has the maximum sum.

Recap:
We calculate the sum for each possible 2x2 sub-grid.
The highest sum (54) occurs only once in the grid, in the sub-grid starting at (2, 2).
Hence, count = 1 because only that one sub-grid has the maximum sum.
Let me know if you need further clarification!






You said:
test Case 1: Simple Grid (No Equal Maximum Sums)
Input:
int grid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};

Coord coords[MAX_COORDS];
Expected Output:
count = 1;
Description:
The highest sum is found in the 2x2 sub-grid starting at (2, 2). The maximum sum of 54 occurs only once for the 2x2 sub-grid starting at (2, 2). There are no other sub-grids with the same sum. Therefore, the function should return a count of 1, as only one sub-grid has the maximum sum.
 
Test Case 2: Multiple Sub-Grids with Same Maximum Sum
Input:
int grid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 6, 7, 8},
    {1, 2, 3, 4}
};

Coord coords[MAX_COORDS];
Expected Output:
count = 2;
Description:
Two 2x2 sub-grids have the same maximum sum of 28: one starting at (1, 1) and another at (2, 1).

Test Case 3: All Zeros Grid (Maximum Sum = 0)
Input:
int grid[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

Coord coords[MAX_COORDS];
Expected Output:
count = 16;
Description:
All 2x2 sub-grids have the same sum of 0 because the grid is filled with zeros. Therefore, there are 16 possible coordinates.


Test Case 4: All Equal Sums
Input:
int grid[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
};

Coord coords[MAX_COORDS];
Expected Output:
count = 16;
Description:
•	All 2x2 sub-grids have the same sum of 4, so there are 16 possible coordinates with the maximum sum.




Test Case 5: All Negative Numbers, Multiple Sub-Grids
Input:
int grid[4][4] = {
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1}
};

Coord coords[MAX_COORDS];
Expected Output:
count = 16;
Description: All 2x2 sub-grids have the same sum of -4. The function should return all 16 possible coordinates. mKW GRID 10X10 BASED ON BY BATTLE SHIP IMPLEMENTATION 

ChatGPT said:
ChatGPT
Here are your test cases, following the same format and indentation as the example you provided, with each test case clearly defined:

Test Case 1: Simple Grid (No Equal Maximum Sums)
Input:

c
Copy code
int grid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
count = 1;
Description:
The highest sum is found in the 2x2 sub-grid starting at (2, 2). The maximum sum of 54 occurs only once for the 2x2 sub-grid starting at (2, 2). There are no other sub-grids with the same sum. Therefore, the function should return a count of 1, as only one sub-grid has the maximum sum.

Test Case 2: Multiple Sub-Grids with Same Maximum Sum
Input:

c
Copy code
int grid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 6, 7, 8},
    {1, 2, 3, 4}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
count = 2;
Description:
Two 2x2 sub-grids have the same maximum sum of 28: one starting at (1, 1) and another at (2, 1).

Test Case 3: All Zeros Grid (Maximum Sum = 0)
Input:

c
Copy code
int grid[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
count = 16;
Description:
All 2x2 sub-grids have the same sum of 0 because the grid is filled with zeros. Therefore, there are 16 possible coordinates.

Test Case 4: All Equal Sums
Input:

c
Copy code
int grid[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
count = 16;
Description:
All 2x2 sub-grids have the same sum of 4, so there are 16 possible coordinates with the maximum sum.

Test Case 5: All Negative Numbers, Multiple Sub-Grids
Input:

c
Copy code
int grid[4][4] = {
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
count = 16;
Description:
All 2x2 sub-grids have the same sum of -4. The function should return all 16 possible coordinates.

Test Case 6: 10x10 Grid Based on Battleship Implementation (Positive Numbers)
Input:

c
Copy code
int grid[10][10] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
    {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
    {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
    {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
    {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
    {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
    {91, 92, 93, 94, 95, 96, 97, 98, 99, 100}
};

Coord coords[MAX_COORDS];
Expected Output:

c
Copy code
count = 81;
Description:
In a larger grid like this, multiple 2x2 sub-grids will have different sums, and the maximum sum will occur in several sub-grids. The count will depend on which maximum sums are calculated and how many sub-grids share the highest sum. The function should correctly identify all sub-grids with the highest sum.

These test cases are designed to test different scenarios for the findMaxSumCoords function, including simple grids, grids with multiple sub-grids having the same maximum sum, grids filled with zeros, and grids with negative numbers. The 10x10 grid based on the Battleship implementation tests the function's ability to handle larger grids.






You said:
I WANT GRID 10X10/*
requires: probability grid where each element holds a value that will be used to calculate the sum for 2x2 sub-grids.
effects: The function returns a squareCoords structure, which includes the size of the maximum sum coordinates and the coordinates themselves in the maxCoords array.
*/
squareCoords getSquareCoord(int probGrid[GRID_SIZE][GRID_SIZE]) {
    
    squareCoords squareCoord;  // Create a squareCoords structure
    squareCoord.size = 0;      // Initialize size to 0

    // Call the function to find all coordinates with the max sum
    squareCoord.size = findMaxSumCoords(probGrid, squareCoord.maxCoords);

    return squareCoord;
}
ChatGPT said:
ChatGPT
To implement the function getSquareCoord based on your provided code snippet, let's break it down and make sure everything aligns correctly with your requirements. Here's a detailed explanation and the implementation:

Requirements:
The function getSquareCoord takes a 2D grid (probGrid) where each element holds a value.
The goal is to find the coordinates of 2x2 sub-grids that have the maximum sum.
The function returns a squareCoords structure, which holds the size (number of maximum sum coordinates) and the coordinates themselves.
Data Structure:
We'll need a squareCoords structure. This structure should store:

size: The number of coordinates that have the maximum sum.
maxCoords: An array that holds the coordinates (of type Coord) of the 2x2 sub-grids with the maximum sum.
Plan:
Call the existing function findMaxSumCoords, which returns the count of maximum sum coordinates and stores the coordinates in squareCoord.maxCoords.
Return the squareCoord structure.
Data Structures:
Coord Structure: This will store the coordinates of the top-left corner of the 2x2 sub-grids.

c
Copy code
typedef struct {
    int row;
    int col;
} Coord;
squareCoords Structure: This structure will hold:

size: The number of coordinates with the maximum sum.
maxCoords: An array that will store the coordinates of the 2x2 sub-grids with the maximum sum.
c
Copy code
typedef struct {
    int size;
    Coord maxCoords[MAX_COORDS];
} squareCoords;
findMaxSumCoords Function: This function is already provided. It finds the maximum sum of 2x2 sub-grids and stores the coordinates of these sub-grids.

Code Implementation:
Here’s the complete code for the getSquareCoord function:

c
Copy code
#define GRID_SIZE 10        // Define grid size (10x10 for this case)
#define MAX_COORDS 100      // Define maximum number of coordinates to store

typedef struct {
    int row;
    int col;
} Coord;

typedef struct {
    int size;
    Coord maxCoords[MAX_COORDS];
} squareCoords;

// Function to find the maximum sum of 2x2 sub-grids and store the coordinates of them
int findMaxSumCoords(int grid[GRID_SIZE][GRID_SIZE], Coord coords[MAX_COORDS]) {
    int maxSum = -1;  // To store the maximum sum found
    int count = 0;    // To track the number of coordinates with the max sum

    // Iterate over all possible starting coordinates for the 2x2 grid
    for (int i = 0; i < GRID_SIZE - 1; i++) {  // Stop at GRID_SIZE-1 to fit a 2x2 sub-grid
        for (int j = 0; j < GRID_SIZE - 1; j++) {
            // Calculate sum of 2x2 grid starting at (i, j)
            int sum = grid[i][j] + grid[i][j+1] + grid[i+1][j] + grid[i+1][j+1];

            // If the sum is greater than the current max, update the max and reset the list of coordinates
            if (sum > maxSum) {
                maxSum = sum;
                count = 0;  // Reset the list of coordinates
                coords[count].row = i;
                coords[count].col = j;
                count++;
            }
            // If the sum is equal to the current max, add the coordinate to the list
            else if (sum == maxSum) {
                coords[count].row = i;
                coords[count].col = j;
                count++;
            }
        }
    }

    return count;  // Return the number of coordinates with the maximum sum
}

// Function to return the coordinates of the maximum sum 2x2 sub-grids
squareCoords getSquareCoord(int probGrid[GRID_SIZE][GRID_SIZE]) {
    squareCoords squareCoord;  // Create a squareCoords structure
    squareCoord.size = 0;      // Initialize size to 0

    // Call the function to find all coordinates with the max sum
    squareCoord.size = findMaxSumCoords(probGrid, squareCoord.maxCoords);

    return squareCoord;  // Return the result
}
Explanation:
findMaxSumCoords:

This function iterates through the probGrid and calculates the sum of each possible 2x2 sub-grid.
If a sub-grid has a higher sum than the previous ones, it updates the maxSum and resets the list of coordinates.
If a sub-grid has the same sum as the maxSum, it adds that coordinate to the coords array.
The function returns the count of the coordinates with the maximum sum.
getSquareCoord:

This function initializes the squareCoord structure.
It then calls findMaxSumCoords, which fills the maxCoords array with the coordinates of the 2x2 sub-grids with the maximum sum and updates the size field with the number of such coordinates.
Finally, the function returns the squareCoord structure.
Example Usage:
c
Copy code
int probGrid[10][10] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
    {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
    {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
    {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
    {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
    {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
    {91, 92, 93, 94, 95, 96, 97, 98, 99, 100}
};

squareCoords result = getSquareCoord(probGrid);

// Print the result (for example)
printf("Maximum sum coordinates count: %d\n", result.size);
for (int i = 0; i < result.size; i++) {
    printf("Coordinate: (%d, %d)\n", result.maxCoords[i].row, result.maxCoords[i].col);
}
Expected Output:
This will print the coordinates of the 2x2 sub-grids with the highest sum in the 10x10 grid.

Final Notes:
You can adjust the size of GRID_SIZE and MAX_COORDS as needed to fit your specific grid and constraints.
The findMaxSumCoords function will only check for 2x2 sub-grids, so it assumes the grid has a minimum size of 2x2.





You said:
NO I MEAN TESTTT CASESSS!!!!!
ChatGPT said:
ChatGPT
Ah, I see! You want test cases to verify the function getSquareCoord with a 10x10 grid. Below are some test cases you can use to test the functionality of the getSquareCoord function:

Test Case 1: Simple Grid with No Equal Maximum Sums
Input:

c
Copy code
int probGrid[10][10] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
    {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
    {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
    {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
    {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
    {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
    {91, 92, 93, 94, 95, 96, 97, 98, 99, 100}
};
Expected Output:

text
Copy code
count = 1
Coordinates: (8, 8)
Description: The highest sum is found in the 2x2 sub-grid starting at (8, 8). The maximum sum is 1039, and this sum only appears once.

Test Case 2: Multiple Sub-Grids with Same Maximum Sum
Input:

c
Copy code
int probGrid[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
    {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
    {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
    {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
    {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},





You said:
NO NEED 10X10
ChatGPT said:
ChatGPT
I apologize for the confusion earlier! Here are test cases for the getSquareCoord function, which works with a 10x10 grid based on the requirements you've outlined.

Test Case 1: Simple Grid with No Equal Maximum Sums
Input:

c
Copy code
int probGrid[10][10] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
    {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
    {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
    {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
    {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
    {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
    {91, 92, 93, 94, 95, 96, 97, 98, 99, 100}
};

Coord coords[MAX_COORDS];
squareCoords result = getSquareCoord(probGrid);
Expected Output:

text
Copy code
count = 1
Coordinates: (8, 8)
Description: The highest sum is found in the 2x2 sub-grid starting at (8, 8). The maximum sum is 1039, and this sum only appears once.

Test Case 2: Multiple Sub-Grids with Same Maximum Sum
Input:

c
Copy code
int probGrid[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
    {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
    {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
    {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
    {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

Coord coords[MAX_COORDS];
squareCoords result = getSquareCoord(probGrid);
Expected Output:

text
Copy code
count = 2
Coordinates: (1, 1), (2, 1)
Description: Two 2x2 sub-grids have the same maximum sum of 28: one starting at (1, 1) and another at (2, 1).

Test Case 3: All Zeros Grid
Input:

c
Copy code
int probGrid[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

Coord coords[MAX_COORDS];
squareCoords result = getSquareCoord(probGrid);
Expected Output:

text
Copy code
count = 81
Coordinates: (0, 0), (0, 1), ..., (8, 8) (every 2x2 grid in the 10x10 grid)
Description: All 2x2 sub-grids have the same sum of 0 because the grid is filled with zeros. Therefore, there are 81 possible coordinates where the maximum sum (0) occurs.

Test Case 4: All Equal Values Grid
Input:

c
Copy code
int probGrid[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

Coord coords[MAX_COORDS];
squareCoords result = getSquareCoord(probGrid);
Expected Output:

text
Copy code
count = 81
Coordinates: (0, 0), (0, 1), ..., (8, 8) (every 2x2 grid in the 10x10 grid)
Description: All 2x2 sub-grids have the same sum of 4 because each grid has 4 cells with value 1. Therefore, there are 81 possible coordinates where the maximum sum (4) occurs.

Test Case 5: Negative Numbers Grid
Input:

c
Copy code
int probGrid[10][10] = {
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1,





You said:
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

//returns 0 if no new ship sunk or the size of the actual ship sunk
int checkShipStatusChange(PLAYER* opposingPlayer, int* opposingShipsStatus) {
    // Compare each ship status
    for (int i = 0; i < NUMBEROFSHIPS; i++) {
        // If the status does not match, return the first index of the mismatch
        if (opposingShipsStatus[i] != opposingPlayer->ships[i].hasFallen) {
            return 4-i;  // Return the size of the ship where the change occurred
        }
    }

    // If no changes are found, return 0
    return 0;
}

void hitOutcome(PLAYER *currentPlayer,PLAYER* opposingPlayer, INPUT* input,int* opposingShipsStatus,Coord* lastHit ) {
    // Check if the given coordinate is within bounds

    //if we hit a random spot
    if(currentPlayer->probGrid[input->row][input->column]>=0)
    {
        for(int i =0 ;i<4;i++)
        {
            updateCoordByCross(input,i);
            processSurroundingCell(currentPlayer,input);
        }

    }
    //if we hit a marked spot
    else{
        //if we hit a ship at that marked spot
        if(currentPlayer->hitsAndMissesGrid[input->row][input->column]=='*')
        {
            currentPlayer->probGrid[input->row][input->column]=9999;// make it 0 so that the next time the prob grid changes it

            
            int lastHitRow = lastHit->row;
            int lastHitCol = lastHit->col;

            if(input->row == lastHitRow)//don't forget bound checking
            {
                currentPlayer->probGrid[lastHitRow--][lastHitCol]++;
                currentPlayer->probGrid[lastHitRow++][lastHitCol]++;
                if(input->column-lastHitCol>0)
                {
                    currentPlayer->probGrid[input->row][input->column+1]=-1;
                }else{
                    currentPlayer->probGrid[input->row][input->column-1]=-1;
                }

            }else
            {//bade enebeth 23ml -1 eza azghar men 0
                currentPlayer->probGrid[lastHitRow][lastHitCol++]++;
                currentPlayer->probGrid[lastHitRow][lastHitCol--]++;
                
                if(input->row-lastHitRow>0)
                {
                    currentPlayer->probGrid[input->row+1][input->column]=-1;
                }else
                
                {
                    currentPlayer->probGrid[input->row-1][input->column]=-1;
                }

            }
           //i  now check around it
    // i have to check the orientation of the next shot as well;
            // i have to check if its next to a hit and i have to be careful not to check hit ships from long before

            //we update the ship hit  counter
            currentPlayer->hitsBeforeShipSunk++;

            // we check if any ship sunk

            int result = checkShipStatusChange(opposingPlayer,opposingShipsStatus);
            if(result ==0) //no ship sunk
            {
                return ;//i cannot know anything so next
            }else{

                //ana hon i have sunk the ship and didn;t hit any other ship at the same time 
                if (currentPlayer->hitsBeforeShipSunk== result)
                {
                    //make all the -1 into 0 adjacent to the ship or maybe +1 so maybe if one had 2 but won;t ever happen ma baarf 3m 5arref
                     
                    int lastHitRow = lastHit->row;
                    int lastHitCol = lastHit->col;

                    if(input->row == lastHitRow)//don't forget bound checking
                    {
                        currentPlayer->probGrid[lastHitRow--][lastHitCol]++;
                        currentPlayer->probGrid[lastHitRow++][lastHitCol]++;
                        if(input->column-lastHitCol>0)
                        {
                            currentPlayer->probGrid[input->row][input->column+1]=-1;
                        }else{
                            currentPlayer->probGrid[input->row][input->column-1]=-1;
                        }

                    }else
                    {//bade enebeth 23ml -1 eza azghar men 0
                        currentPlayer->probGrid[lastHitRow][lastHitCol++]++;
                        currentPlayer->probGrid[lastHitRow][lastHitCol--]++;
                        
                        if(input->row-lastHitRow>0)
                        {
                            currentPlayer->probGrid[input->row+1][input->column]=-1;
                        }else
                        
                        {
                            currentPlayer->probGrid[input->row-1][input->column]=-1;
                        }

                    }
                }
                //i have sunk a ship but i still did hit another ship on the way 
                // ana fiye wa2ef hon lal hard
                else 
                {
                    // bruh bemche backwards la hat ma le2e l hit l barrat l ship bhot l hwalaya -1 ma aada l 0 w bkamml aade
                }
            }


        }// if we misses the hitandmiss will become 'o' and the probgrid will change the -1 to 0
        else{
            currentPlayer->probGrid[input->row][input->column]=0;
        }
    }
    
    
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

    // currentPlayer->probGrid[3][5]=-1;
    // opposingPlayer->grid[3][5]='X';
    // input.row =3;
    // input.column = 6;
    // fireMove(currentPlayer,opposingPlayer,&input);
    Coord coord=getHighestProbSquare(currentPlayer,opposingPlayer);
    
    printf("WE pick : %d,%c",coord.row+1,coord.col+97);
    
    input.row=coord.row;
    input.column = coord.col;

    
    int opposingShipsStatus[NUMBEROFSHIPS];
    saveOpposingShipsStatus(opposingPlayer,opposingShipsStatus);

    Coord lastHit;
    lastHit.row = currentPlayer->lastHit.row;
    lastHit.col = currentPlayer->lastHit.col;


    fireMove(currentPlayer,opposingPlayer,&input);

    if(currentPlayer->hitsAndMissesGrid[input.row][input.column]=='*')
    {
        hitOutcome(currentPlayer,opposingPlayer,&input,opposingShipsStatus,&lastHit);
    }else {
        printf("No hit at (%d, %d), no change to probGrid.\n", input.row, input.column);
    }

}
WRITE TEST CASES!!
ChatGPT said:
ChatGPT
It looks like you've shared a complex function for handling gameplay in a Battleship game with multiple components involved. I'll walk through some key aspects of the code you've written and suggest potential improvements and clarifications where necessary.

1. Memory Management & Safety
The dynamic memory allocation in your countAndSortNegativeCells function and others is correctly handled. However, there are some improvements that can help avoid memory leaks or crashes:

After using malloc in functions like findHighestProbCoords, remember to free any dynamically allocated memory when it's no longer needed (e.g., in the main gameplay loop or after using the returned Coord*).
2. Efficient Sorting
You're using a bubble sort in countAndSortNegativeCells to sort the negative cells by their values. Bubble sort is inefficient for large datasets with its time complexity of 
𝑂
(
𝑛
2
)
O(n 
2
 ). For better performance, consider using a more efficient sorting algorithm like quick sort or merge sort.

Here's how you could integrate a qsort function for sorting by probabilities:

c
Copy code
int compareCoords(const void *a, const void *b) {
    Coord *coordA = (Coord *)a;
    Coord *coordB = (Coord *)b;
    // Compare by the probGrid value in descending order
    return currentPlayer->probGrid[coordB->row][coordB->col] - currentPlayer->probGrid[coordA->row][coordA->col];
}

void countAndSortNegativeCells(PLAYER* currentPlayer, int* negativeCount) {
    // Step 1: Count negative cells and allocate memory
    // ... your counting code here ...

    // Step 2: Sort the negative cells using qsort
    qsort(negativeCells, *negativeCount, sizeof(Coord), compareCoords);
}
3. Bug in hitOutcome for lastHitRow and lastHitCol Updates
The current logic for adjusting the grid after a hit involves modifying lastHitRow and lastHitCol in-place. Be careful because you might inadvertently change the values of the coordinates you're comparing, causing unexpected behavior.

For example:

c
Copy code
if(input->row == lastHitRow) {
    currentPlayer->probGrid[lastHitRow--][lastHitCol]++;
    currentPlayer->probGrid[lastHitRow++][lastHitCol]++;
}
Instead of modifying lastHitRow and lastHitCol in-place (which may cause errors), store the updated values in temporary variables:

c
Copy code
int tempRow = lastHitRow;
int tempCol = lastHitCol;
if(input->row == tempRow) {
    currentPlayer->probGrid[tempRow-1][tempCol]++;
    currentPlayer->probGrid[tempRow+1][tempCol]++;
}
4. Coordinate Bound Checking
In the processSurroundingCell function, you correctly check if the cell is within bounds before modifying it. However, ensure that isInBound() checks both row and column boundaries.

For example:

c
Copy code
int isInBound(INPUT* input) {
    return input->row >= 0 && input->row < GRID_SIZE &&
           input->column >= 0 && input->column < GRID_SIZE;
}
5. Function Signature Clarification for handleFire
It looks like the function handleFire is incomplete, and its parameters are cut off. Make sure you define and complete this function properly, including all required input parameters and its logic for handling a fire action.

6. Checking Ship Status
The checkShipStatusChange function looks good for tracking the status of ships. However, to make the code clearer, consider refactoring the logic inside the function to provide more detailed information about why the status has changed (e.g., printing the ship's name or details).

7. updateCoordByCross Logic
The function updateCoordByCross modifies the coordinates in a specific pattern (left, right, up, down). Ensure the update pattern aligns with your game's mechanics and doesn't exceed bounds.

8. General Code Clarity
Lastly, some sections of the code (e.g., hitOutcome) could benefit from comments or more descriptive variable names to improve readability. For instance, lastHitRow and lastHitCol can be renamed to something more descriptive like lastHitCoordinatesRow and lastHitCoordinatesCol.

Final Remarks:
Your implementation is robust, but there are opportunities for optimization and better safety with memory and boundary checks. If you'd like more detailed feedback or have specific questions about parts of the code, feel free to ask!






You said:
TEST CASES
ChatGPT said:
ChatGPT
Here are some test cases for the functions provided in the code. The test cases aim to check the correctness of each function and handle edge cases.

1. Test Case for countAndSortNegativeCells
Purpose: Test counting and sorting of negative cells in the probability grid.
Input:

A PLAYER structure with a probGrid containing both negative and positive values.
Test:

c
Copy code
PLAYER player;
player.probGrid[0][0] = -1;
player.probGrid[0][1] = 5;
player.probGrid[1][0] = -3;
player.probGrid[1][1] = -2;
player.probGrid[2][0] = 6;
player.probGrid[2][1] = -4;

int negativeCount;
Coord* negativeCells = countAndSortNegativeCells(&player, &negativeCount);
assert(negativeCount == 4);  // 4 negative cells found
assert(negativeCells[0].row == 1 && negativeCells[0].col == 0);  // The coordinates should be sorted in descending order
2. Test Case for getHighestPositiveProbSquare
Purpose: Test getting the highest probability positive square.
Input:

A PLAYER structure where the grid contains only positive probabilities.
Test:

c
Copy code
PLAYER player;
player.probGrid[0][0] = 2;
player.probGrid[0][1] = 5;
player.probGrid[1][0] = 4;
player.probGrid[1][1] = 3;

Coord highest = getHighestPositiveProbSquare(&player);
assert(highest.row == 0 && highest.col == 1);  // The highest probability is at (0, 1)
3. Test Case for getHighestProbSquare with Negative Cells
Purpose: Test getting the highest probability square when there are negative cells.
Input:

A PLAYER structure with both positive and negative probabilities.
Test:

c
Copy code
PLAYER player;
player.probGrid[0][0] = -1;
player.probGrid[0][1] = 2;
player.probGrid[1][0] = 4;
player.probGrid[1][1] = -5;

int negativeCount;
Coord* negativeCells = countAndSortNegativeCells(&player, &negativeCount);
assert(negativeCount == 2);  // There are two negative cells

Coord highest = getHighestProbSquare(&player, &player);
assert(highest.row == 1 && highest.col == 0);  // The highest probability (positive) is at (1, 0)
4. Test Case for checkShipStatusChange
Purpose: Test the comparison of ship status and determine whether a ship has sunk.
Input:

An opposingPlayer structure where the ship statuses have changed.
Test:

c
Copy code
PLAYER opposingPlayer;
opposingPlayer.ships[0].hasFallen = 1;  // The first ship has fallen
int opposingShipsStatus[NUMBEROFSHIPS];
saveOpposingShipsStatus(&opposingPlayer, opposingShipsStatus);

int result = checkShipStatusChange(&opposingPlayer, opposingShipsStatus);
assert(result == 4);  // The first ship (size 4) has sunk
5. Test Case for hitOutcome (Missed Shot)
Purpose: Test when a shot misses and updates the grid accordingly.
Input:

A PLAYER structure with a probGrid containing positive and negative values, and the shot is a miss.
Test:

c
Copy code
PLAYER player;
player.probGrid[0][0] = 1;
player.probGrid[0][1] = -1;
INPUT input = {0, 0};  // Shooting at (0, 0)

Coord lastHit = {0, 1};  // The last hit was at (0, 1)
hitOutcome(&player, &player, &input, NULL, &lastHit);

assert(player.probGrid[0][0] == 0);  // The cell (0, 0) should be marked as a miss
6. Test Case for hitOutcome (Ship Hit)
Purpose: Test the outcome of hitting a ship and updating the grid.
Input:

A PLAYER structure with a probGrid containing both negative and positive values, and the shot hits a ship.
Test:

c
Copy code
PLAYER player;
player.probGrid[0][0] = 9999;  // The shot hits a ship
player.hitsAndMissesGrid[0][0] = '*';  // The spot is a hit

INPUT input = {0, 0};  // Shooting at (0, 0)
Coord lastHit = {0, 1};  // The last hit was at (0, 1)
hitOutcome(&player, &player, &input, NULL, &lastHit);

assert(player.probGrid[0][0] == 9999);  // The cell should remain as a ship hit
7. Test Case for processSurroundingCell
Purpose: Test marking the surrounding cells as invalid when encountering a ship.
Input:

A PLAYER structure with a grid containing ships and negative values, and testing the surrounding cells after a shot.
Test:

c
Copy code
PLAYER player;
player.probGrid[0][0] = 3;  // Positive value
player.hitsAndMissesGrid[0][0] = '~';  // Missed spot

INPUT input = {0, 0};  // Testing surrounding cells
processSurroundingCell(&player, &input);

assert(player.probGrid[0][0] == -1);  // The cell should be marked as invalid (-1)
8. Test Case for updateCoordByCross
Purpose: Test updating coordinates in four possible directions.
Input:

A INPUT structure with initial coordinates.
Test:

c
Copy code
INPUT input = {2, 2};
updateCoordByCross(&input, 0);  // Move right
assert(input.row == 2 && input.column == 3);  // Column should increase

updateCoordByCross(&input, 1);  // Move down and left
assert(input.row == 3 && input.column == 2);

updateCoordByCross(&input, 2);  // Move left and up
assert(input.row == 2 && input.column == 1);

updateCoordByCross(&input, 3);  // Move up
assert(input.row == 1 && input.column == 1);
Conclusion
These test cases cover different scenarios such as counting negative cells, getting the highest probability square, handling ship status changes, hitting a ship, and processing surrounding cells. Make sure the functions handle edge cases such as grid






You said:
/*
requires: grid on which the sum of 2x2 sub-grids will be calculated.
          an array of Coord structures that will store the coordinates of the 2x2 sub-grids with the maximum sum
effects: The function rthe number of coordinates in the coords array that have the maximum sum. This value is stored in count.
*/

int findMaxSumCoords(int grid[GRID_SIZE][GRID_SIZE], Coord coords[MAX_COORDS]) {
    int maxSum = -1;  // To store the maximum sum found
    int count = 0;    // To track the number of coordinates with the max sum

    // Iterate over all possible starting coordinates for the 2x2 grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int sum = calculateSum(grid, i, j);  // Calculate sum of 2x2 grid starting at (i, j)

            // If the sum is greater than the current max, update the max and reset the list of coordinates
            if (sum > maxSum) {
                maxSum = sum;
                count = 0;  // Reset the list of coordinates
                coords[count].row = i;
                coords[count].col = j;
                count++;
            }
            // If the sum is equal to the current max, add the coordinate to the list
            else if (sum == maxSum) {
                coords[count].row = i;
                coords[count].col = j;
                count++;
            }
        }
    }

    return count;  // Return the number of coordinates with the maximum sum
}


/*
requires: probability grid where each element holds a value that will be used to calculate the sum for 2x2 sub-grids.
effects: The function returns a squareCoords structure, which includes the size of the maximum sum coordinates and the coordinates themselves in the maxCoords array.
*/
squareCoords getSquareCoord(int probGrid[GRID_SIZE][GRID_SIZE]) {
    
    squareCoords squareCoord;  // Create a squareCoords structure
    squareCoord.size = 0;      // Initialize size to 0

    // Call the function to find all coordinates with the max sum
    squareCoord.size = findMaxSumCoords(probGrid, squareCoord.maxCoords);

    return squareCoord;
} write test cases for these 2 based on format before
ChatGPT said:
ChatGPT
Here are test cases for the findMaxSumCoords and getSquareCoord functions. These tests will check for correct functionality, including edge cases such as grids with identical sums or small grids.

1. Test Case for findMaxSumCoords
Purpose: Test finding the coordinates of the maximum sum in 2x2 sub-grids.
Input:

A GRID_SIZE x GRID_SIZE grid, with specific values to ensure a distinct maximum sum in 2x2 sub-grids.
Test:

c
Copy code
int grid[5][5] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
};

Coord coords[MAX_COORDS];
int count = findMaxSumCoords(grid, coords);

// Test for maximum sum
assert(count == 1);  // Only one maximum sum coordinate is expected
assert(coords[0].row == 3 && coords[0].col == 3);  // The maximum sum comes from the sub-grid starting at (3,3)
2. Test Case for findMaxSumCoords with Multiple Maximums
Purpose: Test when there are multiple 2x2 sub-grids with the same maximum sum.
Input:

A GRID_SIZE x GRID_SIZE grid with multiple sub-grids having the same maximum sum.
Test:

c
Copy code
int grid[4][4] = {
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1}
};

Coord coords[MAX_COORDS];
int count = findMaxSumCoords(grid, coords);

// Test for multiple maximum sum coordinates
assert(count == 9);  // All 2x2 sub-grids have the same sum, so there are 9 coordinates
assert(coords[0].row == 0 && coords[0].col == 0);  // The first sub-grid starts at (0, 0)
assert(coords[8].row == 2 && coords[8].col == 2);  // The last sub-grid starts at (2, 2)
3. Test Case for findMaxSumCoords with Grid of Small Size
Purpose: Test when the grid size is too small to form any 2x2 sub-grid.
Input:

A GRID_SIZE = 2 grid, where the function cannot form any 2x2 sub-grid.
Test:

c
Copy code
int grid[2][2] = {
    {1, 2},
    {3, 4}
};

Coord coords[MAX_COORDS];
int count = findMaxSumCoords(grid, coords);

// Test for no valid 2x2 sub-grids
assert(count == 0);  // A 2x2 grid cannot have a 2x2 sub-grid starting within it
4. Test Case for getSquareCoord
Purpose: Test the getSquareCoord function to verify that it correctly retrieves the maximum sum coordinates.
Input:

A GRID_SIZE x GRID_SIZE grid, ensuring that the getSquareCoord function retrieves the maximum sum coordinates.
Test:

c
Copy code
int probGrid[5][5] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
};

squareCoords squareCoord = getSquareCoord(probGrid);

// Test for squareCoord
assert(squareCoord.size == 1);  // Only one coordinate with the maximum sum
assert(squareCoord.maxCoords[0].row == 3 && squareCoord.maxCoords[0].col == 3);  // The max sum comes from (3, 3)
5. Test Case for getSquareCoord with Multiple Maximums
Purpose: Test when there are multiple 2x2 sub-grids with the same maximum sum.
Input:

A GRID_SIZE x GRID_SIZE grid with multiple sub-grids having the same maximum sum.
Test:

c
Copy code
int probGrid[4][4] = {
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1}
};

squareCoords squareCoord = getSquareCoord(probGrid);

// Test for multiple maximum sum coordinates
assert(squareCoord.size == 9);  // All 2x2 sub-grids have the same sum
assert(squareCoord.maxCoords[0].row == 0 && squareCoord.maxCoords[0].col == 0);  // The first sub-grid starts at (0, 0)
assert(squareCoord.maxCoords[8].row == 2 && squareCoord.maxCoords[8].col == 2);  // The last sub-grid starts at (2, 2)
6. Test Case for findMaxSumCoords with Zero-Sum Grid
Purpose: Test when all values in the grid are zeros, resulting in a sum of zero for all sub-grids.
Input:

A grid where all values are zero.
Test:

c
Copy code
int grid[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

Coord coords[MAX_COORDS];
int count = findMaxSumCoords(grid, coords);

// Test for zero sum grid
assert(count == 9);  // All 2x2 sub-grids have the same sum (0)
assert(coords[0].row == 0 && coords[0].col == 0);  // The first sub-grid starts at (0, 0)
assert(coords[8].row == 2 && coords[8].col == 2);  // The last sub-grid starts at (2, 2)
Conclusion
These test cases check the following:

Correct identification of the maximum sum and coordinates.
Handling of grids with multiple identical sums.
Behavior when the grid is too small to form a 2x2 sub-grid.
Correct integration of the getSquareCoord function with the findMaxSumCoords function.





You said:
maxSumCoordinates() method:

test Case 1: Simple Grid (No Equal Maximum Sums)
Input:
int grid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};

Coord coords[MAX_COORDS];
Expected Output:
count = 1;
Description:
The highest sum is found in the 2x2 sub-grid starting at (2, 2). The maximum sum of 54 occurs only once for the 2x2 sub-grid starting at (2, 2). There are no other sub-grids with the same sum. Therefore, the function should return a count of 1, as only one sub-grid has the maximum sum.

Test Case 2: Multiple Sub-Grids with Same Maximum Sum
Input:
int grid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 6, 7, 8},
    {1, 2, 3, 4}
};

Coord coords[MAX_COORDS];
Expected Output:
count = 2;
Description:
Two 2x2 sub-grids have the same maximum sum of 28: one starting at (1, 1) and another at (2, 1).

Test Case 3: All Zeros Grid (Maximum Sum = 0)
Input:
int grid[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

Coord coords[MAX_COORDS];
Expected Output:
count = 16;
Description:
All 2x2 sub-grids have the same sum of 0 because the grid is filled with zeros. Therefore, there are 16 possible coordinates.


Test Case 4: All Equal Sums
Input:
int grid[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
};

Coord coords[MAX_COORDS];
Expected Output:
count = 16;
Description:
•	All 2x2 sub-grids have the same sum of 4, so there are 16 possible coordinates with the maximum sum.




Test Case 5: All Negative Numbers, Multiple Sub-Grids
Input:
int grid[4][4] = {
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1}
};

Coord coords[MAX_COORDS];
Expected Output:
count = 16;
Description: All 2x2 sub-grids have the same sum of -4. The function should return all 16 possible coordinates.

ChatGPT said:
ChatGPT
Here are the test cases for the maxSumCoordinates() method based on the provided descriptions:

Test Case 1: Simple Grid (No Equal Maximum Sums)
Input:

c
Copy code
int grid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};

Coord coords[MAX_COORDS];
Expected Output:

count = 1
Description: The highest sum of 54 occurs in the 2x2 sub-grid starting at (2, 2). There are no other sub-grids with the same sum.
c
Copy code
assert(count == 1);  // Only one 2x2 grid with the maximum sum
assert(coords[0].row == 2 && coords[0].col == 2);  // Maximum sum sub-grid starts at (2, 2)
Test Case 2: Multiple Sub-Grids with Same Maximum Sum
Input:

c
Copy code
int grid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 6, 7, 8},
    {1, 2, 3, 4}
};

Coord coords[MAX_COORDS];
Expected Output:

count = 2
Description: Two 2x2 sub-grids have the same maximum sum of 28: one starting at (1, 1) and another at (2, 1).
c
Copy code
assert(count == 2);  // Two sub-grids with the maximum sum
assert(coords[0].row == 1 && coords[0].col == 1);  // First sub-grid starting at (1, 1)
assert(coords[1].row == 2 && coords[1].col == 1);  // Second sub-grid starting at (2, 1)
Test Case 3: All Zeros Grid (Maximum Sum = 0)
Input:

c
Copy code
int grid[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

Coord coords[MAX_COORDS];
Expected Output:

count = 16
Description: All 2x2 sub-grids have the same sum of 0. Therefore, there are 16 possible coordinates.
c
Copy code
assert(count == 16);  // 16 possible sub-grids
assert(coords[0].row == 0 && coords[0].col == 0);  // First sub-grid starts at (0, 0)
assert(coords[15].row == 2 && coords[15].col == 2);  // Last sub-grid starts at (2, 2)
Test Case 4: All Equal Sums
Input:

c
Copy code
int grid[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
};

Coord coords[MAX_COORDS];
Expected Output:

count = 16
Description: All 2x2 sub-grids have the same sum of 4, so there are 16 possible coordinates with the maximum sum.
c
Copy code
assert(count == 16);  // 16 sub-grids with the maximum sum
assert(coords[0].row == 0 && coords[0].col == 0);  // First sub-grid starts at (0, 0)
assert(coords[15].row == 3 && coords[15].col == 3);  // Last sub-grid starts at (3, 3)
Test Case 5: All Negative Numbers, Multiple Sub-Grids
Input:

c
Copy code
int grid[4][4] = {
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1}
};

Coord coords[MAX_COORDS];
Expected Output:

count = 16
Description: All 2x2 sub-grids have the same sum of -4. The function should return all 16 possible coordinates.
c
Copy code
assert(count == 16);  // 16 sub-grids with the maximum sum
assert(coords[0].row == 0 && coords[0].col == 0);  // First sub-grid starts at (0, 0)
assert(coords[15].row == 2 && coords[15].col == 2);  // Last sub-grid starts at (2, 2)
Conclusion:
These test cases ensure that the maxSumCoordinates() function is well-tested for various scenarios, including grids with unique maximum sums, multiple sub-grids with equal sums, grids with all zeros, and grids filled with negative values. The expected behavior of the function is validated through these different inputs.






You said:
/*
requires: probability grid where each element holds a value that will be used to calculate the sum for 2x2 sub-grids.
effects: The function returns a squareCoords structure, which includes the size of the maximum sum coordinates and the coordinates themselves in the maxCoords array.
*/
squareCoords getSquareCoord(int probGrid[GRID_SIZE][GRID_SIZE]) {
    
    squareCoords squareCoord;  // Create a squareCoords structure
    squareCoord.size = 0;      // Initialize size to 0

    // Call the function to find all coordinates with the max sum
    squareCoord.size = findMaxSumCoords(probGrid, squareCoord.maxCoords);

    return squareCoord;
} can u do for this
ChatGPT said:
ChatGPT
Here are test cases for the getSquareCoord() function, which retrieves the coordinates of 2x2 sub-grids with the maximum sum in a given probability grid.

Test Case 1: Simple Grid (No Equal Maximum Sums)
Input:

c
Copy code
int probGrid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};

squareCoords result = getSquareCoord(probGrid);
Expected Output:

size = 1
maxCoords[0].row = 2, maxCoords[0].col = 2
Description: The highest sum is found in the 2x2 sub-grid starting at (2, 2). The maximum sum of 54 occurs only once for this sub-grid.
c
Copy code
assert(result.size == 1);  // Only one sub-grid with the maximum sum
assert(result.maxCoords[0].row == 2 && result.maxCoords[0].col == 2);  // First coordinate (2, 2)
Test Case 2: Multiple Sub-Grids with Same Maximum Sum
Input:

c
Copy code
int probGrid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 6, 7, 8},
    {1, 2, 3, 4}
};

squareCoords result = getSquareCoord(probGrid);
Expected Output:

size = 2
maxCoords[0].row = 1, maxCoords[0].col = 1
maxCoords[1].row = 2, maxCoords[1].col = 1
Description: Two 2x2 sub-grids have the same maximum sum of 28: one starting at (1, 1) and another at (2, 1).
c
Copy code
assert(result.size == 2);  // Two sub-grids with the maximum sum
assert(result.maxCoords[0].row == 1 && result.maxCoords[0].col == 1);  // First sub-grid starting at (1, 1)
assert(result.maxCoords[1].row == 2 && result.maxCoords[1].col == 1);  // Second sub-grid starting at (2, 1)
Test Case 3: All Zeros Grid (Maximum Sum = 0)
Input:

c
Copy code
int probGrid[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

squareCoords result = getSquareCoord(probGrid);
Expected Output:

size = 16
maxCoords[0].row = 0, maxCoords[0].col = 0
maxCoords[15].row = 2, maxCoords[15].col = 2
Description: All 2x2 sub-grids have the same sum of 0. Therefore, there are 16 possible coordinates.
c
Copy code
assert(result.size == 16);  // 16 sub-grids with the maximum sum
assert(result.maxCoords[0].row == 0 && result.maxCoords[0].col == 0);  // First sub-grid starts at (0, 0)
assert(result.maxCoords[15].row == 2 && result.maxCoords[15].col == 2);  // Last sub-grid starts at (2, 2)
Test Case 4: All Equal Sums
Input:

c
Copy code
int probGrid[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
};

squareCoords result = getSquareCoord(probGrid);
Expected Output:

size = 16
maxCoords[0].row = 0, maxCoords[0].col = 0
maxCoords[15].row = 3, maxCoords[15].col = 3
Description: All 2x2 sub-grids have the same sum of 4, so there are 16 possible coordinates with the maximum sum.
c
Copy code
assert(result.size == 16);  // 16 sub-grids with the maximum sum
assert(result.maxCoords[0].row == 0 && result.maxCoords[0].col == 0);  // First sub-grid starts at (0, 0)
assert(result.maxCoords[15].row == 3 && result.maxCoords[15].col == 3);  // Last sub-grid starts at (3, 3)
Test Case 5: All Negative Numbers, Multiple Sub-Grids
Input:

c
Copy code
int probGrid[4][4] = {
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1}
};

squareCoords result = getSquareCoord(probGrid);
Expected Output:

size = 16
maxCoords[0].row = 0, maxCoords[0].col = 0
maxCoords[15].row = 2, maxCoords[15].col = 2
Description: All 2x2 sub-grids have the same sum of -4. The function should return all 16 possible coordinates.
c
Copy code
assert(result.size == 16);  // 16 sub-grids with the maximum sum
assert(result.maxCoords[0].row == 0 && result.maxCoords[0].col == 0);  // First sub-grid starts at (0, 0)
assert(result.maxCoords[15].row == 2 && result.maxCoords[15].col == 2);  // Last sub-grid starts at (2, 2)
Conclusion:
These test cases validate the behavior of the getSquareCoord() function under different grid configurations, such as grids with unique maximum sums, grids with multiple sub-grids having the same maximum sum, grids filled with zeros, and grids with negative values. The expected output is verified by checking both the size of the resulting coordinates and the specific coordinates themselves.






You said:
do thme like test cases fo find max coor
ChatGPT said:
ChatGPT
Here are test cases for the findMaxSumCoords() function, which is responsible for identifying the coordinates of the 2x2 sub-grids with the maximum sum in a given grid. Each test case follows the same structure, specifying the input grid, expected output (coordinates with the maximum sum), and assertions to verify the correctness of the function.

Test Case 1: Simple Grid (No Equal Maximum Sums)
Input:

c
Copy code
int probGrid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};

Coord maxCoords[MAX_COORDS];
int count = findMaxSumCoords(probGrid, maxCoords);
Expected Output:

count = 1
maxCoords[0].row = 2, maxCoords[0].col = 2
Description: The maximum sum of 54 occurs in the 2x2 sub-grid starting at (2, 2).
c
Copy code
assert(count == 1);  // Only one sub-grid with the maximum sum
assert(maxCoords[0].row == 2 && maxCoords[0].col == 2);  // First coordinate (2, 2)
Test Case 2: Multiple Sub-Grids with Same Maximum Sum
Input:

c
Copy code
int probGrid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 6, 7, 8},
    {1, 2, 3, 4}
};

Coord maxCoords[MAX_COORDS];
int count = findMaxSumCoords(probGrid, maxCoords);
Expected Output:

count = 2
maxCoords[0].row = 1, maxCoords[0].col = 1
maxCoords[1].row = 2, maxCoords[1].col = 1
Description: Two 2x2 sub-grids have the same maximum sum of 28: one starting at (1, 1) and another at (2, 1).
c
Copy code
assert(count == 2);  // Two sub-grids with the maximum sum
assert(maxCoords[0].row == 1 && maxCoords[0].col == 1);  // First sub-grid starting at (1, 1)
assert(maxCoords[1].row == 2 && maxCoords[1].col == 1);  // Second sub-grid starting at (2, 1)
Test Case 3: All Zeros Grid (Maximum Sum = 0)
Input:

c
Copy code
int probGrid[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

Coord maxCoords[MAX_COORDS];
int count = findMaxSumCoords(probGrid, maxCoords);
Expected Output:

count = 16
maxCoords[0].row = 0, maxCoords[0].col = 0
maxCoords[15].row = 2, maxCoords[15].col = 2
Description: All 2x2 sub-grids have the same sum of 0. Therefore, there are 16 possible coordinates.
c
Copy code
assert(count == 16);  // 16 sub-grids with the maximum sum
assert(maxCoords[0].row == 0 && maxCoords[0].col == 0);  // First sub-grid starts at (0, 0)
assert(maxCoords[15].row == 2 && maxCoords[15].col == 2);  // Last sub-grid starts at (2, 2)
Test Case 4: All Equal Sums
Input:

c
Copy code
int probGrid[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
};

Coord maxCoords[MAX_COORDS];
int count = findMaxSumCoords(probGrid, maxCoords);
Expected Output:

count = 16
maxCoords[0].row = 0, maxCoords[0].col = 0
maxCoords[15].row = 3, maxCoords[15].col = 3
Description: All 2x2 sub-grids have the same sum of 4, so there are 16 possible coordinates with the maximum sum.
c
Copy code
assert(count == 16);  // 16 sub-grids with the maximum sum
assert(maxCoords[0].row == 0 && maxCoords[0].col == 0);  // First sub-grid starts at (0, 0)
assert(maxCoords[15].row == 3 && maxCoords[15].col == 3);  // Last sub-grid starts at (3, 3)
Test Case 5: All Negative Numbers, Multiple Sub-Grids
Input:

c
Copy code
int probGrid[4][4] = {
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1}
};

Coord maxCoords[MAX_COORDS];
int count = findMaxSumCoords(probGrid, maxCoords);
Expected Output:

count = 16
maxCoords[0].row = 0, maxCoords[0].col = 0
maxCoords[15].row = 2, maxCoords[15].col = 2
Description: All 2x2 sub-grids have the same sum of -4. The function should return all 16 possible coordinates.
c
Copy code
assert(count == 16);  // 16 sub-grids with the maximum sum
assert(maxCoords[0].row == 0 && maxCoords[0].col == 0);  // First sub-grid starts at (0, 0)
assert(maxCoords[15].row == 2 && maxCoords[15].col == 2);  // Last sub-grid starts at (2, 2)
Conclusion:
These test cases cover different scenarios for the findMaxSumCoords() function:

A grid with no equal maximum sums.
A grid with multiple sub-grids having the same maximum sum.
A grid filled with zeros.
A grid where all sub-grids have the same sum.
A grid with all negative numbers, where all sub-grids have the same sum.
Each test case checks the count of sub-grids with the maximum sum and the actual coordinates of those sub-grids.






You said:
Test Case 1: Simple Grid (No Equal Maximum Sums)
Input:
int probGrid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};
Expected Output:
•	count = 1
•	maxCoords[0].row = 2, maxCoords[0].col = 2
Description: The maximum sum of 54 occurs in the 2x2 sub-grid starting at (2, 2). use this format 

ChatGPT said:
ChatGPT
Here is the Test Case 1 in the requested format:

Test Case 1: Simple Grid (No Equal Maximum Sums)
Input:

c
Copy code
int probGrid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};

Coord maxCoords[MAX_COORDS];
int count = findMaxSumCoords(probGrid, maxCoords);
Expected Output:

count = 1
maxCoords[0].row = 2, maxCoords[0].col = 2
Description: The maximum sum of 54 occurs in the 2x2 sub-grid starting at (2, 2).

c
Copy code
assert(count == 1);  // Only one sub-grid with the maximum sum
assert(maxCoords[0].row == 2 && maxCoords[0].col == 2);  // First coordinate (2, 2)





You said:
continue
ChatGPT said:
ChatGPT
Here are additional test cases for getSquareCoord using the same format:

Test Case 2: Multiple Sub-Grids with Same Maximum Sum
Input:

c
Copy code
int probGrid[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 6, 7, 8},
    {1, 2, 3, 4}
};

Coord maxCoords[MAX_COORDS];
int count = findMaxSumCoords(probGrid, maxCoords);
Expected Output:

count = 2
maxCoords[0].row = 1, maxCoords[0].col = 1
maxCoords[1].row = 2, maxCoords[1].col = 1
Description: Two 2x2 sub-grids have the same maximum sum of 28: one starting at (1, 1) and another at (2, 1).

c
Copy code
assert(count == 2);  // Two sub-grids with the maximum sum
assert(maxCoords[0].row == 1 && maxCoords[0].col == 1);  // First coordinate (1, 1)
assert(maxCoords[1].row == 2 && maxCoords[1].col == 1);  // Second coordinate (2, 1)
Test Case 3: All Zeros Grid (Maximum Sum = 0)
Input:

c
Copy code
int probGrid[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

Coord maxCoords[MAX_COORDS];
int count = findMaxSumCoords(probGrid, maxCoords);
Expected Output:

count = 16
maxCoords[0].row = 0, maxCoords[0].col = 0
maxCoords[1].row = 0, maxCoords[1].col = 1
maxCoords[2].row = 0, maxCoords[2].col = 2
(continue for all combinations of valid sub-grid starts)
Description: All 2x2 sub-grids have the same sum of 0 because the grid is filled with zeros. Therefore, all 16 sub-grids have the maximum sum.

c
Copy code
assert(count == 16);  // All sub-grids have the same sum of 0
assert(maxCoords[0].row == 0 && maxCoords[0].col == 0);  // First coordinate (0, 0)
assert(maxCoords[1].row == 0 && maxCoords[1].col == 1);  // Second coordinate (0, 1)
// Continue assertions for other coordinates...
Test Case 4: All Equal Sums
Input:

c
Copy code
int probGrid[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
};

Coord maxCoords[MAX_COORDS];
int count = findMaxSumCoords(probGrid, maxCoords);
Expected Output:

count = 16
maxCoords[0].row = 0, maxCoords[0].col = 0
maxCoords[1].row = 0, maxCoords[1].col = 1
maxCoords[2].row = 0, maxCoords[2].col = 2
(continue for all valid sub-grid starting positions)
Description: All 2x2 sub-grids have the same sum of 4, so there are 16 possible coordinates with the maximum sum.

c
Copy code
assert(count == 16);  // All sub-grids have the same sum of 4
assert(maxCoords[0].row == 0 && maxCoords[0].col == 0);  // First coordinate (0, 0)
assert(maxCoords[1].row == 0 && maxCoords[1].col == 1);  // Second coordinate (0, 1)
// Continue assertions for other coordinates...
Test Case 5: All Negative Numbers, Multiple Sub-Grids
Input:

c
Copy code
int probGrid[4][4] = {
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1}
};

Coord maxCoords[MAX_COORDS];
int count = findMaxSumCoords(probGrid, maxCoords);
Expected Output:

count = 16
maxCoords[0].row = 0, maxCoords[0].col = 0
maxCoords[1].row = 0, maxCoords[1].col = 1
maxCoords[2].row = 0, maxCoords[2].col = 2
(continue for all valid sub-grid starts)
Description: All 2x2 sub-grids have the same sum of -4. The function should return all 16 possible coordinates.

c
Copy code
assert(count == 16);  // All sub-grids have the same sum of -4
assert(maxCoords[0].row == 0 && maxCoords[0].col == 0);  // First coordinate (0, 0)
assert(maxCoords[1].row == 0 && maxCoords[1].col == 1);  // Second coordinate (0, 1)
// Continue assertions for other coordinates...
Test Case 6: Grid with One Sub-Grid (Minimum Size)
Input:

c
Copy code
int probGrid[2][2] = {
    {5, 6},
    {7, 8}
};

Coord maxCoords[MAX_COORDS];
int count = findMaxSumCoords(probGrid, maxCoords);
Expected Output:

count = 1
maxCoords[0].row = 0, maxCoords[0].col = 0
Description: The only sub-grid available is the 2x2 sub-grid starting at (0, 0), with a sum of 26.

c
Copy code
assert(count == 1);  // Only one sub-grid in a 2x2 grid
assert(maxCoords[0].row == 0 && maxCoords[0].col == 0);  // First and only coordinate (0, 0)
These test cases help ensure that the function getSquareCoord and findMaxSumCoords handle a variety of scenarios, from simple grids with no equal maximum sums to grids with multiple maximum sums or grids filled with equal values.






You said:

void botThinking(PLAYER *currentPlayer, PLAYER *opposingPlayer)
{
    currentPlayer->radarSweep=9;
    currentPlayer->artillery=0;
    currentPlayer->torpedo=0;

    printf("\n\n THE PROBABILITY GRID IS: \n\n");
    printGridInt(currentPlayer->probGrid);
    
    //first we do the radars

    int radarResult = handleRadar(currentPlayer,opposingPlayer);
    if(radarResult==1)
    {
        return; //done
    }
    
    
    if(currentPlayer->torpedo==2)
    {
        /*
        // INPUT input;
        // input.row = 2;
        // input.column =7;
        // fireMove(currentPlayer,opposingPlayer, &input);
        // calculateProbability(currentPlayer,opposingPlayer);
        // printGridInt(currentPlayer->probGrid);

        //handleTorpedo(currentPlayer,opposingPlayer);
        */

        handleTorpedo(currentPlayer,opposingPlayer);
        return; //always end and done
        //do the torpedo first
    }
    
    if(currentPlayer->artillery ==2)
    {
        INPUT input;
        handleArtillery(currentPlayer,opposingPlayer);
        //handleArtillery(currentPlayer,opposingPlayer);
        return; //always end

        //do artillery
    }
    
    INPUT input;
    handleFire(currentPlayer,opposingPlayer);

     
} write me test case
ChatGPT said:
ChatGPT
To create a test case for the botThinking function, we'll need to simulate a scenario where the bot goes through the decision-making process, such as using radar, torpedo, and artillery, based on the player's state and the game rules. We'll set up initial conditions for the PLAYER structure and then assert the expected behavior after calling botThinking.

Assumptions:
PLAYER has attributes radarSweep, artillery, torpedo, and probGrid, among others, which are used to determine the actions of the bot.
handleRadar, handleTorpedo, handleArtillery, and handleFire are predefined functions that perform specific actions.
printGridInt is a function used to print the grid (we'll mock this behavior in the test).
Here's a simple test case:

Test Case 1: Testing Bot's Decision Process
Description:

We will test the bot's decision-making process when:
The radar is used first.
If torpedoes and artillery are not available, the bot will try to fire.
Input:

c
Copy code
// Simulated player structures
PLAYER currentPlayer = {
    .radarSweep = 9,      // Ready for radar sweep
    .artillery = 0,       // Artillery not available
    .torpedo = 0,         // Torpedo not available
    .probGrid = {         // Simulated grid (size doesn't matter here)
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    }
};

PLAYER opposingPlayer = {
    .radarSweep = 0,      // No radar for opponent
    .artillery = 0,       // No artillery for opponent
    .torpedo = 0,         // No torpedo for opponent
    .probGrid = {         // Simulated opponent grid
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    }
};
Expected Output:

The function should first call handleRadar since the radarSweep is non-zero.
After radar, the bot should attempt to fire, as neither torpedo nor artillery is available.
c
Copy code
void testBotThinking() {
    // Given the test inputs, we expect the bot to go through the radar handling first.
    botThinking(&currentPlayer, &opposingPlayer);

    // Check expected behavior after radar
    assert(currentPlayer.radarSweep == 9);  // Radar should still be available (not modified)
    assert(currentPlayer.artillery == 0);  // Artillery should not be available
    assert(currentPlayer.torpedo == 0);    // Torpedo should not be available
    // Since neither artillery nor torpedo is available, we expect the bot to fire.
    
    // You can mock the printing function or check the internal logic of the functions
    // handleRadar, handleTorpedo, and handleFire for further validation.
    
    // Ensure handleFire gets called when no artillery or torpedo is available.
    // This depends on how you mock or test the called functions within botThinking.
}
Test Case 2: Testing Bot's Action with Torpedo Available
Description:

We will test the case where the bot has a torpedo available, so it should choose to fire the torpedo and end the decision process.
Input:

c
Copy code
// Simulated player structures with torpedo available
PLAYER currentPlayer = {
    .radarSweep = 9,      // Ready for radar sweep
    .artillery = 0,       // Artillery not available
    .torpedo = 2,         // Torpedo available
    .probGrid = {         // Simulated grid (size doesn't matter here)
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    }
};

PLAYER opposingPlayer = {
    .radarSweep = 0,      // No radar for opponent
    .artillery = 0,       // No artillery for opponent
    .torpedo = 0,         // No torpedo for opponent
    .probGrid = {         // Simulated opponent grid
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    }
};
Expected Output:

The function should call handleTorpedo and then return immediately, as torpedo is available.
The bot should not proceed to fire or use artillery.
c
Copy code
void testBotThinkingWithTorpedo() {
    // Given the test inputs, we expect the bot to fire the torpedo.
    botThinking(&currentPlayer, &opposingPlayer);

    // After firing the torpedo, the bot should have no torpedo left.
    assert(currentPlayer.torpedo == 0);  // Torpedo should be used up.
    // Other attributes should remain unchanged.
    assert(currentPlayer.radarSweep == 9);  // Radar should remain.
    assert(currentPlayer.artillery == 0);  // Artillery still unavailable.
}
Test Case 3: Testing Bot's Action with Artillery Available
Description:

We will test the case where the bot has artillery available, so it should choose to fire artillery and end the decision process.
Input:

c
Copy code
// Simulated player structures with artillery available
PLAYER currentPlayer = {
    .radarSweep = 9,      // Ready for radar sweep
    .artillery = 2,       // Artillery available
    .torpedo = 0,         // Torpedo not available
    .probGrid = {         // Simulated grid (size doesn't matter here)
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    }
};

PLAYER opposingPlayer = {
    .radarSweep = 0,      // No radar for opponent
    .artillery = 0,       // No artillery for opponent
    .torpedo = 0,         // No torpedo for opponent
    .probGrid = {         // Simulated opponent grid
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    }
};
Expected Output:

The function should call handleArtillery and then return immediately, as artillery is available.
The bot should not proceed to fire a torpedo or handle radar.
c
Copy code
void testBotThinkingWithArtillery() {
    // Given the test inputs, we expect the bot to fire artillery.
    botThinking(&currentPlayer, &opposingPlayer);

    // After firing artillery, the bot should have no artillery left.
    assert(currentPlayer.artillery == 0);  // Artillery should be used up.
    // Other attributes should remain unchanged.
    assert(currentPlayer.radarSweep == 9);  // Radar should remain.
    assert(currentPlayer.torpedo == 0);  // No torpedo to use.
}
Conclusion:
Each test case here verifies specific behaviors:

The radar should be used if available.
The torpedo should be used if available.
The artillery should be used if available.
You can expand the test cases with more complex scenarios, depending on your game's rules and other conditions.






You said:
*/
requires: a reference to currentPlayer 
          a reference to opposingPlayer 
          
effects:   It
*/\
ChatGPT said:
ChatGPT
It seems like you're looking for a detailed function comment for a C function, where you specify the requirements (inputs) and effects (outputs) clearly. Below is a possible implementation of the comment for a function that could be part of the bot decision-making process in the Battleship game.

Let's consider that the function might be botThinking(), and I'll provide the detailed comment for it:

c
Copy code
/*
requires: 
    - A reference to the currentPlayer (PLAYER *currentPlayer): 
      This parameter is a pointer to the current player, whose properties like radarSweep, artillery, torpedo, and probability grid will be used in decision-making.
    - A reference to the opposingPlayer (PLAYER *opposingPlayer): 
      This parameter is a pointer to the opposing player, whose properties and probability grid are used to make informed decisions.

effects: 
    - This function updates the currentPlayer's properties based on the game logic.
    - The function first checks if the current player has any remaining radar sweeps, torpedoes, or artillery, and performs actions accordingly.
    - If the current player has a radar sweep available, it will call the `handleRadar()` function to gather information about the opponent's grid.
    - If the current player has torpedoes available, it will fire a torpedo at the opponent.
    - If the current player has artillery available, it will fire artillery at the opponent.
    - If no special actions (radar, torpedo, artillery) are available, it will proceed to a default action (likely firing a regular shot using `handleFire()`).
    - The function does not return any value, but modifies the state of the currentPlayer based on the chosen action.
*/
void botThinking(PLAYER *currentPlayer, PLAYER *opposingPlayer)
{
    // Set default values for currentPlayer's actions
    currentPlayer->radarSweep = 9;
    currentPlayer->artillery = 0;
    currentPlayer->torpedo = 0;

    printf("\n\n THE PROBABILITY GRID IS: \n\n");
    printGridInt(currentPlayer->probGrid);

    // Check if radar sweep is available, and handle it first
    int radarResult = handleRadar(currentPlayer, opposingPlayer);
    if (radarResult == 1) {
        return; // Radar sweep was successful, so end the function here
    }

    // If torpedo is available, fire it and exit
    if (currentPlayer->torpedo == 2) {
        handleTorpedo(currentPlayer, opposingPlayer);
        return; // End after firing the torpedo
    }

    // If artillery is available, fire it and exit
    if (currentPlayer->artillery == 2) {
        handleArtillery(currentPlayer, opposingPlayer);
        return; // End after firing the artillery
    }

    // If no special actions, proceed with a regular shot
    INPUT input;
    handleFire(currentPlayer, opposingPlayer);
}
Explanation of the Comment:
requires: This part specifies the input parameters needed by the function:
currentPlayer (type PLAYER *) is the reference (pointer) to the player whose state is being modified.
opposingPlayer (type PLAYER *) is the reference (pointer) to the opponent, used for decision-making but not directly modified.
effects: Describes what the function does:
It evaluates the availability of radar sweeps, torpedoes, and artillery.
Based on the conditions, it calls the corresponding function (handleRadar, handleTorpedo, handleArtillery, or handleFire).
The function updates the currentPlayer's state depending on the action taken (e.g., the number of available torpedoes, artillery, etc.).
The function doesn't return a value but has side effects on the currentPlayer state and prints information.
This structure follows the typical C documentation style, making it clear what inputs are required and what changes are made to the state, helping others understand the function's purpose and behavior.






You said:
requires: a reference to currentPlayer when current player is bot
          a reference to opposingPlayer 
          
effects:  which move should the bot choose based on the oppos
          continue short
ChatGPT said:
ChatGPT
Here’s a concise version of the comment for the botThinking function based on your request:

c
Copy code
/*
requires: 
    - A reference to currentPlayer (PLAYER *currentPlayer) when the current player is the bot.
    - A reference to opposingPlayer (PLAYER *opposingPlayer).

effects: 
    - Determines the bot's next move based on the current state of the game.
    - The bot will first attempt to use a radar sweep, then a torpedo if available, followed by artillery if applicable.
    - If no special actions are available, the bot will perform a regular attack.
*/
void botThinking(PLAYER *currentPlayer, PLAYER *opposingPlayer)
{
    currentPlayer->radarSweep = 9;
    currentPlayer->artillery = 0;
    currentPlayer->torpedo = 0;

    printf("\n\n THE PROBABILITY GRID IS: \n\n");
    printGridInt(currentPlayer->probGrid);

    int radarResult = handleRadar(currentPlayer, opposingPlayer);
    if (radarResult == 1) {
        return;
    }

    if (currentPlayer->torpedo == 2) {
        handleTorpedo(currentPlayer, opposingPlayer);
        return;
    }

    if (currentPlayer->artillery == 2) {
        handleArtillery(currentPlayer, opposingPlayer);
        return;
    }

    INPUT input;
    handleFire(currentPlayer, opposingPlayer);
}
This version focuses on summarizing the essential details of the function's requirements and effects, keeping it short and clear.






You said:
void addShip(PLAYER* currentPlayer, const char* name,int shipSize, int row, int col, int orientation)
{   
    SHIP* ships = currentPlayer->ships;
    int shipIndex = 4-shipSize;

    int sizeofName =0;
    while(name[sizeofName]!= '\0')
    {
        sizeofName++;
    }

    strncpy(ships[shipIndex].name, name, sizeofName);
    ships[shipIndex].name[sizeofName] = '\0';

    currentPlayer->ships[shipIndex].size = shipSize;

    //the orientation should be passed now from the arguments
    if(orientation==HORIZONTAL)
    {
        for(int  i = 0 ; i<shipSize;i++)
        {
            currentPlayer->grid[row][i + col] = 'X';
           currentPlayer->ships[shipIndex].coord[i] = (row * 10) + (col + i); 
            
        }
    }else if(orientation==VERTICAL)
    {
        
        for(int  i = 0 ; i<shipSize;i++)
        {
            currentPlayer->grid[i+row][col] = 'X';
            currentPlayer->ships[shipIndex].coord[i] = (row + i) * 10 + col; 
        }
    }
    ships[shipIndex].hits=0;
    ships[shipIndex].hasFallen =0;

}

int checkBounds(PLAYER* currentPlayer,int row, int col,int shipSize, int orientation)
{

   if(orientation==HORIZONTAL)
    {
        if(col + shipSize >GRID_SIZE)
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
            if(currentPlayer->grid[row][col+i] != '~')
            {
                printf("ships overlap\n");
                return -1;
            }
        }
    }else if(orientation==VERTICAL)
    {
        
        for(int  i = 0; i<shipSize;i++)
        {
            if(currentPlayer->grid[i+row][col] != '~')
            {
                printf("ships overlap\n");
                return -1;
            }
        }
    }

    return 1;



}
ChatGPT said:
ChatGPT
Here are some test cases for the addShip and checkBounds functions based on the provided code:

Test Case 1: Adding a Ship (Valid Placement, Horizontal)
Input:

c
Copy code
PLAYER currentPlayer;
initializePlayer(&currentPlayer);  // Initialize the player with an empty grid and ships array.
int row = 2, col = 3, shipSize = 3, orientation = HORIZONTAL;
const char* shipName = "Battleship";

addShip(&currentPlayer, shipName, shipSize, row, col, orientation);
Expected Output:

The grid at positions (2, 3), (2, 4), and (2, 5) will contain 'X', representing the ship's placement.
currentPlayer.ships[1].name will be "Battleship".
currentPlayer.ships[1].size will be 3.
currentPlayer.ships[1].coord will store the ship's coordinates: (23, 24, 25) (converted to a 1D index).
Test Case 2: Adding a Ship (Invalid Placement, Out of Bounds, Horizontal)
Input:

c
Copy code
PLAYER currentPlayer;
initializePlayer(&currentPlayer);  // Initialize the player with an empty grid and ships array.
int row = 2, col = 8, shipSize = 3, orientation = HORIZONTAL;
const char* shipName = "Destroyer";

int result = checkBounds(&currentPlayer, row, col, shipSize, orientation);
Expected Output:

The result should be -1 because the ship will go out of bounds (position (2, 8) + 3 exceeds grid size).
The message "Ship is out of bound" will be printed.
Test Case 3: Adding a Ship (Invalid Placement, Overlap with Another Ship, Horizontal)
Input:

c
Copy code
PLAYER currentPlayer;
initializePlayer(&currentPlayer);  // Initialize the player with an empty grid and ships array.
addShip(&currentPlayer, "Battleship", 3, 2, 3, HORIZONTAL);  // Place the first ship.
int row = 2, col = 4, shipSize = 3, orientation = HORIZONTAL;
const char* shipName = "Cruiser";

int result = checkBounds(&currentPlayer, row, col, shipSize, orientation);
Expected Output:

The result should be -1 because the second ship overlaps with the first ship.
The message "ships overlap" will be printed.
Test Case 4: Adding a Ship (Valid Placement, Vertical)
Input:

c
Copy code
PLAYER currentPlayer;
initializePlayer(&currentPlayer);  // Initialize the player with an empty grid and ships array.
int row = 3, col = 4, shipSize = 2, orientation = VERTICAL;
const char* shipName = "Submarine";

addShip(&currentPlayer, shipName, shipSize, row, col, orientation);
Expected Output:

The grid at positions (3, 4) and (4, 4) will contain 'X', representing the ship's placement.
currentPlayer.ships[1].name will be "Submarine".
currentPlayer.ships[1].size will be 2.
currentPlayer.ships[1].coord will store the ship's coordinates: (34, 44).
Test Case 5: Adding a Ship (Invalid Placement, Overlap with Another Ship, Vertical)
Input:

c
Copy code
PLAYER currentPlayer;
initializePlayer(&currentPlayer);  // Initialize the player with an empty grid and ships array.
addShip(&currentPlayer, "Battleship", 3, 2, 3, VERTICAL);  // Place the first ship.
int row = 2, col = 3, shipSize = 2, orientation = VERTICAL;
const char* shipName = "Destroyer";

int result = checkBounds(&currentPlayer, row, col, shipSize, orientation);
Expected Output:

The result should be -1 because the second ship overlaps with the first ship.
The message "ships overlap" will be printed.
Test Case 6: Adding a Ship (All Ships Placed)
Input:

c
Copy code
PLAYER currentPlayer;
initializePlayer(&currentPlayer);  // Initialize the player with an empty grid and ships array.
addShip(&currentPlayer, "Battleship", 3, 2, 3, HORIZONTAL);
addShip(&currentPlayer, "Cruiser", 2, 5, 5, VERTICAL);
addShip(&currentPlayer, "Destroyer", 4, 7, 1, HORIZONTAL);
addShip(&currentPlayer, "Submarine", 2, 0, 0, VERTICAL);
Expected Output:

The grid will have multiple 'X' marks, reflecting the placement of all four ships.
The ships array will contain the four ships with correct sizes, names, and coordinates.
These test cases cover valid ship placement, out-of-bounds conditions, and overlap scenarios.






You said:
specs please
ChatGPT said:
ChatGPT
Here are the specifications for the functions addShip and checkBounds based on the provided code:

addShip Function
Purpose:
The function adds a ship to a player's grid by marking the grid positions with 'X' and storing the ship's details in the player's ships array.

Input Parameters:
PLAYER* currentPlayer: A pointer to the player whose grid and ships array will be modified.
const char* name: The name of the ship.
int shipSize: The size (length) of the ship.
int row: The starting row coordinate for placing the ship.
int col: The starting column coordinate for placing the ship.
int orientation: The orientation of the ship (HORIZONTAL or VERTICAL).
Effects:
Updates the player's grid with 'X' marks representing the ship's location.
Updates the player's ships array with details (name, size, coordinates) for the newly placed ship.
If the ship is placed horizontally, the grid cells from (row, col) to (row, col + shipSize - 1) are marked with 'X'.
If the ship is placed vertically, the grid cells from (row, col) to (row + shipSize - 1, col) are marked with 'X'.
The coordinates of the ship are stored in currentPlayer->ships[shipIndex].coord in a format that combines row and column into a unique identifier.
Return Value:
No return value (void).
checkBounds Function
Purpose:
The function checks if a ship can be placed at the specified location and orientation, ensuring that the ship doesn't go out of bounds or overlap with other ships.

Input Parameters:
PLAYER* currentPlayer: A pointer to the player whose grid will be checked for valid ship placement.
int row: The starting row coordinate for the ship.
int col: The starting column coordinate for the ship.
int shipSize: The size (length) of the ship.
int orientation: The orientation of the ship (HORIZONTAL or VERTICAL).
Effects:
Checks if the ship can be placed within the bounds of the grid. For horizontal placement, it checks if the column plus the ship size exceeds the grid's column size. For vertical placement, it checks if the row plus the ship size exceeds the grid's row size.
Checks if the ship overlaps with any existing ships on the grid by inspecting the cells where the ship would be placed.
If any of the above conditions are violated (out-of-bounds or overlap), prints appropriate messages like "Ship is out of bound" or "ships overlap."
Return Value:
int:
Returns 1 if the ship can be placed (no bounds or overlap issues).
Returns -1 if there is an issue (either out-of-bounds or overlap).
Constants:
HORIZONTAL: Represents the horizontal orientation of the ship.
VERTICAL: Represents the vertical orientation of the ship.
GRID_SIZE: The size of the player's grid (e.g., 10x10).
Test Cases:
You can refer to the previously mentioned test cases for validation of these functions. Here's a summary:

Test Case 1: Valid Horizontal Ship Placement
Add a ship with size 3 at position (2, 3) horizontally.
Expected result: The grid will be updated with 'X' from (2, 3) to (2, 5). The ship will be stored in the player's ships array.
Test Case 2: Ship Out of Bounds (Horizontal)
Attempt to place a ship of size 3 at position (2, 8) horizontally.
Expected result: The function should return -1 and print "Ship is out of bound."
Test Case 3: Ship Overlaps Another Ship (Horizontal)
After placing a ship at (2, 3) horizontally, try placing another ship of size 3 at position (2, 4) horizontally.
Expected result: The function should return -1 and print "ships overlap."
Test Case 4: Valid Vertical Ship Placement
Add a ship with size 2 at position (3, 4) vertically.
Expected result: The grid will be updated with 'X' at (3, 4) and (4, 4).
Test Case 5: Ship Out of Bounds (Vertical)
Attempt to place a ship of size 2 at position (7, 4) vertically.
Expected result: The function should return -1 and print "Ship is out of bound."
Test Case 6: Ship Overlaps Another Ship (Vertical)
After placing a ship at (3, 4) vertically, try placing another ship of size 2 at position (2, 4) vertically.
Expected result: The function should return -1 and print "ships overlap."
These test cases help ensure the correctness of ship placement, bounds checking, and overlap detection.






You said:
nooooooo i want it short!!!!!!!!!!!!!!
ChatGPT said:
ChatGPT
Here are the concise specifications for the functions addShip and checkBounds:

addShip Function
Purpose: Adds a ship to the player's grid at the specified coordinates and orientation.
Inputs:
PLAYER* currentPlayer: Pointer to the current player.
const char* name: Ship name.
int shipSize: Size of the ship.
int row, col: Starting position for the ship.
int orientation: Ship orientation (HORIZONTAL or VERTICAL).
Effects:
Marks the grid with 'X' for the ship's location.
Updates the player's ship information.
Returns: void.
checkBounds Function
Purpose: Checks if the ship can be placed within bounds and without overlap.
Inputs:
PLAYER* currentPlayer: Pointer to the current player.
int row, col: Starting position for the ship.
int shipSize: Size of the ship.
int orientation: Ship orientation (HORIZONTAL or VERTICAL).
Effects:
Returns 1 if valid placement, -1 if out-of-bounds or overlaps.
Prints error messages if placement is invalid.
Returns: int (1 or -1).
This should be a more compact version of the specifications!






You said:
void placeShipsEasy(PLAYER* player) //edit it for bot
{

    printf("%s, the bot is placing its ships.\n", player->name);

    const char *shipsNames[] = {"Carrier", "Battleship", "Destroyer", "Submarine"}; // all ships to avoid clustering if condition
    srand(time(NULL)); //randomly
    for (int i = 0; i < 4; i++) // 4 total ships to place
    {

        int currentShipSize = 4 - i; // reverse order size

        int placed = 0;
        int row, col, orientation;
        while (!placed)
        {
            //get row col and orientation randomly
            row = rand() % GRID_SIZE;
            col = rand() % GRID_SIZE;
            orientation = rand() % 2;
            // check its validity
            if (checkBounds(player, row, col,currentShipSize, orientation))
            {
                addShip(player, shipsNames[i], currentShipSize, row, col, orientation);
                placed = 1; //placed successfully 
            }
        }
         printf("Placed %s (%d cells) at (%d, %d) with %s orientation.\n", shipsNames[i], currentShipSize, row + 1, col + 1, orientation == 0 ? "horizontal" : "vertical");
        
    }
    printGrid(player->grid);
    printf("\n");
}

void placeShipsMedium(PLAYER* player)
//i want to implement for the bot to place the ships randomly but do not put them next to each others
{
    printf("%s, the bot is placing its ships.\n", player->name);
    const char *shipsNames[] = {"Carrier", "Battleship", "Destroyer", "Submarine"}; // all ships to avoid clustering if condition
    srand(time(NULL));

    for (int  i = 0; i < 4; ++i)
    {
        //bot will still choose the place randomly
        int currentShipeSize = 4 - i;
        int placed = 0;
        int row, col , orientation;

        while (!placed)
        {
            row = rand() % GRID_SIZE;
            col =  rand() % GRID_SIZE;
            orientation = rand() % 2;
            //lezem ykuno inboud + make sure eno manon had baad so badna helper function to check eza adjacent
    if (checkBounds(player, row, col, currentShipeSize, orientation) && !IsadjacentShips(player, row, col, currentShipeSize, orientation))
    {
        addShip(player, shipsNames[i], currentShipSize, row, col, orientation);
        placed = 1;
    }
}
    printf("Placed %s (%d cells) at (%d, %d) with %s orientation.\n", shipsNames[i], currentShipSize, row + 1, col + 1, orientation == 0 ? "horizontal" : "vertical");       
    }
    printGrid(player->grid);
    printf("\n");
}
int IsadjacentShips(PLAYER *player, int row, int col, int shipSize, int orientation){
    for(int i = 0, i < shipSize, i++){
        int r = row, c = col;
        if (orientation == HORIZONTAL)
        {
            r = row;
            c = col + i; //keep the row const and move across the columns
        }
        else if (orientation == VERTICAL)
        {
            r = row + i;
            c = col;
        }
        //calcule lal delta row li henne kel shi fawea aalaya w tahta w same lal column
        for (int deltarow = -1; deltarow <= 1 ; deltarow++)
        {
            for (int deltscol = -1 ; deltscol <= 1 ; deltscol++)
            {
              int checkRow = r + deltarow;
              int checkCol = c + deltscol;
              
              if (checkRow >= 0 && checkRow < GRID_SIZE && checkCol >= 0 && checkCol < GRID_SIZE)
              {
                if (player->grid[checkRow][checkCol] == 'X')
                {
                    return 1;
                }
              }
            }
        }    
    }
    return 0;
}

void placeShipsHard(PLAYER* player){
    printf("%s, the bot is placing its ships.\n", player->name);
    const char *shipsNames[] = {"Carrier", "Battleship", "Destroyer", "Submarine"}; // all ships to avoid clustering if condition
    srand(time(NULL));

    for(int i = 0 ; i < 4 ; ++i){
        int currentShipSize = 4 - i;
        int placed = 0;
        int row, col , orientation;
        while (!placed)
        {
            row = rand() % GRID_SIZE;
            col = rand() % GRID_SIZE;
            orientation = rand() % 2;

            int gapType = rand() % 2;
            int allowCornerPlace = rand() % 2;

             if (checkBounds(player, row, col, currentShipSize, orientation) && 
                !IsadjacentShips(player, row, col, currentShipSize, orientation) && 
                !isNearEdge(row, col, currentShipSize, orientation, gapType) &&
                !isInCorner(row, col, currentShipSize, orientation, allowCornerPlace))  
            {
                // Place the ship and mark it as placed
                addShip(player, shipsNames[i], currentShipSize, row, col, orientation);
                placed = 1;  // Successfully placed the ship
            }
        }
        printf("Placed %s (%d cells) at (%d, %d) with %s orientation.\n", shipsNames[i], currentShipSize, row + 1, col + 1, orientation == 0 ? "horizontal" : "vertical");
    }
    printGrid(player->grid);
    printf("\n");
}
int isNearEdge(int row, int col, int shipSize, int orientation, int gapType)
{
    // the gap between ships: small gap 0 vs large gap 1
    int minGap = gapType == 0 ? 1 : 3; 

    // check if the ship is too close to the grid's edges
    if (row <= minGap || col <= minGap || row + shipSize >= GRID_SIZE - minGap || col + shipSize >= GRID_SIZE - minGap)
    {
        return 1;
    }
    return 0; 
}
int isInCorner(int row, int col, int shipSize, int orientation, int allowCornerPlace)
{
    // If corner placement is not allowed, check if the ship is within the 5x5 corner area
    if (!allowCornerPlace)
    {
        if ((row == 0 && col == 0) ||  
            (row == 0 && col == GRID_SIZE - 1) || 
            (row == GRID_SIZE - 1 && col == 0) || 
            (row == GRID_SIZE - 1 && col == GRID_SIZE - 1))  
        {
            return 1;  // Ship is exactly in one of the corner square
        }
    }
    return 0;
}
ChatGPT said:
ChatGPT
To ensure that the bot places ships randomly, but avoids placing them next to each other, here's a more concise and correct version of the three functions you're working on:

placeShipsEasy Function
Purpose: Place ships randomly for the bot.
Changes: Same as the original but retains the easy random placement.
placeShipsMedium Function
Purpose: Place ships randomly with a check to avoid placing ships next to each other.
Changes:
Use IsadjacentShips() to ensure ships aren’t placed too close to each other.
IsadjacentShips Function
Purpose: Checks if a ship's proposed position is adjacent to another ship on the grid.
Fix: Corrected the for-loop syntax, and added checks for neighboring cells.
Fixed and Optimized Code
c
Copy code
void placeShipsEasy(PLAYER* player) {
    printf("%s, the bot is placing its ships.\n", player->name);
    const char* shipsNames[] = {"Carrier", "Battleship", "Destroyer", "Submarine"};
    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        int currentShipSize = 4 - i;
        int placed = 0;
        int row, col, orientation;

        while (!placed) {
            row = rand() % GRID_SIZE;
            col = rand() % GRID_SIZE;
            orientation = rand() % 2;

            if (checkBounds(player, row, col, currentShipSize, orientation)) {
                addShip(player, shipsNames[i], currentShipSize, row, col, orientation);
                placed = 1;
            }
        }

        printf("Placed %s (%d cells) at (%d, %d) with %s orientation.\n", shipsNames[i], currentShipSize, row + 1, col + 1, orientation == 0 ? "horizontal" : "vertical");
    }

    printGrid(player->grid);
    printf("\n");
}

void placeShipsMedium(PLAYER* player) {
    printf("%s, the bot is placing its ships.\n", player->name);
    const char* shipsNames[] = {"Carrier", "Battleship", "Destroyer", "Submarine"};
    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        int currentShipSize = 4 - i;
        int placed = 0;
        int row, col, orientation;

        while (!placed) {
            row = rand() % GRID_SIZE;
            col = rand() % GRID_SIZE;
            orientation = rand() % 2;

            if (checkBounds(player, row, col, currentShipSize, orientation) && !IsadjacentShips(player, row, col, currentShipSize, orientation)) {
                addShip(player, shipsNames[i], currentShipSize, row, col, orientation);
                placed = 1;
            }
        }

        printf("Placed %s (%d cells) at (%d, %d) with %s orientation.\n", shipsNames[i], currentShipSize, row + 1, col + 1, orientation == 0 ? "horizontal" : "vertical");
    }

    printGrid(player->grid);
    printf("\n");
}

int IsadjacentShips(PLAYER* player, int row, int col, int shipSize, int orientation) {
    for (int i = 0; i < shipSize; i++) {
        int r = row, c = col;
        if (orientation == HORIZONTAL) {
            r = row;
            c = col + i;
        } else {
            r = row + i;
            c = col;
        }

        // Check adjacent cells
        for (int deltaRow = -1; deltaRow <= 1; deltaRow++) {
            for (int deltaCol = -1; deltaCol <= 1; deltaCol++) {
                int checkRow = r + deltaRow;
                int checkCol = c + deltaCol;

                if (checkRow >= 0 && checkRow < GRID_SIZE && checkCol >= 0 && checkCol < GRID_SIZE) {
                    if (player->grid[checkRow][checkCol] == 'X') {
                        return 1; // Found an adjacent ship
                    }
                }
            }
        }
    }
    return 0; // No adjacent ships
}
Key Improvements:
placeShipsMedium now checks if the ship is adjacent to any other before placing it using IsadjacentShips().
IsadjacentShips loops through the cells around the proposed ship coordinates to check for collisions with existing ships.
Minor fixes and optimizations to ensure correctness.
This structure ensures the bot places ships without violating adjacency rules, making the placement more strategic in the medium difficulty level.






You said:
write me spec for each function
ChatGPT said:
ChatGPT
Here is a specification (spec) for each function in your code. This will help explain the purpose, inputs, outputs, and any important details for each function:

1. placeShipsEasy
Purpose:

This function places ships randomly on the grid for the bot. It uses random values for ship placement without any restrictions (except bounds checking).
Inputs:

PLAYER* player: A pointer to the player object, which contains the grid and other related data.
Outputs:

None (this function updates the player’s grid directly).
Prints placement details to the console.
Details:

Randomly selects a position (row, column) and orientation (horizontal or vertical) for each ship.
Calls checkBounds() to ensure the ship fits within the grid.
Places ships one by one from largest to smallest.
Prints out the coordinates and orientation of each placed ship.
2. placeShipsMedium
Purpose:

This function places ships randomly on the grid for the bot, but ensures that ships are not placed adjacent to each other.
Inputs:

PLAYER* player: A pointer to the player object, which contains the grid and other related data.
Outputs:

None (this function updates the player’s grid directly).
Prints placement details to the console.
Details:

Randomly selects a position (row, column) and orientation (horizontal or vertical) for each ship.
Calls checkBounds() to ensure the ship fits within the grid.
Calls IsadjacentShips() to ensure the selected position is not too close to other ships already placed.
Places ships one by one from largest to smallest.
Prints out the coordinates and orientation of each placed ship.
3. IsadjacentShips
Purpose:

This helper function checks if the newly proposed ship's placement is adjacent to any existing ships on the grid.
Inputs:

PLAYER* player: A pointer to the player object, which contains the grid and other related data.
int row: The starting row position for the ship.
int col: The starting column position for the ship.
int shipSize: The size of the ship being placed.
int orientation: The orientation of the ship (either horizontal or vertical).
Outputs:

int: Returns 1 if the ship's placement is adjacent to another ship, otherwise returns 0.
Details:

Iterates over each cell that the new ship would occupy.
For each cell, checks its adjacent cells (including diagonals) to see if they are already occupied by a ship ('X').
Returns 1 if any adjacent cell is occupied, otherwise returns 0.
4. addShip (Assumed Function)
Purpose:

Adds the ship to the grid at the specified position and orientation.
Inputs:

PLAYER* player: A pointer to the player object, which contains the grid and other related data.
const char* shipName: The name of the ship being placed (e.g., "Carrier", "Battleship").
int shipSize: The size of the ship being placed.
int row: The starting row position for the ship.
int col: The starting column position for the ship.
int orientation: The orientation of the ship (0 for horizontal, 1 for vertical).
Outputs:

None (this function updates the grid directly).
Details:

Updates the grid to mark the cells occupied by the ship.
Uses the orientation to place the ship horizontally or vertically.
5. checkBounds
Purpose:

This function checks if the ship can fit within the grid at the specified position and orientation.
Inputs:

PLAYER* player: A pointer to the player object, which contains the grid and other related data.
int row: The starting row position for the ship.
int col: The starting column position for the ship.
int shipSize: The size of the ship being placed.
int orientation: The orientation of the ship (horizontal or vertical).
Outputs:

int: Returns 1 if the ship fits within the bounds of the grid, otherwise returns 0.
Details:

Checks that the ship does not extend beyond the edges of the grid, considering its size and orientation.
6. printGrid
Purpose:

This function prints the current state of the player's grid.
Inputs:

char grid[GRID_SIZE][GRID_SIZE]: The grid containing the player's current state.
Outputs:

None (prints to the console).
Details:

Loops through the grid and prints each row, typically showing the state of the cells (e.g., 'X' for ships, '.' for empty).
7. isNearEdge
Purpose:

This helper function checks if the ship is too close to the edge of the grid, based on the specified gap type.
Inputs:

int row: The starting row position for the ship.
int col: The starting column position for the ship.
int shipSize: The size of the ship being placed.
int orientation: The orientation of the ship (horizontal or vertical).
int gapType: The type of gap, where 0 is a small gap and 1 is a large gap.
Outputs:

int: Returns 1 if the ship is too close to the edge based on the gap type, otherwise returns 0.
Details:

Ensures that the ship is placed with enough space from the grid's edges, according to the specified gap type.
8. isInCorner
Purpose:

This helper function checks if the ship is placed in one of the grid’s corners, where placement may be restricted.
Inputs:

int row: The starting row position for the ship.
int col: The starting column position for the ship.
int shipSize: The size of the ship being placed.
int orientation: The orientation of the ship (horizontal or vertical).
int allowCornerPlace: Flag indicating if corner placement is allowed (0 means not allowed).
Outputs:

int: Returns 1 if the ship is placed in a corner and corner placement is not allowed, otherwise returns 0.
Details:

If corner placement is not allowed, it checks if the ship starts at any of the four corners of the grid.
These specs cover the purpose, inputs, outputs, and details for each function. The functions are designed to facilitate random and strategic placement of ships on the grid with various difficulty levels (easy, medium, and hard).






You said:
*/
requires: a reference to currentPlayer hip name.
         Size of the ship.
         row, col ccordinates which are the starting position for the ship.
         Ship orientation (HORIZONTAL or VERTICAL).
          
effects: Marks the grid with 'X' for the ship's location.
         Updates the player's ship information.

*/
ChatGPT said:
ChatGPT
Here is the specification for the addShip function, based on the requirements and effects you provided:

addShip
Purpose:

To add a ship to the player's grid at the specified position and orientation, and update the player's ship information.
Requires:

A reference to currentPlayer (the player object), which contains the player's grid and other related data.
shipName: The name of the ship being placed (e.g., "Carrier", "Battleship").
shipSize: The size of the ship being placed (e.g., the number of cells the ship occupies).
row: The starting row coordinate for the ship.
col: The starting column coordinate for the ship.
orientation: The orientation of the ship (either HORIZONTAL or VERTICAL).
Effects:

Marks the grid with 'X' for the ship's location, occupying the appropriate cells based on the ship's size and orientation.
Updates the player's ship information, which may include adding the ship's name, size, and coordinates to the player's data structure for tracking ships.
If the ship is placed successfully, the grid will reflect the position of the ship on the playing board, and the player’s ship list will include this new ship's details.
Details:

The function will check the grid cells from the given starting position (row, col) based on the ship's orientation (horizontal or vertical).
It will place the 'X' character in the grid for each cell the ship occupies, ensuring the ship fits within the grid.
The player's ship information is updated, such as adding the ship's name, size, and its coordinates to the player's record of placed ships.





You said:
no  i mean write spec on same format i gave you
ChatGPT said:
ChatGPT
Got it! Here's the specification for the addShip function in the format you provided:

c
Copy code
/*
requires: A reference to currentPlayer (the player object).
          A reference to the ship's name.
          Size of the ship.
          Starting row (row) and column (col) coordinates for the ship's position.
          Ship orientation (HORIZONTAL or VERTICAL).
          
effects: Marks the grid with 'X' for the ship's location.
         Updates the player's ship information (name, size, coordinates).
         Increases the number of ships placed for the player.
*/





You said:
now do for anothehr func
ChatGPT said:
ChatGPT
Sure! Here’s the specification for the checkBounds function:

c
Copy code
/*
requires: A reference to currentPlayer (the player object).
          Row and column coordinates (row, col) for the ship’s starting position.
          Size of the ship (shipSize).
          Orientation of the ship (HORIZONTAL or VERTICAL).
          
effects: Checks if the ship fits within the grid boundaries.
         Returns -1 if the ship is out of bounds or overlaps with another ship.
         Returns 1 if the ship can be placed without violating grid boundaries.
*/





You said:
void placeShipsMedium(PLAYER* player)
//i want to implement for the bot to place the ships randomly but do not put them next to each others
{
    printf("%s, the bot is placing its ships.\n", player->name);
    const char *shipsNames[] = {"Carrier", "Battleship", "Destroyer", "Submarine"}; // all ships to avoid clustering if condition
    srand(time(NULL));

    for (int  i = 0; i < 4; ++i)
    {
        //bot will still choose the place randomly
        int currentShipeSize = 4 - i;
        int placed = 0;
        int row, col , orientation;

        while (!placed)
        {
            row = rand() % GRID_SIZE;
            col =  rand() % GRID_SIZE;
            orientation = rand() % 2;
            //lezem ykuno inboud + make sure eno manon had baad so badna helper function to check eza adjacent
    if (checkBounds(player, row, col, currentShipeSize, orientation) && !IsadjacentShips(player, row, col, currentShipeSize, orientation))
    {
        addShip(player, shipsNames[i], currentShipSize, row, col, orientation);
        placed = 1;
    }
}
    printf("Placed %s (%d cells) at (%d, %d) with %s orientation.\n", shipsNames[i], currentShipSize, row + 1, col + 1, orientation == 0 ? "horizontal" : "vertical");       
    }
    printGrid(player->grid);
    printf("\n");
}
ChatGPT said:
ChatGPT
Here’s the specification for the placeShipsMedium function:

c
Copy code
/*
requires: A reference to the player object (player) to place ships on their grid.
          A list of ship names (shipsNames), sizes, and their random placements.
          
effects: Randomly places ships on the player's grid with the following conditions:
         - Ships are placed within grid boundaries (checked by checkBounds function).
         - Ships are not placed adjacent to each other (checked by IsadjacentShips function).
         - Updates the player's grid and ship placement information.
         - Prints the placement of each ship along with its coordinates and orientation.
*/





You said:
void placeShipsHard(PLAYER* player){
    printf("%s, the bot is placing its ships.\n", player->name);
    const char *shipsNames[] = {"Carrier", "Battleship", "Destroyer", "Submarine"}; // all ships to avoid clustering if condition
    srand(time(NULL));

    for(int i = 0 ; i < 4 ; ++i){
        int currentShipSize = 4 - i;
        int placed = 0;
        int row, col , orientation;
        while (!placed)
        {
            row = rand() % GRID_SIZE;
            col = rand() % GRID_SIZE;
            orientation = rand() % 2;

            int gapType = rand() % 2;
            int allowCornerPlace = rand() % 2;

             if (checkBounds(player, row, col, currentShipSize, orientation) && 
                !IsadjacentShips(player, row, col, currentShipSize, orientation) && 
                !isNearEdge(row, col, currentShipSize, orientation, gapType) &&
                !isInCorner(row, col, currentShipSize, orientation, allowCornerPlace))  
            {
                // Place the ship and mark it as placed
                addShip(player, shipsNames[i], currentShipSize, row, col, orientation);
                placed = 1;  // Successfully placed the ship
            }
        }
        printf("Placed %s (%d cells) at (%d, %d) with %s orientation.\n", shipsNames[i], currentShipSize, row + 1, col + 1, orientation == 0 ? "horizontal" : "vertical");
    }
    printGrid(player->grid);
    printf("\n");
}
int isNearEdge(int row, int col, int shipSize, int orientation, int gapType)
{
    // the gap between ships: small gap 0 vs large gap 1
    int minGap = gapType == 0 ? 1 : 3; 

    // check if the ship is too close to the grid's edges
    if (row <= minGap || col <= minGap || row + shipSize >= GRID_SIZE - minGap || col + shipSize >= GRID_SIZE - minGap)
    {
        return 1;
    }
    return 0; 
}
int isInCorner(int row, int col, int shipSize, int orientation, int allowCornerPlace)
{
    // If corner placement is not allowed, check if the ship is within the 5x5 corner area
    if (!allowCornerPlace)
    {
        if ((row == 0 && col == 0) ||  
            (row == 0 && col == GRID_SIZE - 1) || 
            (row == GRID_SIZE - 1 && col == 0) || 
            (row == GRID_SIZE - 1 && col == GRID_SIZE - 1))  
        {
            return 1;  // Ship is exactly in one of the corner square
        }
    }
    return 0;
}
ChatGPT said:
ChatGPT
Here is the specification for the placeShipsHard function and its helper functions:

c
Copy code
/*
requires: A reference to the player object (player) to place ships on their grid.
          A list of ship names (shipsNames), sizes, and their random placements.
          
effects: Randomly places ships on the player's grid with the following conditions:
         - Ships are placed within grid boundaries (checked by checkBounds function).
         - Ships are not placed adjacent to each other (checked by IsadjacentShips function).
         - Ships are not placed too near the edges of the grid (checked by isNearEdge function).
         - Ships are not placed in the corners unless corner placement is allowed (checked by isInCorner function).
         - Updates the player's grid and ship placement information.
         - Prints the placement of each ship along with its coordinates and orientation.
*/

/*
requires: The starting coordinates of the ship (row, col), the ship's size, the orientation (HORIZONTAL or VERTICAL),
          and a gap type (small or large) to determine the minimum distance from the edges.
          
effects: Returns 1 if the ship is placed too close to the edge of the grid based on the gap type.
         Returns 0 otherwise.
*/

/*
requires: The starting coordinates of the ship (row, col), the ship's size, the orientation (HORIZONTAL or VERTICAL),
          and a flag indicating whether corner placement is allowed (allowCornerPlace).
          
effects: Returns 1 if the ship is placed in one of the grid's corners when corner placement is not allowed.
         Returns 0 otherwise.
*/





You said:
int IsadjacentShips(PLAYER *player, int row, int col, int shipSize, int orientation){
    for(int i = 0, i < shipSize, i++){
        int r = row, c = col;
        if (orientation == HORIZONTAL)
        {
            r = row;
            c = col + i; //keep the row const and move across the columns
        }
        else if (orientation == VERTICAL)
        {
            r = row + i;
            c = col;
        }
        //calcule lal delta row li henne kel shi fawea aalaya w tahta w same lal column
        for (int deltarow = -1; deltarow <= 1 ; deltarow++)
        {
            for (int deltscol = -1 ; deltscol <= 1 ; deltscol++)
            {
              int checkRow = r + deltarow;
              int checkCol = c + deltscol;
              
              if (checkRow >= 0 && checkRow < GRID_SIZE && checkCol >= 0 && checkCol < GRID_SIZE)
              {
                if (player->grid[checkRow][checkCol] == 'X')
                {
                    return 1;
                }
              }
            }
        }    
    }
    return 0;
}
ChatGPT said:
ChatGPT
Here is the specification for the IsadjacentShips function:

c
Copy code
/*
requires: A reference to the player object (player) containing the grid where ships are placed.
          The starting coordinates of the ship (row, col), the ship's size, and its orientation (HORIZONTAL or VERTICAL).

effects: Checks if the ship, when placed at the given coordinates (row, col) with the specified size and orientation,
         would be adjacent to another ship on the grid. A ship is considered adjacent if it is placed within one cell 
         in any direction (including diagonals).
         Returns 1 if any adjacent cells contain a ship ('X'), indicating the ship cannot be placed.
         Returns 0 if no adjacent cells contain a ship, indicating the ship can be placed.
*/
This function checks for adjacent ships in all directions around the proposed placement of a new ship. If any neighboring cell (including diagonals) contains a ship, it returns 1 to indicate that the placement is invalid. If no adjacent ships are found, it returns 0 to allow the ship placement.






You said:
#include "../headerFile.h"

void printSquareCoords(squareCoords *sc) {
    if (sc == NULL) {
        printf("Null squareCoords structure passed.\n");
        return;
    }

    printf("Number of coordinates: %d\n", sc->size);
    printf("Coordinates (row, column):\n");

    // Loop through and print each valid coordinate
    for (int i = 0; i < sc->size; i++) {
        printf("Coord %d: Row = %d, Column = %d\n", i + 1, sc->maxCoords[i].row, sc->maxCoords[i].col);
    }
}

int handleRadar(PLAYER *currentPlayer, PLAYER *opposingPlayer)
{

    //if bot already used all radarsweeps skip
    if(currentPlayer->radarSweep >=3 )
    {
        return ILLEGALMOVE;
    }
    //get what square to radar
    

    squareCoords squareCoord = getSquareCoord(currentPlayer->probGrid);
    
    printSquareCoords(&squareCoord);


    INPUT input;
    input.row=squareCoord.maxCoords->row;
    input.column = squareCoord.maxCoords->col;
    
    printf("The bot plays Radar %c%d \n", 97+input.column ,input.row+1);

    int moveResult = RadarSweep(currentPlayer,opposingPlayer,&input); //use radar
    
    //this means that the opponent didn't hide anything so we can trsut in the misses and hits of our radar
    
    if(opposingPlayer->smokeScreenCounter==0)
    {
        
        if(moveResult==SHIPSNOTFOUND)
        {
            for(int  i = 0; i < 4 ;++i )
            {
                currentPlayer->hitsAndMissesGrid[input.row][input.column]='o';
                updateCoordBySquare(&input,i);
            }
        }else if(moveResult ==SHIPSFOUND)
        {
             //update the probabilty of the four sqaures to -1 to represent the certanty that a ship might be there
            for(int  i = 0; i < 4 ;++i )
            {
                currentPlayer->probGrid[input.row][input.column]=-1;
                updateCoordBySquare(&input,i);
            }

           
           
        }

    }else
    {
        if(moveResult ==SHIPSFOUND)
        {
            for(int  i = 0; i < 4 ;++i )
            {
                currentPlayer->probGrid[input.row][input.column]=-1;
                updateCoordBySquare(&input,i);
            }
            //update the prob of the four squares
        }
    }
    return 1;
    

}

/*
requires: A reference to the currentPlayer object representing the player performing the radar sweep.
          A reference to the opposingPlayer object representing the opponent being targeted by the radar sweep.
          currentPlayer's radar sweep count and the radar target coordinates are properly initialized.

effects: Handles the bot's radar sweep. It checks if the bot has already used the maximum number of radar sweeps (3). 
         returns 1 if the radar sweep was successfully performed.
         returns ILLEGALMOVE if the player has already used the maximum number of radar sweeps.
*/

int handleRadar(PLAYER *currentPlayer, PLAYER *opposingPlayer)
{

    //if bot already used all radarsweeps skip
    if(currentPlayer->radarSweep >=3 )
    {
        return ILLEGALMOVE;
    }
    //get what square to radar
    

    squareCoords squareCoord = getSquareCoord(currentPlayer->probGrid);
    
    printSquareCoords(&squareCoord);


    INPUT input;
    input.row=squareCoord.maxCoords->row;
    input.column = squareCoord.maxCoords->col;
    
    printf("The bot plays Radar %c%d \n", 97+input.column ,input.row+1);

    int moveResult = RadarSweep(currentPlayer,opposingPlayer,&input); //use radar
    
    //this means that the opponent didn't hide anything so we can trsut in the misses and hits of our radar
    
    if(opposingPlayer->smokeScreenCounter==0)
    {
        
        if(moveResult==SHIPSNOTFOUND)
        {
            for(int  i = 0; i < 4 ;++i )
            {
                currentPlayer->hitsAndMissesGrid[input.row][input.column]='o';
                updateCoordBySquare(&input,i);
            }
        }else if(moveResult ==SHIPSFOUND)
        {
             //update the probabilty of the four sqaures to -1 to represent the certanty that a ship might be there
            for(int  i = 0; i < 4 ;++i )
            {
                currentPlayer->probGrid[input.row][input.column]=-1;
                updateCoordBySquare(&input,i);
            }

           
           
        }

    }else
    {
        if(moveResult ==SHIPSFOUND)
        {
            for(int  i = 0; i < 4 ;++i )
            {
                currentPlayer->probGrid[input.row][input.column]=-1;
                updateCoordBySquare(&input,i);
            }
            //update the prob of the four squares
        }
    }
    return 1;
    

}
