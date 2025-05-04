#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define MAX_N 1000001

int main(){
	int *count;
	count=(int *)malloc(sizeof(int)*MAX_N);
	int cnt=0;
	bool *a;
	a= (bool *)malloc(sizeof(bool)*MAX_N);
	a[1]=true;

	for(int i=2;i<MAX_N;i++){
		count[i]=cnt;
		if(a[i])continue;
		cnt++;
		count[i]++;
		//int k=1;
		long int k=i;//i??\???????????????????????????
		while(i*k<MAX_N){
			a[i*k]=true;
			k++;
		}

	}

	int n;
	while(cin >> n){
		cout << count[n] << endl;
	}
	return 0;
}