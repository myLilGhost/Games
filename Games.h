#ifndef GAMES_H
#define GAMES_H

#include <iostream>
#include <fstream>
using namespace std;

class Games {
public:
	Games(const string& name)
	{
		setPlayerName(name);
		plWin = 0;
		pcWin = 0;
		total = 0;

	}

	void setPlayerName(const string& name)
	{
		player = name;
	}

	string getPlayer() const
	{
		return player;
	}

	void setPlWin( )
	{
		plWin++;
	}

	int getPlWin() const
	{
		return plWin;
	}

	void setPcWin(  )
	{
		pcWin++;
	}

	int getPcWin() const
	{
		return pcWin;
	}

	void setTotal( )
	{
		total++;
	}

	int getTotal() const
	{
		return total;
	}

	
	void print()
	{
		ofstream out("d:\\games");
		if (!out)
		{
			cout << "Cannot open the grade file." << endl;
			
		}
		out << player << ", Welcome to check out the results! " << endl << endl;
		out << "Total play times:" << getTotal()  << endl;
		out << "You won:" << getPlWin() << endl;
		out << "Pc won:" << getPcWin() << endl;
		out << "Tie:" << getTotal() - getPlWin() - getPcWin() << endl;
		


		if (getPlWin() > getPcWin() )
		{
			out << "Congratulations on your victory!" << endl;
		}

		else if (getPlWin() < getPcWin() )
		{
			out << "Sorry! You lost!" << endl;
		}

		else if (getPlWin() == getPcWin() )
		{
			out << "That's good! A draw!" << endl;
		}
		out.close();


	}

private:
	string  player;
	int plWin;
	int pcWin;
	int total;
};
#endif
