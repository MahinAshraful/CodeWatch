//#define _USE_MATH_DEFINES
#include <iostream>
//#include <stdio.h>
//#include <iomanip>
#include <vector>
//#include <string>
//#include <algorithm>
//#include <functional>
//#include <cmath>

using namespace std;


long money(long m,int n){
	//5%?????? + 1000??????????????????
	const int u = 1000;

	if (n <= 0){
		return m;
	}
	else{
		m = m * 1.05;
		m = (m + u - 1) / u * u;
		n--;
		money(m, n);
	}
	
}


int main(){

	int n;
	long m = 100000;

	cin >> n;

	m = money(m, n);


	cout << m << endl;


	return 0;
}