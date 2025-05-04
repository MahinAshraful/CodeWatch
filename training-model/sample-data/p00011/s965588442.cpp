#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (l);i < (r);i++)
#define ALL(x) (x).begin(),(x).end()
template<typename T> bool chmax(T& a,const T& b){return a < b ? (a = b,true) : false;}
template<typename T> bool chmin(T& a,const T& b){return b < a ? (a = b,true) : false;}
typedef long long ll;

int W,N;

int main()
{
	scanf("%d%d",&W,&N);
	vector<int> A(W + 1);
	for(int i = 1;i <= W;i++){
		A [i] = i;
	}

	FOR(i,0,N){
		int x,y;
		char c;
		scanf("%d%c%d",&x,&c,&y);
		swap(A [x],A [y]);
	}
	for(int i = 1;i <= W;i++){
		printf("%d\n",A [i]);
	}

	return 0;
}