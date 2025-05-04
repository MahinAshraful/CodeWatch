#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> CarEntrance;
	while(true){
		int CarNumber;
		cin >> CarNumber;
		if(cin.eof() == true) break;
		if(CarNumber == 0){
			cout << CarEntrance.top() << endl;
			CarEntrance.pop();
		}else{
			CarEntrance.push(CarNumber);
		}
	}
	return 0;
}