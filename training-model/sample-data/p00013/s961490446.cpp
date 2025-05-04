#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int n[100],k;
	
	k=0;
	while(cin >> n[k]){
		if(n[k]==0){
			cout << n[k-1] << "\n";
			k--;
		}
		else{
			k++;
		}
	}
		
return 0;
}