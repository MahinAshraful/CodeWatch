#include<stdio.h>
#include<algorithm>
int main(){
    int a[10];
    for(int i=0;i<10;i++)scanf("%d",&a[i]);
    std::sort(a,a+10);
    printf("%d\n%d\n%d\n",a[9],a[8],a[7]);
}