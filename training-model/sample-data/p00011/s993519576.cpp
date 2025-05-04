#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int w,n;
  scanf("%d %d",&w,&n);
  int left[n];
  int right[n];
  int ans[w+1];
  for(int i=0;i<n;i++) {
    scanf("%d,%d",&left[i],&right[i]);
  }
  for(int i=1;i<=w;i++) {
    int state = i;
    int t = 0;
    while(t<n) {
      if(left[t] == state) {
        state = right[t];
      }
      else if(right[t] == state) {
        state = left[t];
      }
      t++;
    }
    ans[state] = i;
  }
  for(int i=1;i<=w;i++) {
    printf("%d\n",ans[i]);
  }
}