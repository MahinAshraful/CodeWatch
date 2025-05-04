#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  while(!feof(stdin)) {
    int n, tmp, data[5];
    for(int i=0;i<5;i++) scanf("%d", &data[i]);
    if(feof(stdin)) break;
    for(int i=4;i>0;i--) {
      for(int j=0;j<i;j++) {
	if(data[j]<data[j+1]) {
	  tmp=data[j+1]; data[j+1]=data[j]; data[j]=tmp;
	}
      }
    }
      printf("%d %d %d %d %d\n",data[0], data[1], data[2], data[3], data[4]);
  }
}