#include <iostream>
#include <stack>

using namespace std;
int main(int ac, char **av) {
  stack<int> st;
  int t;

  while (cin >> t) {
    if (t == 0) {
      cout << st.top() << endl;
      st.pop();
    } else {
      st.push(t);
    }
  }
  return 0;
}