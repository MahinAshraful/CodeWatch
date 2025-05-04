#include <stack>

#include <stdio.h>

int main(int argc, char** argv)
{
  std::stack<int> stack;

  int i;

  while (fscanf(stdin, "%d", &i) == 1) {
    if (i) {
      stack.push(i);
    }
    else {
      fprintf(stdout, "%d\n", stack.top());
      
      stack.pop();
    }
  }
}