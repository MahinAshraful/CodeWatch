#include<stdio.h>
int main(void)
{
	int n,s[100],i=0;
	while(scanf("%d",&s[i])!=EOF){
		if(s[i]==0){
			i--;
			printf("%d\n",s[i]);
		}
		else {
			i++;
		}
	}
	return 0;
}