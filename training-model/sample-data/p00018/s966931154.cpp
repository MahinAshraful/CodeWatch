#include<stdio.h>

int main()
{
	int a[5], i, j, tmp;
	scanf("%d %d %d %d %d", &a[0],&a[1],&a[2],&a[3],&a[4]);
	loop:
	for (j = 0;j<4; j++)
	{
		if (a[j] < a[j+1])
		{
			tmp = a[j+1];
			a[j+1] = a[j];
			a[j] = tmp;
		}
	}
	for (i = 0; i < 4; i++)
	{
		if (a[i] < a[i + 1])goto loop;
	}
	printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
	return 0;
}