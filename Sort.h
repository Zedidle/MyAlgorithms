#include "vector"
#include "random"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Shuffle.h"



void Sort_Test()
{
	int N = 50;
	vector<int> arr;
	vector<int> temp(N); // 需要实现分配空间
	for (int i = 0; i < N; ++i)
	{
		arr.push_back(rand()%(3*N));
	}

	int times = 0;
	//times = BubbleSort(arr);
	//times = SelectionSort(arr);
	//times = InsertionSort(arr);
	//times = ShellSort(arr);
	//times = MergeSort(arr, 0, arr.size() - 1, temp);
	QuickSort(arr);


	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << " ";
	}


	// 洗牌算法
	//Shuffle(arr);
	//cout << "times: " << times << endl;
	//for (int i = 0; i < arr.size(); ++i)
	//{
	//	cout << arr[i] << " ";
	//}


}

