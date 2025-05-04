#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    long long int i,arr[10000];

   for(i=0;i<10;i++)
       cin>>arr[i];
       sort(arr,arr+10);
   for(i=9;i>=7;i--)
       cout<<arr[i]<<endl;

}