#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int w, n, b, c, p;
	int a[31];

	cin >> w >> n;

	for (int i = 1; i <= w; i++){
		a[i] = i + 1;
	}
	
	for (int i = 1; i <= n; i++){
		scanf("%d,%d", &b, &c);
		p = a[b];
		a[b] = a[c];
		a[c] = p;
	}

	for (int i = 1; i <= w; i++){
		printf("%d\n", a[i] - 1);
	}
}