#include "vector"
#include "random"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"



namespace Sort
{
	void Test()
	{
		int N = 100;
		default_random_engine e;
		uniform_int_distribution<unsigned> u(0, N * 3);
		vector<int> arr;
		vector<int> temp(N); // 需要实现分配空间
		for (int i = 0; i < N; ++i)
		{
			arr.push_back(u(e));
		}

		int times = 0;
		//times = BubbleSort(arr);
		//times = SelectionSort(arr);
		//times = InsertionSort(arr);
		//times = ShellSort(arr);
		times = MergeSort(arr, 0, arr.size() - 1, temp);


		cout << "times: " << times << endl;
		for (int i = 0; i < arr.size(); ++i)
		{
			cout << arr[i] << " ";
		}
	}

}