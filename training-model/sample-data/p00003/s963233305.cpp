#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int a[3];
    int n;

    scanf("%d", &n);
    while(n>0) {
        scanf("%d %d %d", &a[0], &a[1], &a[2]);
        sort(a, a+3);
        if(a[0]*a[0] + a[1]*a[1] == a[2] * a[2]) {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        n--;
    }
}