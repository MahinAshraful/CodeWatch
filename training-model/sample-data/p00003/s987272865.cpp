#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n, v[5];
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			cin >> v[j];
		}
		
		sort(v, v+3, greater<int>());
		
		if(v[0]*v[0] == v[1]*v[1] + v[2]*v[2]){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}

	}
	
}