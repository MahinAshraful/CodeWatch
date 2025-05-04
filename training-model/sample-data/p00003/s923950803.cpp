#include<iostream>
#include<cmath>
using namespace std;
 
int main() {
	int len[3];
	int N;
	cin >> N;
	for (int j = 0; j < N; j++) {
		cin >> len[0] >> len[1] >> len[2];
		for (int i = 0; i < 3; i++) {
			len[i] = len[i] * len[i];
		}
		if (len[0] + len[1] == len[2] ||
			len[1] + len[2] == len[0] ||
			len[2] + len[0] == len[1])
		{
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

    return 0;
}