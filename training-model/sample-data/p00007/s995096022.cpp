#include<iostream>
#include<string>
using namespace std;

int main(void) {

	//0005
	/*
	int a, b, G, R, L, r;
	while (cin >> a >> b) {
		R = a;
		L = b;
		int tmp;
		if (b > a) {
			tmp = a;
			a = b;
			b = tmp;
		}
		while (1) {
			r = a%b;
			if (r == 0)break;
			a = b;
			b = r;
		}
		G = b;
		R = R / G;
		L = L / G;
		cout << G << " " << R*L * G << endl;
	}
	*/
	//0006
	/*
	string name;
	cin >> name;
	int L = name.size();
	string Ans;
	for (int i = 0; i < L; i++) {
		Ans += name.substr(L-i-1, 1);
	}
	cout << Ans << endl;
	*/
	//0007
	int Dept = 100000;
	int week;
	cin >> week;
	for (int i = 0; i < week; i++) {
		Dept = Dept * 1.05;
		if (Dept % 1000 == 0) {
			Dept = (Dept / 1000);
		}
		else {
			Dept = (Dept / 1000 + 1);
		}
		Dept = Dept * 1000;
	}
	cout << Dept << endl;

	return 0;
}