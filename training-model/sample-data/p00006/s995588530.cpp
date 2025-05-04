#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int i,n;
	char a[41];
	cin >> a;
	n = strlen(a);
	for(i=n-1;i>=0;i--)
	{
		cout << a[i];
	}
	cout << endl;
	return 0;
}