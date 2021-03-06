// Author: Danilo Scodellaro
// Date created: 12-APR-2014
// cs1911 lab06
// DESCRIPTION
// Program  reads a vector of 10 integers then prints the minimum, 
// maximum & mean of the integers

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 10

int main(int argc, char const *argv[]) {
    double vector[SIZE] = {0};   // 1D array of 10 integers
    double minimum = 0;        // Smallest integer of the array
    double maximum = 0;        // Largest vector of the array
    double total = 0;    // Sum of all integers in array
    double mean = 0;         // Average of vectors
    int i, j;     // Loop counters      

    printf("Enter vector of 10 numbers: ");
    // Loop to input integers into array
    for (i = 0; i < SIZE; i++) {
        if (scanf("%lf", &vector[i]) == 0) {
            printf("Sorry I couldn't read enough numbers\n");
            return EXIT_FAILURE;
        }
    }
    
    // Set min and max to first integer of array to make loop work
    minimum = vector[0];
    maximum = vector[0];

    // Loop to determine minimum, maximum and total values
    for (j = 0; j < SIZE; j++) {
        if (vector[j] < minimum) {
            minimum = vector[j];
        }
        if (vector[j] > maximum) {
            maximum = vector[j];
        }
        total = total + vector[j];
    }

    // Determine mean of array
    mean = (total / SIZE);

    // Print vector statistics
    printf("Minimum vector value is %.0lf\n", minimum);
    printf("Maximum vector value is %.0lf\n", maximum);
    printf("Average vector value is %.1lf\n", mean);

    return EXIT_SUCCESS;
}