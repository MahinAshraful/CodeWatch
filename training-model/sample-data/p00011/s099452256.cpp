#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxw=30+5;
int w,n,rank[maxw];
int main(){
    scanf("%d%d",&w,&n);
    for(int i=1;i<=w;i++)
        rank[i]=i;
    for(int i=1,x,y;i<=n;i++){
        scanf("%d,%d",&x,&y);
        swap(rank[x],rank[y]);
    }
    for(int i=1;i<=w;i++)
        cout<<rank[i]<<endl;
    return 0;
}