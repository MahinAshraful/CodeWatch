#include<iostream>
#include<algorithm>
using namespace std;
long long a,b;
int main(){
	while(cin>>a>>b){
		int D=__gcd(a,b);
		cout<<D<<' '<<a*b/D<<endl;
	}
}