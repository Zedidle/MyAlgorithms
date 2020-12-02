
// 基于指针传值的二叉树

#ifndef BINARYTREE_BINARYTREE_H_H_POINTER
#define BINARYTREE_BINARYTREE_H_H_POINTER

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
class BTree
{
	struct Node;
	public:
		BTree();
		BTree(T* val)
		{
			Root = new Node(val);
		}
		~BTree();

		void Insert(T* val)
		{
			if (!Exist(val))
			{
				Insert(val, Root);
			}
		}
		void Remove(T* val)
		{
			Remove(val, Root);
		}
		bool Exist(T* val)
		{
			return Exist(val, Root);
		}
		void makeEmpty();
		T* GetMin() const
		{
			Node* t = GetMin(Root);
			if (t)
			{
				return t->Val;
			}
			else
			{
				return nullptr;
			}
		}
		T* GetMax() const
		{
			Node* t = GetMax(Root);
			if (t)
			{
				return t->Val;
			}
			else
			{
				return nullptr;
			}
		}
		void PreOrder() const
		{
			PreOrder(Root);
			cout << endl;
		}
		void InOrder() const;
		void PostOrder() const;

	private:
		struct Node
		{
			T* Val;
			Node* Left;
			Node* Right;

			Node(T* val)
				: Val(val), Left(nullptr), Right(nullptr) {};
			Node(T* val, Node* left, Node* right)
				: Val(val), Left(left), Left(right) {};

			bool operator > (const Node* node) {
				return Val > node->Val;
			}
			bool operator == (const Node* node) {
				return Val == node->Val;
			}
			bool operator < (const Node* node) {
				return Val < node->Val;
			}
			friend ostream& operator<<(ostream& stream, const Node* node)
			{
				stream << node->Val;
				return stream;
			}
		};
		Node* Root;
		Node* Clone(Node* bNode);

		inline void Insert(T* val, Node*& t)
		{
			if (nullptr == t)
			{
				t = new Node(val);
			}
			else if (*val < *(t->Val))
			{
				Insert(val, t->Left);
			}
			else
			{
				Insert(val, t->Right);
			}
		}
		void Remove(T* val, Node*& t)
		{
			if (nullptr == t)
			{
				return;
			}
			else
			{
				if (*(val) < *(t->Val))
				{
					Remove(val, t->Left);
				}
				else if (val > t->Val)
				{
					Remove(val, t->Right);
				}
				else if (nullptr != t->Left && nullptr != t->Right)
				{
					// 这种是加速法，666
					t->Val = GetMin(t->Right)->Val;
					Remove(t->Val, t->Right);
				}
				else
				{
					Node* oldNode = t;
					t = (nullptr != t->Left) ? t->Left : t->Right;
					delete oldNode;
				}
			}
		}
		bool Exist(T* val, Node* node) const
		{
			if(!node) return false;
			if(val == node->Val) return true;
			if(*val > *node->Val) return Exist(val, node->Right);
			if(*val < *(node->Val)) return Exist(val, node->Left);
		}
		void MakeEmpty(Node*& t);
		Node* GetMin(Node* node) const
		{
			if (nullptr != node)
			{
				while (nullptr != node->Left)
				{
					node = node->Left;
				}
			}
			return node;
		}
		Node* GetMax(Node* node) const
		{
			if (nullptr != node)
			{
				while (nullptr != node->Right)
				{
					node = node->Right;
				}
			}
			return node;
		}
		void PreOrder(Node* node) const
		{
			if (!node) return;
			PreOrder(node->Left);
			cout << node->Val->GetPos() << node << " ";
			PreOrder(node->Right);
		}

		void InOrder(Node* node) const;
		void PostOrder(Node* node) const;
};


void BTree_Test();


#endif //BINARYTREE_BINARYTREE_H_H_POINTER

