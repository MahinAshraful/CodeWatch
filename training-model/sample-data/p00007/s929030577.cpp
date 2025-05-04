#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

int main(){
	int n;
	int ans=100000;
	cin >> n;
	for(int i=0;i<n;i++){
		ans*=1.05;
		if(ans%1000 != 0){
			ans+=1000;
			ans-=ans%1000;
		}
	}
	cout << ans << endl;
}