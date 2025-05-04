#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main()
{
  int n;
  stack<int> st;
  while(1){
    cin >> n;
    if ( cin.eof() ) break;
    if(n == 0) {
      cout << st.top() << endl;
      st.pop();
    }
    else st.push(n);
  }
}