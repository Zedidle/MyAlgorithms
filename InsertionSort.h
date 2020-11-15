#include <iostream>
using namespace std;

// 插入排序
int InsertionSort(vector<int>& arr)
{
	int times = 0;
	for (int i = 1; i < arr.size(); ++i)
	{
		int j = i;
		while (j > 0)
		{
			if (arr[j - 1] > arr[j])
			{
				int t = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = t;
				--j;
				++times;
				continue;
			}
			break;
		}
	}
	return times;
};
