#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int a,b, s;
    while(scanf("%d%d", &a, &b)!=EOF){
        s=__gcd(a, b);
        printf("%d %d\n", s, (a/s)*b);              
                        
    }  
    return 0;
}