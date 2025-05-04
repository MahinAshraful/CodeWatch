#include <stdio.h>
#include <string.h>

int main(void){
	int week,money=100000,i;
	scanf("%d",&week);
	for(i=1;i<=week;i++){
		money=money*1.05;
		if(money%1000!=0){
			money=money+(1000-money%1000);
		}
	}
	printf("%d\n",money);
}