#include <stdio.h>
#include <vector>

int main() {
  int i;
  int cnt = 0;
  std::vector<int> vec;
  while(cnt < 50) {
    scanf("%d", &i);
    if(i == 0){
      printf("%d\n", vec.back());
      vec.pop_back();
    }else{
      vec.push_back(i);
    }
    cnt++;
  }
  return 0;
}
       