#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a;
  for(int i=0;i<5;i++){
    int b;cin>>b;
    a.push_back(b);
  }
  sort(a.begin(),a.end());
  for(int i=0;i<5;i++){
    cout<<a[4-i];
    if(i!=4)
      cout<<" ";
  }cout<<endl;
  return 0;
}