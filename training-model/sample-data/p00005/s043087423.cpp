#include <stdio.h>

int
main(void)
{
	char line[80];
	unsigned long a;
	unsigned long b;

	while (gets(line)) {
		if (sscanf(line, "%lu %lu", &a, &b) == 2) {
			unsigned long x = a;
			unsigned long y = b;
			unsigned long q;
			unsigned long r;
			while (true) {
				q = x / y;
				r = x - q * y;
				if (r == 0) {
					break;
				}
				x = y;
				y = r;
			}
			printf("%lu %lu\n", y, (a/y)*b);
		}
	}

	return 0;
}