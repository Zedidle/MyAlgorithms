#include "BTree.h"
#include <iostream>
using namespace std;

#include "string"
#include <vector>

using namespace std;


int _QuickSort(vector<int>& arr, int left, int right);
int QuickSort(vector<int>& arr);



int QuickSort(vector<int>& arr)
{
	cout << "QuickSort arr.size():" << arr.size() << endl;
	return _QuickSort(arr, 0, arr.size());
}


int _QuickSort(vector<int>& arr, int left, int right)
{
	if(left >= right) return 0;

	int pivot = left;
	for (int i = pivot + 1; i < right; i++)
	{
		if (arr[pivot] > arr[i])
		{
			// C++特有的数组原地换位
			swap(arr[i], arr[pivot + 1]);
			swap(arr[pivot], arr[pivot + 1]);
			++pivot;
		}
	}
	_QuickSort(arr, left, pivot);
	_QuickSort(arr, pivot+1, right);
	return 0;
}



