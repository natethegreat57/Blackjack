// Blackjack.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <ctime>
#include <iostream>
#define DECK_SIZE 52 //Any "DECK_SIZE" will be replaced with the number 52
using namespace std;
int blackjack();
int placeBet(double&);
void shuffleDeck(int(&deck)[52]);
int deckArray[52] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
11, 12, 13, 14, 15, 16, 17, 18,
19, 20, 21, 22, 23, 24, 25, 26,
27, 28, 29, 30, 31, 32, 33, 34,
35, 36, 37, 38, 39, 40, 41, 42,
43, 44, 45, 46, 47, 48, 49, 50, 51 }; //Deck is preloaded with unique numbers ranging from 0 -51. Each unique value represents a card
//in a deck. 
//(Up to you to determine what each number represents 
const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
const char *value[13] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack",
"Queen", "King" };
int numValue[13] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
int main()
{
	int chips = 0;
	int menu = 0;
	int end = 0;
	double chipAmount = 0;
	double withdraw = 0;
	int bet = 0;
	while (end != 1)
	{
		switch (menu)
		{
		case 0:
			cout << "***Blackjack*** \nAmount of chips: $" << chipAmount << "\n[1] Start Game \n[2] Insert Chips \n[3] Withdraw Chips \n[4] Exit \n\n";
			cin >> menu;
			break;
		case 1:
			bet = placeBet(chipAmount);
			switch (blackjack())
			{
			case 0:
				break;
			case 1:
				chipAmount = chipAmount - bet;
				break;
			case 2:
				chipAmount = chipAmount + bet;
				break;
			case 3:
				chipAmount = chipAmount + bet*1.5;
				break;
			}
			menu = 0;
			break;
		case 2:
			cout << "Insert Chips: $";
			cin >> chips;
			chipAmount = chipAmount + chips;
			cout << "\n";
			menu = 0;
			break;
		case 3:
			cout << "Withdraw Chips: $";
			cin >> withdraw;
			chipAmount = chipAmount - withdraw;
			withdraw = 0;
			cout << "\n";
			menu = 0;
			break;
		case 4:
			end = 1;
			break;
		}
	}
}

int blackjack()
{
	int pace = 0;
	int dace = 0;
	int card = 0;
	int pscore = 0;
	int dscore = 0;
	int hitStand = 0;
	int loop = 0;
	int bust = 0;
	shuffleDeck(deckArray);
	cout << "Player's Cards:\n" << value[deckArray[0] % 13] << " of " << suit
		[deckArray[0] % 4] << "\n" << value[deckArray[2] % 13] << " of " << suit[deckArray
		[2] % 4] << "\n";
	pscore = numValue[deckArray[0] % 13] + numValue[deckArray[2] % 13];
	cout << "Your Score: " << pscore << "\n\n";
	if (pscore == 21)
	{
		cout << "BLACKJACK!\n\n";
		bust = 3;
		return bust;
	}
	cout << "Dealer's Cards:\n" << value[deckArray[1] % 13] << " of " << suit
		[deckArray[1] % 4] << "\nCard 2 \n\n";
	dscore = numValue[deckArray[1] % 13] + numValue[deckArray[3] % 13];
	card = card + 4;

	if (numValue[deckArray[0] % 13] == 11)
		pace++;
	if (numValue[deckArray[2] % 13] == 11)
		pace++;
	while (loop == 0)
	{
		switch (hitStand)
		{
		case 0:
			cout << "What would you like to do:\n[1] Hit \n[2] Stand\n";
			cin >> hitStand;
			cout << "\n";
			break;
		case 1:
			cout << value[deckArray[card] % 13] << " of " << suit[deckArray[card] % 4]
				<< "\n";
			pscore = pscore + numValue[deckArray[card] % 13];
			if (numValue[deckArray[card] % 13] == 11)
				pace++;
			if (pscore > 21)
			{
				if (pace >= 1)
				{
					pscore = pscore - 10;
					pace--;
				}
				else
				{
					bust = 1;
					cout << "Your Score: " << pscore << "\n";
					cout << "BUST\n\n";
					return bust;
				}
			}
			cout << "Your Score: " << pscore << "\n\n";
			card++;
			hitStand = 0;
			break;
		case 2:
			loop = 1;
			break;
		}
	}
	cout << "Dealer's Cards:\n" << value[deckArray[1] % 13] << " of " << suit
		[deckArray[1] % 4] << "\n" << value[deckArray[3] % 13] << " of " << suit
		[deckArray[3] % 4] << "\n";

	if (numValue[deckArray[1] % 13] == 11)
		dace++;
	if (numValue[deckArray[3] % 13] == 11)
		dace++;

	while (dscore < 17)
	{
		cout << value[deckArray[card] % 13] << " of " << suit[deckArray[card] % 4] <<
			"\n";
		if (numValue[deckArray[card] % 13] == 11)
			dace++;
		dscore = dscore + numValue[deckArray[card] % 13];
		card++;
	}

	if (dscore > 21)
	{
		if (dace >= 1)
		{
			dscore = dscore - 10;
			while (dscore < 17)
			{
				cout << value[deckArray[card] % 13] << " of " << suit[deckArray[card]
					% 4] << "\n";
				if (numValue[deckArray[card] % 13] == 11)
					dace++;
				dscore = dscore + numValue[deckArray[card] % 13];
				card++;
			}
			dace--;
		}
		else
		{
			bust = 2;
			cout << "Dealer's Score: " << dscore << "\n";
			cout << "YOU WIN\n\n";
			return bust;
		}
	}
	if (pscore == dscore)
	{
		bust = 0;
		cout << "TIE\n";
		return bust;
	}
	if (pscore > dscore)
	{
		bust = 2;
		cout << "Dealer's Score: " << dscore << "\n";
		cout << "YOU WIN\n\n";
		return bust;
	}
	else
	{
		bust = 1;
		cout << "Dealer's Score: " << dscore << "\n";
		cout << "DEALER WINS\n\n";
		return bust;
	}
}

int placeBet(double &k)
{
	int bet = 0;
	cout << "Place your bet: $";
	cin >> bet;
	cout << "\n";
	while (bet > k)
	{
		cout << "Not enough chips\nPlace your bet: $";
		cin >> bet;
		cout << "\n";
	}
	return bet;
} /*
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