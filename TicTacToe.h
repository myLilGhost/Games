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
	bool win1_flag = false; //玩家1获胜标志位
	bool win2_flag = false; //电脑获胜标志位
	void start();   //开始游戏
	void drawChessboard();  //打印棋盘
	void game_start();
	void setScores( );

	void putChess();        //玩家下棋
	void getChess();        //电脑下棋 
	void judge();           //判断输赢
	void result();
};

#endif