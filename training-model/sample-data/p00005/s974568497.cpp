#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int a,b,gcd,lcm;
	while(cin >> a >> b){
		int c=a,d=b;
		lcm=gcd=1;
		for(int i = 2; i < c || i < d;){
			if(c%i==0&&d%i==0){
				c/=i;
				d/=i;
				lcm=gcd*=i;
			}else i++;
		}
		lcm*=c*d;
		cout << gcd << " " << lcm << endl;
	}
	return 0;
}