#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
#define FOR(i,n) for(i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

int a[100];

int main(){
	int w,n;
	cin>>w>>n;
	rep(i,w)a[i]=i+1;
	rep(i,n){
		int x,y;
		scanf("%d,%d",&x,&y);
		int t=a[x-1];
		a[x-1]=a[y-1];
		a[y-1]=t;
	}
	rep(i,w)cout<<a[i]<<endl;
	return 0;
}