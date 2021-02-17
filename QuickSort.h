#include "BTree.h"
#include <iostream>
using namespace std;

#include "string"
#include <vector>

using namespace std;


void QuickSort(vector<int>& arr);
void _QuickSort(vector<int>& arr, int left, int right);



void QuickSort(vector<int>& arr){
	//cout << "QuickSort arr.size():" << arr.size() << endl;
	_QuickSort(arr, 0, arr.size());
}


void _QuickSort(vector<int>& arr, int left, int right){
	if(left >= right) return;

	int pivot = left;
	for (int i = left + 1; i < right; i++) {
		if (arr[pivot] > arr[i]) {
			swap(arr[i], arr[pivot+1]);
			swap(arr[pivot], arr[pivot+1]);
			pivot++;
		}
	}
	_QuickSort(arr, left, pivot);
	_QuickSort(arr, pivot+1, right);
}



