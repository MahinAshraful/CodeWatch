#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
	char s[20],t;
	for(int i=0;i<20;i++){
		s[i]=0;
	}
	gets(s);
	for(t=0;s[t]!=0;t++){
	}
	for(int i=0;i<t;i++){
		cout << s[t-i-1] ;
	}
	cout << "\n" ;
	
return 0;
}