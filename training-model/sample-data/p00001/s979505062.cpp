#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define S 10
using namespace std;

int main(){
    int arr[S];

    for(int i=0;i<S;i++)
        cin>>arr[i];
    sort(arr,arr+S);
    //cout<<endl;
    for(int i=S-1;i>=S-3;i--)
        cout<<arr[i]<<endl;

return 0;
}