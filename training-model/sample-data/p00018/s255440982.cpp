#include<cstdio>
#include<iostream>
int a[5];
int swa;
int change(int n){
    swa=a[n],a[n]=a[n-1],a[n-1]=swa;
}
int main(){
    for(int i=0;i<5;i++)
        scanf("%d",&a[i]);
    for(int i=4;i>=0;i--){
        for(int j=4;j>0;j--){
            if(a[j-1]<a[j])
                change(j);
        }
    }
    for(int i=0;i<4;i++)
        printf("%d ",a[i]);
        printf("%d\n",a[4]);
    return 0;
}