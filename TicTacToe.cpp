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
		cout << "�������games.file�鿴" << endl;
	}
		
}

void TicTacToe::start()
{
	
	cout << "Welcome to TicTacToe!" << endl <<endl;
	cout << "Please select te order of pirority�� 1 -- first�� 2 -- last����" << endl;
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
	int n1 = 0;    //��¼�����Ѿ����˼�����
	int n2 = 0;    //��¼����Ѿ����˼�����
	vector <pair<int, int>> pc_position; //pair�������� <row,col>
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
					//������λ������ܺ͵��Ե������������� ��30��
					if ((row == pc_position[i].first && col + pc_position[i].second != 2) || (col == pc_position[i].second && row + pc_position[i].first != 2) || (row == pc_position[i].second && pc_position[i].second == pc_position[i].first && row + pc_position[i].first != 2))
						score[row][col] > 30 ? score[row][col] += 0 : score[row][col] = 30;
				}

				for (int i = 0; i < n1; i++)
				{
					for (int j = i + 1; j < n1; j++)
					{
						//����������ܺ͵������������� ��50��
						if ((row == pc_position[i].first && row == pc_position[j].first) || (col == pc_position[i].second && col == pc_position[j].second) || (row + col == 2 && pc_position[i].first + pc_position[i].second == 2 && pc_position[j].first + pc_position[j].second == 2))
							score[row][col] = 50;
					}
				}

				for (int i = 0; i < n2; i++)
				{
					//������λ������ܺ���ҵ������������� ��20��
					if ((row == pl_position[i].first && col + pl_position[i].second != 2) || (col == pl_position[i].second && row + pl_position[i].first != 2) || (row == pl_position[i].second && pl_position[i].second == pl_position[i].first && row + pl_position[i].first != 2))
						score[row][col] > 20 ? score[row][col] += 0 : score[row][col] = 20;
				}

				for (int i = 0; i < n2; i++)
				{
					for (int j = i + 1; j < n2; j++)
					{
						//������λ������ܺ���ҵ������������� ��40��
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
	while (board[row0 - 1][col0 - 1] != 0)  //�жϸ�λ���Ƿ���������,�򲻴���
	{
		cout << "Errror! Please reenter!" << endl << endl;
		cout << "Please enter the number of lines(1-3):" << endl;
		cin >> row0 >> col0;   //��������λ��
	}
	board[row0 - 1][col0 - 1] = 1;  //�����з������1����
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



void TicTacToe::game_start()   //��Ϸ��ʼ
{
	int n = 0;            //��3*3=9������λ,�����ж��Ƿ�����
	bool flag = false;     //����л���־λ
	
	cout << "Game start��" << endl << endl;

	while (n < 9 && win1_flag == false && win2_flag == false) //δ����,δ�ֳ�ʤ���������Ϸ
	{
		switch (op)
		{
		case 1:
			if (flag == false)
			{              //�л������1
				cout << "The player : " << getPlayer() << "  input:  ( Please enter the number of lines(1-3) )" << endl;
				putChess();                  //�����������λ��
				flag = true;
			}
			else
			{
				cout << "The pc input��" << endl;
				getChess();
				flag = false;
			}
			judge();      //�ж�ʤ��
			drawChessboard();            //��ӡ������
			n++;               //����������һö����
			break;
		case 2:
			if (flag == false)
			{
				cout << "The pc input��" << endl;
				getChess();
				flag = true;                //��һ�������2
			}
			else
			{                             //�л������2
				cout << "The player" << getPlayer() << "input:Please enter the number of lines(1-3)" << endl;
				putChess();                   //���2��������λ��
				flag = false;               //��һ�������1   
			}
			judge();      //�ж�ʤ��
			drawChessboard();
			n++;               //����������һö����
			break;
		}
	}

	result();
	
}

void TicTacToe::judge()       //�ж�ʤ��
{
	for (int i = 0; i < rows; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 0)    //�жϺ᷽����3����ͬ������
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
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0)    //�ж��ݷ�����3����ͬ������
		{
			
			if (board[0][i] == 1)     //�ж�����ҵ����ӻ��ǵ���
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
		if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0)   //�ж�б������3����ͬ������
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
	if (win1_flag == true) //��һ�ʤ
	{
		Games::setPlWin();
		cout << "Yon win!" << endl << endl;
	}
		
	if (win2_flag == true)       //���Ի�ʤ
	{
		Games::setPcWin();
		cout << "Pc win!" << endl << endl;
	}
		
	if (win1_flag == win2_flag)  //��δ��ʤ,ƽ��
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

