#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include "TicTacToe.h"
#include "Poker.h"
using namespace std;

int main()
{
	string name;
	cout << "Hello! Please enter your name!" << endl;
	cin >> name;

	cout << "Nice to meet you !  " << name << endl << endl;
	cout << "What do you want to play ?( 1 -- TicTacToe £¬ 2 -- Poker£»£© " << endl << endl;
	int op ;
	cin >> op;
	system("cls");
	if (op == 1)
	{
		TicTacToe t(name);
		t.play();
	}

	else if (op == 2)
	{
		Poker p(name);
		p.Play();
	}

	else
		cout << "Error£¡ Please reselect!" << endl;
	
	
    system("pause");
	return 0;
}