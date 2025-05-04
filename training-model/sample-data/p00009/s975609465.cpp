#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#define F first
#define S second
using namespace std;
typedef pair<int, int> P;
const int INF = 1 << 30, MAX_N = int(1e6);


int main(){

  int n, i, j, maxin = 2;
  bool jud;
  vector <int> vec;
  for(i = 2;i <= MAX_N; i++){
        jud = 0;
        for(j = 0;  j < vec.size() ; j++){
          if(vec[ j ] * vec[ j ] > i) break;
          if( !( i % vec[ j ] ) ){
            jud = 1;
            break;
          }
        }
        if(!jud)
          vec.push_back( i );
      }
  while(cin >> n){
    cout << upper_bound(vec.begin(), vec.end(), n) - vec.begin()   <<endl;
  }
}