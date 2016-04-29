// Blackjack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <ctime>
#include <iostream>
using namespace std;
int blackjack();
#define DECK_SIZE 52 //Any "DECK_SIZE" will be replaced with the number 52
int deckArray[52] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
11, 12, 13, 14, 15, 16, 17, 18,
19, 20, 21, 22, 23, 24, 25, 26,
27, 28, 29, 30, 31, 32, 33, 34,
35, 36, 37, 38, 39, 40, 41, 42,
43, 44, 45, 46, 47, 48, 49, 50, 51 }; //Deck is preloaded with unique numbers ranging//from 0 -51. Each unique value represents a card//in a deck. 	//(Up to you to determine what each number represents
void shuffleDeck(int(&deck)[52]);
const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
const char *value[13] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
int numValue[13] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
int card = 0;

struct Cardtype
{

	int numValue;
	const char value;
	const char suit;

};

int main()
{
	int menu = 0;
	int end = 0;
	int chipAmount = 0;
	while (end != 1)
	{
		switch (menu)
		{
		case 0:
			cout << "**Blackjack** \n[1] Start Game \n[2] Insert Chips \n[3] Withdraw Chips \n\n";
			cin >> menu;
			break;

		case 1:
			blackjack();
			end = 1;
			break;
		case 2:
			cout << "Insert Chips: $";
			cin >> chipAmount;
			cout << "\n";
			menu = 0;
			break;
		case 3:
			cout << "Withdraw Chips ($" << chipAmount << "): $";
			cout << "\n";
			menu = 0;
			break;

		}
	}

}

void dealCard()
{
	Cardtype pcard1;
	Cardtype pcard2;
	Cardtype dcard1;
	Cardtype dcard2;

	pcard1.numValue = numValue[deckArray[card] % 13];
	pcard1.value = value[deckArray[card] % 13];
	pcard1.suit = suit[deckArray[card] % 4];
	

}

int blackjack()
{
	shuffleDeck(deckArray);
	return 0;
}

/*
shuffle_deck: The order of the cards in the deck
must become random to simulate "shuffling". The
deck array must be randomized.
To simulate shuffling, two "cards" are swapped with each other
for 52 times (deck size).
Question: Is this "random" enough?
Optional: For more "randominess" you can increase the for-loop iteration
*/
void shuffleDeck(int(&deck)[52])
{
	srand(time(NULL));//get a new seed everytime the shuffle function is called
	for (int i = 0; i < DECK_SIZE; i++) // loops 52 times
	{
		// Pick two random card indexes in the deck
		int first_card_index = rand() % 52; // 0 to 51
		int second_card_index = rand() % 52;
		//swap the values in the two indexes
		int temp_card = deck[first_card_index];
		deck[first_card_index] = deck[second_card_index];
		deck[second_card_index] = temp_card;
	}
}
