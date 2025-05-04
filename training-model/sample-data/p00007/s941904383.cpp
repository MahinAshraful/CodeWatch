#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int now = 100000;
	for(int i = 0; i < n; i++)
	{
		now = now * 105 / 100;
		if(now % 1000 != 0)
		{
			now = (now / 1000 + 1) * 1000;
		}
	}
	printf("%d\n",now);
	return 0;
}