#include<stdio.h>

int w,n;
int a[31];
int x,y;
int k;

int main(){
	for(int i=1;i<31;i++){
		a[i]=i;
	}
	scanf("%d %d",&w,&n);
	for(int i=1;i<=n;i++){
		scanf("%d,%d",&x,&y);
		k=a[x];
		a[x]=a[y];
		a[y]=k;
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}