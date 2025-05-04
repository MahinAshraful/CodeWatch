#include<iostream>
#include<string>

using namespace std;

int main()
{
  string str;
  cin >> str;

  for ( size_t i = 0; i < str.size(); i++ )
    cout << str[str.size()-1-i];

  cout << endl;
  
  return 0;
}