//#define _USE_MATH_DEFINES
#include <iostream>
//#include <stdio.h>
//#include <iomanip>
#include <vector>
//#include <string>
//#include <algorithm>
//#include <functional>
//#include <cmath>
//#include <time.h>

using namespace std;


int main(){

	int w, n;
	int a, b;
	char c;
	vector <int> aa;

	cin >> w;

	for (int i = 0; i < w; i++){
		aa.push_back(i + 1);
	}
	
	cin >> n;

	while (n--){
		cin >> a >> c >> b;
		swap(aa[a - 1], aa[b - 1]);
	}

	for (int i = 0; i < w; i++){
		cout << aa[i] << endl;
	}


	return 0;
}