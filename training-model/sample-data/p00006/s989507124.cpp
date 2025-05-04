#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<complex>
using namespace std ;
typedef vector<int> vi ;
typedef vector<vi> vvi ;
typedef vector<string> vs ;
typedef pair<int, int> pii; 
typedef long long ll ;

#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define rep(i,a) loop(i,0,a)
#define all(a) (a).begin(),(a).end()

int main(void){
  string str;
  cin>>str;
  for(int i = str.size()-1 ; i >= 0 ; --i)
    cout<<str[i];
  cout<<endl;
}