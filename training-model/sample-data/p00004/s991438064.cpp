#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back

# define inOut(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout);
# define RESET(a) memset(a,0,sizeof(a))
# define MEMO(a) memset(a,-1,sizeof(a))
# define DEBUG puts("Debug-Has-Come-Until-Here")


typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main(){
	cin.tie(NULL);
	
	int a,b,c,d,e,f;
	double x,y;
	while(scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f) != EOF){
		//DEBUG;
		x = (double)(c*e - b*f)/(double)(a*e - b*d);
		y = (double)(c*d - a*f)/(double)(b*d - e*a);
		if (fabs(x) < 0.001) x = fabs(x);
		if (fabs(y) < 0.001) y = fabs(y);
		printf("%.3lf %.3lf\n", x,y);
	}

	return 0;
}