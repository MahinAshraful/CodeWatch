#include <iostream>
#include <string>
using namespace std;

main() {
  string s; cin>>s;
  for(string::reverse_iterator it = s.rbegin();it!=s.rend();it++)
    cout << * it;
  cout << endl;
}