#include <iostream>
#include <queue>

using namespace std;

void solve()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	priority_queue<int> PQue;
	PQue.push(a);
	PQue.push(b);
	PQue.push(c);
	PQue.push(d);
	PQue.push(e);
	for(int i = 0; i < 4; ++i)
	{
		cout << PQue.top() << " ";
		PQue.pop();
	}
	cout << PQue.top() << endl;
}

int main()
{
	solve();
	return(0);
}