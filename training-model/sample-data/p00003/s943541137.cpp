#include <iostream>
#include <vector>
#include <algorithm>

#define ALL(a) a.begin(),a.end()

using namespace std;

int main()
{
  int n;
  cin >> n;

  for ( int i = 0; i < n; i++ ) {
    vector<int> v;
    int t;
    for ( int j = 0; j < 3; j++ ) {
      cin >> t;
      v.push_back( t );
    }
    sort(ALL(v));

    if ( v[0] * v[0] + v[1] * v[1] == v[2] * v[2] )
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}