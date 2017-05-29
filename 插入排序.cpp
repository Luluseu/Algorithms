#include <iostream>
using namespace std;

void insertSort(int arr[], int n)
{
	int i, j, key;
	for (i = 1; i < n; ++i)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	int n, i, *arr;
	cin >> n;
	arr = new int[n];
	for (i = 0; i < n; ++i)
		cin >> arr[i];
	insertSort(arr, n);
	for (i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
	system("pause");
}