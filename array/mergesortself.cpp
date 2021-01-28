#include<iostream>

using namespace std;

void mergearray(int arr[],int l,int m,int r)
{
    int n1,n2;
    n1=m-l+1;
    n2=r-m;
    int arr1[n1],arr2[n2];

    for(int i=0;i<n1;i++)
        arr1[i]=arr[l+i];

    for(int j=0;j<n2;j++)
        arr2[j]=arr[m+1+j];
    int i,j,k;
    i=0;
    j=0;
    k=l;
    cout<<k<<"\n";
    while(i<n1 && j<n2)
    {
    if(arr1[i]<=arr2[j])
    {
        arr[k]=arr1[i];
        i++;
    }
    else{
        arr[k]=arr2[j];
        j++;
    }
    k++;
   }
    while(i<n1)
    {
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=arr2[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int l,int r)
{
  if(l<r){
    int m=l+(r-l)/2; // letter l in r-1 not number 1

    mergesort(arr,l,m);
    mergesort(arr,m+1,r);

    mergearray(arr,l,m,r);
}

}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}
int main()
{
    int arr[] = {6, 5, 12, 10, 9, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  mergesort(arr, 0, n - 1);

  cout << "Sorted array: \n";
  printArray(arr, n);
  return 0;

}

