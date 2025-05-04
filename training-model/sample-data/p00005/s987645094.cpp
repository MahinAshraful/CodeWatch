#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
	long a,b,c,ab;
	while(cin >> a >> b){
		ab=a*b;
		while(b!=0){
			a=a%b;
			c=b;b=a;a=c;
		}
		cout << a <<" " <<ab/a<<"\n";
	}
return 0;
}