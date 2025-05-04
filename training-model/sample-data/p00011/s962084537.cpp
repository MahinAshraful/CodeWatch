#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main(void){

	int w, n;
	int left[30] = {}, right[30] = {};
	int ans[30] = {};
	scanf("%d%d", &w, &n );
	for( int i = 0; i < n; i++ ) {
		scanf("%d,%d", left + i, right + i);
		left[i] --;
		right[i] --;
	}
	for( int i = 0; i < w; i++ ) {
		int tmp = i;
		for( int j = 0; j < n; j++ ) {
			if( tmp == left[j] )
				tmp = right[j];
			else if( tmp == right[j] )
				tmp = left[j];
		}
		ans[tmp] = i + 1;
	}
	for( int i = 0; i < w; i++ )
		cout << ans[i] << endl;


    return 0;
}