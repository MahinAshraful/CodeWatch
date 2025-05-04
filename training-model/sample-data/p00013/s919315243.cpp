#include <iostream>
#include <stack>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	stack<int> s;
	s.push(n);
	
	int a;
	while(cin >> a){
		if(a == 0){
			cout << s.top() << endl;
			s.pop();
		}
		else {
			s.push(a);
		}
	}
	
	return 0;
}