#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define loop(i, a, b) for(int i = a; i < b ; i++)
#define rep(i, a) loop(i, 0, a)
#define MAX 1000000

int main()
{
  bool prime[MAX];
  rep(i, MAX) prime[i] = true;
  prime[0] = prime[1] = false;
  loop(i, 2, sqrt(MAX)){
    for(int j = i * 2; j < MAX; j += i){
      prime[j] = false;
    }
  }
  
  int n;
  while(cin >> n) {
    int cnt = 0;
    loop(i, 2, n + 1) if(prime[i] == true) cnt++;
    cout << cnt << endl;
  }
}