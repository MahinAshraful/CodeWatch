#include<bits/stdc++.h>
using namespace std;

int parse(string a){
int s=0;
for(char b:a){
	s*=10;
	s+=b-48;
}
return s;
}
vector<int>split(string a){
	vector<int>b;
	string c="";
	for(char d:a){
		if(d==','){b.push_back(parse(c));c="";}
		else c+=d;
	}
	b.push_back(parse(c));
	return b;
}
int main(){
	int a[30];
	int b,c;
	scanf("%d%d",&b,&c);
	for(int d=0;d<b;d++){
		a[d]=d;
	}
	for(int e=0;e<c;e++){
		string f;
		cin>>f;
		vector<int>g=split(f);
		int h=a[g[0]-1];
		a[g[0]-1]=a[g[1]-1];
		a[g[1]-1]=h;
	}
	for(int x=0;x<b;x++){
		printf("%d\n",a[x]+1);
	}
}