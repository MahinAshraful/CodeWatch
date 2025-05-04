#include<iostream>

using namespace std;
 
int main(){
 
 int tri[1000][3];
 int a,b,c,N;
 
 cin >> N;
 
 for(int i = 0; i < N; i++){
 
  cin >> tri[i][0] >> tri[i][1] >> tri[i][2];
 
  a = tri[i][0]*tri[i][0];
  b = tri[i][1]*tri[i][1];
  c = tri[i][2]*tri[i][2];

 if(a == b+c || b == a+c || c == a + b)
  cout << "YES" << endl;
 else
  cout << "NO" << endl;
 }
 return 0;
}