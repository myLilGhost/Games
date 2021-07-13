#include "Poker.h"
#include <vector>
Poker::Poker(const string& name)
    :Games(name)
{
	plScore = 0;
	pcScore = 0;
}

void Poker::setPlScore(int i)
{
	plScore += i;
}


void Poker::setPcScore(int i)
{
	pcScore += i;
}

int Poker::getPlScore() const
{
	return plScore;
}

int Poker::getPcScore() const
{
	return pcScore;
}

//单张牌分数
void Poker::face()
{
	for (int i = 1; i <= 5; i++)
	{
		setPlScore(pl.getFace(i) );
		setPcScore(pc.getFace(i) );
	}
}

//对子 一个对子10分 分数为10*牌值
void Poker::duizi(  )
{
	int x = 0; //有几个对子
	int y = 0;
	int isDuizi1 = 0; //记录之前的对子的值 防止将三同号当作两个对子 （最多有两个）
	int isDuizi2 = 0;
	for (int i = 1; i < 5; i++)
	{
		for (int j = i+1; j <= 5; j++)
		{
			if (pl.getFace(i) == pl.getFace(j) && pl.getFace(i) != isDuizi1)
			{
				isDuizi1 = pl.getFace(i);
				setPlScore(10 * pl.getFace(i));
				break;
			}
				
			if (pc.getFace(i) == pc.getFace(j) && pc.getFace(i) != isDuizi2)
			{
				isDuizi2 = pc.getFace(i);
				setPcScore(10 * pc.getFace(i));
				break;
			}
		}
			
	}
}

// 三个同号 分数为15*牌值 四个同号 牌值为20*牌值 五同号 分数为25*牌值
void Poker::tonghao()
{
	//三同号
	for (int i = 1; i <= 5; i++)
	{
		for (int j = i + 1; j <= 5; j++)
		{
			for (int k = j + 1; k <= 5; k++)
			{
				if (pl.getFace(i) == pl.getFace(j) && pl.getFace(i) == pl.getFace(k) && i != j && i != k && i != j)
					setPlScore(15 * pl.getFace(i));
				if (pc.getFace(i) == pc.getFace(j) && pc.getFace(i) == pc.getFace(k) && i != j && i != k && i != j)
					setPcScore(15 * pc.getFace(i));

			}

		}

	}

	//四同号
	for (int i = 1; i <= 5; i++)
	{
		for (int j = i+1; j <= 5; j++)
		{
			for (int k = j+1; k <= 5; k++)
			{
				for (int q = k+1; q <= 5; q++)
				{
					if (pl.getFace(i) == pl.getFace(j) && pl.getFace(i) == pl.getFace(k) && pl.getFace(i) == pl.getFace(q)
						&& i != j && i != k && i != j && i != q && j != q && k != q)
						setPlScore(20 * pl.getFace(i));

					if (pc.getFace(i) == pc.getFace(j) && pc.getFace(i) == pc.getFace(k) && pc.getFace(i) == pc.getFace(q)
						&& i != j && i != k && i != j && i != q && j != q && k != q)
						setPcScore(30 * pc.getFace(i));
				}
			}
		}
	}

	//五同号
	if (pl.getFace(1) == pl.getFace(2) && pl.getFace(1) == pl.getFace(3) && pl.getFace(1) == pl.getFace(4) && pl.getFace(1) == pl.getFace(5))
		setPlScore(25 * pl.getFace(1));
	if (pc.getFace(1) == pc.getFace(2) && pc.getFace(1) == pc.getFace(3) && pc.getFace(1) == pc.getFace(4) && pc.getFace(1) == pc.getFace(5))
		setPcScore(25 * pc.getFace(1));

}

//同花 分数为50分
void Poker::tonghua()
{

	if (pl.getSuit(1) == pl.getSuit(2) && pl.getSuit(1) == pl.getSuit(3) && pl.getSuit(1) == pl.getSuit(4) && pl.getSuit(1) == pl.getSuit(5))
		setPlScore(50);
	if (pc.getSuit(1) == pc.getSuit(2) && pc.getSuit(1) == pc.getSuit(3) && pc.getSuit(1) == pc.getSuit(4) && pc.getSuit(1) == pc.getSuit(5))
		setPcScore(50);
}

//同顺 分数为30*最小牌值
void Poker::tongshun()
{
	int x = 0, y = 0;
	int plface[5];
	int pcface[5];
	//将牌值升序排序
	for (int i = 1; i <= 4; i++)
	{
		plface[i] = pl.getFace(i);
		pcface[i] = pc.getFace(i);
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int j = i + 1; j <= 4; j++)
		{
			if (plface[i] > plface[j])
			{
				int t1 = plface[i];
				plface[i] = plface[j];
				plface[j] = t1;
			}
			if (pcface[i] > pcface[j])
			{
				int t2 = pcface[i];
				pcface[i] = pcface[j];
				pcface[j] = t2;
			}
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (plface[0] == plface[i] + i)
			x++;
		
		if (pcface[0] == pcface[i] + i)
			y++;
	}

	if (x == 4)
		setPlScore(30 * plface[0]);
	if (y == 4)
		setPcScore(30 * pcface[0]);
}

void Poker::result()
{
	if (getPlScore() > getPcScore())
	{
		setPlWin();
		setTotal();
		cout << "Your score:" << getPlScore() << endl;
		cout << "Pc score:" << getPcScore() << endl;
		cout << "You win!" << endl;

	}
	else if (getPlScore() < getPcScore())
	{
		setPcWin();
		setTotal();
		cout << "Your score:" << getPlScore() << endl;
		cout << "Pc score:" << getPcScore() << endl;
		cout << "You Lose!" << endl;

	}
	else if( getPcScore() == getPlScore())
	{
		setTotal();
		cout << "Your score:" << getPlScore() << endl;
		cout << "Pc score:" << getPcScore() << endl;
		cout << "Tie!" << endl;

	}
	
}
void Poker::Play()
{   

	int a;
	pl.shuffle();
	cout << "Your poker：" << endl;
	pl.deal();
	cout << endl;
	Sleep(1000);
	cout << "Pc's poker：" << endl;
	pc.shuffle();
	pc.deal();
	cout << endl;
	plScore = 0;
	pcScore = 0;
	face();
	duizi();
	tonghao();
	tonghua();
	tongshun();
	result();

	cout << "Do you want another round? ( 1 -- Yes , 2 -- No )" << endl;

	cin >> a;
	if (a == 1)
	{
		system("cls");
		Play();
	}
	else 
	{
		system("cls");
		print();
		cout << "Total play times:" << getTotal() << endl;
		cout << "You won:" << getPlWin() << endl;
		cout << "Pc won:" << getPcWin() << endl;
		cout << "Tie:" << getTotal() - getPlWin() - getPcWin() << endl;



		if (getPlWin() > getPcWin())
		{
			cout << "Congratulations on your victory!" << endl;
		}

		else if (getPlWin() < getPcWin())
		{
			cout << "Sorry! You lost!" << endl;
		}

		else if (getPlWin() == getPcWin())
		{
			cout << "That's good! A draw!" << endl;
		}
	}
		
}