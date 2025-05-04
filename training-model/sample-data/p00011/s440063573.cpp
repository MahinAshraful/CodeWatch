#include <bits/stdc++.h>

using namespace std;

int main() {
	int w, n;
	cin >> w >> n;

	int kuji[n];
	for (int i = 1; i <= w; i++) kuji[i] = i;

	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d, %d", &a, &b);
		int tmp = kuji[a];
		kuji[a] = kuji[b];
		kuji[b] = tmp;
	}

	for (int i = 1; i <= w; ++i) {
		cout << kuji[i] << endl;
	}
}