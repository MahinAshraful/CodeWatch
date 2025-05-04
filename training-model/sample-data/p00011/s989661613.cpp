#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define rp(a) while(a--)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main(){
	int n,m;
	cin>>m>>n;
	vector<int>out(m);
	rep(i,m)out[i]=i+1;
	rep(i,n){
		int a,b;
		char d;
		cin>>a>>d>>b;
		swap(out[a-1],out[b-1]);
	}
	rep(i,m)cout<<out[i]<<endl;

}