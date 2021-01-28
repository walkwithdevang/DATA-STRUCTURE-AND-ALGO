#include<iostream>

using namespace std;

int power(int a,int b)
{
    if(b==1)
    {
        return a;
    }
    return power(a,b-1)*a;
}

int main()
{
  cout<<power(3,4);
}
