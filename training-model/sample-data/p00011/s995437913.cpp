#include <stdio.h>

int
main(void)
{
	char line[80];
	int w;
	int n;

	if (fgets(line, sizeof line, stdin) == NULL) {
		return 1;
	}
	if (sscanf(line, "%d", &w) != 1) {
		return 1;
	}

	if (fgets(line, sizeof line, stdin) == NULL) {
		return 1;
	}
	if (sscanf(line, "%d", &n) != 1) {
		return 1;
	}

	int a[n];
	int b[n];

	for (int i = 0; i < n; i++) {
		if (fgets(line, sizeof line, stdin) == NULL) {
			return 1;
		}
		if (sscanf(line, "%d,%d", &(a[i]), &(b[i])) != 2) {
			return 1;
		}
	}

	int r[w];
	for (int i = 1; i <= w; i++) {
		int k = i;
		for (int j = 0; j < n; j++) {
			if (a[j] == k) {
				k = b[j];
			} else if (b[j] == k) {
				k = a[j];
			}
		}
		r[k-1] = i;
	}

	for (int i = 0; i < w; i++) {
		printf("%d\n", r[i]);
	}

	return 0;
}