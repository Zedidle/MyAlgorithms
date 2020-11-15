#include "Test.h"
#include "vector"
#include "random"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"


int main(void)
{
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 200);
	vector<int> arr;

	for (int i = 0; i < 100; ++i)
	{
		arr.push_back(u(e));
	}



	int times = 0;

	//times = BubbleSort(arr);
	//times = SelectionSort(arr);
	//times = InsertionSort(arr);
	//times = ShellSort(arr);
	times = MergeSort(arr);





	cout << "times: " << times << endl;

	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
