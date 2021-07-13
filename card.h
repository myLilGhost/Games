#include <iostream>
#include<iomanip>
#include <cstdlib>
#include<ctime>
using namespace std;
#ifndef CARD_H
#define CARD_H

class Card
{
public:
	const char* suit[4] = { "Hearts","Diamonds","Clubs","Spades" };
	const char* face[13] = { "Ace","Two","Three","Four","Five","Six",
			  "Seven","Eight","Nine","Ten","Jacke","Queen","King" };
	Card()
	{
		int face1, suit1;

		for (face1 = 0; face1 <= 3; face1++)
		{
			for (suit1 = 0; suit1 <= 12; suit1++)
			{
				deck[face1][suit1] = 0;
			}
		}
	}
	void shuffle()
	{
		int row;
		int column;
		int card = 1;
		srand((unsigned int)time(0));

		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j <= 12; j++)
			{
				deck[i][j] = card;
				card++;
			}
		}

		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j <= 12; j++)
			{
				row = rand() % 4;
				column = rand() % 13;
				int k = deck[i][j];  //½«deck[i][j]Óëdeck[row][column]½»»» 
				deck[i][j] = deck[row][column];
				deck[row][column] = k;
			}
		}
	}
	void deal()
	{
 
			for (int row = 0; row <= 3; row++)
			{
				
				for (int column = 0; column <= 12; column++)
				{
					if (deck[row][column] == 1 || deck[row][column] == 2 || deck[row][column] == 3 || deck[row][column] == 4 || deck[row][column] == 5)
					{
						cout << "   " << face[column]
							<< " of " << "   " << suit[row] << endl;
						
					}

				}

			}
		
	}
	int getSuit(int card)
	{
		
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j <= 12; j++)
			{
				if (deck[i][j] == card)
					suits = i + 1;
			}
		}
		return suits;
	}
	int getFace(int card)
	{
	
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j <= 12; j++)
			{
				if (deck[i][j] == card)
					faces = j + 1;
			}
		}
		return faces;
	}
	
private:
	int deck[4][13];
	int suits;
	int faces;
	
};

#endif









