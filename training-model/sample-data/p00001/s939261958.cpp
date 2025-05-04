#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=10;
    int ara[12];
    for(int i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    sort(ara,ara+n);
        for(int i=n-1;i>=7;i--)
    {
        cout<<ara[i]<<endl;
    }
    return 0;

}