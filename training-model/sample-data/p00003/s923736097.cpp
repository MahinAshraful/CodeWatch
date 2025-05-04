#include<iostream>
using namespace std;
int main(){
	int n,a,a2,b,b2,c,c2;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a >> b >> c;
		a2=a*a; b2=b*b; c2=c*c;
		if(a2+b2==c2||a2+c2==b2||b2+c2==a2)cout << "YES" <<endl;
		else cout << "NO" << endl;
	}
	return 0;
}