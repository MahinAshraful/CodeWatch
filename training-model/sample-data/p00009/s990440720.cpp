#include<stdio.h>
#include<math.h>

int main(){
	int ans[1000000];
	int count=2;
	
	for(int i=4;i<1000000;i++){
		bool p=true;
		double sqrti = i;
		for(int j=2;j<=sqrt(sqrti);j++){
			if(i % j == 0){
				p=false;
				break;
			}
		}
		if(p){
			count++;
			ans[i]=count;
			}
		else ans[i]=count;
	}
	ans[1] = 0;
	ans[2] = 1;
	ans[3] = 2;
	
	int n;
	
	while(scanf("%d",&n)==1){
		printf("%d\n",ans[n]);
	}
	return 0;
}