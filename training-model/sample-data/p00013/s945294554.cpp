#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
	stack<int> R;
	int n;
	int car[1000];
	int i = 0;
	
	while (cin >> n){
		if (n == 0){
			car[i] = R.top();
			R.pop();
			i++;
		}
		else {
			R.push(n);
		}
	}
	
	for (int j = 0; j < i; j++){
		cout << car[j] << endl;
	}
	
	return (0);
}