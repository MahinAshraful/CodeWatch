#include <bits/stdc++.h>

using namespace std;

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define INF 114514810
#define ELEM(array) (sizeof (array)/sizeof *(array))
#define MAX_N 100
#define SAFE_FREE(ptr) if( ptr != NULL ){ free(ptr); ptr = NULL; }
typedef unsigned int UINT;
typedef long long ll;

int main()
{
	vector<int> v;
	int n;
	while (cin>>n)
	{
		if (n != 0) v.push_back(n);
		else
		{
			cout << v.back() << endl;
			v.pop_back();
		}

	}
	return 0;
}