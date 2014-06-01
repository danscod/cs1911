
// add your header comment here

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
// put any extra includes here, but don't delete the ones above

#define SIZE    4

// add your function_prototypes here 


// The functions moveLeft, moveRight, moveUp, moveDown
// return -1 if the specified moving of numbers  is not possible.
// Otherwise they move the numbers as indicated and return 
// the change to the score from combining adjacent identical numbers.
// They return 0 if no numbers were combined.

int moveLeft(int board[SIZE][SIZE]) {
    return -1;
}

int moveRight(int board[SIZE][SIZE]) {
    return -1;
}

int moveDown(int board[SIZE][SIZE]) {
    return -1;
}

int moveUp(int board[SIZE][SIZE]) {
    return -1;
}

// gameOver returns 0 iff it is possible to make a move on the board
// It returns 1 otherwise.

int gameOver(int board[SIZE][SIZE]) {
    return 0;
}

// boardContains2048 returns 1 iff the board contains 2048.
// It returns 0 otherwise.

int boardContains2048(int board[SIZE][SIZE]) {
    return 0;
}

// printBoard displays the board.

void printBoard(int board[SIZE][SIZE]) {
}


// readBoard attempts to read SIZE*SIZE integers into array board
// it returns how many integers actually were read

int readBoard(int board[SIZE][SIZE]) {
    return 0;
}

//
// add your functions here
//

//
// You do not need to modify the code below here.
//
// If you wish to modify the code below, you have
// misunderstood the assignment specification
//

void printHelp(void);
void insertNewNumber(int board[SIZE][SIZE]);

int main(int argc, char *argv[]) {
    int board[SIZE][SIZE] = {{0}};
    int c, score, moveScore, gameWon, numbersRead;
    unsigned int seed;
    
    // initialize random generator with command-line argument if provided
    // or with current time
    if (argc > 1){
        seed = atoi(argv[1]);
    } else {
        seed = time(0);
    }
    srand(seed);

    printf("Enter %d numbers making up initial board:\n", SIZE * SIZE);
    numbersRead = readBoard(board);
    if (numbersRead != SIZE * SIZE) {
        printf("Warning readBoard read only %d numbers\n", numbersRead);
    }

    printf("Repeat game by running: %s %u\n", argv[0], seed);
    printHelp();
    score = 0;
    gameWon = 0;
    while (gameOver(board) == 0) {
        printf("\n");
        printBoard(board);
        printf("Your score is %d.\n", score);   
        if (gameWon == 0 && boardContains2048(board)) {
            gameWon = 1;
            printf("Congratulations you've won the game - q to quit or you can keep going\n");
        }
        printf("> ");
        
        c = getchar();
        while (c != EOF && isspace(c)) {
            c = getchar();
        }
        
        printf("\n");
        
        if (c == EOF || c == 'q' || c == 'Q') {
            printf("Good bye - your final score was %d.\n", score); 
            return 0;
        }

        c = tolower(c);
        if (!strchr("hjklaswd", c)) {
            printHelp();
        } else {
            moveScore = 0;
            if (c == 'h' || c == 'a') {
                moveScore = moveLeft(board);
            } else if (c == 'j' || c == 's') {
                moveScore = moveDown(board);
            } else if (c == 'k' || c == 'w') {
                moveScore = moveUp(board);
            } else if (c == 'l' || c == 'd') {
                moveScore = moveRight(board);
            }

            if (moveScore == -1) {
                printf("%c is not a legal move in the current position.\n", c); 
            } else {
                insertNewNumber(board);
                score = score + moveScore;
            }
        } 
    }
    printBoard(board);
    printf("Game over - your final score was %d.\n", score);    
    return 0;
}

// print a help message
// do not change this function

void
printHelp(void) {
    printf("Enter h or a for left, j or s for down, k or w for up, l or d for right, q to quit\n");
}


// add a new number to the board
// it will either be a 2 (90% probability) or a 4 (10% probability)
// do not change this function

void insertNewNumber(int board[SIZE][SIZE]) {
    int row, column;
    int index, availableSquares = 0;
    
    // count vacant squares
    for (row = 0; row < SIZE; row = row + 1) {
        for (column = 0; column < SIZE; column = column + 1) {
            if (board[row][column] == 0) {
                availableSquares = availableSquares + 1;
            }
        }
    }

    if (availableSquares == 0) {
        printf("Internal error no available square\n");
        exit(1);
    }

    // randomly pick a vacant square
    index = rand() % availableSquares;
    for (row = 0; row < SIZE; row = row + 1) {
        for (column = 0; column < SIZE; column = column + 1) {
            if (board[row][column] == 0) {
                if (index == 0) {
                    if (rand() % 10 == 0) {
                        board[row][column] = 4;
                    } else {
                        board[row][column] = 2;
                    }
                    return;
                }
                index = index - 1;
            }
        }
    }
}
