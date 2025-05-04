#include <iostream>
using namespace std;

class Triangle{
private:
	int a, b, c;
public:
	void Set();
	bool Jugde();
};

void Triangle::Set(){
	cin >> a >> b >> c;
}

bool Triangle::Jugde(){
	int buf;
	if(a < b){
		buf = a;
		a = b;
		b = buf;
	}
	if(a < c){
		buf = a;
		a = c;
		c = buf;
	}
	if(a*a == b*b + c*c) return true;
	else return false;
}

int main(){

	int n;
	bool jugde;
	Triangle* dataset;

	cin >> n;

	dataset = new Triangle[n];

	for(int i = 0; i < n; i++)
		dataset[i].Set();

	for(int i = 0; i < n; i++){
		jugde = dataset[i].Jugde();
		if(jugde == true)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}