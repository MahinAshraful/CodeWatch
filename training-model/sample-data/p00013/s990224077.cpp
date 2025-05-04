#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	vector<int> a(100);
	int b;
	int i=0;
	while(cin>>b){
		if(b!=0){
			a[i]=b;
			i++;
		}
		else if(b==0){
			cout<<a.at(i-1)<<endl;
			a.erase(a.begin()+i-1);
			i--;
		}
	}
	return 0;
}