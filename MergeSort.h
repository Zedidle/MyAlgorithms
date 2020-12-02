
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int times = 0;

int MergeSort(vector<int>& vec, int left, int right, vector<int>& temp);
void MergeArray(vector<int>& vec, int left, int mid, int right, vector<int>& temp);


void MergeArray(vector<int>& vec, int left, int mid, int right, vector<int>& temp)
{
    int i = left, j = mid;
    int m = mid + 1, n = right;
    int k = 0;

    while (i <= j && m <= n)
    {
        if (vec[i] <= vec[m])
        {
            temp[k++] = vec[i++];
            ++times;
        }
        else
        {
            temp[k++] = vec[m++];
			++times;
		}
    }

    while (i <= j)
    {
        temp[k++] = vec[i++];
	}

    while (m <= n)
    {
        temp[k++] = vec[m++];
	}

    for (int i = 0; i < k; i++)
    {
        vec[left + i] = temp[i];
	}
}

int MergeSort(vector<int>& vec, int left, int right, vector<int>& temp)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(vec, left, mid, temp);
        MergeSort(vec, mid + 1, right, temp);
        MergeArray(vec, left, mid, right, temp);
    }

    return times;
}