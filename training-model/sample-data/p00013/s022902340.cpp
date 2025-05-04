#include <stdio.h>
int main(){
  int a = 0, i, data[100] = {0};
  while(scanf("%d", &a) != EOF){
    if(a == 0){
      printf("%d\n", data[i]);
      i --;
    }else{
      i ++;
      data[i] = a;
    }
  }
  return 0;
}