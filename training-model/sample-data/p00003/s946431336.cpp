#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int a,testcase;
int input[3];

int main()
{
	scanf("%d",&testcase);
	for(a=1;a<=testcase;a++)
	{
		scanf("%d %d %d",&input[0],&input[1],&input[2]);
		sort(input,input+3);
		if(input[0]*input[0]+input[1]*input[1]==input[2]*input[2])
		{
			printf("YES\n");
		}
		else
		printf("NO\n");
	}
	return 0;
}