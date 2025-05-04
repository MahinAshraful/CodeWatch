#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int i,j,a[100],temp;
    for(i=0;i<10;i++){
        cin>>a[i];
    }
    for(i=0;i<10;i++){
        for(j=0;j<10-(i+1);j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(j=9;j>=7;j--){
        printf("%d\n",a[j]);
    }
    return 0;
}