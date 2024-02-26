/*
 * @author  Andrew Anca
 * @version 1.0.0
 * @date    2024-02-24
 *
 * This program will demonstrate the functionality of the popular casino game "21" through functional programming.
 */

#include <stdio.h>

void print();

// main entry point of the program
int main()
{
	print();

	return 0;
}

// user-defined data type to represent a "Card".
struct Card
{
	// members
	char Suit;
	char Rank;
};

void print()
{
	struct Card deck[52];

	for (int i = 0; i < 52; i++)
	{
		deck[i].Rank = i % 13 + 1;

		if (deck[i].Rank == 1)
		{
			deck[i].Rank = 'A';
		}
		 else if(deck[i].Rank >= 2 && deck[i].Rank <11)
        {
            deck[i].Rank = deck[i].Rank + '0'; // Convert numeric ranks to characters
        }
		else if (deck[i].Rank == 11)
		{
			deck[i].Rank = 'J';
		}
		else if (deck[i].Rank == 12)
		{
			deck[i].Rank = 'Q';
		}
		else if (deck[i].Rank == 13)
		{
			deck[i].Rank = 'K';
		}

		if (i < 13)
		{
			deck[i].Suit = 'S';
		}
		else if (i < 26)
		{
			deck[i].Suit = 'H';
		}
		else if (i < 39)
		{
			deck[i].Suit = 'C';
		}
		else
		{
			deck[i].Suit = 'D';
		}
	}

	// print the deck
	for (int i = 0; i < 52; i++)
	{
		printf("Card Suit: %c Card Rank: %c\n", deck[i].Suit, deck[i].Rank);
	}
}
