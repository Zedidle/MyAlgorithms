#include <iostream>
using namespace std;


// 希尔排序
int ShellSort(vector<int>& arr)
{
	int times = 0;;
	int len = arr.size();
	int gap = 2;
	for (int gap = floor(len / 2); gap > 0; gap = floor(gap / 2))
	{
		for (int i = gap; i < len; ++i)
		{
			int j = i;
			int cur = arr[i];
			while (j - gap >= 0 && cur < arr[j - gap])
			{
				arr[j] = arr[j-gap];
				j = j - gap;
				++times;
			}
			arr[j] = cur;
		}
	}
	return times;
}
