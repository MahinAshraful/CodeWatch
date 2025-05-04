#include <stdio.h>
#include <stack>

int main() {
  int i;
  int cnt = 0;
  std::stack<int> st;
  while(cnt < 50) {
    scanf("%d", &i);
    if(i == 0){
      printf("%d\n", st.top());
      st.pop();
    }else{
      st.push(i);
    }
    cnt++;
  }
  return 0;
}