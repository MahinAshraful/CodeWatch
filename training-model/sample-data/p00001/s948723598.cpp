#include <iostream>
using namespace std;

int main() {
	int a = 0, b = 0, c = 0, h[10];
        for(int i = 0; i < 10; ++i){
             cin >> h[i];
		if(a < h[i]){
			c = b;
			b = a;
			a = h[i];
		}
		else if(b < h[i]){
		    c = b;
		    b = h[i];
		}
		else if(c < h[i]){
			c = h[i];
		}
	}
	cout << a << endl << b << endl << c << endl;
	return 0;
}