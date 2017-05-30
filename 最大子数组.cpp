#include <iostream>
using namespace std;

void findMaximumCrossingSubarray(int *arr, int low, int mid, int high, int &cross_low, int &cross_high, int &cross_sum)
{
	int sum = 0, left_sum, right_sum, i;
	left_sum = right_sum = 0x80000000;
	for (i = mid; i >= low; --i)
	{
		sum += arr[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			cross_low = i;
		}
	}
	sum = 0;
	for (i = mid + 1; i <= high; ++i)
	{
		sum += arr[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			cross_high = i;
		}
	}
	cross_sum = left_sum + right_sum;
	return;
}

void findMaximumSubarray(int *arr, int low, int high, int &max_low, int &max_high, int &max_sum)
{
	if (low == high)
	{
		max_low = max_high = max_sum = 0;
	}
	else
	{
		int mid = (low + high)/2;
		int left_low, left_high, left_sum;
		findMaximumSubarray(arr, low, mid, left_low, left_high, left_sum);
		int right_low, right_high, right_sum;
		findMaximumSubarray(arr, mid+1, high, right_low, right_high, right_sum);
		int cross_low, cross_high, cross_sum;
		findMaximumCrossingSubarray(arr, low, mid, high, cross_low, cross_high, cross_sum);
		if (left_sum >= right_sum && left_sum >= cross_sum)
		{
			max_low = left_low;
			max_high = left_high;
			max_sum = left_sum;
		}
		else if (right_sum >= left_sum && right_sum >= cross_sum)
		{
			max_low = right_low;
			max_high = right_high;
			max_sum = right_sum;
		}
		else
		{
			max_low = cross_low;
			max_high = cross_high;
			max_sum = cross_sum;
		}
	}	
}
int main()
{
	int n, i, *arr, max_low, max_high, max_sum;
	cin >> n;
	arr = new int[n];
	for (i = 0; i < n; ++i)
		cin >> arr[i];
	findMaximumSubarray(arr, 0, n - 1, max_low, max_high, max_sum);
	cout << "low=" << max_low << endl
		 << "high=" << max_high << endl
		 << "sum=" << max_sum << endl;
} 
