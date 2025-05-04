#include <bits/stdc++.h>
using namespace std;

int main()

{
    int ar[11];
    int i,j;
    for(i=0;i<10;i++)
        scanf("%d",&ar[i]);
    sort(ar, ar+10);
    for(j=9;j>6;j--){
        printf("%d\n",ar[j]);
    }

    return 0;
}