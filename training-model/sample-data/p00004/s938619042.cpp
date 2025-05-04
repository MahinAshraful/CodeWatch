#include<stdio.h>
#define N 1000000
struct{int a[6];}data[N];

int main(){
    int i,j,L;
    double a,b,c,d,e,f;
    double x,y;
    for(i=0; i<N; i++){
        for(j=0;j<6;j++)
            if(scanf("%d",&data[i].a[j])==EOF)break;
        if(j==0)break;
    }
    L=i;
    for(i=0;i<L;i++){       
        a=data[i].a[0]; b=data[i].a[1]; c=data[i].a[2]; d=data[i].a[3]; e=data[i].a[4]; f=data[i].a[5];
        x=(1/(a*e-b*d))*(e*c-b*f);
        y=(1/(a*e-b*d))*(a*f-d*c);
        if(x==-0)x=0;
        if(y==-0)y=0;
        printf("%4.3f %4.3f\n",x,y);
    }
    return 0;
}