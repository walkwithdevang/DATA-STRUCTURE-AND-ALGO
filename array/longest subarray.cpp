#include<iostream>
using namespace std;

int longestSubarry(int *arr, int n)
{

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int curr_count = 0;

		while (i < n && arr[i] >= 0)
		{
			curr_count++;
			i++;
		}
		res = max(res, curr_count);
	}

	return res;
}

// Driver code
int main()
{
	int arr[] = {-8,2,3,-6,10};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << longestSubarry(arr, n);
	return 0;
}
