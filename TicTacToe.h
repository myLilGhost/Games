#include <iostream>
#include <fstream>
#include <vector>
#include "Games.h"
using namespace std;

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe : public Games {
public:
	TicTacToe(const string& name);
	void play();
	
private:
	int rows = 3;
	int cols = 3;
	int op;
	int board[3][3] = { 0 };
	int score[3][3];
	bool win1_flag = false; //���1��ʤ��־λ
	bool win2_flag = false; //���Ի�ʤ��־λ
	void start();   //��ʼ��Ϸ
	void drawChessboard();  //��ӡ����
	void game_start();
	void setScores( );

	void putChess();        //�������
	void getChess();        //�������� 
	void judge();           //�ж���Ӯ
	void result();
};

#endif