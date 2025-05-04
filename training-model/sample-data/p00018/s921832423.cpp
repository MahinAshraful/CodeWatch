#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<int> v(5);
  for(int i = 0 ; i < 5 ; i++){
    cin >> v[i];
  }
  sort(v.rbegin(),v.rend());
  bool flg = false;
  for(auto x : v){
    if(flg){ cout << " "; }
    flg = true;
    cout << x;
  }
  cout << endl;
  return 0;
}