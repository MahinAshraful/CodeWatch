#include <iostream>
using namespace std;

int sieve_of_eratosthenes(int n){
  int p = 0; //素数の数
  int primes[n];
  bool is_prime[n+1]; 
  for(int i=0;i<=n;i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false; //0,1は素数じゃない
  for(int i=2;i<=n;i++){
    if(is_prime[i]){
      primes[p++] = i;
      for(int j= i*2;j<=n;j+=i) is_prime[j] = false;
    }
  }
  return p;
}

int main(){
  int n;
  while(cin >> n){
    cout << sieve_of_eratosthenes(n) << endl;
  }
}