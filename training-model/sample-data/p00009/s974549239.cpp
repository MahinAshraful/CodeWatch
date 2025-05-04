#include <stdio.h>
 #include <string.h>
int main(void) {
    int n,i,c,k,prime[999999] = {0},t;
    for(i = 2; 999999 >= i; i++){
        if(!prime[i])
    		for(c = i*2; 999999 >= c; c += i)prime[c] = 1;
    }
    while(scanf("%d",&n) != EOF){
    	i = 0;
    for(c = 2; n >= c; c++){
        	if(!prime[c]) i++;
        }
    printf("%d\n",i);
    }
     
    return 0;
}