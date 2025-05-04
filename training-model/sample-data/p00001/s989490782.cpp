#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long I;
#define REP(i , x) for(int i = 0 ; i < x ; ++i)

int mo[10];

int main()
{
	REP(i, 10){
		cin >> mo[i];
	}
	sort(mo, mo + 10);

	cout << mo[9] << endl;
	cout << mo[8] << endl;
	cout << mo[7] << endl;

	return 0;
}