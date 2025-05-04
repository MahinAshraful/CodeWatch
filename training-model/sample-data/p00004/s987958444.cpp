#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	double a, b, c, d, e, f, x, y;
	while (cin >> a >> b >> c >> d >> e >> f) {
		double bd = b*d;
		double ea = e*a;
		double cd = c*d;
		double fa = f*a;
		y = (cd - fa) / (bd - ea);
		x = (c - b*y) / a;
		printf("%.3f %.3f\n", x, y);
	}
}