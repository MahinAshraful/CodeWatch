#include <stdio.h>
#include <stdlib.h>

long long GCD(long long a,long long b){
    if(b!=0){
        GCD(b,a%b);
    }
    else{
        return a;
    }

}

int main()
{
    long long a,b,x;

    while(scanf("%lld %lld",&a,&b)!=EOF){
        if(a==0 || b==0){
            printf("0 0\n");
            continue;
        }
        else if(a<b){
            x=a;
            a=b;
            b=x;
        }
        x=GCD(a,b);
        printf("%lld %lld\n",x,(a/x)*b);

    }
}