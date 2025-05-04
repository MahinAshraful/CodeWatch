#include<iostream>
#include<iomanip>
#include<memory>
#include<array>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
  int n;

  while ( cin >> n )
    {
      unique_ptr<int[]> tbl(new int[n+1]);
      for ( int i = 2; i <= n; i++ )
        tbl[i] = 1;

      for ( int i = 2; i <= n; i++ )
        if ( tbl[i] == 1 )
          {
            int j = i * 2;
            while ( j <= n )
              {
                tbl[j] = 0;
                j += i;
              }
          }

      int ret = 0;
      
      for ( int i = 2; i <= n; i++ )
        ret += tbl[i];

      cout << ret << endl;
    }
  
  return 0;
}