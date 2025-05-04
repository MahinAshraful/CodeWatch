#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int num[10];
    for(long long int i=0;i<10;i++)
    {
        cin>>num[i];
    }
    sort(num,num+10);
    for(long long int i=9;i>=7;i--)
    {
        cout<<num[i]<<endl;
    }
    return 0;
}