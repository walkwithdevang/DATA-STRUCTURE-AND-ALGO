#include<iostream>
#include<algorithm>

using namespace std;

int lis(int arr[],int n)
{
    int lis[n];
    lis[0]=1;
    for(int j=1;j<n;j++)
    {
        lis[j]=1;
        for(int i=0;i<j;i++)
        {
            if(arr[j]>arr[i] && lis[j]<lis[i]+1)
            {
                lis[j]=lis[i]+1;
            }
        }
    }
    cout<<"max element index:"<<max_element(arr,arr+n)-arr<<endl;
    return *max_element(lis,lis+n);
}


int main()
{
    int arr[]={1,15,51,45,33,100,12,18,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<lis(arr,n);

}
