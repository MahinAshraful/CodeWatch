#include<cstdio>
#include<string.h>

using namespace std;

int main(){
	static bool p[1000000];
	memset(p,true,sizeof(p));
	p[0] = false;
	p[1] = false;
	for(int i= 2;i<1000000;i++){
		if(p[i]){
			for(int j=i*2;j<1000000;j+=i){
				p[j] = false;
			}
		}
	}
	int n,ans;
	while(!(scanf("%d",&n)==EOF)){
		ans=0;
		for(int j=2;j<=n;j++){
			if(p[j])ans++;
		}
		printf("%d\n",ans);
	}
}