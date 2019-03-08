#include <ctime>
#include <iostream>
#include <string>

using namespace std;

#define DECK_SIZE 52
#define SAMPLE_SIZE 100000000

// Function which shuffle and print the array 
void shuffle(int card[])
{
	// Initialize seed randomly 
	srand(time(0));

	for (int i = 0; i<DECK_SIZE; i++)
	{
		// Random for remaining positions. 
		int r = i + (rand() % (DECK_SIZE - i));

		swap(card[i], card[r]);
	}
}

int main()
{
	int deck[DECK_SIZE];		// deck buffer
	int results[SAMPLE_SIZE];	// result set

	// Generate a deck where 0-3 are four aces
	for (int i = 0; i < DECK_SIZE; i++)
		deck[i] = i;
	
	for (int i = 0; i < SAMPLE_SIZE; i++)
	{
		// Shuffle deck
		shuffle(deck);

		int j = 0;
		// Loop until getting the first ace
		while (deck[j] != 0 && deck[j] != 1
			&& deck[j] != 2 && deck[j] != 3)
			j++;
		results[i] = j;
	}

	float sum = 0;
	for (int i = 0; i < SAMPLE_SIZE; i++)
		sum += results[i];

	cout << "How many cards are required to produce the first ace: "
		<< sum / SAMPLE_SIZE << endl;

    return 0;
}
