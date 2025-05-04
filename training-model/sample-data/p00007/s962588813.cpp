#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long > vll;
typedef vector< vi > vvi;
int main() {
	int n,m=100000;
	cin>>n;
	for(int i=0;i<n;i++){
			m +=m/20;
		if(m%1000!=0){
			m=m-m%1000+1000;
		}
	}
	cout<<m<<endl;
}