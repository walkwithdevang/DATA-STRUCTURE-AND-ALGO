/*
Given N non-negative integers a1,a2,....an where each represents a point at coordinate (i, ai).
 N vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i,0).
Find two lines, which together with x-axis forms a container, such that it contains the most water.
*/
#include <bits/stdc++.h>
using namespace std;
// function maxArea
long long maxArea(long long A[], int len)
{
    // Your code goes here
    int max,capacity=0;
    max=max_element(A,A+len)-A;
    if(max==0)
    {
        for(int i=1;i<len;i++)
        {
            int height=min(A[0],A[i]);
            int area=height*i;
            if(area>capacity)
            {
                capacity=area;
            }
        }
    }
    else if(max==len-1)
    {
        for(int i=len-2;i>=0;i--)
        {
            int height=min(A[0],A[i]);
            int area=height*i;
            if(area>capacity)
            {
                capacity=area;
            }
        }
    }
    else{
        for(int i=max;i<len;i++)
        {
            int height=min(A[0],A[i]);
            int area=height*i;
            if(area>capacity)
            {
                capacity=area;
            }
        }
        for(int i=max;i>=0;i--)
        {
            int height=min(A[0],A[i]);
            int area=height*i;
            if(area>capacity)
            {
                capacity=area;
            }
        }

    }
    return capacity;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<maxArea
    }
}
