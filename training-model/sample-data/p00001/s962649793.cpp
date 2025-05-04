#include<stdio.h>
#include<algorithm>
using namespace std;
long long int nums[10];
void input()
{
	int i;
	for (i = 0; i < 10; i++)
		scanf("%lld", &nums[i]);
	sort(nums,nums+10);
	printf("%lld\n%lld\n%lld\n", nums[9], nums[8], nums[7]);
}
int main()
{
	input();
	return 0;
}