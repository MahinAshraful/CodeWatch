#include <iostream>
using namespace std;

int GCD(int a, int b)
{
 if(a%b == 0)
  return b;

 GCD(b, a%b);
}

int LCM(int a, int b)
{
 int c = GCD(a, b);

 return a*(b/c);
}

int main()
{
 int a, b;

 while( cin >> a >> b){
  cout << GCD(a, b) << ' ' << LCM(a, b) << '\n';
 }

 return 0;
}