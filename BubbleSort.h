#include <iostream>
using namespace std;

// 冒泡排序
int BubbleSort(vector<int>& arr)
{
	int times = 0;
	int j = arr.size();
	while (j > 0)
	{
		int i = 0;
		while (i < j - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				int t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
				++times;
			}
			++i;
		}
		--j;
	}
	return times;
};
