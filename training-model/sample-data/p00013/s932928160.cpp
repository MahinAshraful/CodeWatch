#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main() {
  stack<int> c;
  queue<int> q;

  int n;
  while(cin >> n) {
    if(n == 0) {
      int s = c.top();
      q.push(s);
      c.pop();
    }else {
      c.push(n);
    }
  }

  while(!q.empty()) {
    cout << q.front() << endl;
    q.pop();
  }

  return 0;
}