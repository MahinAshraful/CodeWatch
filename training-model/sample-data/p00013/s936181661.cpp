/*
 * Problem     : AOJ0013
 * Title       : Switching Railroad Cars
 * Author      : mizo0203
 * Copyright   : Your copyright free
 * Description : スタック
 */

#include <stdio.h>
#include <stack>
using namespace std;

int cn; // car number or 0
stack<int> st;

bool input() {

  if (scanf("%d", &cn) == EOF)
    return false;

  return true;
}

int main() {

  while (input()) {
    if (cn) st.push(cn);
    else {
      printf("%d\n", st.top());
      st.pop();
    }
  }

  return 0;
}