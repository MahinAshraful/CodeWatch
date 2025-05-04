#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;

int main(void){
	long n;
	int a;
	while(scanf("%d", &n) != EOF){
		vector<bool>p;
		for(int i = 0; i <= n; i++) p.push_back(true);
		p[0] = false;
		p[1] = false;
		for(int i = 2; i < sqrt(n)+1; i++){
			if(p[i]){
				for(int j = 0; i*(j+2) <= n; j++){
					p[i*(j+2)] = false;
				}
			}
		}
		int count = 0;
		for(int i = 2; i <= n; i++){
			if(p[i]) count++;
		}
		cout << count << endl;
	}
	return 0;
}