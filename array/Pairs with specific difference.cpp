#include <bits/stdc++.h>
using namespace std;

// Method to return maximum sum we can get by
// finding less than K difference pairs
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int k)
{
    int maxSum = 0;

    // Sort elements to ensure every i and i-1 is closest
    // possible pair
    sort(arr, arr+N);

    // To get maximum possible sum, iterate from largest to
    // smallest, giving larger numbers priority over smaller
    // numbers.
    for (int i=N-1; i>0; --i)
    {
        // Case I: Diff of arr[i] and arr[i-1] is less then K,
        //         add to maxSum
        // Case II: Diff between arr[i] and arr[i-1] is not less
        //          then K, move to next i since with sorting we
        //          know, arr[i]-arr[i-1] < arr[i]-arr[i-2] and
        //          so on.
        if (arr[i]-arr[i-1] < k)
        {
            //Assuming only positive numbers.
            maxSum += arr[i];
            maxSum += arr[i-1];

            //When a match is found skip this pair
            --i;
        }
    }

    return maxSum;
}

// Driver code to test above methods
int main()
{
    int arr[] = {3, 5, 10, 15, 17, 12, 9};
    int N = sizeof(arr)/sizeof(int);

    int K = 4;
    cout << maxSumPairWithDifferenceLessThanK(arr, N, K);
    return 0;
}

/*#include <iostream>
using namespace std;
int maxpairsum(int arr[],int N,int k)
{
    int temp,curr,count1,sum;
    for(int i=0;i<N;i++)
    {
        temp=arr[i]+k;
        for(int j=0;j<N;j++)
        {
            if(arr[j]<temp && arr[j]!=arr[i])
            {
                sum=arr[j]+arr[i];               //THIS CODE DOESNT WORK
            }
            if(sum>curr)
            {
                curr=sum;
            }
        }
        count1=count1+curr;
    }
    return count1;
}
int main() {
	//code

	    int N,k;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	    {
	        cin>>arr[i];
	    }
	    cin>>k;
	    cout<<maxpairsum(arr,N,k)<<"\n";
	return 0;
}

*/
