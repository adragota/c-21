/*
 * @author  Andrew Anca
 * @version 1.0.0
 * @date    2024-02-24
 *
 * This program will demonstrate the functionality of the popular casino game "21" through functional programming.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// calls to functions in program in order to keep main at TOF 
void print_array();
void swap();
void shuffle();


// populate a global array that simulate the cards needed for a game of "21"
int deck[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 
			   2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 
			   2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 
			   2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 };

// get the number of elemtents in our global array by dividing the total size of array in bytes by a single element of the array in bytes
int deck_length = sizeof(deck) / sizeof(deck[0]);


// funct: Main entry point of the program
// param: None
int main()
{
	print_array();

	shuffle(deck, deck_length);

	print_array();

	return 0;
}


// funct: Print the elements of an integer array to the console
// param: None
void print_array()
{
	// loop through the length of the array
	for (int i = 0; i < deck_length; i++)
	{
		// print each element of the array
		printf("%d ", deck[i]);
	}
	printf("\n");
}


// funct: Swap two integers anywhere in memory
// param: int *first_int	pointer to first integer
// param: int *second_int 	pointer to second integer
void swap(int *first_int, int *second_int)
{
	int temp;

	temp        = *first_int;
    *first_int  = *second_int;
    *second_int = temp;
}


// funct: Generate random permutations of an integer array
// param: int array[]	integer array
// param: int n			integer size of array
void shuffle(int array[], int n)
{
	// Use a different seed value so that we don't get same
    // result each time we run this program
	srand(time(NULL));

	// Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
	for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
 
        // Swap arr[i] with the element at random index
        swap(&array[i], &array[j]);
    }
}
