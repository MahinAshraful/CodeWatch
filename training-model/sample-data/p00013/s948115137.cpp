#include <stack>
#include <iostream>
using namespace std;
int main()
{
	stack<int> data;
	int input;
	
	while (cin >> input)
	{
		if (input)
		{
			data.push(input);
		}
		else
		{
			cout << data.top() << endl;
			data.pop();
		}
	}
}