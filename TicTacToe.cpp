#include "TicTacToe.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "TicTacToe.h"
using namespace std;

TicTacToe::TicTacToe(const string& name)
	:Games(name)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			score[i][j] = 10;

		}
	}
}

void TicTacToe::play()
{
	int a;
	
	start();
	drawChessboard();
	game_start();

	cout << "Do you want another round? ( 1 -- Yes , 2 -- No )" << endl;
		
	cin >> a;
	if (a == 1)
	{
		system("cls");
		play();
	}
	else
	{
		system("cls");
		print();
		cout << "结果请在games.file查看" << endl;
	}
		
}

void TicTacToe::start()
{
	
	cout << "Welcome to TicTacToe!" << endl <<endl;
	cout << "Please select te order of pirority（ 1 -- first； 2 -- last；）" << endl;
	cin >> op;
	system("cls");
}

void TicTacToe::drawChessboard()
{
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << board[i][j];
			if (j < cols - 1)
				cout << " |";
		}
		cout << endl;
		if (i < rows - 1)
			cout << "--+--+--" << endl;
	}
	cout << endl;
}

void TicTacToe::setScores( )
{
	int n1 = 0;    //记录电脑已经下了几个棋
	int n2 = 0;    //记录玩家已经下了几个棋
	vector <pair<int, int>> pc_position; //pair类型里存放 <row,col>
	vector <pair<int, int>> pl_position;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			if (board[i][j] == 2)
			{
				n1++;
				pc_position.push_back(pair<int, int>(i, j));
			}
				
			    
			if (board[i][j] == 1)
			{
				n2++;
				pl_position.push_back(pair<int, int>(i, j));
			}
		}
	}

	
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (board[row][col] != 0)
			score[row][col] = 0;

			
			if (score[row][col] != 0)
			{
				for (int i = 0; i < n1; i++)
				{
					//该棋子位置如果能和电脑的棋子连成两个 得30分
					if ((row == pc_position[i].first && col + pc_position[i].second != 2) || (col == pc_position[i].second && row + pc_position[i].first != 2) || (row == pc_position[i].second && pc_position[i].second == pc_position[i].first && row + pc_position[i].first != 2))
						score[row][col] > 30 ? score[row][col] += 0 : score[row][col] = 30;
				}

				for (int i = 0; i < n1; i++)
				{
					for (int j = i + 1; j < n1; j++)
					{
						//该棋子如果能和的棋子连成三个 得50分
						if ((row == pc_position[i].first && row == pc_position[j].first) || (col == pc_position[i].second && col == pc_position[j].second) || (row + col == 2 && pc_position[i].first + pc_position[i].second == 2 && pc_position[j].first + pc_position[j].second == 2))
							score[row][col] = 50;
					}
				}

				for (int i = 0; i < n2; i++)
				{
					//该棋子位置如果能和玩家的棋子连成两个 得20分
					if ((row == pl_position[i].first && col + pl_position[i].second != 2) || (col == pl_position[i].second && row + pl_position[i].first != 2) || (row == pl_position[i].second && pl_position[i].second == pl_position[i].first && row + pl_position[i].first != 2))
						score[row][col] > 20 ? score[row][col] += 0 : score[row][col] = 20;
				}

				for (int i = 0; i < n2; i++)
				{
					for (int j = i + 1; j < n2; j++)
					{
						//该棋子位置如果能和玩家的棋子连成三个 得40分
						if ((row == pl_position[i].first && row == pl_position[j].first) || (col == pl_position[i].second && col == pl_position[j].second) || (row + col == 2 && pl_position[i].first + pl_position[i].second == 2 && pl_position[j].first + pl_position[j].second == 2))
							score[row][col] > 40 ? score[row][col] += 0 : score[row][col] = 40;
					}
				}
			}
	
		}
	}

}


void TicTacToe::putChess()
{
	int row0, col0;
	cin >> row0 >> col0;
	while (board[row0 - 1][col0 - 1] != 0)  //判断该位置是否已有棋子,或不存在
	{
		cout << "Errror! Please reenter!" << endl << endl;
		cout << "Please enter the number of lines(1-3):" << endl;
		cin >> row0 >> col0;   //重新输入位置
	}
	board[row0 - 1][col0 - 1] = 1;  //棋盘中放置玩家1棋子
	setScores();

}

void TicTacToe::getChess()
{
	int row = 0, col = 0;
	int max = score[0][0];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (max < score[i][j])
			{
				max = score[i][j];
				row = i;
				col = j;
			}
		}
			
	}
	board[row][col] = 2;
	setScores();
}



void TicTacToe::game_start()   //游戏开始
{
	int n = 0;            //总3*3=9个输入位,用于判断是否填完
	bool flag = false;     //玩家切换标志位
	
	cout << "Game start！" << endl << endl;

	while (n < 9 && win1_flag == false && win2_flag == false) //未填完,未分出胜负则继续游戏
	{
		switch (op)
		{
		case 1:
			if (flag == false)
			{              //切换到玩家1
				cout << "The player : " << getPlayer() << "  input:  ( Please enter the number of lines(1-3) )" << endl;
				putChess();                  //玩家输入棋子位置
				flag = true;
			}
			else
			{
				cout << "The pc input：" << endl;
				getChess();
				flag = false;
			}
			judge();      //判断胜负
			drawChessboard();            //打印出棋盘
			n++;               //棋盘又添了一枚棋子
			break;
		case 2:
			if (flag == false)
			{
				cout << "The pc input：" << endl;
				getChess();
				flag = true;                //下一步是玩家2
			}
			else
			{                             //切换到玩家2
				cout << "The player" << getPlayer() << "input:Please enter the number of lines(1-3)" << endl;
				putChess();                   //玩家2输入棋子位置
				flag = false;               //下一步是玩家1   
			}
			judge();      //判断胜负
			drawChessboard();
			n++;               //棋盘又添了一枚棋子
			break;
		}
	}

	result();
	
}

void TicTacToe::judge()       //判断胜负
{
	for (int i = 0; i < rows; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 0)    //判断横方向满3个相同的棋子
		{
			
			if (board[i][0] == 1)
			{
				win1_flag = true;
			
			}
		    else
			{
				win2_flag = true;
				
			}

			
				   
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0)    //判断纵方向满3个相同的棋子
		{
			
			if (board[0][i] == 1)     //判断是玩家的棋子还是电脑
			{
				win1_flag = true;
				Games::setPlWin( );
			}
			else
			{
				win2_flag = true;
				Games::setPlWin( );
			}
			
		}
		if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0)   //判断斜方向满3个相同的棋子
			|| (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != 0))
		{
			
			if (board[1][1] == 1)
			{
				win1_flag = true;
				Games::setPlWin( );
			}
			else
			{
				win2_flag = true;
				Games::setPlWin( );
			}
		}
	}
}

void TicTacToe::result()
{
	Games::setTotal();
	if (win1_flag == true) //玩家获胜
	{
		Games::setPlWin();
		cout << "Yon win!" << endl << endl;
	}
		
	if (win2_flag == true)       //电脑获胜
	{
		Games::setPcWin();
		cout << "Pc win!" << endl << endl;
	}
		
	if (win1_flag == win2_flag)  //均未获胜,平局
	{
		cout << "Tie!" << endl << endl;
	}
		
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			score[i][j] = 10;
			board[i][j] = 0;
		}
	}
	win1_flag = false; 
	win2_flag = false;

}

