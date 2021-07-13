#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include "Games.h"
#include "card.h"
using namespace std;

#ifndef POKER_H
#define POKER_H


//一个对子 10  两个对子 20  三张同号 15 四张同号 30  同花 50 同顺 50
class Poker : public Games {
public:
	Poker(const string& name);
	void Play();

private:
	void face();
	void duizi();
	void tonghao();
	void tonghua();
	void tongshun();
	void result();
	void setPlScore(int i);
	void setPcScore(int i);
	int getPlScore() const;
	int getPcScore() const;
	Card pl;
	Card pc;
	int pcScore;
	int plScore;
};
#endif
