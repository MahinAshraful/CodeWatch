#include <stdio.h>

int main() {
	int a,i,k,m;
	int data[100] = {0};
	int output[100] = {0};
	while(scanf("%d", &a) != EOF) {
		if (a != 0) {
			for (k = 0; k < 100; k++) {
				if (data[k] == 0) {
					data[k] = a;
					break;
				}
			}
		}
		else {
			for (k = 0; k < 100; k++) {
				if (data[k] == 0) {
					for (m = 0; m < 100; m++) {
						if (output[m] == 0) {
							output[m] = data[k - 1];
							break;
						}
					}
					data[k - 1] = 0;
					break;
				}
			}
		}
	}
	for (i = 0; i < 100; i++) {
		if (output[i] != 0) {
			printf("%d\n", output[i]);
		}
	}
	return 0;
}