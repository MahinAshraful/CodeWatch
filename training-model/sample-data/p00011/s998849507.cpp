#include<bits/stdc++.h>
using namespace std;

int main(){
  int w, n, wd[31];
  for(int i = 0; i < 31; i++) wd[i] = i+1;
  cin >> w;
  cin >> n;
  for(int i = 0; i < n; i++){
    int a, b, tmp;
    scanf("%d,%d", &a, &b);
    tmp = wd[a-1];
    wd[a-1] = wd[b-1];
    wd[b-1] = tmp;
  }

  for(int i = 0; i < w; i++){
    cout << wd[i] << endl;
  }
}