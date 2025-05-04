#include<iostream>
#include<string>
using namespace std;

int main()
{
  char s[21],tmp;
  int len;

  while(cin >> s){
    len = 0;
    while(s[len++]);
    for(int i=0;i<(len-1)/2;i++){
      tmp = s[i];
      s[i] = s[len-i-2];
      s[len-i-2] = tmp;
    }
    s[len-1] = '\0';

    cout << s << endl;
  }
  return 0;
}