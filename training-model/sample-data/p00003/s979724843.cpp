#include <stdio.h>

int right(int x, int y, int z);

int main(void)
{
    int n, x, y, z;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
	scanf("%d %d %d", &x, &y, &z);
	if (right(x, y, z) == 1) {
	    printf("YES\n");
	} else {
	    printf("NO\n");
	}
    }
    return 0;
}

int right(int x, int y, int z)
{
    if (x * x == y * y + z * z) {
	return 1;
    } else if (y * y ==  x * x + z * z) {
	return 1;
    } else if (z * z == x * x + y * y) {
	return 1;
    } else {
	return 0;
    }
}