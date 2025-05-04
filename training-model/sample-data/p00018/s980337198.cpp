#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<list>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<string>
using namespace std;

bool order(int a,int b){
	return a>b;
}	

int main(){
	vector<int> w;
	for(int x=0;x<5;++x){
		int j;scanf("%d",&j);
		w.push_back(j);
	}
	sort(w.begin(),w.end(),order);
	for(int x=0;x<4;++x){
		cout<<w[x]<<" ";
	}
	cout<<w[4]<<endl;
	return 0;
}	