#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int w, n, num[31], damy, i, j, bou1, bou2;

	cin >> w >> n;

	for(i = i; i <= w; i++){
		num[i] = i;
	}

	for(i = 0; i < n; i++){
		scanf("%d,%d", &bou1, &bou2);
		damy = num[bou1];
		num[bou1] = num [bou2];
		num[bou2] = damy;
	}

	for(i = 1; i <= w; i++){
		cout << num[i] << endl;
	}
	return 0;
}