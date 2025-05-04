#include <stdio.h>
 
using namespace std;
 
 
int main(){
    int n,a,b,c,A,B,C;
    scanf("%d",&n);
 
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&a,&b,&c);
        A = a*a;
        B = b*b;
        C = c*c;
        if(A+B==C||B+C==A||C+A==B){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
 
    return 0;
}
