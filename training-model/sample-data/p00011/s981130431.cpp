#include <iostream>

using namespace std;

int main(){
	int w, n;
	cin >> w >> n;
	int s[w];

	for(int i=0; i<w; i++){
		s[i] = i+1;
	}

	for(int t=0; t<n; t++){
		int a, b;
		char c;
		cin >> a >> c >> b;
		swap(s[a-1], s[b-1]);
	}

	for(int i=0; i<w; i++){
		cout << s[i] << endl;
	}

	return 0;
}