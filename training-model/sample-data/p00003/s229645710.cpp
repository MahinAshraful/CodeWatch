#include <stdio.h>

int
main(void)
{
	char line[80];
	int n;
	int a;
	int b;
	int c;
	bool r;

	if (gets(line) == NULL) {
		return 1;
	}
	if (sscanf(line, "%d", &n) != 1) {
		return 1;
	}
	
	for (int i = 0; i < n; i++) {
		if (gets(line) == NULL) {
			return 1;
		}
		if (sscanf(line, "%d %d %d", &a, &b, &c) != 3) {
			return 1;
		}
		r = false;
		if (a > b && a > c) {
			r = (a*a == b*b + c*c);
		} else if (b > a && b > c) {
			r = (b*b == a*a + c*c);
		} else if (c > a && c > b) {
			r = (c*c == a*a + b*b);
		}
		printf("%s\n", (r ? "YES" : "NO"));
	}

	return 0;
}