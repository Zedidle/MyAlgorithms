#include "BTree.h"
#include <iostream>
using namespace std;

#include "string"


template<typename T>
BTree<T>::BTree()
{
}

//template <typename T>
//BTree<T>::BTree(T* val)
//{
//	Root = new Node(val);
//}


template<typename T>
BTree<T>::~BTree()
{
	makeEmpty();
}

//template<typename T>
//void BTree<T>::Insert(T* val)
//{
//	Insert(val, Root);
//}


//template<typename T>
//void BTree<T>::Remove(T* val)
//{
//	Remove(val, Root);
//}

template<typename T>
void BTree<T>::makeEmpty()
{
}

//template<typename T>
//typename T* BTree<T>::GetMin() const
//{
//	return GetMin(Root)->Val;
//}

//template<typename T>
//typename T* BTree<T>::GetMax() const
//{
//	return GetMax(Root)->Val;
//}

//template<typename T>
//void BTree<T>::PreOrder() const
//{
//	PreOrder(Root);
//	cout << endl;
//}
template<typename T>
void BTree<T>::InOrder() const
{
	InOrder(Root);
	cout << endl;
}
template<typename T>
void BTree<T>::PostOrder() const
{
	PostOrder(Root);
	cout << endl;
}


template<typename T>
typename BTree<T>::Node* BTree<T>::Clone(Node* node)
{
	return NULL;
}

//template<typename T>
//void BTree<T>::Insert(T* val, Node*& t)
//{
//	if (nullptr == t)
//	{
//		t = new Node(val);
//	}
//	else if (val < t->Val)
//	{
//		Insert(val, t->Left);
//	}
//	else
//	{
//		Insert(val, t->Right);
//	}
//}


//template<typename T>
//void BTree<T>::Remove(T* val, Node*& t)
//{
//	if (nullptr == t)
//	{
//		return;
//	}
//	else
//	{
//		if (val < t->Val)
//		{
//			Remove(val, t->Left);
//		}
//		else if(val > t->Val)
//		{
//			Remove(val, t->Right);
//		}
//		else if (nullptr != t->Left && nullptr != t->Right)
//		{
//			// 这种是加速法，666
//			t->Val = GetMin(t->Right)->Val; 
//			Remove(t->Val, t->Right);
//		}
//		else
//		{
//			//Node* oldNode = t;
//			t = (nullptr != t->Left) ? t->Left : t->Right;
//			//delete oldNode;
//		}
//	}
//}

template<typename T>
void BTree<T>::MakeEmpty(Node*& t)
{
}

//template<typename T>
//typename BTree<T>::Node* BTree<T>::GetMin(Node* node) const
//{
//	if (nullptr != node)
//	{
//		while (nullptr != node->Left)
//		{
//			node = node->Left;
//		}
//	}
//	return node;
//}

//template<typename T>
//typename BTree<T>::Node* BTree<T>::GetMax(Node* node) const
//{
//	if (nullptr != node)
//	{
//		while (nullptr != node->Right)
//		{
//			node = node->Right;
//		}
//	}
//	return node;
//}

//template<typename T>
//void BTree<T>::PreOrder(Node* node) const
//{
//	if(!node) return;
//	PreOrder(node->Left);
//	cout << node << " ";
//	PreOrder(node->Right);
//}

template<typename T>
void BTree<T>::InOrder(Node* node) const
{
	if (!node) return;
	cout << node << " ";
	InOrder(node->Left);
	InOrder(node->Right);
}

template<typename T>
void BTree<T>::PostOrder(Node* node) const
{
	if (!node) return;
	PostOrder(node->Left);
	PostOrder(node->Right);
	cout << node << " ";
}



struct Dot
{
	Dot() :X(0), Y(0), Cost(1) {}
	Dot(int x, int y, int cost = 1) :X(x), Y(y), Cost(cost) {}
	int X;
	int Y;
	int Cost = 1;
	int State = 0; // 0:为探索  1:将要探索 Open  2:已探索 Close


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
		// Open
		if (State == 2)
		{
			return "·";
		}
		// Close
		else if (State == 1)
		{
			return "*";
		}

		return to_string(Cost);
	}
	bool operator > (const Dot& dot) {
		return Step > dot.Step;
	}
	bool operator == (const Dot& dot) {
		return *this == dot;
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

	int Step = 10000000; // 记录预算  之前的 + Cost
};


void BTree_Test()
{
	//int a = 10, b = 21, c = 12, d = 15, e = 19, f = 4;
	//int* pa = &a;
	//int* pb = &b;
	//int* pc = &c;
	//int* pd = &d;
	//int* pe = &e;
	//int* pf = &f;
	
	//BTree<int>* BTree0 = new BTree<int>();
	//BTree0->Insert(pb);
	//BTree0->Insert(pc);
	//BTree0->Insert(pd);
	//BTree0->Insert(pe);
	//BTree0->Insert(pf);
	//BTree0->PreOrder();


	//cout << endl;
	//cout << *BTree0->GetMin()  << endl;
	//cout << *BTree0->GetMax()  << endl;
	//BTree0->Remove(b);
	//BTree0->InOrder();
	//BTree0->PostOrder();




	BTree<Dot>* BTree0 = new BTree<Dot>(new Dot());
	for (int i = 0; i < 10; ++i)
	{
		Dot* dot = new Dot();
		dot->SetStep(i);
		BTree0->Insert(dot);
	}
	BTree0->PreOrder();
	BTree0->Remove(BTree0->GetMin());
	BTree0->PreOrder();

	BTree0->Remove(BTree0->GetMin());
	BTree0->PreOrder();





}
