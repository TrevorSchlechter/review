// CSC 250 - SP 2022 - Zwach
// Trevor Schlechter

#include <stdio.h>  // input/output
#include <stdlib.h> // random functions, exit
#include <time.h>   // time (used for seed sometimes)

int findMax(int [], int); // returns index of max value
int findMin(int [], int); // returns index of min value
int findSum(int [], int); // returns sum of array
int IndMin(int [], int);
int IndMax(int [], int);

int main()
{
    // Declare variables
    int size;
    int seed;
    int index;
    int avg;

    // Determine how many numbers to generate (no more than 1000)
    do {
    printf("Enter quantity: ");
    scanf("%d", &size);
    } while (size >= 1000);

    // Read a seed from user
    printf("Enter a seed: ");
    scanf("%d", &seed);

    // If seed is >= 0, use that seed; else use time
    if (seed >= 0) {
        srand(seed);
    }   else {
        srand(time(0));
    }

    // Fill array with random values in range 0-299
    int arr[size];
    for (int j = 0; j < size; j++) {
        arr[j] = rand() % 300;
    }

    // Use functions and arithmetic to get min, max, sum, and average (integer)
    for (int k = 0; k < size; k++) {
        avg += arr[k];
    }
    avg = avg / size;

    // Print min and max with index, sum, and average
    printf("Maximum: %3d Index: %3d\n", findMax(arr, size), IndMax(arr, size));
    printf("Minimum: %3d Index: %3d\n", findMin(arr, size), IndMin(arr, size));
    printf("Average: %6d\n", avg);
    printf("    Sum: %6d\n", findSum(arr, size));

    // Print the contents of the array
    printf(" Index | Value\n");
    printf("-------+------\n");
    for (int i = 0; i < size; i++) {
        printf("%6d | %3d\n", index, arr[i]);
        index++;
    }
    return 0;
}

int findSum(int arr[], int count)
{
    // Return the sum of the array contents
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += arr[i];
    }
return sum;
}

int findMax(int arr[], int count)
{
    // Return the index of the maximum value
    int max = arr[0];
    for (int i = 0; i < count; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
return max;
}

int findMin(int arr[], int count)
{
    // Return the index of the minimum value
    int min = arr[0];
    for (int i = 0; i < count; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
return min;
}

int IndMin(int arr[], int count)
{
    int min = arr[0];
    int index = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] < min) {
            min = arr[i];
            index = i;
        }
    }
return index;
}

int IndMax(int arr[], int count) 
{
    int max = arr[0];
    int index = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }
return index;
}
