#include <iostream>
#include <string>
using namespace std;

string triangle(int x,int y,int z){
  if(x*x==y*y+z*z) return "YES";
  else if(y*y==z*z+x*x) return "YES";
  else if(z*z==x*x+y*y) return "YES";
  else return "NO";
}

int main()
{
  int n,a,b,c;
  cin >> n;
  
  for(int i=0;i<n;i++){
    cin >> a >> b >> c;
    string str=triangle(a,b,c);
    cout << str << endl;
  }
  return 0;
}