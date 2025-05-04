#include<iostream>
#define N 999999
int p[(N+1)/2];int m[N+1];void k();using namespace std;main(){int n;p[0]=2;m[1]=0;m[2]=1;k();while(cin>>n){cout<<m[n]<<endl;}}void k(){int i,j,e=1;for(i=3;i<N+1;i++){for(j=0;p[j]*p[j]<=i;j++){if(i%p[j]==0){goto tag;}}p[e]=i;e++;tag:m[i]=e;}}