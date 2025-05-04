#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
 
typedef long long ll;
typedef pair<int, int> ii;
 
int main(){

	vector<int> ans(5);
	rep(i, 5) cin >> ans[i];
	SORT(ans);
	rep(i, 5){
		cout << ans[4-i];
		if(i != 4) cout << " ";
	}
	cout << endl;
	
	return 0;
}