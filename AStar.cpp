#include "AStar.h"
#include "BTree.h"

ASart::ASart(int row, int line) :Row(row), Line(line)
{
	int PlainFactor = 10; // 平原系数：数值越大，遇到障碍（不可通过）的概率越低
	int CostFactor = 5; // 耗费系数；数值越大，所在区域平均每步所耗费的体力越大
	for (int i = 0; i < Row; ++i)
	{
		vector<Dot*> m;
		for (int j = 0; j < Line; ++j)
		{
			int cost;
			
			if ( j == Line/2 && i > 1 && i < Row - 2)
			{
				// 强行障碍
				cost = 10;
			}
			else
			{
				if (i < Row / 2)
				{
					// 沼泽区
					PlainFactor = 7;
					CostFactor = 9;
				}
				else
				{
					// 平原区
					PlainFactor = 10;
					CostFactor = 3;
				}
				cost = (rand() % PlainFactor) ? (rand() % CostFactor + CostFactor / 3) : 10;
			}
			m.push_back(new Dot(i, j, cost));
		}
		Map.push_back(m);
	}
	SetStart(0, 0);
}

void ASart::SetStart(int row, int line)
{
	if (!(0 <= row < Row) || !(0 <= line < Line))
	{
		cout << "错误，设置的起点不在地图中" << endl;
		return;
	}
	StartX = row;
	StartY = line;
}


inline void ASart::SetEnd(int row, int line)
{
	if (!(0 <= row < Row) || !(0 <= line < Line))
	{
		cout << "错误，设置的终点不在地图中" << endl;
		return;
	}

	EndX = row;
	EndY = line;
}

void ASart::Find()
{
	int curX = StartX, curY = StartY;
	int CurStep = 0;
	Open = new BTree<Dot>(new Dot(curX, curY));

	Dot* dot = nullptr;
	while (!(curX == EndX && curY == EndY))
	{

		Map[curX][curY]->State = 2;
		if (curX - 1 >= 0 && (dot = Map[curX - 1][curY]) && dot->State == 0 && dot->Cost < 10)
		{
			dot->SetStep(CurStep + dot->Cost);
			dot->PreDot = Map[curX][curY];
			Open->Insert(dot);
		}
		if (curX + 1 < Row && (dot = Map[curX + 1][curY]) && dot->State == 0 && dot->Cost < 10)
		{
			dot->SetStep(CurStep + dot->Cost);
			dot->PreDot = Map[curX][curY];
			Open->Insert(dot);
		}
		if (curY - 1 >= 0 && (dot = Map[curX][curY - 1]) && dot->State == 0 && dot->Cost < 10)
		{
			dot->SetStep(CurStep + dot->Cost);
			dot->PreDot = Map[curX][curY];
			Open->Insert(dot);
		}
		if (curY + 1 < Line && (dot = Map[curX][curY + 1]) && dot->State == 0 && dot->Cost < 10)
		{
			dot->SetStep(CurStep + dot->Cost);
			dot->PreDot = Map[curX][curY];
			Open->Insert(dot);
		}


		if (nullptr != Open->GetMin())
		{
			CurStep = Open->GetMin()->Step;
			curX = Open->GetMin()->X;
			curY = Open->GetMin()->Y;
			Open->Remove(Open->GetMin());
			++Step;
			Sleep(50);
			system("cls");
			cout << "预备可行位置的消耗：";
			Open->PreOrder();
			//cout << "探索步数：" << Step << endl;
			//cout << "当前位置：" << Open->GetMin()->GetPos() << endl;
			ShowMap();
	}
		else
		{
			cout << "没法抵达" << endl;
			break;
		}
	}
	dot = nullptr;
	delete dot;
	ShowRoute(curX, curY);
}

void ASart::ShowMap()
{
	cout << endl;
	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Line; ++j)
		{
			cout << Map[i][j]->GetMark();
		}
		cout << endl;
	}
}

void ASart::ShowRoute(int row, int line)
{
	cout << "ASart::ShowRoute" << endl;
	if (!(0 <= row && row < Row) || !(0 <= line && line < Line))
	{
		cout << "错误，点不在地图中" << endl;
		return;
	}
	Dot* curDot = Map[row][line];
	while (nullptr != curDot)
	{
		curDot->State = 3;
		curDot = curDot->PreDot;
	}
	ShowMap();
	cout << "抵达终点，所用路线消耗体力：" << Map[row][line]->Step << endl;
}

void ASart_Test()
{
	int row = 10;
	int line = 20;

	ASart* aSart = new ASart(row, line);
	aSart->SetStart(0, 0);
	aSart->SetEnd(row-1, line-1);
	aSart->Find();


	//aSart->ShowMap();
}
