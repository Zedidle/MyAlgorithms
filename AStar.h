#include <iostream>
#include <vector>
#include <algorithm>
#include<windows.h>
#include "string"
#include "BTree.h"
using namespace std;


class ASart
{
	int Row, Line;
	int StartX, StartY;
	int EndX, EndY;
	
	int Step = 0;
	int Cost = 0;


	private:
		struct Dot
		{
			Dot():X(), Y(), Cost(1){}
			Dot(int x, int y, int cost = 1) :X(x), Y(y), Cost(cost) {}
			Dot* PreDot = nullptr;
			int X;
			int Y;
			int Cost = 1;
			int State = 0; // 0:为探索  1:将要探索 Open  2:已探索 Close  3:画成路线

			string GetPos()
			{
				string s = "(";
				s.insert(s.length(), to_string(X));
				s.insert(s.length(), ",");
				s.insert(s.length(), to_string(Y));
				s.insert(s.length(), ")");
				return s;
			}
			string GetMark()
			{
				if (State == 3)
				{
					return "*";
				}
				else if (State == 2) // Close
				{
					return ".";
				}
				else if (State == 1) // Open
				{
					return "o";
				}
				else if (Cost > 9) // Obstacle
				{
					return "#";
				}

				return to_string(Cost);
			}

			bool operator > (const Dot& dot) {
				return Step > dot.Step;
			}
			bool operator == (const Dot* dot) {
				return this == dot;
			}
			bool operator < (const Dot& dot) {
				return Step < dot.Step;
			}
			friend ostream& operator<<(ostream& stream, const Dot& dot)
			{
				stream << dot.Step << " ";
				return stream;
			}
			friend ostream& operator<<(ostream& stream, const Dot* dot)
			{
				stream << dot->Step << " ";
				return stream;
			}
			void SetStep(int step)
			{
				State = 1;
				Step = step;
			}

			int Step = 10; // 记录预算  之前的 + Cost
		};

		vector<vector<Dot*>> Map;
		BTree<Dot>* Open;

	public:
		ASart(int row, int line);
		void SetStart(int row, int line);
		void SetEnd(int row, int line);
		void Find();
		void ShowMap();
		void ShowRoute(int row, int line);
};



void ASart_Test();
