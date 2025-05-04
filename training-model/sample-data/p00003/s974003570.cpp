#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cstdio>
#include<cmath>
#define pb push_back
#define mp make_pair
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) loop(i,0,b)
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
using namespace std;
int main(){
	int n;
	cin>>n;
	rep(i,n){
		vector<int>in(3);
		rep(j,3)cin>>in[j];
		sort(all(in));
		if(in[0]*in[0]+in[1]*in[1]==in[2]*in[2])cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}