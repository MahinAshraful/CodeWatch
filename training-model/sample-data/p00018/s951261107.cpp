#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>


using namespace std;

int main()
{
	int hoge[5];
	for (int i = 0; i < 5; ++i)
		scanf("%d", hoge+i);
	sort(hoge, hoge+5, greater<int>());
	for (int i = 0; i < 4; ++i)
		printf("%d ", hoge[i]);
	printf("%d\n", hoge[4]);

	return 0;
}