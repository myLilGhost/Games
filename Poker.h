#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include "Games.h"
#include "card.h"
using namespace std;

#ifndef POKER_H
#define POKER_H


//һ������ 10  �������� 20  ����ͬ�� 15 ����ͬ�� 30  ͬ�� 50 ͬ˳ 50
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
