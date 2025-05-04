#include <cstdio>

using namespace std;

int main() {
	double a, b, c, d, e, f;
	double _b, _c, _e, _f;
	double x, y;

	while (scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f) != EOF) {
	    _b = b * d;
	    _c = c * d;
	    _e = e * a;
	    _f = f * a;
	    
	    y = (_c - _f) / (_b - _e);
	    x = (c - b * y) / a;
	    
	    printf("%.3f %.3f\n", x, y);
	}
	
	return 0;
}