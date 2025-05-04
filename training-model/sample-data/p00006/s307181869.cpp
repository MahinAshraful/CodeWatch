#include<stdio.h>
#include<string.h>
char a[21];
int main()
{
	while (gets(a))
	{
		for (int i = strlen(a) - 1; i >= 0; i--)
			printf("%c", a[i]);
		printf("\n");
	}
	
	return 0;

}