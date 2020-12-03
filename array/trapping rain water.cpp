// C++ implementation of the approach
#include<bits/stdc++.h>
using namespace std;
int maxWater(int arr[], int n){

    // Your code here
    int i=0,j=n-1;
    int max_cap=0,m,l,total_water=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]<=arr[i+1])
        {
            i++;
            if(arr[m]>arr[i])
            {
                m=i;
            }

        }
        if(arr[j]<=arr[j-1])
        {
            j--;
            if(arr[l]>arr[i])
            {
            l=j;
            }
        }
    }
    cout<<m<<"\n"<<l<<"\n";
    if(arr[m]<arr[l])
    {
        max_cap=arr[m];
    }
    else{
        max_cap=arr[l];
    }

    for(int i=m;i<l;i++)
    {
        if(arr[i]==0)
        {
            total_water=total_water+max_cap;
            cout<<"total water:"<<total_water<<"\n";
        }
        else if(arr[i]!=0 && arr[i]<max_cap){
            int k=max_cap-arr[i];
            total_water=total_water+k;
        }
    }
    return total_water;
}

int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxWater(arr, n);

    return 0;
}
