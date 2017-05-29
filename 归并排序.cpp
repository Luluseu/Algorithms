#include <iostream>
using namespace std;

void megre(int *arr, int p, int q, int r)
{
	int i, j = 0, k = 0;
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];
	for (i = 0; i < n1; ++i)
		L[i] = arr[p + i];
	for (i = 0; i < n2; ++i)
		R[i] = arr[q + 1 + i];
	L[n1] = 0X7FFFFFFF;
	R[n2] = 0X7FFFFFFF;
	for (i = 0; i <= r - p; ++i)
	{
		if (L[j] < R[k])
		{
			arr[p + i] = L[j];
			j++;
		}
		else
		{
			arr[p + i] = R[k];
			k++;
		}
	}
}

void megreSort(int *arr, int p, int r)
{
	if (p == r)
		return;
	else
	{
		int q = (p + r) / 2;
		megreSort(arr, p, q);
		megreSort(arr, q + 1, r);
		megre(arr, p, q, r);
	}
}
int main()
{
	int n, *arr, i;
	cin >> n;
	arr = new int[n];
	for (i = 0; i < n; ++i)
		cin >> arr[i];
	megreSort(arr, 0, n - 1);
	for (i = 0; i < n; ++i)
		cout << arr[i] << "a ";
	cout << endl;
	system("pause");
}