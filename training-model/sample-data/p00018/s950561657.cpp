#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, char const* argv[])
{
	int target[5];

	cin >> target[0] >> target[1] >> target[2] >> target[3] >> target[4];

	sort( target, target + 5, greater<int>() );

	for( int i = 0;i < 5;i++ ){
		cout << ( i == 0 ? "" : " " ) << target[i];
	}
	cout << endl;
	return 0;
}