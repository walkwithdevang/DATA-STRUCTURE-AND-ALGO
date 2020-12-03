/* NON OPTIMAL SOLUTION
int transitionPoint(int arr[], int n) {
    // code here
    int temp=0;
    if(arr[0]==1)
    {
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            temp=i;
            break;
        }
    }
    if(temp==0)
    {
        return -1;
    }
    else{
        return temp;
    }
}
*/ //scroll down for optimal
//optimal solution
#include<iostream>
using namespace std;

int findTransitionPoint(int arr[], int n)
{
    for(int i=0; i<n ;i++)
      if(arr[i]==1)
        return i;

    return -1;
}

// Driver code
int main()
{
    int arr[] = {0, 0, 0, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int point = findTransitionPoint(arr, n);

    point >= 0 ? cout << "Transition point is "
                      << point
        : cout<<"There is no transition point";
    return 0;
}

