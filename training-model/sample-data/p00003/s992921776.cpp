#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int main(void)
{
	int i,x,suu,cnt;
	int hen[3];
	cnt=0;
	scanf("%d",&suu);
	while(!(suu==cnt)){
		cnt++;
		for(i=0;i<3;i++){
			scanf("%d",&hen[i]);
		}
		sort(hen,hen+3,greater<int>());
		if(hen[2]*hen[2]+hen[1]*hen[1]==hen[0]*hen[0]){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}