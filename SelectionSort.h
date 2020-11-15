#include <iostream>
using namespace std;

// 选择排序
int SelectionSort(vector<int>& arr)
{
	int times = 0;
	int len = arr.size();
	for (int i = 0; i < len-1; ++i)
	{
		int cur = i;
		for (int j = i+1; j < len; ++j)
		{
			if (arr[cur] > arr[j])
			{
;				cur = j;
				++times;
			}
		}
		int t = arr[cur];
		arr[cur] = arr[i];
		arr[i] = t;
	}
	return times;
};
