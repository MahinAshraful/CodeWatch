#include <bits/stdc++.h>

using namespace std;

/*-------------------------------*/
#define FOR(i, a, b) for(int i = (a); i < (b); i++)  //a~(b - 1)?????§
#define print(i) cout << i << endl //?°??????????Python?????????
#define all(i) (i).begin(),(i).end() //??¨??????(sort??¨???)
#define mp make_pair //mp(OO, OO)??¨???:::pint??¨???

typedef long long ll;
typedef pair<int, int> pint;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<long long> llv;
typedef vector<pint> vpint;
/*-------------------------------*/

int main(void)
{
  int w, n, a, b; cin >> w >> n;
  int x[35];
  FOR(i, 0, w + 1) x[i] = i;

  FOR(i, 0, n){
    scanf("%d,%d", &a, &b);
    swap(x[a], x[b]);
  } 

  FOR(i, 1, w + 1) cout << x[i] << endl;

  return 0;
}