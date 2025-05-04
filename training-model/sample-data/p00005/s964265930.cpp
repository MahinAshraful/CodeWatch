#include<stdio.h>
int main(void)
{
	int x,y,temp,X,xx,yy,sb;
	while(scanf("%d %d",&x,&y)!=EOF){
		xx=x; yy=y;
		if(x<=y){
			temp=x;
			x=y;
			y=temp;
		}
		while(1){
			if(y==0)break;
			X=x%y;
			x=y;
			y=X;
		}
		sb=(xx/x)*(yy/x)*x;
		printf("%d %d\n",x,sb);
	}
	return 0;
}	