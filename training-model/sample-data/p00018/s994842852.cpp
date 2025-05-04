#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

int a[5];

int main(){
	REP(i,5){
		cin>>a[i];
	}
	sort(a,a+5);
	REP(i,5){
		if (i) cout<<" ";
		cout<<a[4-i];
	}
	cout<<endl;
	return 0;
}