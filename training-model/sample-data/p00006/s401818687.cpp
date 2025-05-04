#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
int main(){
	char s[21];
	int n;
	scanf("%s", s);
	rep(i, 21) if(s[i]=='\0') n=i-1;
	for(int i=n; i>=0; i--) cout << s[i];
	cout << endl;
    return 0;
}