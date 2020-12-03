#include "BTree.h"
#include <iostream>
using namespace std;

#include "string"


// 洗牌算法
void Shuffle(vector<int>& arr)
{
	for (int i = arr.size()-1; i > 0; --i)
	{
		swap(arr[i], arr[rand()%i]);
	}
}
