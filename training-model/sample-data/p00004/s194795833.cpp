#include <stdio.h>
#include <math.h>

static double
round3(double r)
{
	r *= 1000.0;
	r = round(r);
	r /= 1000.0;
	
	if (r == -0) {
		r = 0;
	}
	
	return r;
}

int
main(void)
{
	char line[80];
	double a;
	double b;
	double c;
	double d;
	double e;
	double f;
	double x;
	double y;

	while (gets(line)) {
		if (sscanf(line, "%lf %lf %lf %lf %lf %lf",
				   &a, &b, &c, &d, &e, &f) == 6) {
			x = (e*c  -b*f)/(a*e - b*d);
			y = (d*c - a*f)/(d*b - a*e);
			
			printf("%.3f %.3f\n", round3(x), round3(y));
		}
	}

	return 0;
}