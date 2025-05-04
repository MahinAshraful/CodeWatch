#include <iostream>
using namespace std;

int main() {
	char str[21] = "";

	cin>>str;

	for (int i=19;i>=0;i--) {
		if (str[i]!=NULL)
			cout<<str[i];
	}
	cout<<endl;

	return 0;
}